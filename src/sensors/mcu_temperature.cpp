#include "sensors/mcu_temperature.h"
#include "boxcar.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "util/interval.h"
#include <avr/pgmspace.h>

static DMAMEM Interval interval(10_Hz);
static DMAMEM BoxcarFilter<Temperature, 100> filter(24_Celcius);

static DMAMEM ErrorLevelRangeCheck<EXPECT_UNDER>
    error_check(canzero_get_mcu_temperature,
                canzero_get_error_level_config_mcu_temperature,
                canzero_set_error_level_mcu_temperature);

void FLASHMEM sensors::mcu_temperature::begin() {
  // pass
}

void PROGMEM sensors::mcu_temperature::calibrate() {
  for(size_t i = 0; i < filter.size(); ++i) {
    filter.push(input_board::read_mcu_temperature());
  }
  // pass
}

void FASTRUN sensors::mcu_temperature::update() {
  if (interval.next()) {
    filter.push(input_board::read_mcu_temperature());
    float temp_celcius = static_cast<float>(filter.get());
    canzero_set_mcu_temperature(temp_celcius);
  }
  error_check.check();
}
