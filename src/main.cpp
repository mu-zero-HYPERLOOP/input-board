/** @author      : kistenklaus (karlsasssie@gmail.com)
 readonly* @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

/* static Interval mcu_temperature_interval(100_Hz); */
/* static BoxcarFilter<Temperature, 10> mcu_temperature_filter(24_Celcius); */
/* static ErrorLevelRangeCheck<EXPECT_UNDER> */
/*     mcu_temp_check(canzero_get_mcu_temperature, */
/*                    canzero_get_error_level_config_mcu_temperature, */
/*                    canzero_set_error_level_mcu_temperature); */

#include "canzero/canzero.h"
#include "defaults.h"
#include "print.h"
#include "firmware/input_board.h"
#include "sdc.h"
#include "sensors/accelerometer.h"
#include "sensors/ambient_temperature.h"
#include "sensors/bat24_current.h"
#include "sensors/bat24_temperature.h"
#include "sensors/bat24_voltage.h"
#include "sensors/ebox_temperature.h"
#include "sensors/linear_encoder.h"
#include "sensors/link24_current.h"
#include "sensors/supercap_voltage.h"
#include "sensors/link45_current.h"
#include "sensors/link45_voltage.h"
#include "sensors/mcu_temperature.h"
#include "sensors/supercap_temperature.h"
#include "error_handling.hpp"
#include <avr/pgmspace.h>
#include "state_estimation/state_estimation.h"
#include "util/timing.h"


static IntervalTiming loopIntervalTiming;

int main() {
  canzero_init();

  can_defaults();

  canzero_set_state(input_board_state_INIT);

  canzero_update_continue(canzero_get_time());

  canzero_set_target_acceleration(0);

  input_board::begin();

  sdc::begin();

  sensors::ambient_temperature::begin();
  sensors::accelerometer::begin();
  sensors::linear_encoder::begin();

  sensors::bat24_temperature::begin();
  sensors::ebox_temperature::begin();
  sensors::mcu_temperature::begin();
  sensors::supercap_temperature::begin();

  sensors::bat24_current::begin();
  sensors::bat24_voltage::begin();
  sensors::link24_current::begin();

  sensors::supercap_voltage::begin();
  sensors::link45_current::begin();
  sensors::link45_voltage::begin();

  state_estimation::begin();

calibration:
  sdc::open();
  canzero_set_state(input_board_state_CALIBRATION);
  canzero_update_continue(canzero_get_time());

  sensors::accelerometer::calibrate();
  sensors::linear_encoder::calibrate();

  sensors::ambient_temperature::calibrate();
  sensors::bat24_temperature::calibrate();
  sensors::ebox_temperature::calibrate();
  sensors::mcu_temperature::calibrate();
  sensors::supercap_temperature::calibrate();
  sensors::ambient_temperature::calibrate();

  sensors::bat24_current::calibrate();
  sensors::bat24_voltage::calibrate();
  sensors::link24_current::calibrate();
  sensors::supercap_voltage::calibrate();
  sensors::link45_current::calibrate();
  sensors::link45_voltage::calibrate();

  //state_estimation::calibrate();
  debugPrintf("Init DONE\n");

  loopIntervalTiming.reset();
  while (true) {
    canzero_can0_poll();
    canzero_can1_poll();
    canzero_set_state(input_board_state_RUNNING);

    if (input_board_command_CALIBRATE == canzero_get_command()) {
      canzero_set_command(input_board_command_NONE);
      goto calibration;
    }

    
    if (error_handling::no_error()) {
      sdc::close();
    } else {
      sdc::open();
    }

    input_board::update_continue();

    sensors::accelerometer::update();
    sensors::linear_encoder::update();

    sensors::ambient_temperature::update();
    sensors::bat24_temperature::update();
    sensors::ebox_temperature::update();
    sensors::mcu_temperature::update();
    sensors::supercap_temperature::update();

    sensors::bat24_current::update();
    sensors::bat24_voltage::update();
    sensors::link24_current::update();
    sensors::supercap_voltage::update();
    sensors::link45_current::update();
    sensors::link45_voltage::update();

    //======== Power Consumption ==========
    float total_power = canzero_get_bat24_voltage() * canzero_get_bat24_current() +
      canzero_get_link45_voltage() * canzero_get_link45_current();
    canzero_set_system_power_consumption(total_power);
    float communication_power = canzero_get_link24_current() * 24.0f;
    canzero_set_communication_power_consumption(communication_power);

    state_estimation::update();

    loopIntervalTiming.tick();
    canzero_set_loop_frequency(loopIntervalTiming.frequency() / 1_kHz);
    canzero_update_continue(canzero_get_time());
  }
}
