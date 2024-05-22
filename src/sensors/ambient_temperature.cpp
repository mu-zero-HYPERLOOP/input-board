#include "sensors/ambient_temperature.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/voltage_divider.h"
#include "util/metrics.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::ambient_temperature::NTC_BETA;
using sensors::ambient_temperature::NTC_R_REF;
using sensors::ambient_temperature::NTC_T_REF;
using sensors::ambient_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter(24_Celcius);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_ambient_temperature,
                canzero_get_error_level_config_ambient_temperature,
                canzero_set_error_level_ambient_temperature);

static void FASTRUN on_value(const Voltage &v) {
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter.push(temperature);
  canzero_set_ambient_temperature(static_cast<float>(filter.get() - 0_Celcius));
}

void FLASHMEM sensors::ambient_temperature::begin() {
  canzero_set_error_level_config_ambient_temperature(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
      .m_info_thresh = 45,
      .m_info_timeout = 5,
      .m_warning_thresh = 65,
      .m_warning_timeout = 5,
      .m_error_thresh = 80,
      .m_error_timeout = 5,
  });
  canzero_set_error_level_ambient_temperature(error_level_OK);
  canzero_set_error_ambient_temperature_invalid(error_flag_OK);

  canzero_set_ambient_temperature(24);
  assert(input_board::register_periodic_reading(FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::ambient_temperature::calibrate() {
  for (size_t i = 0; i < filter.size(); ++i) {
    on_value(input_board::sync_read(PIN));
    input_board::delay(1_ms);
  }
  bool invalid_reading =
      (filter.get() <= -1_Celcius || filter.get() >= 100_Celcius);
  canzero_set_error_ambient_temperature_invalid(
      invalid_reading ? error_flag_ERROR : error_flag_OK);
}

void FASTRUN sensors::ambient_temperature::update() { error_check.check(); }
