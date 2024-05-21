#include "canzero/canzero.h"
#include "core_pins.h"
#include "firmware/input_board.h"
#include <cmath>
#include <Arduino.h>

/**
 * This function get's invoked if a assertion fails
 */
void __assert_func(const char *filename, int line, const char *assert_func,
                   const char *expr) {
  input_board::set_sdc(false);
  canzero_set_sdc_status(sdc_status_OPEN);
  canzero_set_assertion_fault(error_flag_ERROR);
  canzero_update_continue(canzero_get_time());
  while (true) {
    Serial.println("Assertion fault");
    delay(1000);
  }
}
