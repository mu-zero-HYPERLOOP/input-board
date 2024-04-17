#pragma once

#include "util/metrics.h"
#include "util/timestamp.h"

class AnalogConfig {
public:
  enum class tag {
    RESISTANCE_MEAS,
    VOLTAGE_MEAS,
    CURRENT_MEAS,
    ISOLATED_VOLTAGES,
  };

  [[maybe_unused]] static constexpr AnalogConfig
  resistance_meas(const Resistance &r, const Voltage &vin,
                  const Frequency &f = 1_MHz) {
    return AnalogConfig(tag::RESISTANCE_MEAS, 0_Ohm, r, 0_Ohm, vin, f);
  }

  [[maybe_unused]] static constexpr AnalogConfig
  voltage_meas(const Resistance &r1, const Resistance &r2,
               const Frequency &f = 1_MHz) {
    return AnalogConfig(tag::VOLTAGE_MEAS, 0_Ohm, r1, r2, 0_V, f);
  }

  [[maybe_unused]] static constexpr AnalogConfig
  current_meas(const Resistance &r, const Frequency &f = 1_kHz) {
    return AnalogConfig(tag::CURRENT_MEAS, 0_Ohm, r, 0_Ohm, 0_V, f);
  }

  [[maybe_unused]] static constexpr AnalogConfig
  isolated_voltage_meas(const Resistance &r1, const Resistance &r2,
                        const Frequency &f = 1_MHz) {
    return AnalogConfig(tag::ISOLATED_VOLTAGES, 0_Ohm, r1, r2, 0_V, f);
  }

  constexpr tag tag() const { return m_tag; }

  constexpr Voltage vin() const { return m_vin; }
  constexpr Resistance r1() const { return m_r1; }

  constexpr Resistance r2() const { return m_r2; }

  constexpr Resistance r3() const { return m_r3; }

  constexpr Duration period() const { return m_period; }

private:
  constexpr explicit AnalogConfig(enum tag tag, const Resistance &r1,
                                  const Resistance &r2, const Resistance &r3,
                                  const Voltage &vin, const Frequency &f)
      : m_tag(tag), m_r1(r1), m_r2(r2), m_r3(r3), m_vin(vin),
        m_period(1.0f / f) {}
  const enum tag m_tag;
  const Resistance m_r1;
  const Resistance m_r2;
  const Resistance m_r3;
  const Voltage m_vin;
  const Duration m_period;
};
