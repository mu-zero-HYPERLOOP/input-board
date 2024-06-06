#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::bat24_current {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_17;

constexpr Resistance VOLT_PER_AMP = 66_mV / 1_A;
constexpr Current DEFAULT_OFFSET = -25.297924_A;

void begin();

void calibrate();

void update();

};
