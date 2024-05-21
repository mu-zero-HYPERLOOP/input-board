#pragma once

#include "canzero/canzero.h"

static void can_defaults() {
  // ============== BAT24 Error handling config =====================
  canzero_set_bat24_current(0);
  canzero_set_bat24_voltage(0);
  canzero_set_error_level_bat24_under_voltage(error_level_OK);
  canzero_set_error_level_config_bat24_under_voltage(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 22,    // Volts
      .m_info_timeout = 10.0, // seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 20.0,
      .m_warning_timeout = 10.0,
      .m_error_thresh = 18.0,
      .m_error_timeout = 10.0,
  });
  canzero_set_error_level_bat24_over_voltage(error_level_OK);
  canzero_set_error_level_config_bat24_over_voltage(
      error_level_config{.m_ignore_info = bool_t_FALSE,
                         .m_info_thresh = 28.0,  // Volts
                         .m_info_timeout = 10.0, // seconds
                         .m_ignore_warning = bool_t_FALSE,
                         .m_warning_thresh = 30,
                         .m_warning_timeout = 10.0,
                         .m_ignore_error = bool_t_FALSE,
                         .m_error_thresh = 32.0,
                         .m_error_timeout = 10.0});
  canzero_set_error_level_bat24_over_current(error_level_OK);
  canzero_set_error_level_config_bat24_over_current(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 20.0,
      .m_info_timeout = 2.0,
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 25.0,
      .m_warning_timeout = 2.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 30,
      .m_error_timeout = 2.0,
  });

  // ============== LINK24 Error handling config ====================
  canzero_set_link24_current(0);
  canzero_set_link24_voltage(0);
  canzero_set_error_level_link24_under_voltage(error_level_OK);
  canzero_set_error_level_config_link24_under_voltage(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 23.0,
      .m_info_timeout = 30.0,
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 22.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 20.0,
      .m_error_timeout = 5.0,
  });
  canzero_set_error_level_link24_over_voltage(error_level_OK);
  canzero_set_error_level_config_link24_over_voltage(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 25.0,
      .m_info_timeout = 30.0,
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 26.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 26.0,
      .m_error_timeout = 5.0,
  });
  canzero_set_error_level_link24_over_current(error_level_OK);
  canzero_set_error_level_config_link24_over_current(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 20.0,
      .m_info_timeout = 2.0,
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 25.0,
      .m_warning_timeout = 2.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 30,
      .m_error_timeout = 2.0,
  });
  // ============== LINK45 Error handling config ====================
  canzero_set_link45_current(0);
  canzero_set_link45_voltage(0);
  canzero_set_error_level_link45_under_voltage(error_level_OK);
  canzero_set_error_level_config_link45_under_voltage(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 40.0,
      .m_info_timeout = 30.0,
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 35.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 30.0,
      .m_error_timeout = 5.0,
  });
  canzero_set_error_level_link45_over_voltage(error_level_OK);
  canzero_set_error_level_config_link45_over_voltage(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 48.0,
      .m_info_timeout = 30.0,
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 49.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 50.0,
      .m_error_timeout = 5.0,
  });
  canzero_set_error_level_link45_over_current(error_level_OK);
  canzero_set_error_level_config_link45_over_current(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 100.0,
      .m_info_timeout = 2.0,
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 200.0,
      .m_warning_timeout = 2.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 300,
      .m_error_timeout = 2.0,
  });
  // ======= Cooling over/under pressure Error handling config =======
  canzero_set_cooling_cycle_pressure_calibration_offset(0);
  canzero_set_cooling_cycle_pressure_calibration_target(1);
  canzero_set_error_level_cooling_cycle_under_pressure(error_level_OK);
  canzero_set_error_level_config_cooling_cycle_under_pressure(
      error_level_config{
          .m_ignore_info = bool_t_FALSE,
          .m_info_thresh = 1.1,  // bar
          .m_info_timeout = 2.0, // seconds
          .m_ignore_warning = bool_t_FALSE,
          .m_warning_thresh = 0.9,
          .m_warning_timeout = 2.0,
          .m_ignore_error = bool_t_FALSE,
          .m_error_thresh = 0.5,
          .m_error_timeout = 2.0,
      });
  canzero_set_error_level_cooling_cycle_over_pressure(error_level_OK);
  canzero_set_error_level_config_cooling_cycle_over_pressure(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 2.0,  // bar
      .m_info_timeout = 2.0, // seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 3.0,
      .m_warning_timeout = 2.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 4,
      .m_error_timeout = 2.0,
  });
  // ============ Temperature Error handling config =================
  canzero_set_mcu_temperature(0);
  canzero_set_error_level_mcu_temperature(error_level_OK);
  canzero_set_error_level_config_mcu_temperature(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 55.0,  // Celcius
      .m_info_timeout = 30.0, // Seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 70.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 85.0,
      .m_error_timeout = 1.0,
  });
  canzero_set_cooling_cycle_temperature(0);
  canzero_set_error_level_cooling_cycle_temperature(error_level_OK);
  canzero_set_error_level_config_cooling_temperature(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 40.0,  // Celcius
      .m_info_timeout = 30.0, // Seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 60.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 80.0,
      .m_error_timeout = 1.0,
  });
  canzero_set_bat24_temperature(0);
  canzero_set_error_level_bat24_temperature(error_level_OK);
  canzero_set_error_level_config_bat24_temperature(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 40.0,  // Celcius
      .m_info_timeout = 30.0, // Seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 60.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 80.0,
      .m_error_timeout = 1.0,
  });
  canzero_set_supercap_temperature(0);
  canzero_set_error_level_supercap_temperature(error_level_OK);
  canzero_set_error_level_config_supercap_temperature(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 40.0,  // Celcius
      .m_info_timeout = 30.0, // Seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 60.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 80.0,
      .m_error_timeout = 1.0,
  });
  canzero_set_ebox_temperature(0);
  canzero_set_error_level_ebox_temperature(error_level_OK);
  canzero_set_error_level_config_ebox_temperature(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 40.0,  // Celcius
      .m_info_timeout = 30.0, // Seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 60.0,
      .m_warning_timeout = 5.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 80.0,
      .m_error_timeout = 1.0,
  });
  canzero_set_ambient_temperature(0);
  canzero_set_error_level_ambient_temperature(error_level_OK);
  canzero_set_error_level_config_ambient_temperature(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_info_thresh = 40.0,  // Celcius
      .m_info_timeout = 30.0, // Seconds
      .m_ignore_warning = bool_t_FALSE,
      .m_warning_thresh = 45.0,
      .m_warning_timeout = 10.0,
      .m_ignore_error = bool_t_FALSE,
      .m_error_thresh = 50.0,
      .m_error_timeout = 10.0,
  });
  // ================= MICS =====================
  canzero_set_assert_45V_system_online(bool_t_FALSE);
  canzero_set_sdc_status(sdc_status_OPEN);
  canzero_set_assertion_fault(error_flag_OK);
}
