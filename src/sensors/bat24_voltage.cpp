#include "sensors/bat24_voltage.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/isolated_voltage.h"
#include <cassert>
#include <iostream>


using sensors::bat24_voltage::R1;
using sensors::bat24_voltage::R2;

static BoxcarFilter<Voltage, 10> filter(0_V);

static ErrorLevelRangeCheck<EXPECT_OVER>
    bat24_under_volt_check(canzero_get_bat24_voltage,
                           canzero_get_error_level_config_bat24_under_voltage,
                           canzero_set_error_level_bat24_under_voltage);
static Timestamp SOR = Timestamp::now();

static ErrorLevelRangeCheck<EXPECT_UNDER>
    bat24_over_volt_check(canzero_get_bat24_voltage,
                          canzero_get_error_level_config_bat24_over_voltage,
                          canzero_set_error_level_bat24_over_voltage);

static void on_value(const Voltage &v) {
  const Voltage reading = sensors::formula::isolated_voltage_meas(v, R1, R2);
  filter.push(reading);
  canzero_set_bat24_voltage(static_cast<float>(filter.get()));
}

void sensors::bat24_voltage::begin() {
  assert(input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value));
}

void sensors::bat24_voltage::calibrate() {
  for (size_t i = 0; i < filter.size(); ++i) {
    Voltage v = input_board::sync_read(PIN);
    on_value(v);
    input_board::delay(1_ms);
  }
  const Voltage expected =
      Voltage(canzero_get_bat24_voltage_calibration_target());
  Voltage reading = filter.get();
  Voltage calibration_offset = expected - reading;
  canzero_set_bat24_voltage_calibration_offset(
      static_cast<float>(calibration_offset));
}

void sensors::bat24_voltage::update() {
  bat24_over_volt_check.check();
  bat24_under_volt_check.check();
}
