#include "state_estimation.h"
#include "canzero/canzero.h"
#include "print.h"
#include "sensors/linear_encoder.h"
#include "state_estimation/ekf.hpp"
#include "util/metrics.h"
#include "util/static_vec.h"
#include "util/timestamp.h"
#include <algorithm>
#include <avr/pgmspace.h>

DMAMEM Acceleration previous_target_acceleration = 0_mps2;
constexpr unsigned char DIM_STATE = 3;
constexpr unsigned char DIM_OBSER = 2;
constexpr unsigned int pos_i = 0;
constexpr unsigned int speed_i = 1;
constexpr unsigned int acc_i = 2;
constexpr unsigned int stripe_i = 0;
constexpr unsigned int imu_i = 1;
constexpr float stripe_variance = 0.0001f;
float imu_variance = 0.01f;
constexpr float max_variance = std::numeric_limits<float>::max();
static Timestamp last_state_update;

static Ekf<DIM_STATE, DIM_OBSER> ekf;


enum class StateEstimationEventType {
  Position,
  Acceleration,
};

struct StateEstimationEvent {
  StateEstimationEventType m_type;
  Timestamp m_timestamp;
  union {
    Acceleration m_acceleration;
    sensors::linear_encoder::LinearEncoderEventTag m_event_tag;
  };
  StateEstimationEvent(const Timestamp &timestamp, Acceleration acceleration)
      : m_type(StateEstimationEventType::Acceleration), m_timestamp(timestamp),
        m_acceleration(acceleration) {}
  StateEstimationEvent(const Timestamp &timestamp,
                       sensors::linear_encoder::LinearEncoderEventTag tag)
      : m_type(StateEstimationEventType::Position), m_timestamp(timestamp),
        m_event_tag(tag) {}
  StateEstimationEvent(const StateEstimationEvent &o)
      : m_type(o.m_type), m_timestamp(o.m_timestamp) {
    switch (m_type) {
    case StateEstimationEventType::Acceleration:
      m_acceleration = o.m_acceleration;
      break;
    case StateEstimationEventType::Position:
      m_event_tag = o.m_event_tag;
      break;
    }
  };
  StateEstimationEvent &operator=(const StateEstimationEvent &o) {
    if (this == &o) {
      return *this;
    }
    m_type = o.m_type;
    m_timestamp = o.m_timestamp;
    switch (m_type) {
    case StateEstimationEventType::Acceleration:
      m_acceleration = o.m_acceleration;
      break;
    case StateEstimationEventType::Position:
      m_event_tag = o.m_event_tag;
      break;
    }
    return *this;
  };
};

static StaticVec<StateEstimationEvent, 10> event_queue;

void FLASHMEM state_estimation::begin() {
  for (int i = 0; i < DIM_STATE; i++) {
    ekf.x_hat[i] = 0.0f;
  }
  ekf.x_hat[pos_i] = 0.2f; // TODO: add actual start distance here
  for (int i = 0; i < DIM_STATE; i++) {
    for (int j = 0; j < DIM_STATE; j++) {
      ekf.P_pre[i * DIM_STATE + j] = 0.0f;
      ekf.F[i * DIM_STATE + j] = 0.0f;
      ekf.F_T[i * DIM_STATE + j] = 0.0f;
      ekf.Q[i * DIM_STATE + j] = 0.0f; // process noise
    }
    ekf.P_pre[i * DIM_STATE + i] = 1.0f;
    ekf.F[i * DIM_STATE + i] = 1.0f;
    ekf.F_T[i * DIM_STATE + i] = 1.0f;
  }
  ekf.Q[pos_i * DIM_STATE + pos_i] = 0.00001f;     // position process noise
  ekf.Q[speed_i * DIM_STATE + speed_i] = 0.00001f; // velocity process noise
  ekf.Q[acc_i * DIM_STATE + acc_i] = 0.00001f;     // acceleration process noise

  for (int i = 0; i < DIM_OBSER; i++) {
    for (int j = 0; j < DIM_OBSER; j++) {
      ekf.R[i * DIM_OBSER + j] = 0.0f;
    }
  }
  ekf.R[stripe_i * DIM_OBSER + stripe_i] =
      stripe_variance; // variance of feducial
  ekf.R[imu_i * DIM_OBSER + imu_i] = imu_variance;

  for (int i = 0; i < DIM_OBSER; i++) {
    for (int j = 0; j < DIM_STATE; j++) {
      ekf.H[i * DIM_STATE + j] = 0.0f;
      ekf.H_T[j * DIM_OBSER + i] = 0.0f;
    }
  }
  ekf.H[0 * DIM_STATE + 0] = 1.0f;
  ekf.H[1 * DIM_STATE + 2] = 1.0f;
  ekf.H_T[0 * DIM_OBSER + 0] = 1.0f;
  ekf.H_T[2 * DIM_OBSER + 1] = 1.0f;
  last_state_update = Timestamp::now();
}

