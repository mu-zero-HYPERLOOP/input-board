#pragma once

#include "./input_board_config.h"
#include "./metrics.h"
#include "core_pins.h"

class InputBoard {
public:

  static auto read_ain_mux1() {
    mux_sel(0, 0, 0);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX1_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      // voltage divider configured by AnalogConfig::ntc_config(<R>, <VIN>);
      //  VIN
      //   |
      //  NTC
      //   |
      //   o--- ADC
      //   |
      //   R
      //   |
      //  GND
      return (AIN_MUX1_CONFIG.vin() / reading) * AIN_MUX1_CONFIG.r2() -
             AIN_MUX1_CONFIG.r2();
    } else if constexpr (AIN_MUX1_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      // voltage divider configured by AnalogConfig::voltage_divider(<R1>,
      // <R2>);
      //  AIN
      //   |
      //   R1
      //   |
      //   o--- ADC
      //   |
      //   R2
      //   |
      //  GND
      return reading * ((AIN_MUX1_CONFIG.r1() + AIN_MUX1_CONFIG.r2()) /
                        AIN_MUX1_CONFIG.r2());
    } else {
      // current measurment configured by AnalogConfig::current_meas(<R2>);
      //  AIN
      //   |
      //   o--- ADC
      //   |
      //   R2
      //   |
      //  GND
      return reading / AIN_MUX1_CONFIG.r2();
    }
  }

  static auto read_ain_mux2() {
    mux_sel(0, 0, 1);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX2_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN_MUX2_CONFIG.vin() / reading) * AIN_MUX2_CONFIG.r2() -
             AIN_MUX2_CONFIG.r2();
    } else if constexpr (AIN_MUX2_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN_MUX2_CONFIG.r1() + AIN_MUX2_CONFIG.r2()) /
                        AIN_MUX2_CONFIG.r2());
    } else {
      return reading / AIN_MUX2_CONFIG.r2();
    }
  }

  static auto read_ain_mux3() {
    mux_sel(0, 1, 0);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX3_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN_MUX3_CONFIG.vin() / reading) * AIN_MUX3_CONFIG.r2() -
             AIN_MUX3_CONFIG.r2();
    } else if constexpr (AIN_MUX3_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN_MUX3_CONFIG.r1() + AIN_MUX3_CONFIG.r2()) /
                        AIN_MUX3_CONFIG.r2());
    } else {
      return reading / AIN_MUX3_CONFIG.r2();
    }
  }

  static auto read_ain_mux4() {
    mux_sel(0, 1, 1);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX4_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN_MUX4_CONFIG.vin() / reading) * AIN_MUX4_CONFIG.r2() -
             AIN_MUX4_CONFIG.r2();
    } else if constexpr (AIN_MUX4_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN_MUX4_CONFIG.r1() + AIN_MUX4_CONFIG.r2()) /
                        AIN_MUX4_CONFIG.r2());
    } else {
      return reading / AIN_MUX4_CONFIG.r2();
    }
  }

  static auto read_ain_mux5() {
    mux_sel(1, 0, 0);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX5_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN_MUX5_CONFIG.vin() / reading) * AIN_MUX5_CONFIG.r2() -
             AIN_MUX5_CONFIG.r2();
    } else if constexpr (AIN_MUX5_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN_MUX5_CONFIG.r1() + AIN_MUX5_CONFIG.r2()) /
                        AIN_MUX5_CONFIG.r2());
    } else {
      return reading / AIN_MUX5_CONFIG.r2();
    }
  }

  static auto read_ain_mux6() {
    mux_sel(1, 0, 1);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX6_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN_MUX6_CONFIG.vin() / reading) * AIN_MUX6_CONFIG.r2() -
             AIN_MUX6_CONFIG.r2();
    } else if constexpr (AIN_MUX6_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN_MUX6_CONFIG.r1() + AIN_MUX6_CONFIG.r2()) /
                        AIN_MUX6_CONFIG.r2());
    } else {
      return reading / AIN_MUX6_CONFIG.r2();
    }
  }

  static auto read_ain_mux7() {
    mux_sel(1, 1, 0);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX7_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN_MUX7_CONFIG.vin() / reading) * AIN_MUX7_CONFIG.r2() -
             AIN_MUX7_CONFIG.r2();
    } else if constexpr (AIN_MUX7_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN_MUX7_CONFIG.r1() + AIN_MUX7_CONFIG.r2()) /
                        AIN_MUX7_CONFIG.r2());
    } else {
      return reading / AIN_MUX7_CONFIG.r2();
    }
  }

  static auto read_ain_mux8() {
    mux_sel(1, 1, 1);
    Voltage reading = 0_V;
    if constexpr (AIN_MUX8_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN_MUX8_CONFIG.vin() / reading) * AIN_MUX8_CONFIG.r2() -
             AIN_MUX8_CONFIG.r2();
    } else if constexpr (AIN_MUX8_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN_MUX8_CONFIG.r1() + AIN_MUX8_CONFIG.r2()) /
                        AIN_MUX8_CONFIG.r2());
    } else {
      return reading / AIN_MUX8_CONFIG.r2();
    }
  }

  static Resistance read_ntc1() {
    mux_sel(0, 0, 0);
    Voltage reading = 0_V;
    return (5_V / reading) * NTC1_R - NTC1_R;
  }

  static Resistance read_ntc2() {
    mux_sel(0, 0, 1);
    Voltage reading = 0_V;
    return (5_V / reading) * NTC2_R - NTC2_R;
  }

  static Resistance read_ntc3() {
    mux_sel(0, 1, 0);
    Voltage reading = 0_V;
    return (5_V / reading) * NTC3_R - NTC3_R;
  }

  static Resistance read_ntc4() {
    mux_sel(0, 1, 1);
    Voltage reading = 0_V;
    return (5_V / reading) * NTC4_R - NTC4_R;
  }

  static Resistance read_ntc5() {
    mux_sel(1, 0, 0);

    Voltage reading = 0_V;
    return (5_V / reading) * NTC5_R - NTC5_R;
  }

  static Resistance read_ntc6() {
    mux_sel(1, 0, 1);

    Voltage reading = 0_V;
    return (5_V / reading) * NTC6_R - NTC6_R;
  }

  static Resistance read_ntc7() {
    mux_sel(1, 1, 0);

    Voltage reading = 0_V;
    return (5_V / reading) * NTC7_R - NTC7_R;
  }

  static Resistance read_ntc8() {
    mux_sel(1, 1, 1);
    Voltage reading = 0_V;
    return (5_V / reading) * NTC8_R - NTC8_R;
  }

  static Voltage read_vmeas1() {
    Voltage reading = 0_V;
    return reading;
  }

  static Voltage read_vmeas2() {
    Voltage reading = 0_V;
    return reading;
  }

  static Voltage read_vmeas3() {
    Voltage reading = 0_V;
    return reading;
  }

  static auto read_ain1() {
    Voltage reading = 0_V;
    if constexpr (AIN1_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN1_CONFIG.vin() / reading) * AIN1_CONFIG.r2() -
             AIN1_CONFIG.r2();
    } else if constexpr (AIN1_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN1_CONFIG.r1() + AIN1_CONFIG.r2()) /
                        AIN1_CONFIG.r2());
    } else {
      return reading / AIN1_CONFIG.r2();
    }
  }

  static auto read_ain2() {
    Voltage reading = 0_V;
    if constexpr (AIN2_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return (AIN2_CONFIG.vin() / reading) * AIN2_CONFIG.r2() -
             AIN2_CONFIG.r2();
    } else if constexpr (AIN2_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return reading * ((AIN2_CONFIG.r1() + AIN2_CONFIG.r2()) /
                        AIN2_CONFIG.r2());
    } else {
      return reading / AIN2_CONFIG.r2();
    }
  }

  static auto read_ain3() {
    Voltage reading = 0_V;
    if constexpr (AIN3_CONFIG.tag() == AnalogConfig::tag::NTC_CONFIG) {
      return ((AIN2_CONFIG.vin() * AIN2_CONFIG.r2()) / reading) -
             AIN2_CONFIG.r2();
    } else if constexpr (AIN3_CONFIG.tag() ==
                         AnalogConfig::tag::VOLTAGE_DIVIDER) {
      return  reading * ((AIN3_CONFIG.r1() + AIN3_CONFIG.r2()) /
                        AIN3_CONFIG.r2());
    } else {
      return reading / AIN3_CONFIG.r2();
    }
  }


