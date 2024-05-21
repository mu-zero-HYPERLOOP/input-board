#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::link45_voltage {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_iso_21;

constexpr Resistance R1 = 33_kOhm;
constexpr Resistance R2 = 570_Ohm;

void begin();

void calibrate();

void update();

};
