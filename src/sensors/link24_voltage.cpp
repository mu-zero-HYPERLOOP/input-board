#include "sensors/link24_voltage.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/isolated_voltage.h"
#include "util/metrics.h"
#include <avr/pgmspace.h>

using sensors::link24_voltage::R1;
using sensors::link24_voltage::R2;

static DMAMEM BoxcarFilter<Voltage, 10> filter(0_V);

static DMAMEM ErrorLevelRangeCheck<EXPECT_OVER>
    link24_under_volt_check(canzero_get_link24_voltage,
                            canzero_get_error_level_config_link24_under_voltage,
                            canzero_set_error_level_link24_under_voltage);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    link24_over_volt_check(canzero_get_link24_voltage,
                           canzero_get_error_level_config_link24_over_voltage,
                           canzero_set_error_level_link24_over_voltage);

static void FASTRUN on_value(const Voltage &v) {
  Voltage reading = sensors::formula::isolated_voltage_meas(v, R1, R2);
  filter.push(reading);
  canzero_set_link24_voltage(static_cast<float>(filter.get()));
}

void FLASHMEM sensors::link24_voltage::begin() {
  input_board::register_periodic_reading(MEAS_FREQUENCY, PIN, on_value);
}

void PROGMEM sensors::link24_voltage::calibrate() {
  for (unsigned int i = 0; i < filter.size(); ++i) {
    Voltage v = input_board::sync_read(PIN);
    on_value(v);
    input_board::delay(1_ms);
  }
  Voltage reading = filter.get();
  Voltage expected = Voltage(canzero_get_link24_voltage_calibration_target());
  Voltage calibration_offset = expected - reading;
  canzero_set_link24_voltage_calibration_offset(
      static_cast<float>(calibration_offset));
}

void FASTRUN sensors::link24_voltage::update() {
  link24_over_volt_check.check();
  link24_under_volt_check.check();
}