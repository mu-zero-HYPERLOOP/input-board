#include "error_handling.hpp"
#include "canzero/canzero.h"
#include "print.h"
#include <algorithm>
#include <array>

bool error_handling::no_error() {
  return true;
  const auto error_flags = std::array<error_flag, 25>{
    canzero_get_error_heartbeat_miss(),
    canzero_get_error_bat24_current_invalid(),
    canzero_get_error_bat24_voltage_invalid(),
    canzero_get_error_link24_current_invalid(),
    canzero_get_error_supercap_voltage_invalid(),
    canzero_get_error_link45_current_invalid(),
    canzero_get_error_link45_voltage_invalid(),
    canzero_get_error_mcu_temperature_invalid(),
    canzero_get_error_sac_ebox_temperature_invalid(),
    canzero_get_error_power_ebox_temperature_invalid(),
    canzero_get_error_acceleration_out_of_range(),
    canzero_get_error_ambient_temperature_1_invalid(),
    canzero_get_error_ambient_temperature_2_invalid(),
    canzero_get_error_ambient_temperature_3_invalid(),
    canzero_get_error_acceleration_out_of_range(),
    canzero_get_error_supercap_temperature_invalid(),
    canzero_get_error_acceleration_calibration_failed(),
    canzero_get_error_lateral_acceleration_out_of_range(),
    canzero_get_error_vertical_acceleration_out_of_range(),
    canzero_get_error_mcu_temperature_invalid(),
    canzero_get_error_ambient_temperature_1_invalid(),
    canzero_get_error_ambient_temperature_2_invalid(),
    canzero_get_error_ambient_temperature_3_invalid(),
    canzero_get_error_bat24_cell_temperature_1_invalid(),
    canzero_get_error_bat24_cell_temperature_2_invalid(),
  };

  const auto max_error_flag_it = std::max_element(error_flags.begin(), error_flags.end());
  const error_flag max_error_flag = *max_error_flag_it;
  if (max_error_flag == error_flag_ERROR){
    // early bail out.
    debugPrintf("ERROR_FLAG_SET\n");
    return false;
  }

  const auto error_levels = std::array<error_level, 13>{
      canzero_get_error_level_mcu_temperature(),
      canzero_get_error_level_sac_ebox_temperature(),
      canzero_get_error_level_power_ebox_temperature(),
      canzero_get_error_level_bat24_temperature(),
      canzero_get_error_level_bat24_over_current(),
      canzero_get_error_level_bat24_over_voltage(),
      canzero_get_error_level_bat24_under_voltage(),
      canzero_get_error_level_supercap_over_voltage(),
      canzero_get_error_level_link24_over_current(),
      // /* canzero_get_error_level_link45_over_current(), */
      canzero_get_error_level_link45_over_voltage(),
      canzero_get_error_level_ambient_temperature(),
      canzero_get_error_level_link45_under_voltage(),
      canzero_get_error_level_supercap_under_voltage(),
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
    return false;
  }
}
