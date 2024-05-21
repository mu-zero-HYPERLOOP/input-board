#pragma once

#include "util/metrics.h"
#include <cmath>
namespace sensors::formula {

static constexpr Temperature ntc_steinhart(Resistance R, 
      float A, float B, float C) {
  const float r = static_cast<float>(R);
  const float log_r = std::log(r);
  const float log_r2 = log_r * log_r;
  const float inv_temp = A + B * log_r + C * log_r * log_r2;
  return Temperature(1.0f / inv_temp);
}

static constexpr Resistance inv_ntc_steinhart(Temperature T,
    float A, float B, float C) {
  const float t = static_cast<float>(T);
  const float x = (1.0 / C) * (A - (1.0 / t));
  const float y = std::sqrt(std::pow(B / (3 * C), 3) + (x*x)/4.0);
  const float r = std::exp(std::pow(y - x / 2.0, 1.0 / 3.0) - std::pow(y + x / 2.0, 1.0 / 3.0));
  return Resistance(r);
}

};
