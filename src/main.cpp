#include "firmware/input_board.h"
#include "firmware/pinout.h"
#include "print.h"
#include "sensors/formulas/isolated_voltage.h"
#include "util/metrics.h"

int main() {
  input_board::begin();

  input_board::delay(1_s);

  Resistance r1 = 33_kOhm;
  Resistance r2 = 560_Ohm;

  while (true) {
    Voltage pin_voltage = input_board::sync_read(ain_iso_19 );
    Voltage isolated_voltage =
        sensors::formula::isolated_voltage_meas(pin_voltage, r1, r2);

    float as_float = isolated_voltage / 1_V;

    debugPrintf("Measurement: %fV\n", as_float);

    input_board::delay(100_ms);
  }
}