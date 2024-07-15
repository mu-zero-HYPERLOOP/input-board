#include "sensors/ambient_temperature.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "print.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/voltage_divider.h"
#include "util/boxcar.h"
#include "util/metrics.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::ambient_temperature::NTC_BETA;
using sensors::ambient_temperature::NTC_R_REF;
using sensors::ambient_temperature::NTC_T_REF;
using sensors::ambient_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter_ambient1(24_Celcius);
static DMAMEM BoxcarFilter<Temperature, 10> filter_ambient2(24_Celcius);
static DMAMEM BoxcarFilter<Temperature, 10> filter_ambient3(24_Celcius);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_ambient_temperature_max,
                canzero_get_error_level_config_ambient_temperature,
                canzero_set_error_level_ambient_temperature);

static void FASTRUN on_value_ambient1(const Voltage &v) {
  if (v < 0.1_V) {
    canzero_set_error_ambient_temperature_1_invalid(error_flag_ERROR);
    canzero_set_ambient_temperature_1(0);
    return;
  }
  canzero_set_error_ambient_temperature_1_invalid(error_flag_OK);
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter_ambient1.push(temperature);
  canzero_set_ambient_temperature_1(
      static_cast<float>(filter_ambient1.get() - 0_Celcius));
}

static void FASTRUN on_value_ambient2(const Voltage &v) {
  if (v < 0.1_V) {
    canzero_set_error_ambient_temperature_2_invalid(error_flag_ERROR);
    canzero_set_ambient_temperature_2(0);
    return;
  }
  canzero_set_error_ambient_temperature_2_invalid(error_flag_OK);
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter_ambient2.push(temperature);
  canzero_set_ambient_temperature_1(
      static_cast<float>(filter_ambient2.get() - 0_Celcius));
}

static void FASTRUN on_value_ambient3(const Voltage &v) {
  if (v < 0.1_V){
    canzero_set_error_ambient_temperature_3_invalid(error_flag_ERROR);
    canzero_set_ambient_temperature_3(0);
    return;
  }
  canzero_set_error_ambient_temperature_3_invalid(error_flag_OK);
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter_ambient3.push(temperature);
  canzero_set_ambient_temperature_1(
      static_cast<float>(filter_ambient3.get() - 0_Celcius));
}

void FLASHMEM sensors::ambient_temperature::begin() {
  canzero_set_error_level_config_ambient_temperature(error_level_config{
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
  canzero_set_error_level_ambient_temperature(error_level_OK);
  canzero_set_error_ambient_temperature_1_invalid(error_flag_OK);
  canzero_set_error_ambient_temperature_2_invalid(error_flag_OK);
  canzero_set_error_ambient_temperature_3_invalid(error_flag_OK);

  canzero_set_ambient_temperature_1(20);
  canzero_set_ambient_temperature_2(20);
  canzero_set_ambient_temperature_3(20);
  canzero_set_ambient_temperature_avg(20);
  canzero_set_ambient_temperature_max(20);
  assert(input_board::register_periodic_reading(FREQUENCY, PIN_AMBIENT_1,
                                                on_value_ambient1));
  assert(input_board::register_periodic_reading(FREQUENCY, PIN_AMBIENT_2,
                                                on_value_ambient2));
  assert(input_board::register_periodic_reading(FREQUENCY, PIN_AMBIENT_3,
                                                on_value_ambient3));
}

void PROGMEM sensors::ambient_temperature::calibrate() {
  for (size_t i = 0; i < filter_ambient1.size(); ++i) {
    on_value_ambient1(input_board::sync_read(PIN_AMBIENT_1));
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  for (size_t i = 0; i < filter_ambient2.size(); ++i) {
    on_value_ambient2(input_board::sync_read(PIN_AMBIENT_2));
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  for (size_t i = 0; i < filter_ambient3.size(); ++i) {
    on_value_ambient3(input_board::sync_read(PIN_AMBIENT_3));
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
}

void FASTRUN sensors::ambient_temperature::update() {
  float max = 0;
  float avg = 0;
  int div = 0;
  if (canzero_get_error_ambient_temperature_1_invalid() == error_flag_OK){
    max = canzero_get_ambient_temperature_1();
    avg += canzero_get_ambient_temperature_1();
    div += 1;
  }
  if (canzero_get_error_ambient_temperature_2_invalid() == error_flag_ERROR){
    max = std::max(canzero_get_ambient_temperature_2(), max);
    avg += canzero_get_ambient_temperature_2();
    div += 1;
  }
  if (canzero_get_error_ambient_temperature_3_invalid() == error_flag_ERROR){
    max = std::max(canzero_get_ambient_temperature_3(), max);
    avg += canzero_get_ambient_temperature_3();
    div += 1;
  }
  avg /= static_cast<float>(div);


  canzero_set_ambient_temperature_max(max);
  canzero_set_ambient_temperature_avg(avg);
  error_check.check();
}
