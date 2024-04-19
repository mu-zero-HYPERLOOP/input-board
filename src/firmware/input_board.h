#pragma once

#include <InternalTemperature.h>
#include "core_pins.h"
#include "firmware/input_board_config.h"
#include "inttypes.h"
#include "util/metrics.h"
#include "util/timestamp.h"
#include <cassert>
#include <cstring>

// DON'T TOUCH ME
static constexpr AnalogConfig ANALOG_CONFIGS[] = {
    AnalogConfig::isolated_voltage_meas(VMEAS1_R1, VMEAS1_R2, VMEAS1_FREQUENCY),
    AnalogConfig::isolated_voltage_meas(VMEAS2_R1, VMEAS2_R2, VMEAS2_FREQUENCY),
    AnalogConfig::isolated_voltage_meas(VMEAS3_R1, VMEAS3_R2, VMEAS3_FREQUENCY),
    AIN1_CONFIG,
    AIN2_CONFIG,
    AIN3_CONFIG,
    AnalogConfig::resistance_meas(NTC1_R, 5_V),
    AnalogConfig::resistance_meas(NTC2_R, 5_V),
    AnalogConfig::resistance_meas(NTC3_R, 5_V),
    AnalogConfig::resistance_meas(NTC4_R, 5_V),
    AnalogConfig::resistance_meas(NTC5_R, 5_V),
    AnalogConfig::resistance_meas(NTC6_R, 5_V),
    AnalogConfig::resistance_meas(NTC7_R, 5_V),
    AnalogConfig::resistance_meas(NTC8_R, 5_V),
    AIN_MUX1_CONFIG,
    AIN_MUX2_CONFIG,
    AIN_MUX3_CONFIG,
    AIN_MUX4_CONFIG,
    AIN_MUX5_CONFIG,
    AIN_MUX6_CONFIG,
    AIN_MUX7_CONFIG,
    AIN_MUX8_CONFIG,
};

enum AnalogInput : uint8_t {
  VMEAS1,
  VMEAS2,
  VMEAS3,
  AIN1,
  AIN2,
  AIN3,
  NTC1,
  NTC2,
  NTC3,
  NTC4,
  NTC5,
  NTC6,
  NTC7,
  NTC8,
  AIN_MUX1,
  AIN_MUX2,
  AIN_MUX3,
  AIN_MUX4,
  AIN_MUX5,
  AIN_MUX6,
  AIN_MUX7,
  AIN_MUX8,
  AIN_COUNT,
};

enum DigitalInputPin : uint8_t {
  PIN_DIN2 = 2,
  PIN_DIN3 = 3,
  PIN_DIN4 = 4,
  PIN_DIN5 = 5,
  PIN_DIN6 = 6,
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
    PIN_VMEAS1 = 21,
    PIN_VMEAS2 = 20,
    PIN_VMEAS3 = 19,
    PIN_NTC1 = 17,
    PIN_NTC2 = 17,
    PIN_NTC3 = 17,
    PIN_NTC4 = 17,
    PIN_NTC5 = 17,
    PIN_NTC6 = 17,
    PIN_NTC7 = 17,
    PIN_NTC8 = 17,
    PIN_AIN1 = 15,
    PIN_AIN2 = 14,
    PIN_AIN3 = 18,
    PIN_AIN_MUX1 = 16,
    PIN_AIN_MUX2 = 16,
    PIN_AIN_MUX3 = 16,
    PIN_AIN_MUX4 = 16,
    PIN_AIN_MUX5 = 16,
    PIN_AIN_MUX6 = 16,
    PIN_AIN_MUX7 = 16,
    PIN_AIN_MUX8 = 16,
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
    case VMEAS1:
      return PIN_VMEAS1;
    case VMEAS2:
      return PIN_VMEAS2;
    case VMEAS3:
      return PIN_VMEAS3;
    case AIN1:
      return PIN_AIN1;
    case AIN2:
      return PIN_AIN2;
    case AIN3:
      return PIN_AIN3;
    case NTC1:
      return PIN_NTC1;
    case NTC2:
      return PIN_NTC2;
    case NTC3:
      return PIN_NTC3;
    case NTC4:
      return PIN_NTC4;
    case NTC5:
      return PIN_NTC5;
    case NTC6:
      return PIN_NTC6;
    case NTC7:
      return PIN_NTC7;
    case NTC8:
      return PIN_NTC8;
    case AIN_MUX1:
      return PIN_AIN_MUX1;
    case AIN_MUX2:
      return PIN_AIN_MUX2;
    case AIN_MUX3:
      return PIN_AIN_MUX3;
    case AIN_MUX4:
      return PIN_AIN_MUX4;
    case AIN_MUX5:
      return PIN_AIN_MUX5;
    case AIN_MUX6:
      return PIN_AIN_MUX6;
    case AIN_MUX7:
      return PIN_AIN_MUX7;
    case AIN_MUX8:
      return PIN_AIN_MUX8;
    case AIN_COUNT:
      return NaP;
    }
  }

  template <AnalogInput AIN> static auto read() {
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
    }
  }

  static AnalogReading m_readings[AIN_COUNT];
  static bool m_new_value[AIN_COUNT];
  static uint8_t m_mux_sel;
  static Timestamp m_last_mux_transition;
  static Timestamp m_last_meas[AIN3 + 1]; // not for mux inputs
  static constexpr Duration MUX_TRANSITION_TIME = 100_ms;


public:
  static void begin();

  static inline void set_sdc_status(bool close) {
    digitalWrite(SDC_TRIG_PIN, close);
  }

  static void update();

  template <AnalogInput AIN> static inline bool has_next() {
    return m_new_value[AIN];
  }

  template <AnalogInput AIN> static inline auto get_ain() {
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
    }
  }

  static Temperature read_mcu_temperature() {
    float temp = InternalTemperature.readTemperatureC();
    float temp_kelvin = temp - 273.15f;
    return Temperature(temp_kelvin);
  }
};
