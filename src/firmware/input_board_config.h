#pragma once

#include "firmware/analog_config.h"
#include "util/metrics.h"

// 5V----NTC----uC----R----GND
static constexpr Resistance NTC18_1_R = 10_kOhm;
static constexpr Resistance NTC18_2_R = 10_kOhm;
static constexpr Resistance NTC18_3_R = 10_kOhm;
static constexpr Resistance NTC18_4_R = 10_kOhm;
static constexpr Resistance NTC18_5_R = 10_kOhm;
static constexpr Resistance NTC18_6_R = 10_kOhm;
static constexpr Resistance NTC18_7_R = 10_kOhm;
static constexpr Resistance NTC18_8_R = 10_kOhm;

// AnalogConfig::
// - voltage_meas(r1,r2)       -> [ PIN-----R1----uC----R2----GND ]
// - current_meas(r)           -> [ PIN-----uC----R-----------GND ]
// - resistance_meas(r1, Vref) -> [ Vref----R-----uC----R1----GND ]

static constexpr AnalogConfig AIN14_1_CONFIG = AnalogConfig::current_meas(180_Ohm);

static constexpr AnalogConfig AIN14_2_CONFIG = AnalogConfig::voltage_meas(1_kOhm, 2_kOhm);
static constexpr AnalogConfig AIN14_3_CONFIG = AnalogConfig::none();
static constexpr AnalogConfig AIN14_4_CONFIG = AnalogConfig::none();
static constexpr AnalogConfig AIN14_5_CONFIG = AnalogConfig::none();
static constexpr AnalogConfig AIN14_6_CONFIG = AnalogConfig::none();
static constexpr AnalogConfig AIN14_7_CONFIG = AnalogConfig::none();
static constexpr AnalogConfig AIN14_8_CONFIG = AnalogConfig::none();

static constexpr AnalogConfig AIN17_CONFIG = AnalogConfig::voltage_meas(1_kOhm, 1_kOhm);
static constexpr AnalogConfig AIN16_CONFIG = AnalogConfig::voltage_meas(1_kOhm, 1_kOhm);
static constexpr AnalogConfig AIN15_CONFIG = AnalogConfig::voltage_meas(1_kOhm, 1_kOhm);

// Vref -- R1 -- uC --- R2 --- Vmeas
static constexpr Resistance VMEAS21_R1 = 1_kOhm;
static constexpr Resistance VMEAS21_R2 = 1_kOhm;

static constexpr Resistance VMEAS20_R1 = 1_kOhm;
static constexpr Resistance VMEAS20_R2 = 1_kOhm;

static constexpr Resistance VMEAS19_R1 = 1_kOhm;
static constexpr Resistance VMEAS19_R2 = 1_kOhm;
