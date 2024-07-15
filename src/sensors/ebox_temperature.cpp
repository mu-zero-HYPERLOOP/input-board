#include "sensors/ebox_temperature.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/voltage_divider.h"
#include "util/boxcar.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::ebox_temperature::NTC_BETA;
using sensors::ebox_temperature::NTC_R_REF;
using sensors::ebox_temperature::NTC_T_REF;
using sensors::ebox_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter_sac(24_Celcius);
static DMAMEM BoxcarFilter<Temperature, 10> filter_power(24_Celcius);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    sac_error_check(canzero_get_sac_ebox_temperature,
                    canzero_get_error_level_config_sac_ebox_temperature,
                    canzero_set_error_level_sac_ebox_temperature);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    power_error_check(canzero_get_power_ebox_temperature,
                      canzero_get_error_level_config_power_ebox_temperature,
                      canzero_set_error_level_power_ebox_temperature);

static void FASTRUN on_value_sac(const Voltage &v) {
  if (v < 0.1_V){
    canzero_set_error_sac_ebox_temperature_invalid(error_flag_ERROR);
    canzero_set_sac_ebox_temperature(0);
    return;
  }
  canzero_set_error_sac_ebox_temperature_invalid(error_flag_OK);
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter_sac.push(temperature);
  canzero_set_sac_ebox_temperature(
      static_cast<float>(filter_power.get() - 0_Celcius));
}

static void FASTRUN on_value_power(const Voltage &v) {
  if (v < 0.1_V){
    canzero_set_error_power_ebox_temperature_invalid(error_flag_ERROR);
    canzero_set_power_ebox_temperature(0);
    return;
  }
  canzero_set_error_power_ebox_temperature_invalid(error_flag_OK);
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter_power.push(temperature);
  canzero_set_sac_ebox_temperature(
      static_cast<float>(filter_power.get() - 0_Celcius));
}

void FLASHMEM sensors::ebox_temperature::begin() {
  canzero_set_sac_ebox_temperature(20);
  canzero_set_error_sac_ebox_temperature_invalid(error_flag_OK);
  canzero_set_error_level_sac_ebox_temperature(error_level_OK);
  canzero_set_error_level_config_sac_ebox_temperature(error_level_config{
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

  canzero_set_power_ebox_temperature(20);
  canzero_set_error_power_ebox_temperature_invalid(error_flag_OK);
  canzero_set_error_level_power_ebox_temperature(error_level_OK);
  canzero_set_error_level_config_power_ebox_temperature(error_level_config{
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
  assert(
      input_board::register_periodic_reading(FREQUENCY, PIN_SAC, on_value_sac));
  assert(input_board::register_periodic_reading(FREQUENCY, PIN_POWER,
                                                on_value_power));
}

void PROGMEM sensors::ebox_temperature::calibrate() {
  {
    for (size_t i = 0; i < filter_sac.size(); ++i) {
      on_value_sac(input_board::sync_read(PIN_SAC));
      canzero_update_continue(canzero_get_time());
      input_board::delay(1_ms);
    }
  }
  {
    for (size_t i = 0; i < filter_power.size(); ++i) {
      on_value_power(input_board::sync_read(PIN_POWER));
      canzero_update_continue(canzero_get_time());
      input_board::delay(1_ms);
    }
  }
}

void FASTRUN sensors::ebox_temperature::update() {

  sac_error_check.check();
  power_error_check.check();
}
