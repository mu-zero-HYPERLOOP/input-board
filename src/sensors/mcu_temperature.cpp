#include "sensors/mcu_temperature.h"
#include "util/boxcar.h"
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
  canzero_set_mcu_temperature(24);
  canzero_set_error_mcu_temperature_invalid(error_flag_OK);
  canzero_set_error_level_mcu_temperature(error_level_OK);
  canzero_set_error_level_config_mcu_temperature(error_level_config{
      .m_info_thresh = 70,
      .m_info_timeout = 1,
      .m_warning_thresh = 80,
      .m_warning_timeout = 1,
      .m_error_thresh = 90,
      .m_error_timeout = 1,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
}

void PROGMEM sensors::mcu_temperature::calibrate() {
  for (size_t i = 0; i < filter.size(); ++i) {
    filter.push(input_board::read_mcu_temperature());
    canzero_update_continue(canzero_get_time());
    input_board::delay(1_ms);
  }
}

void FASTRUN sensors::mcu_temperature::update() {
  if (interval.next()) {
    filter.push(input_board::read_mcu_temperature());
    canzero_set_mcu_temperature(static_cast<float>(filter.get() - 0_Celcius));

    const bool sensible = filter.get() <= 200_Celcius && filter.get() >= 0_Celcius;
    canzero_set_error_mcu_temperature_invalid(sensible ? error_flag_OK : error_flag_ERROR);
  }
  error_check.check();
}
