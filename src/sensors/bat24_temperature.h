#pragma once
#include "firmware/pinout.h"
#include "util/metrics.h"

namespace sensors::bat24_temperature {

constexpr Resistance R_MEAS = 1_kOhm;
constexpr float NTC_BETA = 3900;
constexpr Resistance NTC_R_REF = 10_kOhm;
constexpr Temperature NTC_T_REF = 25_Celcius;

constexpr mux_pin PIN_CELL1 = mux_pin::mux_ntc_3;
constexpr mux_pin PIN_CELL2 = mux_pin::mux_ntc_6;
constexpr Frequency FREQUENCY = 10_Hz;

void begin();

void calibrate();

void update();

}
