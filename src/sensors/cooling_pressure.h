#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::cooling_pressure {

static constexpr Frequency MEAS_FREQUENCY = 10_Hz;
static constexpr mux_pin PIN = mux_ain_2;

void begin();

void calibrate(const Pressure& expected);

void update();
  
}

