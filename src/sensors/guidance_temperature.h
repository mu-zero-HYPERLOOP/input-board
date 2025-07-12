#pragma once
#include "firmware/pinout.h"
#include "util/metrics.h"

namespace sensors::guidance_temperature {

constexpr Resistance R_MEAS = 1_kOhm;
constexpr float NTC_BETA = 3900;
constexpr Resistance NTC_R_REF = 10_kOhm;
constexpr Temperature NTC_T_REF = 25_Celcius;

constexpr mux_pin PIN_MGU_FRONT_LEFT = mux_pin::mux_ain_4;   // 4
constexpr mux_pin PIN_MGU_FRONT_RIGHT = mux_pin::mux_ain_2;
constexpr mux_pin PIN_MGU_BACK_LEFT = mux_pin::mux_ain_5;   // 5
constexpr mux_pin PIN_MGU_BACK_RIGHT = mux_pin::mux_ntc_3;  // 3

constexpr Frequency FREQUENCY = 10_Hz;

void begin();

void calibrate();

void update();

}
