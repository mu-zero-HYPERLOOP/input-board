#pragma once

#include "core_pins.h"
#include "firmware/input_board_config.h"
#include "util/metrics.h"
#include "util/timestamp.h"
#include <InternalTemperature.h>
#include <cassert>
#include <cstring>
#include <inttypes.h>

// DON'T TOUCH ME
static constexpr AnalogConfig ANALOG_CONFIGS[] = {
    AnalogConfig::isolated_voltage_meas(VMEAS21_R1, VMEAS21_R2),
    AnalogConfig::isolated_voltage_meas(VMEAS20_R1, VMEAS20_R2),
    AnalogConfig::isolated_voltage_meas(VMEAS19_R1, VMEAS19_R2),
    AIN17_CONFIG,
    AIN16_CONFIG,
    AIN15_CONFIG,
    AnalogConfig::resistance_meas(NTC18_1_R, 5_V),
    AnalogConfig::resistance_meas(NTC18_2_R, 5_V),
    AnalogConfig::resistance_meas(NTC18_3_R, 5_V),
    AnalogConfig::resistance_meas(NTC18_4_R, 5_V),
    AnalogConfig::resistance_meas(NTC18_5_R, 5_V),
    AnalogConfig::resistance_meas(NTC18_6_R, 5_V),
    AnalogConfig::resistance_meas(NTC18_7_R, 5_V),
    AnalogConfig::resistance_meas(NTC18_8_R, 5_V),
    AIN14_1_CONFIG,
    AIN14_2_CONFIG,
    AIN14_3_CONFIG,
    AIN14_4_CONFIG,
    AIN14_5_CONFIG,
    AIN14_6_CONFIG,
    AIN14_7_CONFIG,
    AIN14_8_CONFIG,
};

enum AnalogInput : uint8_t {
  VMEAS21,
  VMEAS20,
  VMEAS19,
  AIN17,
  AIN16,
  AIN15,
  NTC18_1,
  NTC18_2,
  NTC18_3,
  NTC18_4,
  NTC18_5,
  NTC18_6,
  NTC18_7,
  NTC18_8,
  AIN14_1,
  AIN14_2,
  AIN14_3,
  AIN14_4,
  AIN14_5,
  AIN14_6,
  AIN14_7,
  AIN14_8,
  AIN_COUNT,
};

enum DigitalInputPin : uint8_t {
  DIN2 = 2,
  DIN3 = 3,
  DIN4 = 4,
  DIN5 = 5,
  DIN6 = 6,
};

class InputBoard {

private:
  union AnalogReading {
    Voltage u;
    Current i;
    Resistance r;

    AnalogReading() { this->u = Voltage(0.0); }

    AnalogReading &operator=(Voltage &&u) {
      this->u = u;
      return *this;
    }

    AnalogReading &operator=(Current &&i) {
      this->i = i;
      return *this;
    }

    AnalogReading &operator=(Resistance &&r) {
      this->r = r;
      return *this;
    }

    AnalogReading &operator=(Voltage &u) {
      this->u = u;
      return *this;
    }

    AnalogReading &operator=(Current &i) {
      this->i = i;
      return *this;
    }

    AnalogReading &operator=(Resistance &r) {
      this->r = r;
      return *this;
    }
  };

  enum MuxControlPin : uint8_t {
    MUX_SEL_0 = 38,
    MUX_SEL_1 = 37,
    MUX_SEL_2 = 36,
  };

  enum AnalogInputPin : uint8_t {
    PIN_VMEAS21 = 21,
    PIN_VMEAS20 = 20,
    PIN_VMEAS19 = 19,
    PIN_NTC_MUX = 18,
    PIN_AIN15 = 15,
    PIN_AIN14 = 14,
    PIN_AIN18 = 17,
    PIN_AIN_MUX = 14,
    NaP = 0xFF,
  };

  static constexpr uint8_t SDC_TRIG_PIN = 32;

  static inline void set_mux_sel(uint8_t mux_sel) {
    digitalWriteFast(MuxControlPin::MUX_SEL_0, (mux_sel & 0x1) != 0);
    digitalWriteFast(MuxControlPin::MUX_SEL_1, (mux_sel & 0x2) != 0);
    digitalWriteFast(MuxControlPin::MUX_SEL_2, (mux_sel & 0x4) != 0);
  }

