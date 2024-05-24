#include "state_estimation.h"
#include "canzero/canzero.h"
#include "state_estimation/ekf.hpp"
#include "util/timestamp.h"
#include <iterator>
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
constexpr float max_variance = std::numeric_limits<float>::max();
static Timestamp last_state_update;

static Ekf<DIM_STATE, DIM_OBSER> ekf;


void FLASHMEM state_estimation::begin() {
  for (int i = 0; i < DIM_STATE; i++) {
    ekf.x_hat[i] = 0.2f; // TODO: add actual end stripe distance here?
  }
  ekf.x_hat[pos_i] = 0.0f;
  ekf.x_hat[speed_i] = 0.0f;
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
  ekf.Q[pos_i * DIM_STATE + pos_i] = 0.00001f; // position process noise
  ekf.Q[speed_i * DIM_STATE + speed_i] = 0.00001f; // velocity process noise
  ekf.Q[acc_i * DIM_STATE + acc_i] = 0.00001f; // acceleration process noise

  for (int i = 0; i < DIM_OBSER; i++) {
    for (int j = 0; j < DIM_OBSER; j++) {
      ekf.R[i * DIM_OBSER + j] = 0.0f;
    }
  }
  ekf.R[stripe_i * DIM_OBSER + stripe_i] = stripe_variance; // variance of feducial

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
  ekf.R[imu_i * DIM_OBSER + imu_i] = variance;

}

void FASTRUN state_estimation::linear_encoder_update(
    const sensors::linear_encoder::LinearEncoderEvent event) {
  int16_t stripe_count = canzero_get_linear_encoder_count();
  switch (event.m_tag) {
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
  /* Distance x = STRIPE_STRIDE; */

  const Timestamp &timestamp = event.m_timestamp;

  // perform actual state estimation here.
  const float dur_us = (timestamp - last_state_update).as_us();
  last_state_update = Timestamp::now();
  constexpr float us_in_s = 1e6f;
  // predict new state based on old one
  ekf.f_xu[pos_i] = ekf.x_hat[pos_i] 
    + dur_us * ekf.x_hat[speed_i] / us_in_s 
    + 0.5 * dur_us * dur_us * ekf.x_hat[acc_i] / us_in_s / us_in_s;
  ekf.f_xu[speed_i] = ekf.x_hat[speed_i] + dur_us * ekf.x_hat[acc_i] / us_in_s;
  ekf.f_xu[acc_i] = ekf.x_hat[acc_i];

  // set jacobian of process matrix
  ekf.F[0 * DIM_STATE + 1] = dur_us / us_in_s;
  ekf.F[0 * DIM_STATE + 2] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F[1 * DIM_STATE + 2] = dur_us / us_in_s;
  ekf.F_T[1 * DIM_STATE + 0] = dur_us / us_in_s;
  ekf.F_T[2 * DIM_STATE + 0] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F_T[2 * DIM_STATE + 1] = dur_us / us_in_s;

  // set expected measurements, H is constant and does not have to be changed
  ekf.h_x[stripe_i] = ekf.f_xu[pos_i];
  ekf.h_x[imu_i] = ekf.f_xu[acc_i];

  BaseType measurement[DIM_OBSER];
  measurement[stripe_i] = static_cast<float>(STRIPE_STRIDE * stripe_count);
  measurement[imu_i] = ekf.h_x[imu_i]; // use predicted value as missing measurement
                                              // => measurement should be ignored by filter
  ekf.R[imu_i * DIM_OBSER + imu_i] = max_variance;
  ekf_step<DIM_STATE, DIM_OBSER>(ekf, measurement);
  ekf.R[imu_i * DIM_OBSER + imu_i] = canzero_get_acceleration_calibration_variance();
}

void FASTRUN state_estimation::acceleration_update(const Acceleration &acc,
                                           const Timestamp &timestamp) {
  const float dur_us = (timestamp - last_state_update).as_us();
  last_state_update = Timestamp::now();
  constexpr float us_in_s = 1e6f;
  // predict new state based on old one
  ekf.f_xu[pos_i] = ekf.x_hat[pos_i] 
    + dur_us * ekf.x_hat[speed_i] / us_in_s 
    + 0.5 * dur_us * dur_us * ekf.x_hat[acc_i] / us_in_s / us_in_s;
  ekf.f_xu[speed_i] = ekf.x_hat[speed_i] + dur_us * ekf.x_hat[acc_i] / us_in_s;
  ekf.f_xu[acc_i] = ekf.x_hat[acc_i];

  // set jacobian of process matrix
  ekf.F[0 * DIM_STATE + 1] = dur_us / us_in_s;
  ekf.F[0 * DIM_STATE + 2] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F[1 * DIM_STATE + 2] = dur_us / us_in_s;
  ekf.F_T[1 * DIM_STATE + 0] = dur_us / us_in_s;
  ekf.F_T[2 * DIM_STATE + 0] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F_T[2 * DIM_STATE + 1] = dur_us / us_in_s;

  // set expected measurements, H is constant and does not have to be changed
  // TODO: limit expected measurement by stripe count!
  ekf.h_x[stripe_i] = ekf.f_xu[pos_i]; // try something new?!
  ekf.h_x[imu_i] = ekf.f_xu[acc_i];

  BaseType measurement[DIM_OBSER];
  // TODO: limit simulated measurement by stripe count!
  measurement[stripe_i] = ekf.x_hat[pos_i]; // use old value as missing measurement
  measurement[imu_i] = static_cast<float>(acc); 

  ekf.R[stripe_i * DIM_OBSER + stripe_i] = max_variance;
  ekf_step<DIM_STATE, DIM_OBSER>(ekf, measurement);
  ekf.R[stripe_i * DIM_OBSER + stripe_i] = stripe_variance;
}


void FASTRUN state_estimation::target_acceleration_update(const Acceleration &acc, const Timestamp &timestamp) {
}

void FASTRUN state_estimation::update() {
  Acceleration target_acceleration = Acceleration(canzero_get_target_acceleration());
  if ((target_acceleration - previous_target_acceleration).abs() < 0.00001_mps2) {
    target_acceleration_update(target_acceleration, Timestamp::now());
    previous_target_acceleration = target_acceleration;
  }
}

