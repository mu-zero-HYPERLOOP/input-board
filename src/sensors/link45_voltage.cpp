#include "sensors/link45_voltage.h"
#include "canzero/canzero.h"
#include "print.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/isolated_voltage.h"
#include "util/boxcar.h"
#include "util/metrics.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::link45_voltage::R1;
using sensors::link45_voltage::R2;

static DMAMEM BoxcarFilter<Voltage, 10> filter(0_V);

static DMAMEM ErrorLevelRangeCheck<EXPECT_OVER>
    link45_under_volt_check(canzero_get_link45_voltage,
                            canzero_get_error_level_config_link45_under_voltage,
                            canzero_set_error_level_link45_under_voltage);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    link45_over_volt_check(canzero_get_link45_voltage,
                           canzero_get_error_level_config_link45_over_voltage,
                           canzero_set_error_level_link45_over_voltage);

static DMAMEM Voltage offset = 0_V;

static void FASTRUN on_value(const Voltage &v) {

  const Voltage reading =
      sensors::formula::isolated_voltage_meas(v, R1, R2) + offset;
  filter.push(reading);

  const bool sensible = filter.get() <= 100_V && filter.get() >= -10_V;
  canzero_set_error_link45_voltage_invalid(sensible ? error_flag_OK
                                                    : error_flag_ERROR);
  canzero_set_link45_voltage(static_cast<float>(filter.get()));
}

void FLASHMEM sensors::link45_voltage::begin() {
  canzero_set_link45_voltage(0);
  canzero_set_link45_voltage_calibration_offset(
      static_cast<float>(DEFAULT_OFFSET));
  canzero_set_link45_voltage_calibration_mode(calibration_mode_USE_OFFSET);
  canzero_set_link45_voltage_calibration_target(0);
  canzero_set_error_level_link45_over_voltage(error_level_OK);
  canzero_set_error_level_config_link45_over_voltage(error_level_config{
      .m_info_thresh = 46,
      .m_info_timeout = 0.1,
      .m_warning_thresh = 48,
      .m_warning_timeout = 0.1,
      .m_error_thresh = 50,
      .m_error_timeout = 0.1,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
  canzero_set_error_level_link45_under_voltage(error_level_OK);
  canzero_set_error_level_config_link45_under_voltage(error_level_config{
      .m_info_thresh = 40,
      .m_info_timeout = 0.1,
      .m_warning_thresh = 35,
      .m_warning_timeout = 0.1,
      .m_error_thresh = 30,
      .m_error_timeout = 0.1,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
  canzero_set_error_link45_voltage_invalid(error_flag_OK);
  canzero_set_assert_45V_system_online(bool_t_FALSE);

  input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value);
}

void PROGMEM sensors::link45_voltage::calibrate() {
  offset = 0_V;
  for (unsigned int i = 0; i < filter.size(); ++i) {
    const Voltage v = input_board::sync_read(PIN);
    on_value(v);
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  const bool sensible = filter.get() <= 100_V && filter.get() >= -10_V;
  canzero_set_error_link45_voltage_invalid(sensible ? error_flag_OK
                                                    : error_flag_ERROR);
  const calibration_mode mode = canzero_get_link45_voltage_calibration_mode();
  switch (mode) {
  case calibration_mode_USE_OFFSET: {
    offset = Voltage(canzero_get_link45_voltage_calibration_offset());
    break;
  }
  case calibration_mode_USE_TARGET: {
    const Voltage expected =
        Voltage(canzero_get_link45_voltage_calibration_target());
    offset = expected - filter.get();
    canzero_set_link45_voltage_calibration_offset(static_cast<float>(offset));
    break;
  }
  case calibration_mode_DISABLE: {
    offset = 0_V;
    canzero_set_link45_voltage_calibration_offset(0);
    break;
  }
  }
}

void FASTRUN sensors::link45_voltage::update() {
  if (canzero_get_ignore_45v() == bool_t_FALSE) {
    if (canzero_get_assert_45V_system_online()) {
      link45_under_volt_check.check();
    } else {
      canzero_set_error_level_link45_under_voltage(error_level_OK);
    }
    link45_over_volt_check.check();
  }
}
