#pragma once

#include "util/metrics.h"
#include <avr/pgmspace.h>
namespace sensors::formula {

// slope should be given as A / V
static FASTRUN Current hall_effect_sensor(Voltage v, Conductance slope, 
    Current offset) {
  return v * slope + offset;
}


// slope should be given as A / V
static FASTRUN Current hall_effect_sensor(Voltage v, Resistance inv_slope, 
    Current offset) {
  return v / inv_slope + offset;
}

static FASTRUN Voltage inv_hall_effect_sensor(Current i, Conductance slope, 
    Current offset) {
  return (i - offset) / slope;
}

static FASTRUN Voltage inv_hall_effect_sensor(Current i, Resistance inv_slope, 
    Current offset) {
  return (i - offset) * inv_slope;
}

}
