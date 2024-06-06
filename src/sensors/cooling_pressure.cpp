#include "sensors/cooling_pressure.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/sick_pbt.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::cooling_pressure::R_MEAS;

static DMAMEM BoxcarFilter<Pressure, 10> filter(1_bar);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER> over_pressure_check(
    canzero_get_cooling_cycle_pressure,
    canzero_get_error_level_config_cooling_cycle_over_pressure,
    canzero_set_error_level_cooling_cycle_over_pressure);

static DMAMEM Pressure offset = 0_bar;

static FASTRUN void on_value(const Voltage &voltage) {
  Current i = voltage / R_MEAS;

  // pressure is in bar
  Pressure pressure = sensors::formula::sick_pbt(i) + offset;

  filter.push(pressure);
  canzero_set_cooling_cycle_pressure(static_cast<float>(pressure));
}

void FLASHMEM sensors::cooling_pressure::begin() {
  canzero_set_cooling_cycle_pressure_calibration_mode(calibration_mode_DISABLE);
  canzero_set_cooling_cycle_pressure_calibration_offset(0);
  offset = 0_bar;
  canzero_set_cooling_cycle_pressure_calibration_target(0);
  canzero_set_cooling_cycle_pressure(0);
  canzero_set_error_cooling_cycle_pressure_invalid(error_flag_OK);
  canzero_set_error_level_cooling_cycle_over_pressure(error_level_OK);
  canzero_set_error_level_config_cooling_cycle_over_pressure(error_level_config{
      .m_info_thresh = 40,
      .m_info_timeout = 1,
      .m_warning_thresh = 60,
      .m_warning_timeout = 1,
      .m_error_thresh = 80,
      .m_error_timeout = 1,
      .m_ignore_info = bool_t_TRUE,
      .m_ignore_warning = bool_t_TRUE,
      .m_ignore_error = bool_t_TRUE,
  });
  assert(input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::cooling_pressure::calibrate(const Pressure &expected) {
  offset = 0_bar;
  for (unsigned int i = 0; i < filter.size(); ++i) {
    const Voltage v = input_board::sync_read(PIN);
    on_value(v);
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
  const bool sensable = filter.get() <= 16_bar && filter.get() >= 0.5_bar;
  canzero_set_error_cooling_cycle_pressure_invalid(sensable ? error_flag_OK
                                                            : error_flag_ERROR);
  const calibration_mode mode = canzero_get_cooling_cycle_pressure_calibration_mode();
  switch (mode) {
  case calibration_mode_USE_OFFSET: {
    offset = Pressure(canzero_get_cooling_cycle_pressure_calibration_offset());
    break;
  }
  case calibration_mode_USE_TARGET: {
    Pressure expected =
        Pressure(canzero_get_cooling_cycle_pressure_calibration_target());
    offset = expected - filter.get();
    canzero_set_cooling_cycle_pressure_calibration_offset(
        static_cast<float>(offset));
    break;
  }
  case calibration_mode_DISABLE:
    offset = 0_bar;
    break;
  }
}

void FASTRUN sensors::cooling_pressure::update() {
  over_pressure_check.check();
}
