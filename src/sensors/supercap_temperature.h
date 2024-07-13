#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
namespace sensors::supercap_temperature {

constexpr Resistance R_MEAS = 1_kOhm;
constexpr float NTC_BETA = 3900;
constexpr Resistance NTC_R_REF = 10_kOhm;
constexpr Temperature NTC_T_REF = 25_Celcius;

constexpr mux_pin PIN = mux_pin::mux_ntc_1;
constexpr Frequency FREQUENCY = 10_Hz;

void begin();

void calibrate();

void update();

}
