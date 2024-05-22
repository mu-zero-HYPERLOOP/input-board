#include "sensors/bat24_current.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/hall_sensors.h"
#include "util/metrics.h"
#include <avr/pgmspace.h>

using sensors::bat24_current::VOLT_PER_AMP;

static DMAMEM BoxcarFilter<Current, 10> filter(0_A);

static Current offset;

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    bat24_over_current_check(canzero_get_bat24_current,
                             canzero_get_error_level_config_bat24_over_current,
                             canzero_set_error_level_bat24_over_current);

static FASTRUN void on_value(const Voltage &v) {
  Current i = sensors::formula::hall_effect_sensor(v, VOLT_PER_AMP, offset);
  filter.push(i);
  canzero_set_bat24_current(static_cast<float>(filter.get()));
}

void FLASHMEM sensors::bat24_current::begin() {
  canzero_set_bat24_current(0);
  canzero_set_bat24_current_calibration_offset(0);
  canzero_set_bat24_current_calibration_target(0);

  canzero_set_error_level_config_bat24_over_current(error_level_config{
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
      .m_info_thresh = 10,
      .m_info_timeout = 0.1,
      .m_warning_thresh = 15,
      .m_warning_timeout = 0.1,
      .m_error_thresh = 20,
      .m_error_timeout = 0.1,
  });
  canzero_set_error_level_bat24_over_current(error_level_OK);
  canzero_set_error_bat24_current_calibration_failed(error_flag_OK);

  offset = 0_A;
  input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value);
}

void PROGMEM sensors::bat24_current::calibrate() {
  for (unsigned int i = 0; i < filter.size(); ++i) {
    Voltage v = input_board::sync_read(PIN);
    on_value(v);
    input_board::delay(1_ms);
  }

  calibration_mode mode = canzero_get_bat24_current_calibration_mode();
  switch (mode) {
  case calibration_mode_USE_OFFSET: {
    offset = Current(canzero_get_bat24_current_calibration_offset());
    canzero_set_error_bat24_current_calibration_failed(error_flag_OK);
    break;
  }
  case calibration_mode_USE_TARGET: {
    const Current reading = filter.get();
    const Current expected =
        Current(canzero_get_bat24_current_calibration_target());
    const Current calibration_offset = expected - reading;
    bool calibration_unreasonable =
        fabs(canzero_get_bat24_current_calibration_offset()) > 10;
    canzero_set_error_bat24_current_calibration_failed(
        calibration_unreasonable ? error_flag_ERROR : error_flag_OK);
    if (!calibration_unreasonable) {
      offset = calibration_offset;
      canzero_set_bat24_current_calibration_offset(
          static_cast<float>(calibration_offset));
    }
    break;
  }
  case calibration_mode_DISABLE: {
    offset = 0_A;
    canzero_set_error_bat24_current_calibration_failed(error_flag_OK);
    canzero_set_bat24_current_calibration_offset(0);
    break;
  }
  }
}

void FASTRUN sensors::bat24_current::update() {
  bat24_over_current_check.check();
}
