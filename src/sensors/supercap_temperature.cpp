#include "sensors/supercap_temperature.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include <avr/pgmspace.h>
#include <cassert>

using sensors::supercap_temperature::NTC_BETA;
using sensors::supercap_temperature::NTC_R_REF;
using sensors::supercap_temperature::NTC_T_REF;
using sensors::supercap_temperature::R_MEAS;

static DMAMEM BoxcarFilter<Temperature, 10> filter(24_Celcius);
static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_supercap_temperature,
                canzero_get_error_level_config_supercap_temperature,
                canzero_set_error_level_supercap_temperature);

static void FASTRUN on_value(const Voltage &v) {
  const Current i_ntc = v / R_MEAS;
  const Voltage v_ntc = 5_V - v;
  const Resistance r_ntc = v_ntc / i_ntc;
  const Temperature temperature =
      sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
  filter.push(temperature);
  canzero_set_supercap_temperature(static_cast<float>(filter.get() - 0_Celcius));
}

void FLASHMEM sensors::supercap_temperature::begin() {
  assert(input_board::register_periodic_reading(FREQUENCY, PIN, on_value));
}

void PROGMEM sensors::supercap_temperature::calibrate() {
  for(size_t i= 0; i< filter.size(); ++i) {
    on_value(input_board::sync_read(PIN));
  }
}

void FASTRUN sensors::supercap_temperature::update() { error_check.check(); }