void PROGMEM state_estimation::calibrate() {
  float variance = canzero_get_acceleration_calibration_variance();
  // idk do some shit with it.
  // ekf.R[imu_i * DIM_OBSER + imu_i] = variance;
  // imu_variance = variance;
}

void FASTRUN state_estimation::linear_encoder_update(
    const sensors::linear_encoder::LinearEncoderEventTag &tag,
    const Timestamp &timestamp) {
  debugPrintf("linear encoder update\n");
  int16_t stripe_count = canzero_get_linear_encoder_count();
  switch (tag) {
  case sensors::linear_encoder::COUNT_INCREMENT:
    stripe_count += 1;
    break;
  case sensors::linear_encoder::COUNT_DECREMENT:
    stripe_count -= 1;
    break;
  case sensors::linear_encoder::COUNT_NONE: // when the linear encoder moves
                                            // back and forth over the same
                                            // edge.
    break;
  case sensors::linear_encoder::END_DETECTION_FRONT:
  case sensors::linear_encoder::END_DETECTION_BACK:
    break;
  }
  canzero_set_linear_encoder_count(stripe_count);

  // perform actual state estimation here.
  const float dur_us = timestamp > last_state_update
                           ? (timestamp - last_state_update).as_us()
                           : 0.0f;
  last_state_update = timestamp;
  constexpr float us_in_s = 1e6f;
  // predict new state based on old one
  float target_accel = canzero_get_target_acceleration();
  ekf.f_xu[acc_i] = target_accel;
  ekf.f_xu[speed_i] = ekf.x_hat[speed_i] + dur_us * target_accel / us_in_s;
  ekf.f_xu[pos_i] = ekf.x_hat[pos_i] + dur_us * ekf.x_hat[speed_i] / us_in_s +
                    0.5 * dur_us * dur_us * target_accel / us_in_s / us_in_s;
  /*debugPrintf("predicted acceleration: %f\n", ekf.f_xu[acc_i]);*/
  /*debugPrintf("predicted speed: %f\n", ekf.f_xu[speed_i]);*/
  debugPrintf("predicted position: %f\n", ekf.f_xu[pos_i]);

  // set jacobian of process function (derivative of f)
  float target_accel_d = 1;
  ekf.F[0 * DIM_STATE + 1] = dur_us / us_in_s;
  ekf.F[0 * DIM_STATE + 2] =
      0.5f * dur_us * dur_us * target_accel_d / us_in_s / us_in_s;
  ekf.F[1 * DIM_STATE + 2] = dur_us * target_accel_d / us_in_s;
  ekf.F[2 * DIM_STATE + 2] = target_accel_d;
  ekf.F_T[1 * DIM_STATE + 0] = dur_us / us_in_s;
  ekf.F_T[2 * DIM_STATE + 0] =
      0.5f * dur_us * dur_us * target_accel_d / us_in_s / us_in_s;
  ekf.F_T[2 * DIM_STATE + 1] = dur_us * target_accel_d / us_in_s;
  ekf.F_T[2 * DIM_STATE + 2] = target_accel_d;

  // set expected measurements, H is constant and does not have to be changed
  ekf.h_x[stripe_i] = ekf.f_xu[pos_i];
  ekf.h_x[imu_i] = ekf.f_xu[acc_i];

  BaseType measurement[DIM_OBSER];
  measurement[stripe_i] = static_cast<float>(STRIPE_STRIDE / 2 * stripe_count);
  measurement[imu_i] =
      ekf.h_x[imu_i]; // use predicted value as missing measurement
                      // => measurement should be ignored by filter
  ekf.R[imu_i * DIM_OBSER + imu_i] = max_variance;
  ekf_step<DIM_STATE, DIM_OBSER>(ekf, measurement);
  ekf.R[imu_i * DIM_OBSER + imu_i] = imu_variance;
}

