#pragma once

#include "util/metrics.h"
#include "./input_board_pinout.h"
#include "firmware/analog_config.h"

static constexpr Resistance NTC1_R = 10_kOhm;
static constexpr Resistance NTC2_R = 10_kOhm;
static constexpr Resistance NTC3_R = 10_kOhm;
static constexpr Resistance NTC4_R = 10_kOhm;
static constexpr Resistance NTC5_R = 10_kOhm;
static constexpr Resistance NTC6_R = 10_kOhm;
static constexpr Resistance NTC7_R = 10_kOhm;
static constexpr Resistance NTC8_R = 10_kOhm;



static constexpr AnalogConfig AIN_MUX1_CONFIG = AnalogConfig::voltage_meas(10_kOhm, 2_kOhm);
static constexpr AnalogConfig AIN_MUX2_CONFIG = AnalogConfig::voltage_meas(1_kOhm, 2_kOhm);
static constexpr AnalogConfig AIN_MUX3_CONFIG = AnalogConfig::current_meas(180_Ohm);
static constexpr AnalogConfig AIN_MUX4_CONFIG = AnalogConfig::resistance_meas(10_kOhm, 3.3_V);
static constexpr AnalogConfig AIN_MUX5_CONFIG = AnalogConfig::resistance_meas(10_kOhm, 3.3_V);
static constexpr AnalogConfig AIN_MUX6_CONFIG = AnalogConfig::resistance_meas(10_kOhm, 3.3_V);
static constexpr AnalogConfig AIN_MUX7_CONFIG = AnalogConfig::resistance_meas(10_kOhm, 3.3_V);
static constexpr AnalogConfig AIN_MUX8_CONFIG = AnalogConfig::resistance_meas(10_kOhm, 3.3_V);


static constexpr AnalogConfig AIN1_CONFIG = AnalogConfig::current_meas(180_Ohm);
static constexpr AnalogConfig AIN2_CONFIG = AnalogConfig::resistance_meas(10_kOhm, 3.3_V);
static constexpr AnalogConfig AIN3_CONFIG = AnalogConfig::resistance_meas(10_kOhm, 3.3_V);

static constexpr Resistance VMEAS1_R1 = 1_kOhm;
static constexpr Resistance VMEAS1_R2 = 1_kOhm;

static constexpr Resistance VMEAS2_R1 = 1_kOhm;
static constexpr Resistance VMEAS2_R2 = 1_kOhm;

static constexpr Resistance VMEAS3_R1 = 1_kOhm;
static constexpr Resistance VMEAS3_R2 = 1_kOhm;

