/**
 * @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

#include "canzero/canzero.h"
#include "core_pins.h"
#include "firmware/input_board.h"
#include "state_estimation/state_estimation.h"
#include "util/ema.hpp"
#include "util/metrics.h"

int main() {

  Frequency f = 1_Hz;
  /* Duration x = 1.0f / f; */

  canzero_set_state(input_board_state_INIT);
  canzero_init();

  InputBoard::begin();

  ExponentialMovingAverage<Voltage> vmeas1_filter(0.1, 0_V);
  ExponentialMovingAverage<Voltage> vmeas2_filter(0.1, 0_V);
  ExponentialMovingAverage<Voltage> vmeas3_filter(0.1, 0_V);

  ExponentialMovingAverage<Current> ain1_filter(0.1, 0_A);
  ExponentialMovingAverage<Resistance> ain2_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain3_filter(0.1, 0_Ohm);

  ExponentialMovingAverage<Resistance> ntc1_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc2_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc3_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc4_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc5_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc6_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc7_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc8_filter(0.1, 0_Ohm);

  ExponentialMovingAverage<Voltage> ain_mux1_filter(0.1, 0_V);
  ExponentialMovingAverage<Voltage> ain_mux2_filter(0.1, 0_V);
  ExponentialMovingAverage<Current> ain_mux3_filter(0.1, 0_A);
  ExponentialMovingAverage<Resistance> ain_mux4_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux5_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux6_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux7_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux8_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux9_filter(0.1, 0_Ohm);

  Timestamp last_sdc_trig = Timestamp::now();
  Timestamp last_log = Timestamp::now();

  bool sdc_trig = false;

  StateEstimation::begin();

  Timestamp last_mcu_over_temp_error_ok = Timestamp::now();
  Timestamp last_mcu_over_temp_warn_ok = Timestamp::now();

  while (true) {
    const Timestamp now = Timestamp::now();

    canzero_can0_poll();
    canzero_can1_poll();

    // ====================   MCU Temperature ===================
    float mcu_temp = static_cast<float>(InputBoard::read_mcu_temperature()) +
                     273.15; // convert to °C
    canzero_set_mcu_temperature(mcu_temp);
    if (canzero_get_warn_mcu_over_temperature_thresh() < mcu_temp) {
      last_mcu_over_temp_warn_ok = now;
    }
    canzero_set_warn_mcu_over_temperature(
        now - last_mcu_over_temp_warn_ok <
                Time(canzero_get_warn_mcu_over_temperature_timeout())
            ? error_flag_OK
            : error_flag_ERROR);

    if (canzero_get_error_mcu_over_temperature_thresh() < mcu_temp) {
      last_mcu_over_temp_error_ok = now;
    }
    canzero_set_error_mcu_over_temperature(
        now - last_mcu_over_temp_error_ok <
                Time(canzero_get_error_mcu_over_temperature_timeout())
            ? error_flag_OK
            : error_flag_ERROR);

    // ==================== EBOX-Temperature ==================
    // TODO

    // ==================== Cooling Cycle Temperature =========
    // TODO

    // ==================== State Estimation ==================
    StateEstimation::update();

    const Distance pos = StateEstimation::getPosition();
    const Velocity vel = StateEstimation::getVelocity();
    const Acceleration accel = StateEstimation::getAcceleration();
    canzero_set_position_estimation(static_cast<float>(pos));
    canzero_set_velocity_estimation(static_cast<float>(vel));
    canzero_set_acceleration_estimation(static_cast<float>(accel));

    canzero_set_error_invalid_position(
        (pos<0_m || pos> Distance(canzero_get_track_length())) ? error_flag_ERROR
                                                              : error_flag_OK);

    canzero_set_error_invalid_acceleration(
        accel.abs() > 10_mps2 ? error_flag_ERROR : error_flag_OK);

    canzero_update_continue(canzero_get_time());

    canzero_set_state(input_board_state_RUNNING);
  }
}
