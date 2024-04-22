#pragma once

#include "canzero/canzero.h"

static void defaults() {
  // ============== BAT24 Error handling config =====================
  canzero_set_error_level_bat24_under_voltage(error_level_OK);
  canzero_set_error_level_config_bat24_under_voltage(error_level_config{
      .info_thresh = 22,    // Volts
      .info_timeout = 10.0, // seconds
      .warning_thresh = 20.0,
      .warning_timeout = 10.0,
      .error_thresh = 18.0,
      .error_timeout = 10.0,
  });
  canzero_set_error_level_bat24_over_voltage(error_level_OK);
  canzero_set_error_level_config_bat24_over_voltage(
      error_level_config{.info_thresh = 28.0,  // Volts
                         .info_timeout = 10.0, // seconds
                         .warning_thresh = 30,
                         .warning_timeout = 10.0,
                         .error_thresh = 32.0,
                         .error_timeout = 10.0});
  canzero_set_error_level_bat24_over_current(error_level_OK);
  canzero_set_error_level_config_bat24_over_current(error_level_config{
      .info_thresh = 20.0,
      .info_timeout = 2.0,
      .warning_thresh = 25.0,
      .warning_timeout = 2.0,
      .error_thresh = 30,
      .error_timeout = 2.0,
  });

  // ============== LINK24 Error handling config ====================
  canzero_set_error_level_link24_under_voltage(error_level_OK);
  canzero_set_error_level_config_link24_under_voltage(error_level_config{
      .info_thresh = 23.0,
      .info_timeout = 30.0,
      .warning_thresh = 22.0,
      .warning_timeout = 5.0,
      .error_thresh = 20.0,
      .error_timeout = 5.0,
  });
  canzero_set_error_level_link24_over_voltage(error_level_OK);
  canzero_set_error_level_config_link24_over_voltage(error_level_config{
      .info_thresh = 25.0,
      .info_timeout = 30.0,
      .warning_thresh = 26.0,
      .warning_timeout = 5.0,
      .error_thresh = 26.0,
      .error_timeout = 5.0,
  });
  canzero_set_error_level_link24_over_current(error_level_OK);
  canzero_set_error_level_config_link24_over_current(error_level_config{
      .info_thresh = 20.0,
      .info_timeout = 2.0,
      .warning_thresh = 25.0,
      .warning_timeout = 2.0,
      .error_thresh = 30,
      .error_timeout = 2.0,
  });
  // ============== LINK45 Error handling config ====================
  canzero_set_error_level_link45_under_voltage(error_level_OK);
  canzero_set_error_level_config_link45_under_voltage(error_level_config{
      .info_thresh = 40.0,
      .info_timeout = 30.0,
      .warning_thresh = 35.0,
      .warning_timeout = 5.0,
      .error_thresh = 30.0,
      .error_timeout = 5.0,
  });
  canzero_set_error_level_link45_over_voltage(error_level_OK);
  canzero_set_error_level_config_link45_over_voltage(error_level_config{
      .info_thresh = 48.0,
      .info_timeout = 30.0,
      .warning_thresh = 49.0,
      .warning_timeout = 5.0,
      .error_thresh = 50.0,
      .error_timeout = 5.0,
  });
  canzero_set_error_level_link45_over_current(error_level_OK);
  canzero_set_error_level_config_link45_over_current(error_level_config{
      .info_thresh = 100.0,
      .info_timeout = 2.0,
      .warning_thresh = 200.0,
      .warning_timeout = 2.0,
      .error_thresh = 300,
      .error_timeout = 2.0,
  });
  // ======= Cooling over/under pressure Error handling config =======
  canzero_set_error_level_cooling_cycle_under_pressure(error_level_OK);
  canzero_set_error_level_config_cooling_cycle_under_pressure(
      error_level_config{
          .info_thresh = 1.1,  // bar
          .info_timeout = 2.0, // seconds
          .warning_thresh = 0.9,
          .warning_timeout = 2.0,
          .error_thresh = 0.5,
          .error_timeout = 2.0,
      });
  canzero_set_error_level_cooling_cycle_over_pressure(error_level_OK);
  canzero_set_error_level_config_cooling_cycle_over_pressure(error_level_config{
      .info_thresh = 2.0,  // bar
      .info_timeout = 2.0, // seconds
      .warning_thresh = 3.0,
      .warning_timeout = 2.0,
      .error_thresh = 4,
      .error_timeout = 2.0,
  });
  // ============ Temperature Error handling config =================
  canzero_set_error_level_mcu_temperature(error_level_OK);
  canzero_set_error_level_config_mcu_temperature(error_level_config{
      .info_thresh = 55.0,  // Celcius
      .info_timeout = 30.0, // Seconds
      .warning_thresh = 70.0,
      .warning_timeout = 5.0,
      .error_thresh = 85.0,
      .error_timeout = 1.0,
  });
  canzero_set_error_level_cooling_cycle_temperature(error_level_OK);
  canzero_set_error_level_config_cooling_temperature(error_level_config{
      .info_thresh = 40.0,  // Celcius
      .info_timeout = 30.0, // Seconds
      .warning_thresh = 60.0,
      .warning_timeout = 5.0,
      .error_thresh = 80.0,
      .error_timeout = 1.0,
  });
  canzero_set_error_level_bat24_temperature(error_level_OK);
  canzero_set_error_level_config_bat24_temperature(error_level_config{
      .info_thresh = 40.0,  // Celcius
      .info_timeout = 30.0, // Seconds
      .warning_thresh = 60.0,
      .warning_timeout = 5.0,
      .error_thresh = 80.0,
      .error_timeout = 1.0,
  });
  canzero_set_error_level_supercap_temperature(error_level_OK);
  canzero_set_error_level_config_supercap_temperature(error_level_config{
      .info_thresh = 40.0,  // Celcius
      .info_timeout = 30.0, // Seconds
      .warning_thresh = 60.0,
      .warning_timeout = 5.0,
      .error_thresh = 80.0,
      .error_timeout = 1.0,
  });
  canzero_set_error_level_ebox_temperature(error_level_OK);
  canzero_set_error_level_config_ebox_temperature(error_level_config{
      .info_thresh = 40.0,  // Celcius
      .info_timeout = 30.0, // Seconds
      .warning_thresh = 60.0,
      .warning_timeout = 5.0,
      .error_thresh = 80.0,
      .error_timeout = 1.0,
  });
  canzero_set_error_level_ambient_temperature(error_level_OK);
  canzero_set_error_level_config_ambient_temperature(error_level_config{
      .info_thresh = 40.0,  // Celcius
      .info_timeout = 30.0, // Seconds
      .warning_thresh = 45.0,
      .warning_timeout = 10.0,
      .error_thresh = 50.0,
      .error_timeout = 10.0,
  });
  // ================= MICS =====================
  canzero_set_expect_link45_online(bool_t_FALSE);
  canzero_set_sdc_status(sdc_status_OPEN);
  canzero_set_assertion_fault(error_flag_OK);

}
