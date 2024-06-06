#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::link45_current {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_15;

constexpr auto VOLT_PER_AMP = 6.25_mV / 1_A;

void begin();
void calibrate();
void update();

};
