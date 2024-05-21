#include "state_estimation.h"
#include "canzero/canzero.h"
#include <cmath>
#include <iterator>
#include <avr/pgmspace.h>

DMAMEM Acceleration previous_target_acceleration = 0_mps2;

void FLASHMEM state_estimation::begin() {
  // no need to initalize the periperals.
}

void PROGMEM state_estimation::calibrate() {
  float variance = canzero_get_acceleration_calibration_variance();
  // idk do some shit with it.
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
}

void FASTRUN state_estimation::acceleration_update(const Acceleration &acc,
                                           const Timestamp &timestamp) {

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
