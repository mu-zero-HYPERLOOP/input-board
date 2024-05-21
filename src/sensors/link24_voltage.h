#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::link24_voltage {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_iso_20;

constexpr Resistance R1 = 17.950_kOhm;
constexpr Resistance R2 = 624_Ohm;

void begin();
void calibrate();
void update();

};
