#include "state_estimation.h"
#include "firmware/input_board.h"
#include "linear_encoder.h"
#include "state_estimation/accelerometer.h"
#include "util/metrics.h"
#include "util/timestamp.h"
#include <cmath>
#include <cstring>
#include <limits>

static int32_t last_stripe_count = 0;
constexpr Frequency ACCELEROMETER_FREQ = 1_kHz;
static Timestamp last_accel;
static Timestamp last_update;
static Distance s_pos;
static Velocity s_vel;
static Acceleration s_acc;
constexpr float stripe_variance = 0.000001f;
constexpr float imu_variance = 0.00001f;

void StateEstimation::begin() {
  LinearEncoderBeginInfo linEncBeginInfo;
  linEncBeginInfo.stride = 2_cm;
  linEncBeginInfo.back_pin = PIN_DIN2;
  linEncBeginInfo.front_pin = PIN_DIN3;
  linEncBeginInfo.back_edge_pin = PIN_DIN4;
  linEncBeginInfo.front_edge_pin = PIN_DIN5;
  linEncBeginInfo.stripe_count = last_stripe_count;
  LinearEncoder::begin(linEncBeginInfo);
  last_accel = Timestamp::now();
  Accelerometer::begin();

  for (int i = 0; i < DIM_STATE; i++) {
    ekf.x_hat[i] = 0.0f;
  }
  for (int i = 0; i < DIM_STATE; i++) {
    for (int j = 0; j < DIM_STATE; j++) {
      ekf.P_pre[i][j] = 0.0f;
      ekf.F[i][j] = 0.0f;
      ekf.F_T[i][j] = 0.0f;
      ekf.Q[i][j] = 0.000025f;
    }
    ekf.P_pre[i][i] = 1.0f;
    ekf.F[i][i] = 1.0f;
    ekf.F_T[i][i] = 1.0f;
  }
  for (int i = 0; i < DIM_OBSER; i++) {
    for (int j = 0; j < DIM_OBSER; j++) {
      ekf.R[i][j] = 0.0f;
    }
  }
  for (int i = 0; i < DIM_OBSER; i++) {
    for (int j = 0; j < DIM_STATE; j++) {
      ekf.H[i][j] = 0.0f;
      ekf.H_T[j][i] = 0.0f;
    }
  }
  ekf.H[0][0] = 1.0f;
  ekf.H[1][2] = 1.0f;
  ekf.H_T[0][0] = 1.0f;
  ekf.H_T[2][1] = 1.0f;
  ekf.R[stripe_i][stripe_i] = stripe_variance; // variance of feducial
  ekf.R[imu_i][imu_i] = imu_variance; // variance of imu
  last_update = Timestamp::now();
}

void StateEstimation::update() {
  if (last_stripe_count != LinearEncoder::stripe_count()) {
    StateEstimation::position_update(LinearEncoder::position(), LinearEncoder::last_isr());
  }
  const Timestamp now = Timestamp::now();
  if (now - last_accel > 1.0f / ACCELEROMETER_FREQ) {
    Acceleration accel = Accelerometer::readAccel();
    acceleration_update(accel, now);
    last_accel = last_accel + 1.0f / ACCELEROMETER_FREQ;
  }
}
Distance StateEstimation::getPosition() {
  return Distance(ekf.x_hat[pos_i]);
}
Velocity StateEstimation::getVelocity() {
  return Velocity(ekf.x_hat[speed_i]);
}
Acceleration StateEstimation::getAcceleration() {
  return Acceleration(ekf.x_hat[acc_i]);
}


void StateEstimation::position_update(const Distance &pos,
                                      const Timestamp &timestamp) {
  const float dur_us = (timestamp - last_update).as_us();
  last_update = Timestamp::now();
  constexpr float us_in_s = 1000000.0f;
  // predict new state based on old one
  ekf.f_xu[pos_i] = ekf.x_hat[pos_i] + dur_us * ekf.x_hat[speed_i] / us_in_s
    + dur_us * dur_us * ekf.x_hat[acc_i] / us_in_s;
  ekf.f_xu[speed_i] = ekf.x_hat[speed_i] + dur_us * ekf.x_hat[acc_i] / us_in_s;
  ekf.f_xu[acc_i] = ekf.x_hat[acc_i];

  // set jacobian of process matrix
  ekf.F[0][1] = dur_us / us_in_s;
  ekf.F[0][2] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F[1][2] = dur_us / us_in_s;
  ekf.F_T[1][0] = dur_us / us_in_s;
  ekf.F_T[2][0] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F_T[2][1] = dur_us / us_in_s;

  // set expected measurements, H is constant and does not have to be changed
  ekf.h_x[stripe_i] = ekf.f_xu[pos_i];
  ekf.h_x[imu_i] = ekf.f_xu[acc_i];

  float measurement[DIM_OBSER];
  measurement[stripe_i] = static_cast<float>(pos);
  measurement[imu_i] = ekf.f_xu[acc_i]; // use predicted value as missing measurement
  ekf.R[imu_i][imu_i] = std::numeric_limits<float>::infinity(); // and its variance high 
                                              // => measurement should be ignored by filter
  ekf_step(ekf, measurement);
  ekf.R[imu_i][imu_i] = imu_variance;
}
void StateEstimation::acceleration_update(const Acceleration &acc,
                                          const Timestamp &timestamp) {
  const float dur_us = (timestamp - last_update).as_us();
  last_update = Timestamp::now();
  constexpr float us_in_s = 1000000.0f;
  // predict new state based on old one
  ekf.f_xu[pos_i] = ekf.x_hat[pos_i] + dur_us * ekf.x_hat[speed_i] / us_in_s
    + dur_us * dur_us * ekf.x_hat[acc_i] / us_in_s;
  ekf.f_xu[speed_i] = ekf.x_hat[speed_i] + dur_us * ekf.x_hat[acc_i] / us_in_s;
  ekf.f_xu[acc_i] = ekf.x_hat[acc_i];

  // set jacobian of process matrix
  ekf.F[0][1] = dur_us / us_in_s;
  ekf.F[0][2] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F[1][2] = dur_us / us_in_s;
  ekf.F_T[1][0] = dur_us / us_in_s;
  ekf.F_T[2][0] = 0.5f * dur_us * dur_us / us_in_s / us_in_s;
  ekf.F_T[2][1] = dur_us / us_in_s;

  // set expected measurements, H is constant and does not have to be changed
  ekf.h_x[stripe_i] = ekf.f_xu[pos_i];
  ekf.h_x[imu_i] = ekf.f_xu[acc_i];

  float measurement[DIM_OBSER];
  measurement[stripe_i] = ekf.f_xu[pos_i]; // use predicted value as missing measurement
  measurement[imu_i] = static_cast<float>(acc); 
  ekf.R[stripe_i][stripe_i] = std::numeric_limits<float>::infinity(); // and its variance high 
                                              // => measurement should be ignored by filter
  ekf_step(ekf, measurement);
  ekf.R[stripe_i][stripe_i] = stripe_variance;
}