void FASTRUN state_estimation::acceleration_update(const Acceleration &acc,
                                                   const Timestamp &timestamp) {
  debugPrintf("acceleration update\n");

  const float dur_us = timestamp > last_state_update
                           ? (timestamp - last_state_update).as_us()
                           : 0.0f;
  last_state_update = timestamp;
  constexpr float us_in_s = 1e6f;
  // predict new state based on old one
  float target_accel = canzero_get_target_acceleration();
  ekf.f_xu[acc_i] = target_accel;
  ekf.f_xu[speed_i] = ekf.x_hat[speed_i] + dur_us * target_accel / us_in_s;
  ekf.f_xu[pos_i] = ekf.x_hat[pos_i] + dur_us * ekf.x_hat[speed_i] / us_in_s +
                    0.5 * dur_us * dur_us * target_accel / us_in_s / us_in_s;
  /*debugPrintf("predicted acceleration: %f\n", ekf.f_xu[acc_i]);*/
  /*debugPrintf("predicted speed: %f\n", ekf.f_xu[speed_i]);*/
  debugPrintf("predicted position: %f\n", ekf.f_xu[pos_i]);

  // set jacobian of process function (derivative of f)
  float target_accel_d = 1;
  ekf.F[0 * DIM_STATE + 1] = dur_us / us_in_s;
  ekf.F[0 * DIM_STATE + 2] =
      0.5f * dur_us * dur_us * target_accel_d / us_in_s / us_in_s;
  ekf.F[1 * DIM_STATE + 2] = dur_us * target_accel_d / us_in_s;
  ekf.F[2 * DIM_STATE + 2] = target_accel_d;
  ekf.F_T[1 * DIM_STATE + 0] = dur_us / us_in_s;
  ekf.F_T[2 * DIM_STATE + 0] =
      0.5f * dur_us * dur_us * target_accel_d / us_in_s / us_in_s;
  ekf.F_T[2 * DIM_STATE + 1] = dur_us * target_accel_d / us_in_s;
  ekf.F_T[2 * DIM_STATE + 2] = target_accel_d;
  // set expected measurements, H is constant and does not have to be changed
  // TODO: limit expected measurement by stripe count!
  ekf.h_x[stripe_i] = ekf.f_xu[pos_i];
  ekf.h_x[imu_i] = ekf.f_xu[acc_i];

  BaseType measurement[DIM_OBSER];
  measurement[imu_i] = static_cast<float>(acc);
  // simulate missing position value based on predicted position and stripe
  // count
  const int16_t stripe_count = canzero_get_linear_encoder_count();
  const float min_position = stripe_count * static_cast<float>(STRIPE_STRIDE / 2);
  const float max_position = min_position + static_cast<float>(STRIPE_STRIDE / 2);
  const float possible_position =
      std::clamp(ekf.x_hat[pos_i], min_position, max_position);
  measurement[stripe_i] = possible_position;

  ekf.R[stripe_i * DIM_OBSER + stripe_i] = max_variance;
  ekf_step<DIM_STATE, DIM_OBSER>(ekf, measurement);
  ekf.R[stripe_i * DIM_OBSER + stripe_i] = stripe_variance;
}

void FASTRUN state_estimation::target_acceleration_update(
    const Acceleration &acc, const Timestamp &timestamp) {}

int FASTRUN state_estimation::push_acceleration_event(
    const Acceleration &acc, const Timestamp &timestamp) {
  StateEstimationEvent event(timestamp, acc);
  return event_queue.push(event);
}

int FASTRUN state_estimation::push_position_event(
    const sensors::linear_encoder::LinearEncoderEvent &e) {
  StateEstimationEvent event(e.m_timestamp, e.m_tag);
  return event_queue.push(event);
}

void FASTRUN state_estimation::update() {

  std::sort(event_queue.begin(), event_queue.end(),
            [](const StateEstimationEvent &a, const StateEstimationEvent &b) {
              return static_cast<uint32_t>(a.m_timestamp) <
                     static_cast<uint32_t>(b.m_timestamp);
            });
  auto it = event_queue.begin();
  while (it != event_queue.end()) {
    StateEstimationEvent event = *it;
    switch (event.m_type) {
    case StateEstimationEventType::Position:
      linear_encoder_update(event.m_event_tag, event.m_timestamp);
      break;
    case StateEstimationEventType::Acceleration:
      acceleration_update(event.m_acceleration, event.m_timestamp);
    }
    it++;
  }
  event_queue.clear();

  Acceleration target_acceleration =
      Acceleration(canzero_get_target_acceleration());
  if ((target_acceleration - previous_target_acceleration).abs() <
      0.00001_mps2) {
    target_acceleration_update(target_acceleration, Timestamp::now());
    previous_target_acceleration = target_acceleration;
  }
  const float dur_us = (Timestamp::now() - last_state_update).as_us();
  constexpr float us_in_s = 1e6f;
  canzero_set_acceleration(ekf.x_hat[acc_i]);
  canzero_set_velocity(ekf.x_hat[speed_i] +
                       dur_us * ekf.x_hat[acc_i] / us_in_s);
  float predicted_position =
      ekf.x_hat[pos_i] + dur_us * ekf.x_hat[speed_i] / us_in_s +
      0.5 * dur_us * dur_us * ekf.x_hat[acc_i] / us_in_s / us_in_s;
  int16_t stripe_count = canzero_get_linear_encoder_count();
  float min_position = stripe_count * static_cast<float>(STRIPE_STRIDE / 2);
  float max_position = min_position + static_cast<float>(STRIPE_STRIDE / 2);
  float possible_position =
      std::clamp(predicted_position, min_position, max_position);
  canzero_set_position(possible_position);
}
