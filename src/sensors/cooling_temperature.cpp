#include "sensors/cooling_temperature.h"
#include "util/boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/voltage_divider.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::cooling_temperature::NTC_BETA;
using sensors::cooling_temperature::NTC_R_REF;
using sensors::cooling_temperature::NTC_T_REF;
using sensors::cooling_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter(24_Celcius);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_cooling_cycle_temperature,
                canzero_get_error_level_config_cooling_temperature,
                canzero_set_error_level_cooling_cycle_temperature);

static void FASTRUN on_value(const Voltage &v) {
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  /* const Temperature temperature = */
  /*     sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF); */
  const Temperature temperature = 24_Celcius;
  filter.push(temperature);
  canzero_set_cooling_cycle_temperature(
      static_cast<float>(filter.get() - 0_Celcius));
}

void FLASHMEM sensors::cooling_temperature::begin() {
  canzero_set_cooling_cycle_temperature(0);
  canzero_set_error_level_cooling_cycle_temperature(error_level_OK);
  canzero_set_error_level_config_cooling_temperature(error_level_config{
      .m_info_thresh = 40,
      .m_info_timeout = 5,
      .m_warning_thresh = 60,
      .m_warning_timeout = 5,
      .m_error_thresh = 75,
      .m_error_timeout = 5,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
  canzero_set_error_cooling_cycle_temperature_invalid(error_flag_OK);
  assert(input_board::register_periodic_reading(FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::cooling_temperature::calibrate() {
  for (size_t i = 0; i < filter.size(); ++i) {
    on_value(input_board::sync_read(PIN));
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  const bool sensable =
      filter.get() <= 100_Celcius && filter.get() >= 0_Celcius;
  canzero_set_error_cooling_cycle_temperature_invalid(
      sensable ? error_flag_OK : error_flag_ERROR);
}

void FASTRUN sensors::cooling_temperature::update() { error_check.check(); }
