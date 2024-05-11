#pragma once
#include <cstdint>

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

enum SpiPin : uint8_t {
  ACCEL_CS = 10,
};


