#pragma once


#include "util/metrics.h"
namespace sensors::formula {

/// converts a current in A to a pressure in bar based on the datasheet of sick-pbt.
static Pressure sick_pbt(const Current& i) {
  return Pressure((i - 4_mA) / 1_mA) + 1_bar;
}

static constexpr Current inv_sick_pbt(Pressure p) {
  return 4_mA + static_cast<float>(p - 1_bar) * 1_mA;
}

}
