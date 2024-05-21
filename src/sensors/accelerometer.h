#pragma once

#include "util/metrics.h"
namespace sensors::accelerometer {

constexpr Frequency MEAS_FREQUENCY = 100_Hz;

void begin();

void calibrate();

void update();

};
