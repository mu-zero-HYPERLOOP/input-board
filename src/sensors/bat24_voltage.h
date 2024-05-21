#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::bat24_voltage {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_iso_19;

constexpr Resistance R1 = 18_kOhm;
constexpr Resistance R2 = 620_Ohm;
 
void begin();

void calibrate();

void update();

};
