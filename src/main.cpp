/**
 * @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

#include "canzero/canzero.h"
#include "core_pins.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "firmware/input_board_config.h"
#include "state_estimation/state_estimation.h"
#include "util/ema.hpp"
#include "util/interval.h"
#include "util/metrics.h"
#include "util/ntc_eq.h"
#include "util/timeout.h"
#include "defaults.h"

constexpr AnalogInput AIN_24BAT_TEMP = NTC18_1;
constexpr auto BAT24_NTC_EQ =
    BetaModelNtc(3984.0f, 10_kOhm); // probably incorrect

constexpr AnalogInput AIN_EBOX_TEMP = NTC18_2;
constexpr auto EBOX_NTC_EQ = BetaModelNtc(3984.0f, 10_kOhm);

constexpr AnalogInput AIN_SUPERCAP_TEMP = NTC18_3;
constexpr auto SUPERCAP_NTC_EQ = BetaModelNtc(3984.0f, 10_kOhm);

constexpr AnalogInput AIN_BUCK_TEMP = NTC18_4;
constexpr auto BUCK_NTC_EQ = BetaModelNtc(3984.0f, 10_kOhm);

constexpr AnalogInput AIN_COOLING_TEMP = NTC18_5;
constexpr auto COOLING_NTC_EQ = BetaModelNtc(3984.0f, 10_kOhm);

constexpr AnalogInput AIN_AMBIENT_TEMP = NTC18_6;
constexpr auto AMBIENT_NTC_EQ = BetaModelNtc(3984.0f, 10_kOhm);

constexpr AnalogInput AIN_COOLING_PRESSURE = AIN14_1;

constexpr AnalogInput AIN_BAT_VOLTAGE = VMEAS21;
constexpr AnalogInput AIN_24LINK_VOLTAGE = VMEAS20;
constexpr AnalogInput AIN_45LINK_VOLTAGE = VMEAS19;

constexpr AnalogInput AIN_BAT_CURRENT = AIN17;
constexpr AnalogInput AIN_24LINK_CURRENT = AIN16;
constexpr AnalogInput AIN_45LINK_CURRENT = AIN15;

static Interval mcu_temp_interval = Interval(10_Hz);
static Interval bat24_meas_interval = Interval(100_Hz);
static Interval link24_meas_interval = Interval(100_Hz);
static Interval link45_meas_interval = Interval(100_Hz);

static ErrorLevelRangeCheck<EXPECT_OVER>
    bat24_under_volt_check(canzero_get_bat24_voltage,
                           canzero_get_error_level_config_bat24_under_voltage,
                           canzero_set_error_level_bat24_under_voltage);
static ErrorLevelRangeCheck<EXPECT_UNDER>
    bat24_over_volt_check(canzero_get_bat24_voltage,
                          canzero_get_error_level_config_bat24_over_voltage,
                          canzero_set_error_level_bat24_over_voltage);
static ErrorLevelRangeCheck<EXPECT_UNDER>
    bat24_over_current_check(canzero_get_bat24_current,
                             canzero_get_error_level_config_bat24_over_current,
                             canzero_set_error_level_bat24_over_current);

static ErrorLevelRangeCheck<EXPECT_OVER>
    link24_under_volt_check(canzero_get_link24_voltage,
                            canzero_get_error_level_config_link24_under_voltage,
                            canzero_set_error_level_link24_under_voltage);
static ErrorLevelRangeCheck<EXPECT_UNDER>
    link24_over_volt_check(canzero_get_link24_voltage,
                           canzero_get_error_level_config_link24_over_voltage,
                           canzero_set_error_level_link24_over_voltage);
static ErrorLevelRangeCheck<EXPECT_UNDER> link24_over_current_check(
    canzero_get_link24_current,
    canzero_get_error_level_config_link24_over_current,
    canzero_set_error_level_link24_over_current);

static ErrorLevelRangeCheck<EXPECT_OVER>
    link45_under_volt_check(canzero_get_link45_voltage,
                            canzero_get_error_level_config_link45_under_voltage,
                            canzero_set_error_level_link45_under_voltage);
static ErrorLevelRangeCheck<EXPECT_UNDER>
    link45_over_volt_check(canzero_get_link45_voltage,
                           canzero_get_error_level_config_link45_over_voltage,
                           canzero_set_error_level_link45_over_voltage);
static ErrorLevelRangeCheck<EXPECT_UNDER> link45_over_current_check(
    canzero_get_link45_current,
    canzero_get_error_level_config_link45_over_current,
    canzero_set_error_level_link45_over_current);

static ErrorLevelRangeCheck<EXPECT_OVER> cooling_cycle_under_pressure_check(
    canzero_get_cooling_cycle_pressure,
    canzero_get_error_level_config_cooling_cycle_under_pressure,
    canzero_set_error_level_cooling_cycle_under_pressure);
static ErrorLevelRangeCheck<EXPECT_UNDER> cooling_cycle_over_pressure_check(
    canzero_get_cooling_cycle_pressure,
    canzero_get_error_level_config_cooling_cycle_over_pressure,
    canzero_set_error_level_cooling_cycle_over_pressure);

static ErrorLevelRangeCheck<EXPECT_UNDER>
    mcu_temp_check(canzero_get_mcu_temperature,
                   canzero_get_error_level_config_mcu_temperature,
                   canzero_set_error_level_mcu_temperature);

static ErrorLevelRangeCheck<EXPECT_UNDER>
    cooling_cycle_temp_check(canzero_get_cooling_cycle_temperature,
                             canzero_get_error_level_config_cooling_temperature,
                             canzero_set_error_level_cooling_cycle_temperature);

static ErrorLevelRangeCheck<EXPECT_UNDER>
    bat24_temp_check(canzero_get_bat24_temperature,
                     canzero_get_error_level_config_bat24_temperature,
                     canzero_set_error_level_bat24_temperature);

static ErrorLevelRangeCheck<EXPECT_UNDER>
    supercap_temp_check(canzero_get_supercap_temperature,
                        canzero_get_error_level_config_supercap_temperature,
                        canzero_set_error_level_supercap_temperature);

static ErrorLevelRangeCheck<EXPECT_UNDER>
    ebox_temp_check(canzero_get_ebox_temperature,
                    canzero_get_error_level_config_ebox_temperature,
                    canzero_set_error_level_ebox_temperature);
static ErrorLevelRangeCheck<EXPECT_UNDER>
    ambient_temp_check(canzero_get_ambient_temperature,
                       canzero_get_error_level_config_ambient_temperature,
                       canzero_set_error_level_ambient_temperature);

int main() {

  canzero_set_state(input_board_state_INIT);

  canzero_init();
  defaults();

  InputBoard::begin();

  StateEstimation::begin();

  while (true) {
    canzero_set_state(input_board_state_RUNNING);
    // =============== CANzero receive from CAN =================
    canzero_can0_poll();
    canzero_can1_poll();

    // ====================== MCU Temperature ===================
    if (mcu_temp_interval.next()) {
      const Temperature mcu_temp = InputBoard::read_mcu_temperature();
      canzero_set_mcu_temperature(mcu_temp.as_celcius());
    }

    // ==================== 24V-Battery Temperature =============
    if (InputBoard::has_next<AIN_24BAT_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_24BAT_TEMP>();
      const Temperature bat24_temp = BAT24_NTC_EQ.apply(ntc_r);
      canzero_set_bat24_temperature(bat24_temp.as_celcius());
    }

    // ==================== EBOX-Temperature ====================
    if (InputBoard::has_next<AIN_EBOX_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_EBOX_TEMP>();
      const Temperature ebox_temp = EBOX_NTC_EQ.apply(ntc_r);
      canzero_set_ebox_temperature(ebox_temp.as_celcius());
    }

    // ==================== SuperCap Temperature ================
    if (InputBoard::has_next<AIN_SUPERCAP_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_SUPERCAP_TEMP>();
      const Temperature supercap_temp = SUPERCAP_NTC_EQ.apply(ntc_r);
      canzero_set_supercap_temperature(supercap_temp.as_celcius());
    }
    // ==================== Buck Converter Temperature ==========
    if (InputBoard::has_next<AIN_BUCK_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_BUCK_TEMP>();
      const Temperature buck_temp = BUCK_NTC_EQ.apply(ntc_r);
      canzero_set_buck_temperature(buck_temp.as_celcius());
    }
    // ==================== Cooling Cycle Temperature ===========
    if (InputBoard::has_next<AIN_COOLING_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_COOLING_TEMP>();
      const Temperature cooling_temp = COOLING_NTC_EQ.apply(ntc_r);
      canzero_set_cooling_cycle_temperature(cooling_temp.as_celcius());
    }
    // ==================== Ambient Temperature =================
    if (InputBoard::has_next<AIN_AMBIENT_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_AMBIENT_TEMP>();
      const Temperature ambient_temp = AMBIENT_NTC_EQ.apply(ntc_r);
      canzero_set_ambient_temperature((ambient_temp.as_celcius()));
    }

    // ==================== Cooling Pressure ====================
    if (InputBoard::has_next<AIN_COOLING_PRESSURE>()) {
      const Current i = InputBoard::read_mux<AIN_COOLING_PRESSURE>();
      // Note that we are using a bar here as the unit!
      // Therefor literals will not compare correctly because they are based on
      // Pascal (Pa)
      const Pressure p_bar = Pressure(((i - 4_mA) / 16_mA));
      canzero_set_cooling_cycle_pressure(static_cast<float>(p_bar));
    }

    // ==================== 24V Bat =============================
    if (bat24_meas_interval.next()) {
      const Voltage bat_u = InputBoard::read<AIN_BAT_VOLTAGE>();
      const Voltage bat_i_meas = InputBoard::read<AIN_BAT_CURRENT>();
      // see https://cdn-reichelt.de/documents/datenblatt/A300/ME068.pdf
      const Current bat_i = -30_A + static_cast<Current>(bat_i_meas) * 60.0f;

      canzero_set_bat24_voltage(static_cast<float>(bat_u));
      canzero_set_bat24_current(static_cast<float>(bat_i));
    }

    // ==================== 24V Link ============================
    if (link24_meas_interval.next()) {
      const Voltage link24_u = InputBoard::read<AIN_24LINK_VOLTAGE>();
      const Voltage link24_i_meas = InputBoard::read<AIN_24LINK_CURRENT>();
      // see https://cdn-reichelt.de/documents/datenblatt/A300/ME068.pdf
      const Current link24_i =
          -30_A + static_cast<Current>(link24_i_meas) * 60.0f;
      canzero_set_link24_voltage(static_cast<float>(link24_u));
      canzero_set_link24_current(static_cast<float>(link24_i));
    }

    // ==================== 45V Link =============================
    if (link45_meas_interval.next()) {
      const Voltage link45_u = InputBoard::read<AIN_45LINK_VOLTAGE>();
      const Voltage link45_i_meas = InputBoard::read<AIN_45LINK_CURRENT>();
      // see https://docs.rs-online.com/173f/0900766b8146d231.pdf
      // TODO the range is probably wrong here!!!!
      const Current link45_i =
          -300_A + static_cast<Current>(link45_i_meas) * 600.0f;
      canzero_set_link45_voltage(static_cast<float>(link45_u));
      canzero_set_link45_current(static_cast<float>(link45_i));
    }

    // ==================== State Estimation ====================
    StateEstimation::update();

    const Distance pos = StateEstimation::getPosition();
    const Velocity vel = StateEstimation::getVelocity();
    const Acceleration accel = StateEstimation::getAcceleration();
    canzero_set_position_estimation(static_cast<float>(pos));
    canzero_set_velocity_estimation(static_cast<float>(vel));
    canzero_set_acceleration_estimation(static_cast<float>(accel));

    // ================= Error-Handling & Logging ===============
    bat24_under_volt_check.check();
    bat24_over_volt_check.check();
    bat24_over_current_check.check();
    link24_under_volt_check.check();
    link24_over_volt_check.check();
    link24_over_current_check.check();
    if (canzero_get_expect_link45_online()) {
      // only check if 45V is actually expected to be online!
      link45_under_volt_check.check();
    } else {
      canzero_set_error_level_link45_under_voltage(error_level_OK);
    }
    link45_over_volt_check.check();
    link45_over_current_check.check();
    cooling_cycle_under_pressure_check.check();
    cooling_cycle_over_pressure_check.check();
    mcu_temp_check.check();
    cooling_cycle_temp_check.check();
    bat24_temp_check.check();
    supercap_temp_check.check();
    ebox_temp_check.check();
    ambient_temp_check.check();
    // ====> SDC-Status:
    // TODO some better handling is probably required here
    canzero_set_sdc_status(sdc_status_CLOSED);


    // =================== CANzero update =======================
    canzero_update_continue(canzero_get_time());
  }
}

