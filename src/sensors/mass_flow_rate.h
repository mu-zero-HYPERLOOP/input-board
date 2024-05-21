#pragma once

#include "firmware/pinout.h"
namespace sensors::mass_flow_rate {

constexpr din_pin PIN = din_6;

void begin();

void calibrate();

void update();

};