  static constexpr AnalogInputPin input_to_pin(AnalogInput ain) {
    switch (ain) {
    case VMEAS21:
      return PIN_VMEAS21;
    case VMEAS20:
      return PIN_VMEAS20;
    case VMEAS19:
      return PIN_VMEAS19;
    case AIN17:
      return PIN_AIN15;
    case AIN16:
      return PIN_AIN14;
    case AIN15:
      return PIN_AIN18;
    case NTC18_1:
    case NTC18_2:
    case NTC18_3:
    case NTC18_4:
    case NTC18_5:
    case NTC18_6:
    case NTC18_7:
    case NTC18_8:
      return PIN_NTC_MUX;
    case AIN14_1:
    case AIN14_2:
    case AIN14_3:
    case AIN14_4:
    case AIN14_5:
    case AIN14_6:
    case AIN14_7:
    case AIN14_8:
      return PIN_AIN_MUX;
    case AIN_COUNT:
      return NaP;
    }
  }

  template <AnalogInput AIN> static auto read_internal() {
    constexpr AnalogInputPin pin = input_to_pin(AIN);
    Voltage reading =
        Voltage(static_cast<float>(analogRead(pin)) * 3.3f / 4095.0f);
    m_new_value[AIN] = true;
    if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                  AnalogConfig::tag::RESISTANCE_MEAS) {
      return (ANALOG_CONFIGS[AIN].vin() * ANALOG_CONFIGS[AIN].r2()) / reading -
             ANALOG_CONFIGS[AIN].r2();
    } else if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return reading * ((ANALOG_CONFIGS[AIN].r1() + ANALOG_CONFIGS[AIN].r2()) /
                        ANALOG_CONFIGS[AIN].r2());
    } else if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                         AnalogConfig::tag::CURRENT_MEAS) {
      return reading / ANALOG_CONFIGS[AIN].r2();
    } else if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                         AnalogConfig::tag::ISOLATED_VOLTAGES) {
      // TODO
      return reading;
    }else { //Not used
      return reading;
    }
  }

  static AnalogReading m_readings[AIN_COUNT];
  static bool m_new_value[AIN_COUNT];
  static uint8_t m_mux_sel;
  static Timestamp m_last_mux_transition;
  static Timestamp m_last_meas[AIN15 + 1]; // not for mux inputs
  static constexpr Duration MUX_TRANSITION_TIME = 100_ms;

public:
  static void begin();

  static inline void set_sdc_status(bool close) {
    digitalWrite(SDC_TRIG_PIN, close);
  }

  static void update();

  template <AnalogInput AIN> static inline bool has_next() {
    static_assert((AIN >= NTC18_1 && AIN <= NTC18_8) ||
                      (AIN >= AIN14_1 && AIN <= AIN14_8),
                  "has_next() is only applicable for multiplexed pins");
    return m_new_value[AIN];
  }

  template <AnalogInput AIN> static inline auto read_mux() {
    static_assert((AIN >= NTC18_1 && AIN <= NTC18_8) ||
                      (AIN >= AIN14_1 && AIN <= AIN14_8),
                  "use read() for non multiplexed pins");
    m_new_value[AIN] = false;
    if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                  AnalogConfig::tag::RESISTANCE_MEAS) {
      return m_readings[AIN].r;
    } else if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                         AnalogConfig::tag::VOLTAGE_MEAS) {
      return m_readings[AIN].u;
    } else if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                         AnalogConfig::tag::CURRENT_MEAS) {
      return m_readings[AIN].i;
    } else if constexpr (ANALOG_CONFIGS[AIN].tag() ==
                         AnalogConfig::tag::ISOLATED_VOLTAGES) {
      return m_readings[AIN].u;
    } else {
      return m_readings[AIN].u;
    }
  }

  template <AnalogInput AIN> static auto read() {
    static_assert(!((AIN >= NTC18_1 && AIN <= NTC18_8) ||
                    (AIN >= AIN14_1 && AIN <= AIN14_8)),
                  "use read_mux() for multiplexed pins");
    return read_internal<AIN>();
  }

  static Temperature read_mcu_temperature() {
    float temp = InternalTemperature.readTemperatureC();
    float temp_kelvin = temp - 273.15f;
    return Temperature(temp_kelvin);
  }
};
