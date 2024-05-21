#include "sensors/bat24_temperature.h"
#include "avr/pgmspace.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include <cassert>

using sensors::bat24_temperature::NTC_BETA;
using sensors::bat24_temperature::NTC_R_REF;
using sensors::bat24_temperature::NTC_T_REF;
using sensors::bat24_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter(24_Celcius);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_bat24_temperature,
                canzero_get_error_level_config_bat24_temperature,
                canzero_set_error_level_bat24_temperature);

static void FASTRUN on_value(const Voltage &v) {
  const Current i_ntc = v / R_MEAS;
  const Voltage v_ntc = 5_V - v;
  const Resistance r_ntc = v_ntc / i_ntc;
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter.push(temperature);
  canzero_set_bat24_temperature(static_cast<float>(filter.get() - 0_Celcius));
}

void FLASHMEM sensors::bat24_temperature::begin() {
  assert(input_board::register_periodic_reading(FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::bat24_temperature::calibrate() {
  for (size_t i = 0; i < filter.size(); ++i) {
    on_value(input_board::sync_read(PIN));
  }
}

void FASTRUN sensors::bat24_temperature::update() { error_check.check(); }