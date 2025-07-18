#include "sensors/link24_current.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "print.h"
#include "sensors/formulas/hall_sensors.h"
#include "sensors/formulas/voltage_divider.h"
#include "util/boxcar.h"
#include "util/metrics.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::link24_current::R1_V_DIV;
using sensors::link24_current::R2_V_DIV;
using sensors::link24_current::VOLT_PER_AMP;
using sensors::link24_current::ZERO_A_READING;

static DMAMEM BoxcarFilter<Current, 1000> filter(0_A);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER> link24_over_current_check(
    canzero_get_link24_current,
    canzero_get_error_level_config_link24_over_current,
    canzero_set_error_level_link24_over_current);

static DMAMEM Current offset = 0_A;

static void FASTRUN on_value(const Voltage &v) {
  debugPrintf("link24: Current V %f\n", v / 1_V);
  const Voltage v_sensor =
      sensors::formula::vin_of_voltage_divider(v, R1_V_DIV, R2_V_DIV);

  const Current i = sensors::formula::hall_effect_sensor(v_sensor, VOLT_PER_AMP,
                                                         ZERO_A_READING) +
                    offset;
  filter.push(i);
  // debugPrintf("voltage: %f\ncurrent: %f\noffset: %fA\n", v / 1_V, i / 1_A,
  // offset / 1_A);

  const bool sensible = filter.get() <= 100_A && filter.get() >= -1_A;
  canzero_set_error_link24_current_invalid(sensible ? error_flag_OK
                                                    : error_flag_ERROR);
  canzero_set_link24_current(static_cast<float>(filter.get()));
}

void FLASHMEM sensors::link24_current::begin() {
  canzero_set_link24_current(0);
  canzero_set_link24_current_calibration_mode(calibration_mode_DISABLE);
  canzero_set_link24_current_calibration_target(0);
  canzero_set_link24_current_calibration_offset(0);
  canzero_set_error_level_link24_over_current(error_level_OK);
  canzero_set_error_level_config_link24_over_current(error_level_config{
      .m_info_thresh = 10,
      .m_info_timeout = 0.1,
      .m_warning_thresh = 15,
      .m_warning_timeout = 0.1,
      .m_error_thresh = 20,
      .m_error_timeout = 0.1,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
  canzero_set_error_link24_current_invalid(error_flag_OK);
  assert(input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value));
}
void PROGMEM sensors::link24_current::calibrate() {
  offset = 0_A;
  for (unsigned int i = 0; i < filter.size(); ++i) {
    const Voltage v = input_board::sync_read(PIN);
    on_value(v);
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  const calibration_mode mode = canzero_get_link24_current_calibration_mode();
  switch (mode) {
  case calibration_mode_USE_OFFSET: {
    offset = Current(canzero_get_link24_current_calibration_offset());
    break;
  }
  case calibration_mode_USE_TARGET: {
    const Current expected =
        Current(canzero_get_link24_current_calibration_target());
    offset = expected - filter.get();
    canzero_set_link24_current_calibration_offset(static_cast<float>(offset));
    break;
  }
  case calibration_mode_DISABLE: {
    offset = 0_A;
    canzero_set_link24_current_calibration_offset(0);
    break;
  }
  }
}
void FASTRUN sensors::link24_current::update() {
  link24_over_current_check.check();
}
