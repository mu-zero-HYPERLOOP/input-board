#pragma once

#include "util/metrics.h"
namespace sensors::accelerometer {

constexpr Frequency MEAS_FREQUENCY = 3.2_kHz;

void begin();

void calibrate();

void update();

};
