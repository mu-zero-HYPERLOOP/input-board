#include "canzero/canzero.h"
#include "firmware/input_board.h"
#include "print.h"
#include "sensors/linear_encoder.h"
#include "state_estimation.h"
#include "util/interval.h"
#include "util/timing.h"
#include <avr/pgmspace.h>

static IntervalTiming loopIntervalTiming;

int main() {
  canzero_init();
  input_board::delay(3_s);
  input_board::begin();

  sensors::linear_encoder::begin();
  state_estimation::begin();

  sensors::linear_encoder::calibrate();
  state_estimation::calibrate();

  Interval logInterval{10_Hz};

  while (true) {
    input_board::update_continue();

    sensors::linear_encoder::update();
    state_estimation::update();

    input_board::delay(100_us);

    if (logInterval.next()) {
      debugPrintf("count = %u\n", canzero_get_linear_encoder_count());
    }
  }
}
