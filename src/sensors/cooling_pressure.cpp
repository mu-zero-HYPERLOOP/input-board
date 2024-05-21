#include "sensors/cooling_pressure.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/sick_pbt.h"
#include <cassert>
#include <iostream>

static BoxcarFilter<Pressure, 10> filter(1_bar);

static ErrorLevelRangeCheck<EXPECT_OVER> under_pressure_check(
    canzero_get_cooling_cycle_pressure,
    canzero_get_error_level_config_cooling_cycle_under_pressure,
    canzero_set_error_level_cooling_cycle_under_pressure);

static ErrorLevelRangeCheck<EXPECT_UNDER> over_pressure_check(
    canzero_get_cooling_cycle_pressure,
    canzero_get_error_level_config_cooling_cycle_over_pressure,
    canzero_set_error_level_cooling_cycle_over_pressure);

static void on_value(const Voltage &voltage) {
  Current i = voltage / 150_Ohm;
  // pressure is in bar
  Pressure pressure =
      sensors::formula::sick_pbt(i) +
      Pressure(canzero_get_cooling_cycle_pressure_calibration_offset());

  filter.push(pressure);
  canzero_set_cooling_cycle_pressure(static_cast<float>(pressure));
}

void sensors::cooling_pressure::begin() {
  assert(input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value));
}

void sensors::cooling_pressure::calibrate(const Pressure &expected) {
  for (unsigned int i = 0; i < filter.size(); ++i) {
    const Voltage &v = input_board::sync_read(PIN);
    on_value(v);
    input_board::delay(1_ms);
  }
  Pressure reading = filter.get();
  Pressure calibration_offset = expected - reading;
  canzero_set_cooling_cycle_pressure_calibration_offset(
      static_cast<float>(calibration_offset));
}

void sensors::cooling_pressure::update() {
  under_pressure_check.check();
  over_pressure_check.check();
}
