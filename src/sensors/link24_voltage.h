#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::link24_voltage {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_iso_20;

constexpr Resistance R1 = 18_kOhm;
constexpr Resistance R2 = 620_Ohm;

constexpr Voltage DEFAULT_OFFSET = -0.163040_V;

void begin();
void calibrate();
void update();

};
