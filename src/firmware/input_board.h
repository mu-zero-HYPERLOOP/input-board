#pragma once

#include "./input_board_config.h"
#include "./metrics.h"
#include "core_pins.h"
#include "inttypes.h"
#include <cassert>

class InputBoard {
public:
  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux1() {
    mux_sel(0, 0, 0);
    Voltage reading = read_analog_voltage(AIN_MUX1);
    if constexpr (AIN_MUX1_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX1_CONFIG.vin() * AIN_MUX1_CONFIG.r2() / reading) -
             AIN_MUX1_CONFIG.r2();
    } else if constexpr (AIN_MUX1_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX1_CONFIG.r1() + AIN_MUX1_CONFIG.r2()) /
                        AIN_MUX1_CONFIG.r2());
    } else {
      return reading / AIN_MUX1_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux2() {
    mux_sel(0, 0, 1);
    Voltage reading = read_analog_voltage(AIN_MUX2);
    if constexpr (AIN_MUX2_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX2_CONFIG.vin() * AIN_MUX2_CONFIG.r2() / reading) -
             AIN_MUX2_CONFIG.r2();
    } else if constexpr (AIN_MUX2_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX2_CONFIG.r1() + AIN_MUX2_CONFIG.r2()) /
                        AIN_MUX2_CONFIG.r2());
    } else {
      return reading / AIN_MUX2_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux3() {
    mux_sel(0, 1, 0);
    Voltage reading = read_analog_voltage(AIN_MUX3);
    if constexpr (AIN_MUX3_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX3_CONFIG.vin() * AIN_MUX3_CONFIG.r2() / reading) -
             AIN_MUX3_CONFIG.r2();
    } else if constexpr (AIN_MUX3_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX3_CONFIG.r1() + AIN_MUX3_CONFIG.r2()) /
                        AIN_MUX3_CONFIG.r2());
    } else {
      return reading / AIN_MUX3_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux4() {
    mux_sel(0, 1, 1);
    Voltage reading = read_analog_voltage(AIN_MUX4);
    if constexpr (AIN_MUX4_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX4_CONFIG.vin() * AIN_MUX4_CONFIG.r2() / reading) -
             AIN_MUX4_CONFIG.r2();
    } else if constexpr (AIN_MUX4_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX4_CONFIG.r1() + AIN_MUX4_CONFIG.r2()) /
                        AIN_MUX4_CONFIG.r2());
    } else {
      return reading / AIN_MUX4_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux5() {
    mux_sel(1, 0, 0);
    Voltage reading = read_analog_voltage(AIN_MUX5);
    if constexpr (AIN_MUX5_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX5_CONFIG.vin() * AIN_MUX5_CONFIG.r2() / reading) -
             AIN_MUX5_CONFIG.r2();
    } else if constexpr (AIN_MUX5_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX5_CONFIG.r1() + AIN_MUX5_CONFIG.r2()) /
                        AIN_MUX5_CONFIG.r2());
    } else {
      return reading / AIN_MUX5_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux6() {
    mux_sel(1, 0, 1);
    Voltage reading = read_analog_voltage(AIN_MUX6);
    if constexpr (AIN_MUX6_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX6_CONFIG.vin() * AIN_MUX6_CONFIG.r2() / reading) -
             AIN_MUX6_CONFIG.r2();
    } else if constexpr (AIN_MUX6_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX6_CONFIG.r1() + AIN_MUX6_CONFIG.r2()) /
                        AIN_MUX6_CONFIG.r2());
    } else {
      return reading / AIN_MUX6_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux7() {
    mux_sel(1, 1, 0);
    Voltage reading = read_analog_voltage(AIN_MUX7);
    if constexpr (AIN_MUX7_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX7_CONFIG.vin() * AIN_MUX7_CONFIG.r2() / reading) -
             AIN_MUX7_CONFIG.r2();
    } else if constexpr (AIN_MUX7_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX7_CONFIG.r1() + AIN_MUX7_CONFIG.r2()) /
                        AIN_MUX7_CONFIG.r2());
    } else {
      return reading / AIN_MUX7_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain_mux8() {
    mux_sel(1, 1, 1);
    Voltage reading = read_analog_voltage(AIN_MUX8);
    if constexpr (AIN_MUX8_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN_MUX8_CONFIG.vin() * AIN_MUX8_CONFIG.r2() / reading) -
             AIN_MUX8_CONFIG.r2();
    } else if constexpr (AIN_MUX8_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((AIN_MUX8_CONFIG.r1() + AIN_MUX8_CONFIG.r2()) /
                        AIN_MUX8_CONFIG.r2());
    } else {
      return reading / AIN_MUX8_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc1() {
    mux_sel(0, 0, 0);
    Voltage reading = read_analog_voltage(NTC1);
    return (5_V * NTC1_R / reading) - NTC1_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc2() {
    mux_sel(0, 0, 1);
    Voltage reading = read_analog_voltage(NTC2);
    return (5_V * NTC2_R / reading) - NTC2_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc3() {
    mux_sel(0, 1, 0);
    Voltage reading = read_analog_voltage(NTC3);
    return (5_V * NTC3_R / reading) - NTC3_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc4() {
    mux_sel(0, 1, 1);
    Voltage reading = read_analog_voltage(NTC4);
    return (5_V * NTC4_R / reading) - NTC4_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc5() {
    mux_sel(1, 0, 0);
    Voltage reading = read_analog_voltage(NTC5);
    return (5_V * NTC5_R / reading) - NTC5_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc6() {
    mux_sel(1, 0, 1);
    Voltage reading = read_analog_voltage(NTC6);
    return (5_V * NTC6_R / reading) - NTC6_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc7() {
    mux_sel(1, 1, 0);
    Voltage reading = read_analog_voltage(NTC7);
    return (5_V * NTC7_R / reading) - NTC7_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Resistance read_ntc8() {
    mux_sel(1, 1, 1);
    Voltage reading = read_analog_voltage(NTC8);
    return (5_V * NTC8_R / reading) - NTC8_R;
  }

  [[nodiscard]] [[maybe_unused]] static inline Voltage read_vmeas1() {
    Voltage reading = read_analog_voltage(VMEAS1);
    return reading;
  }

  [[nodiscard]] [[maybe_unused]] static inline Voltage read_vmeas2() {
    Voltage reading = read_analog_voltage(VMEAS2);
    return reading;
  }

  [[nodiscard]] [[maybe_unused]] static inline Voltage read_vmeas3() {
    Voltage reading = read_analog_voltage(VMEAS3);
    return reading;
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain1() {
    Voltage reading = read_analog_voltage(AIN1);
    if constexpr (AIN1_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN1_CONFIG.vin() * AIN1_CONFIG.r2() / reading) -
             AIN1_CONFIG.r2();
    } else if constexpr (AIN1_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading *
             ((AIN1_CONFIG.r1() + AIN1_CONFIG.r2()) / AIN1_CONFIG.r2());
    } else {
      return reading / AIN1_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain2() {
    Voltage reading = read_analog_voltage(AIN2);
    if constexpr (AIN2_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return (AIN2_CONFIG.vin() * AIN2_CONFIG.r2() / reading) -
             AIN2_CONFIG.r2();
    } else if constexpr (AIN2_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading *
             ((AIN2_CONFIG.r1() + AIN2_CONFIG.r2()) / AIN2_CONFIG.r2());
    } else {
      return reading / AIN2_CONFIG.r2();
    }
  }

  [[nodiscard]] [[maybe_unused]] static inline auto read_ain3() {
    Voltage reading = read_analog_voltage(AIN3);
    if constexpr (AIN3_CONFIG.tag() == AnalogConfig::tag::RESISTANCE_MEAS) {
      return ((AIN2_CONFIG.vin() * AIN2_CONFIG.r2()) / reading) -
             AIN2_CONFIG.r2();
    } else if constexpr (AIN3_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading *
             ((AIN3_CONFIG.r1() + AIN3_CONFIG.r2()) / AIN3_CONFIG.r2());
    } else {
      return reading / AIN3_CONFIG.r2();
    }
  }

  [[nodiscard]] static inline Voltage read_analog_voltage(uint8_t pin) {
    switch (pin) {
    case VMEAS1:
      break;
    case VMEAS2:
      break;
    case VMEAS3:
      break;
    case NTC_MUX_PIN:
      break;
    case AIN1:
      break;
    case AIN2:
      break;
    case AIN3:
      break;
    case AIN_MUX_PIN:
      break;
    }
    assert(false);
    return 0_V;
  }

  [[nodiscard]] [[maybe_unused]] static inline bool read_din2() {
    return digitalReadFast(DIN2);
  }
  [[nodiscard]] [[maybe_unused]] static inline bool read_din3() {
    return digitalReadFast(DIN3);
  }
  [[nodiscard]] [[maybe_unused]] static inline bool read_din4() {
    return digitalReadFast(DIN4);
  }
  [[nodiscard]] [[maybe_unused]] static inline bool read_din5() {
    return digitalReadFast(DIN5);
  }
  [[nodiscard]] [[maybe_unused]] static inline bool read_din6() {
    return digitalReadFast(DIN6);
  }
  [[nodiscard]] [[maybe_unused]] static inline bool read_digital(uint8_t pin) {
    return digitalReadFast(pin);
  }

private:
  enum AnalogInputPin : uint8_t {
    VMEAS1 = 21,
    VMEAS2 = 20,
    VMEAS3 = 19,
    NTC_MUX_PIN = 17,
    NTC1 = NTC_MUX_PIN,
    NTC2 = NTC_MUX_PIN,
    NTC3 = NTC_MUX_PIN,
    NTC4 = NTC_MUX_PIN,
    NTC5 = NTC_MUX_PIN,
    NTC6 = NTC_MUX_PIN,
    NTC7 = NTC_MUX_PIN,
    NTC8 = NTC_MUX_PIN,
    AIN1 = 15,
    AIN2 = 14,
    AIN3 = 18,
    AIN_MUX_PIN = 16,
    AIN_MUX1 = AIN_MUX_PIN,
    AIN_MUX2 = AIN_MUX_PIN,
    AIN_MUX3 = AIN_MUX_PIN,
    AIN_MUX4 = AIN_MUX_PIN,
    AIN_MUX5 = AIN_MUX_PIN,
    AIN_MUX6 = AIN_MUX_PIN,
    AIN_MUX7 = AIN_MUX_PIN,
    AIN_MUX8 = AIN_MUX_PIN,
  };

  enum DigitalInputPin : uint8_t {
    DIN2 = 2,
    DIN3 = 3,
    DIN4 = 4,
    DIN5 = 5,
    DIN6 = 6,
  };

  enum MuxControlPin : uint8_t {
    MUX_SEL_0 = 38,
    MUX_SEL_1 = 37,
    MUX_SEL_2 = 36,
  };

  static inline void mux_sel(bool sel2, bool sel1, bool sel0) {
    digitalWriteFast(MuxControlPin::MUX_SEL_0, sel0);
    digitalWriteFast(MuxControlPin::MUX_SEL_1, sel1);
    digitalWriteFast(MuxControlPin::MUX_SEL_2, sel2);
  }
};
