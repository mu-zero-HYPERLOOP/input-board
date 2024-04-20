#include "state_estimation.h"
#include "firmware/input_board.h"
#include "linear_encoder.h"
#include "state_estimation/accelerometer.h"
#include "util/metrics.h"

static int32_t last_stripe_count = 0;
constexpr Frequency ACCELEROMETER_FREQ = 1_kHz;
static Timestamp last_accel;
static Distance s_pos;
static Velocity s_vel;
static Acceleration s_acc;

void StateEstimation::begin() {
  LinearEncoderBeginInfo linEncBeginInfo;
  linEncBeginInfo.stride = 2_cm;
  linEncBeginInfo.back_pin = DIN2;
  linEncBeginInfo.front_pin = DIN3;
  linEncBeginInfo.back_edge_pin = DIN4;
  linEncBeginInfo.front_edge_pin = DIN5;
  linEncBeginInfo.stripe_count = last_stripe_count;
  LinearEncoder::begin(linEncBeginInfo);
  last_accel = Timestamp::now();
  Accelerometer::begin();
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
Distance StateEstimation::getPosition() {}
Velocity StateEstimation::getVelocity() {}
Acceleration StateEstimation::getAcceleration() {}

void StateEstimation::position_update(const Distance &pos,
                                      const Timestamp &timstamp) {
  s_pos = pos;
}
void StateEstimation::acceleration_update(const Acceleration &acc,
                                          const Timestamp &timestamp) {
  s_acc = acc;
}
