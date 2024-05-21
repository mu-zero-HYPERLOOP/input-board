#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::bat24_current {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_15;

constexpr Resistance VOLT_PER_AMP = 66_mV / 1_A;

void begin();

void calibrate();

void update();

};
