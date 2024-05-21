/** @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
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
#include "firmware/input_board.h"
#include "sensors/accelerometer.h"
#include "sensors/bat24_current.h"
#include "sensors/bat24_voltage.h"
#include "sensors/cooling_pressure.h"
#include "sensors/linear_encoder.h"
#include "sensors/link24_current.h"
#include "sensors/link24_voltage.h"
#include "sensors/link45_current.h"
#include "sensors/link45_voltage.h"
#include "sensors/mass_flow_rate.h"
#include <avr/pgmspace.h>

int main() {

  canzero_init();
  can_defaults();
  canzero_set_state(input_board_state_INIT);
  canzero_update_continue(canzero_get_time());

  canzero_set_target_acceleration(0);

  input_board::begin();

  sensors::accelerometer::begin();
  sensors::linear_encoder::begin();

  sensors::cooling_pressure::begin();
  sensors::mass_flow_rate::begin();

  sensors::bat24_current::begin();
  sensors::bat24_voltage::begin();
  sensors::link24_current::begin();
  sensors::link24_voltage::begin();
  sensors::link45_current::begin();
  sensors::link45_voltage::begin();

calibration:
  canzero_set_state(input_board_state_CALIBRATION);
  canzero_update_continue(canzero_get_time());

  sensors::accelerometer::calibrate();
  sensors::linear_encoder::calibrate();

  sensors::cooling_pressure::calibrate(1_bar);
  sensors::mass_flow_rate::calibrate();

  sensors::bat24_current::calibrate();
  sensors::bat24_voltage::calibrate();
  sensors::link24_current::calibrate();
  sensors::link24_voltage::calibrate();
  sensors::link45_current::calibrate();
  sensors::link45_voltage::calibrate();

  
  

  canzero_set_state(input_board_state_RUNNING);
  canzero_update_continue(canzero_get_time()); 
  while (true) {
    canzero_can0_poll();
    canzero_can1_poll();

    if (input_board_command_CALIBRATE == canzero_get_command()) {
      goto calibration;
    }
    input_board::update_continue();
    
    sensors::accelerometer::update();
    sensors::linear_encoder::update();

    sensors::cooling_pressure::update();
    sensors::mass_flow_rate::calibrate();

    sensors::bat24_current::update();
    sensors::bat24_voltage::update();
    sensors::link24_current::update();
    sensors::link24_voltage::update();
    sensors::link45_current::update();
    sensors::link45_voltage::update();

    canzero_update_continue(canzero_get_time());
  }

}
