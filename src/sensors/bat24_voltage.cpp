#include "sensors/bat24_voltage.h"
#include "util/boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/isolated_voltage.h"
#include <cassert>

#include <avr/pgmspace.h>

using sensors::bat24_voltage::R1;
using sensors::bat24_voltage::R2;

static DMAMEM BoxcarFilter<Voltage, 1000> filter(0_V);

static Voltage DMAMEM offset = 0_V;

static DMAMEM ErrorLevelRangeCheck<EXPECT_OVER>
    bat24_under_volt_check(canzero_get_bat24_voltage,
                           canzero_get_error_level_config_bat24_under_voltage,
                           canzero_set_error_level_bat24_under_voltage);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    bat24_over_volt_check(canzero_get_bat24_voltage,
                          canzero_get_error_level_config_bat24_over_voltage,
                          canzero_set_error_level_bat24_over_voltage);

static FASTRUN void on_value(const Voltage &v) {
  const Voltage reading = sensors::formula::isolated_voltage_meas(v, R1, R2) + offset;
  filter.push(reading);
  canzero_set_bat24_voltage(static_cast<float>(filter.get()));
}

void FLASHMEM sensors::bat24_voltage::begin() {
  offset = 0_V;
  canzero_set_bat24_voltage_calibration_offset(static_cast<float>(DEFAULT_OFFSET));
  canzero_set_bat24_voltage_calibration_mode(calibration_mode_USE_OFFSET);
  canzero_set_bat24_voltage_calibration_target(0);
  canzero_set_bat24_voltage(0);
  canzero_set_error_bat24_voltage_invalid(error_flag_OK);
  canzero_set_error_level_config_bat24_over_voltage(error_level_config{
      .m_info_thresh = 29,
      .m_info_timeout = 1,
      .m_warning_thresh = 30,
      .m_warning_timeout = 1,
      .m_error_thresh = 30,
      .m_error_timeout = 1,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_TRUE,
      .m_ignore_error = bool_t_FALSE,
  });
  canzero_set_error_level_bat24_over_voltage(error_level_OK);
  canzero_set_error_level_config_bat24_under_voltage(error_level_config{
      .m_info_thresh = 24,
      .m_info_timeout = 1,
      .m_warning_thresh = 23,
      .m_warning_timeout = 1,
      .m_error_thresh = 22,
      .m_error_timeout = 1,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
  assert(input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::bat24_voltage::calibrate() {
  offset = 0_V;
  for (size_t i = 0; i < filter.size(); ++i) {
    Voltage v = input_board::sync_read(PIN);
    on_value(v);
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  bool sensible = filter.get() <= 100_V && filter.get() >= 0_V;
  canzero_set_error_bat24_voltage_invalid(sensible ? error_flag_OK
                                                           : error_flag_ERROR);
  const calibration_mode mode = canzero_get_bat24_voltage_calibration_mode();
  switch (mode) {
  case calibration_mode_USE_OFFSET: {
    offset = Voltage(canzero_get_bat24_voltage_calibration_offset());
    break;
  }
  case calibration_mode_USE_TARGET: {
    const Voltage expected =
        Voltage(canzero_get_bat24_voltage_calibration_target());
    offset = expected - filter.get();
    canzero_set_bat24_voltage_calibration_offset(static_cast<float>(offset));
    break;
  }
  case calibration_mode_DISABLE: {
    offset = 0_V;
    canzero_set_bat24_voltage_calibration_offset(0);
    break;
  }
  }
}

void FASTRUN sensors::bat24_voltage::update() {
  bat24_over_volt_check.check();
  bat24_under_volt_check.check();
}
