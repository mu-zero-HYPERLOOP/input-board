#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::link24_current {

constexpr Frequency MEAS_FREQUENCY = 1_kHz;
constexpr ain_pin PIN = ain_16;

constexpr auto VOLT_PER_AMP = 1_A / 66_mV;

constexpr Resistance R1_V_DIV = 620_Ohm;
constexpr Resistance R2_V_DIV = 1200_Ohm;

void begin();
void calibrate();
void update();

};
