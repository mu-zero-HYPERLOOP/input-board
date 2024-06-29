#include "sensors/ebox_temperature.h"
#include "util/boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/voltage_divider.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::ebox_temperature::NTC_BETA;
using sensors::ebox_temperature::NTC_R_REF;
using sensors::ebox_temperature::NTC_T_REF;
using sensors::ebox_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter(24_Celcius);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_ebox_temperature,
                canzero_get_error_level_config_ebox_temperature,
                canzero_set_error_level_ebox_temperature);

static void FASTRUN on_value(const Voltage &v) {
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  /* const Temperature temperature = */
  /*     sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF); */

  const Temperature temperature = 24_Celcius;
  filter.push(temperature);
  canzero_set_ebox_temperature(static_cast<float>(filter.get() - 0_Celcius));
}

void FLASHMEM sensors::ebox_temperature::begin() {
  canzero_set_ebox_temperature(24);
  canzero_set_error_level_ebox_temperature(error_level_OK);
  canzero_set_error_level_config_ebox_temperature(error_level_config{
      .m_info_thresh = 45,
      .m_info_timeout = 5,
      .m_warning_thresh = 65,
      .m_warning_timeout = 5,
      .m_error_thresh = 80,
      .m_error_timeout = 5,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
  canzero_set_error_ebox_temperature_invalid(error_flag_OK);
  assert(input_board::register_periodic_reading(FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::ebox_temperature::calibrate() {
  for (size_t i = 0; i < filter.size(); ++i) {
    on_value(input_board::sync_read(PIN));
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  const bool sensible =
      filter.get() <= 100_Celcius && filter.get() >= 0_Celcius;
  canzero_set_error_ebox_temperature_invalid(sensible ? error_flag_OK
                                                      : error_flag_ERROR);
}

void FASTRUN sensors::ebox_temperature::update() { error_check.check(); }
