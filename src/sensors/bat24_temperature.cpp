#include "sensors/bat24_temperature.h"
#include "avr/pgmspace.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/voltage_divider.h"
#include "util/boxcar.h"
#include <cassert>

using sensors::bat24_temperature::NTC_BETA;
using sensors::bat24_temperature::NTC_R_REF;
using sensors::bat24_temperature::NTC_T_REF;
using sensors::bat24_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter_cell1(24_Celcius);
static DMAMEM BoxcarFilter<Temperature, 10> filter_cell2(24_Celcius);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_bat24_temperature_max,
                canzero_get_error_level_config_bat24_temperature,
                canzero_set_error_level_bat24_temperature);

static void FASTRUN on_value_cell1(const Voltage &v) {
  if (v < 0.1_V){
    canzero_set_error_bat24_cell_temperature_1_invalid(error_flag_ERROR);
    canzero_set_bat24_cell_temperature_1(0);
    return;
  }
  canzero_set_error_bat24_cell_temperature_1_invalid(error_flag_OK);
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter_cell1.push(temperature);
  canzero_set_bat24_cell_temperature_1(
      static_cast<float>(filter_cell1.get() - 0_Celcius));
}

static void FASTRUN on_value_cell2(const Voltage &v) {
  if (v < 0.1_V){
    canzero_set_error_bat24_cell_temperature_2_invalid(error_flag_ERROR);
    canzero_set_bat24_cell_temperature_2(0);
  }
  canzero_set_error_bat24_cell_temperature_2_invalid(error_flag_OK);
  const Resistance r_ntc =
      sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter_cell2.push(temperature);
  canzero_set_bat24_cell_temperature_2(
      static_cast<float>(filter_cell2.get() - 0_Celcius));
}

void FLASHMEM sensors::bat24_temperature::begin() {

  canzero_set_bat24_cell_temperature_1(20);
  canzero_set_bat24_cell_temperature_2(20);
  canzero_set_bat24_temperature_max(20);
  canzero_set_error_level_config_bat24_temperature(error_level_config{
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
  canzero_set_error_level_bat24_temperature(error_level_OK);
  canzero_set_error_bat24_cell_temperature_1_invalid(error_flag_OK);
  canzero_set_error_bat24_cell_temperature_2_invalid(error_flag_OK);

  assert(input_board::register_periodic_reading(FREQUENCY, PIN_CELL1,
                                                on_value_cell1));
  assert(input_board::register_periodic_reading(FREQUENCY, PIN_CELL2,
                                                on_value_cell2));
}

void PROGMEM sensors::bat24_temperature::calibrate() {
  {
    for (size_t i = 0; i < filter_cell1.size(); ++i) {
      on_value_cell1(input_board::sync_read(PIN_CELL1));
      canzero_update_continue(canzero_get_time());
      input_board::delay(1_ms);
    }
    const Temperature reading = filter_cell1.get();
  }
  {
    for (size_t i = 0; i < filter_cell2.size(); ++i) {
      on_value_cell2(input_board::sync_read(PIN_CELL2));
      canzero_update_continue(canzero_get_time());
      input_board::delay(1_ms);
    }
    const Temperature reading = filter_cell2.get();
    bool invalid_reading = reading >= 100_Celcius || reading <= 0_Celcius;

    canzero_set_error_bat24_cell_temperature_2_invalid(
        invalid_reading ? error_flag_ERROR : error_flag_OK);
  }
}
 
void FASTRUN sensors::bat24_temperature::update() {
  float max = 0;
  if (canzero_get_error_bat24_cell_temperature_1_invalid() == error_flag_OK){
    max = std::max(canzero_get_bat24_cell_temperature_1(), max);
  }
  if (canzero_get_error_bat24_cell_temperature_2_invalid() == error_flag_OK){
    max = std::max(canzero_get_bat24_cell_temperature_2(), max);
  }

  canzero_set_bat24_temperature_max(
      std::max(canzero_get_bat24_cell_temperature_1(),
               canzero_get_bat24_cell_temperature_2()));
  error_check.check();
}
