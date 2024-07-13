#include "sensors/supercap_temperature.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include "util/boxcar.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::supercap_temperature::NTC_BETA;
using sensors::supercap_temperature::NTC_R_REF;
using sensors::supercap_temperature::NTC_T_REF;
using sensors::supercap_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter(24_Celcius);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_supercap_temperature,
                canzero_get_error_level_config_supercap_temperature,
                canzero_set_error_level_supercap_temperature);

static void FASTRUN on_value(const Voltage &v) {
  const Current i_ntc = v / R_MEAS;
  const Voltage v_ntc = 5_V - v;
  const Resistance r_ntc = v_ntc / i_ntc;
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter.push(temperature);

  canzero_set_supercap_temperature(
      static_cast<float>(filter.get() - 0_Celcius));
}

void FLASHMEM sensors::supercap_temperature::begin() {
  canzero_set_supercap_temperature(24);
  canzero_set_error_supercap_temperature_invalid(error_flag_OK);
  canzero_set_error_level_supercap_temperature(error_level_OK);
  canzero_set_error_level_config_supercap_temperature(error_level_config{
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
  assert(input_board::register_periodic_reading(FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::supercap_temperature::calibrate() {
  for (size_t i = 0; i < filter.size(); ++i) {
    on_value(input_board::sync_read(PIN));
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
}

void FASTRUN sensors::supercap_temperature::update() {

  const bool sensable =
      filter.get() <= 200_Celcius && filter.get() >= 0_Celcius;
  canzero_set_error_supercap_temperature_invalid(sensable ? error_flag_OK
                                                          : error_flag_ERROR);
  error_check.check();
}
