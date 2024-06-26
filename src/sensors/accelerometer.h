#pragma once

#include "firmware/input_board.h"
#include "util/metrics.h"
namespace sensors::accelerometer {

constexpr Frequency MEAS_FREQUENCY = 3.2_kHz;
constexpr input_board::AccelerometerRange range = input_board::ACCEL_RANGE_2G;

void begin();

void calibrate();

void update();

};
