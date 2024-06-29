#include "error_handling.hpp"
#include "canzero/canzero.h"
#include <algorithm>
#include <array>
#include <iostream>

bool error_handling::no_error() {
  const auto error_flags = std::array<error_flag, 19>{
    canzero_get_error_heartbeat_miss(),
    canzero_get_error_bat24_current_invalid(),
    canzero_get_error_bat24_voltage_invalid(),
    canzero_get_error_link24_current_invalid(),
    canzero_get_error_supercap_voltage_invalid(),
    canzero_get_error_link45_current_invalid(),
    canzero_get_error_link45_voltage_invalid(),
    canzero_get_error_mcu_temperature_invalid(),
    canzero_get_error_buck_temperature_invalid(),
    canzero_get_error_ebox_temperature_invalid(),
    canzero_get_error_bat24_temperature_invalid(),
    canzero_get_error_acceleration_out_of_range(),
    canzero_get_error_ambient_temperature_invalid(),
    canzero_get_error_supercap_temperature_invalid(),
    canzero_get_error_cooling_cycle_pressure_invalid(),
    canzero_get_error_acceleration_calibration_failed(),
    canzero_get_error_cooling_cycle_temperature_invalid(),
    canzero_get_error_lateral_acceleration_out_of_range(),
    canzero_get_error_vertical_acceleration_out_of_range(),
  };

  const auto max_error_flag_it = std::max_element(error_flags.begin(), error_flags.end());
  const error_flag max_error_flag = *max_error_flag_it;
  if (max_error_flag == error_flag_ERROR){
    // early bail out.
    std::cout << "ERROR_FLAG_SET" << std::endl;
    return false;
  }

  const auto error_levels = std::array<error_level, 15>{
      canzero_get_error_level_mcu_temperature(),
      canzero_get_error_level_buck_temperature(),
      canzero_get_error_level_ebox_temperature(),
      canzero_get_error_level_bat24_temperature(),
      canzero_get_error_level_bat24_over_current(),
      canzero_get_error_level_bat24_over_voltage(),
      canzero_get_error_level_bat24_under_voltage(),
      canzero_get_error_level_supercap_over_voltage(),
      canzero_get_error_level_link24_over_current(),
      canzero_get_error_level_link45_over_current(),
      canzero_get_error_level_link45_over_voltage(),
      canzero_get_error_level_ambient_temperature(),
      canzero_get_error_level_link45_under_voltage(),
      canzero_get_error_level_supercap_under_voltage(),
      canzero_get_error_level_cooling_cycle_temperature(),
  };
  const auto max_error_level_it = std::max_element(error_levels.begin(), error_levels.end());
  const error_level max_error_level = *max_error_level_it;

  const error_level error_level = std::max(max_error_level,
      (max_error_flag == error_flag_OK) ? error_level_OK : error_level_ERROR);
  switch (error_level){
  case error_level_OK:
  case error_level_INFO:
  case error_level_WARNING:
    return true;
  case error_level_ERROR:
  default:
    std::cout << canzero_get_error_level_link45_under_voltage() << std::endl;
    std::cout << "ERROR_LEVEL" << std::endl;
    return false;
  }
}
