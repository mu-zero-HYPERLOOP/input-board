#include "canzero/canzero.h"
#include "firmware/input_board.h"
#include "sensors/link24_current.h"
#include "sensors/link24_voltage.h"
#include "print.h"
#include <avr/pgmspace.h>
#include "sensors/link45_current.h"
#include "util/interval.h"
#include "util/timing.h"


static IntervalTiming loopIntervalTiming;

int main() {


  canzero_init();
  input_board::begin();

  sensors::link24_current::begin();

  sensors::link24_current::calibrate();
  
  Interval logInterval {10_Hz};

  debugPrintf("Calibration done\n");

  while (true) {

    input_board::update_continue();

    sensors::link24_current::update();

    if (logInterval.next()){
      debugPrintf("I = %fA\n\n", canzero_get_link24_current());
      debugPrintFlush();
    }
  }
}
