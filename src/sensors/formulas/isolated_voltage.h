#pragma once

#include "util/metrics.h"
namespace sensors::formula{
  
static Voltage isolated_voltage_meas(Voltage v, Resistance r1, Resistance r2) {
  return v * ((r1 + r2) / (3 * r2));
}

static Voltage inv_isolated_voltage_meas(Voltage v, Resistance r1, Resistance r2) {
  return v / ((r1 + r2) / (3 * r2));
}
};

