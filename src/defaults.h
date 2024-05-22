#pragma once

#include "canzero/canzero.h"

static void can_defaults() {
  // ============== BAT24 Error handling config =====================
  canzero_set_bat24_current(0);
  canzero_set_bat24_voltage(0);
  canzero_set_error_level_bat24_under_voltage(error_level_OK);
  canzero_set_error_level_bat24_over_voltage(error_level_OK);
  canzero_set_error_level_bat24_over_current(error_level_OK);

  // ============== LINK24 Error handling config ====================
  canzero_set_link24_current(0);
  canzero_set_link24_voltage(0);
  canzero_set_error_level_link24_under_voltage(error_level_OK);
  canzero_set_error_level_link24_over_voltage(error_level_OK);
  canzero_set_error_level_link24_over_current(error_level_OK);
  // ============== LINK45 Error handling config ====================
  canzero_set_link45_current(0);
  canzero_set_link45_voltage(0);
  canzero_set_error_level_link45_under_voltage(error_level_OK);
  canzero_set_error_level_link45_over_voltage(error_level_OK);
  canzero_set_error_level_link45_over_current(error_level_OK);
  // ======= Cooling over/under pressure Error handling config =======
  canzero_set_cooling_cycle_pressure_calibration_offset(0);
  canzero_set_cooling_cycle_pressure_calibration_target(1);
  canzero_set_error_level_cooling_cycle_under_pressure(error_level_OK);
  canzero_set_error_level_cooling_cycle_over_pressure(error_level_OK);
  // ============ Temperature Error handling config =================
  canzero_set_mcu_temperature(0);
  canzero_set_error_level_mcu_temperature(error_level_OK);
  canzero_set_cooling_cycle_temperature(0);
  canzero_set_error_level_cooling_cycle_temperature(error_level_OK);
  canzero_set_bat24_temperature(0);
  canzero_set_error_level_bat24_temperature(error_level_OK);
  canzero_set_supercap_temperature(0);
  canzero_set_error_level_supercap_temperature(error_level_OK);
  canzero_set_ebox_temperature(0);
  canzero_set_error_level_ebox_temperature(error_level_OK);
  canzero_set_ambient_temperature(0);
  canzero_set_error_level_ambient_temperature(error_level_OK);
  // ================= MICS =====================
  canzero_set_assert_45V_system_online(bool_t_FALSE);
  canzero_set_sdc_status(sdc_status_OPEN);
  canzero_set_assertion_fault(error_flag_OK);
}
