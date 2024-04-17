#pragma once

#include "util/metrics.h"

class AnalogConfig {
public:
  enum class tag {
    RESISTANCE_MEAS,
    VOLTAGE_MEAS,
    CURRENT_MEAS,
  };

  [[maybe_unused]] static constexpr AnalogConfig
  resistance_meas(const Resistance &r, const Voltage &vin) {
    return AnalogConfig(tag::RESISTANCE_MEAS, 0_Ohm, r, 0_Ohm, vin);
  }

  [[maybe_unused]] static constexpr AnalogConfig
  voltage_meas(const Resistance &r1, const Resistance &r2) {
    return AnalogConfig(tag::VOLTAGE_MEAS, 0_Ohm, r1, r2, 0_V);
  }

  [[maybe_unused]] static constexpr AnalogConfig
  current_meas(const Resistance &r) {
    return AnalogConfig(tag::CURRENT_MEAS, 0_Ohm, r, 0_Ohm, 0_V);
  }

  constexpr tag tag() const { return m_tag; }

  constexpr Voltage vin() const { return m_vin; }
  constexpr Resistance r1() const { return m_r1; }

  constexpr Resistance r2() const { return m_r2; }

  constexpr Resistance r3() const { return m_r3; }

private:
  constexpr explicit AnalogConfig(enum tag tag, const Resistance &r1,
                                  const Resistance &r2, const Resistance &r3,
                                  const Voltage &vin)
      : m_tag(tag), m_r1(r1), m_r2(r2), m_r3(r3), m_vin(vin) {}
  const enum tag m_tag;
  const Resistance m_r1;
  const Resistance m_r2;
  const Resistance m_r3;
  const Voltage m_vin;
};
