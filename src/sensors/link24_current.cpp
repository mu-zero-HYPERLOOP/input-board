#include "sensors/link24_current.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/hall_sensors.h"
#include "util/metrics.h"
#include <avr/pgmspace.h>

using sensors::link24_current::VOLT_PER_AMP;

static DMAMEM BoxcarFilter<Current, 10> filter(0_A);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER> link24_over_current_check(
    canzero_get_link24_current,
    canzero_get_error_level_config_link24_over_current,
    canzero_set_error_level_link24_over_current);

static void FASTRUN on_value(const Voltage &v) {
  Current i = sensors::formula::hall_effect_sensor(
      v, VOLT_PER_AMP,
      Current(canzero_get_link24_current_calibration_offset()));
  filter.push(i);
  canzero_set_link24_current(static_cast<float>(filter.get()));
}

void FLASHMEM sensors::link24_current::begin() {
  input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value);
}
void PROGMEM sensors::link24_current::calibrate() {
  for (unsigned int i = 0; i < filter.size(); ++i) {
    Voltage v = input_board::sync_read(PIN);
    on_value(v);
    input_board::delay(1_ms);
  }
  Current reading = filter.get();
  Current expected = Current(canzero_get_link24_current_calibration_target());
  Current calibration_offset = expected - reading;
  canzero_set_link24_current_calibration_offset(
      static_cast<float>(calibration_offset));
}
void FASTRUN sensors::link24_current::update() { link24_over_current_check.check(); }
