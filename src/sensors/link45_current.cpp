#include "sensors/link45_current.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/hall_sensors.h"
#include "util/metrics.h"

using sensors::link45_current::VOLT_PER_AMP;

static BoxcarFilter<Current, 10> filter(0_A);

static ErrorLevelRangeCheck<EXPECT_UNDER> link45_over_current_check(
    canzero_get_link45_current,
    canzero_get_error_level_config_link45_over_current,
    canzero_set_error_level_link45_over_current);

static void on_value(const Voltage &v) {
  Current i = sensors::formula::hall_effect_sensor(
      v, VOLT_PER_AMP,
      Current(canzero_get_link45_current_calibration_offset()));
  filter.push(i);
  canzero_set_link45_current(static_cast<float>(filter.get()));
}

void sensors::link45_current::begin() {
  input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value);
}

void sensors::link45_current::calibrate() {
  for (unsigned int i = 0; i < filter.size(); ++i) {
    Voltage v = input_board::sync_read(PIN);
    on_value(v);
    input_board::delay(1_ms);
  }
  Current reading = filter.get();
  Current expected = Current(canzero_get_link45_current_calibration_target());
  Current calibration_offset = expected - reading;
  canzero_set_link45_current_calibration_offset(
      static_cast<float>(calibration_offset));
}

void sensors::link45_current::update() { link45_over_current_check.check(); }