private:
  enum AnalogInputPin : int {
    VMEAS1 = 21,
    VMEAS2 = 20,
    VMEAS3 = 19,
    NTC1 = 17,
    NTC2 = 17,
    NTC3 = 17,
    NTC4 = 17,
    NTC5 = 17,
    NTC6 = 17,
    NTC7 = 17,
    NTC8 = 17,
    AIN1 = 15,
    AIN2 = 14,
    AIN3 = 18,
    AIN_MUX1 = 16,
    AIN_MUX2 = 16,
    AIN_MUX3 = 16,
    AIN_MUX4 = 16,
    AIN_MUX5 = 16,
    AIN_MUX6 = 16,
    AIN_MUX7 = 16,
    AIN_MUX8 = 16,
  };

  enum DigitalInputPin : int {
    DIN2 = 2,
    DIN3 = 3,
    DIN4 = 4,
    DIN5 = 5,
    DIN6 = 6,
  };

  enum MuxControlPin {
    MUX_SEL_0 = 38,
    MUX_SEL_1 = 37,
    MUX_SEL_2 = 36,
  };

  static void mux_sel(bool sel2, bool sel1, bool sel0) {
    digitalWriteFast(MuxControlPin::MUX_SEL_0, sel0);
    digitalWriteFast(MuxControlPin::MUX_SEL_1, sel1);
    digitalWriteFast(MuxControlPin::MUX_SEL_2, sel2);
  }
};
