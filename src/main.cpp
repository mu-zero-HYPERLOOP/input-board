/**
 * @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

#include "canzero/canzero.h"
#include "core_pins.h"
#include "firmware/input_board.h"
#include "firmware/input_board_config.h"
#include "state_estimation/state_estimation.h"
#include "util/ema.hpp"
#include "util/interval.h"
#include "util/metrics.h"
#include "util/ntc_eq.h"
#include "util/timeout.h"

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

Temperature steinhart_equation(const Resistance ntc_r, const float A,
                               const float B, const float C, const float D) {
  const float ln_r = log(static_cast<float>(ntc_r));
  const float ln2_r = ln_r * ln_r;
  return Temperature(1.0f / (A + B * ln_r + C * ln2_r + D * ln2_r * ln_r));
}

int main() {

  Frequency f = 1_Hz;
  /* Duration x = 1.0f / f; */

  canzero_set_state(input_board_state_INIT);
  canzero_init();

  InputBoard::begin();

  StateEstimation::begin();

  Interval mcu_temp_interval = Interval(10_Hz);
  Timeout mcu_over_temp_warn_timeout =
      Timeout(canzero_get_warn_mcu_over_temperature_timeout());
  Timeout mcu_over_temp_error_timeout =
      Timeout(canzero_get_error_mcu_over_temperature_timeout());

  Interval bat24_meas_interval = Interval(100_Hz);
  Interval link24_meas_interval = Interval(100_Hz);
  Interval link45_meas_interval = Interval(100_Hz);

  Timeout bat24_over_temp_error_timeout =
      Timeout(canzero_get_error_bat24_over_temperature_timeout());
  Timeout bat24_over_temp_warn_timeout =
      Timeout(canzero_get_warn_bat24_over_temperature_timeout());

  Timeout ebox_over_temp_error_timeout =
      Timeout(canzero_get_error_ebox_over_temperature_timeout());
  Timeout ebox_over_temp_warn_timeout =
      Timeout(canzero_get_warn_ebox_over_temperature_timeout());

  Timeout supercap_over_temp_error_timeout =
      Timeout(canzero_get_error_supercap_over_temperature_timeout());
  Timeout supercap_over_temp_warn_timeout =
      Timeout(canzero_get_warn_supercap_over_temperature_timeout());

  Timeout buck_over_temp_error_timeout =
      Timeout(canzero_get_error_buck_over_temperature_timeout());
  Timeout buck_over_temp_warn_timeout =
      Timeout(canzero_get_warn_buck_over_temperature_timeout());

  Timeout cooling_over_temp_error_timeout =
      Timeout(canzero_get_error_cooling_cycle_over_temperature_timeout());
  Timeout cooling_over_temp_warn_timeout =
      Timeout(canzero_get_warn_cooling_cycle_over_temperature_timeout());

  Timeout ambient_over_temp_error_timeout =
      Timeout(canzero_get_error_ambient_over_temperature_timeout());
  Timeout ambient_over_temp_warn_timeout =
      Timeout(canzero_get_warn_ambient_over_temperature_timeout());

  Timeout cooling_over_pressure_error_timeout =
      Timeout(canzero_get_error_cooling_cycle_over_pressure_timeout());
  Timeout cooling_over_pressure_warn_timeout =
      Timeout(canzero_get_warn_cooling_cycle_over_pressure_timeout());
  Timeout cooling_low_pressure_error_timeout =
      Timeout(canzero_get_error_cooling_cycle_low_pressure_timeout());
  Timeout cooling_low_pressure_warn_timeout =
      Timeout(canzero_get_warn_cooling_cycle_low_pressure_timeout());

  while (true) {
    const Timestamp now = Timestamp::now();

    canzero_can0_poll();
    canzero_can1_poll();

    // ====================   MCU Temperature ===================
    if (mcu_temp_interval.next()) {
      float mcu_temp = static_cast<float>(InputBoard::read_mcu_temperature()) +
                       273.15; // convert to °C
      canzero_set_mcu_temperature(mcu_temp);
      if (mcu_temp < canzero_get_warn_mcu_over_temperature_thresh()) {
        mcu_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_mcu_over_temperature(
          mcu_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                 : error_flag_OK);

      if (mcu_temp < canzero_get_error_mcu_over_temperature_thresh()) {
        mcu_over_temp_error_timeout.reset();
      }
      canzero_set_error_mcu_over_temperature(
          mcu_over_temp_error_timeout.timed_out() ? error_flag_ERROR
                                                  : error_flag_OK);
    }

    // ==================== 24V-Battery Temperature ==========
    if (InputBoard::has_next<AIN_24BAT_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_24BAT_TEMP>();
      const Temperature bat24_temp = BAT24_NTC_EQ.apply(ntc_r);
      canzero_set_bat24_temperature(static_cast<float>(bat24_temp) + 273.15f);
      if (bat24_temp < Temperature::from_celcius(
                           canzero_get_error_bat24_over_temperature_thresh())) {
        bat24_over_temp_error_timeout.reset();
      }
      canzero_set_error_bat24_over_temperature(
          bat24_over_temp_error_timeout.timed_out() ? error_flag_ERROR
                                                    : error_flag_OK);
      if (bat24_temp < Temperature::from_celcius(
                           canzero_get_warn_bat24_over_temperature_thresh())) {
        bat24_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_bat24_over_temperature(
          bat24_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                   : error_flag_OK);
    }

    // ==================== EBOX-Temperature ==================
    if (InputBoard::has_next<AIN_EBOX_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_EBOX_TEMP>();
      const Temperature ebox_temp = EBOX_NTC_EQ.apply(ntc_r);
      canzero_set_ebox_temperature(static_cast<float>(ebox_temp) + 273.15f);
      if (ebox_temp < Temperature::from_celcius(
                          canzero_get_error_ebox_over_temperature_thresh())) {
        ebox_over_temp_error_timeout.reset();
      }
      canzero_set_error_ebox_over_temperature(
          ebox_over_temp_error_timeout.timed_out() ? error_flag_ERROR
                                                   : error_flag_OK);
      if (ebox_temp < Temperature::from_celcius(
                          canzero_get_warn_ebox_over_temperature_thresh())) {
        ebox_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_ebox_over_temperature(
          ebox_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                  : error_flag_OK);
    }

    // ==================== SuperCap Temperature ==============
    if (InputBoard::has_next<AIN_SUPERCAP_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_SUPERCAP_TEMP>();
      const Temperature supercap_temp = SUPERCAP_NTC_EQ.apply(ntc_r);
      canzero_set_supercap_temperature(static_cast<float>(supercap_temp) +
                                       273.15f);
      if (supercap_temp <
          Temperature::from_celcius(
              canzero_get_error_supercap_over_temperature_thresh())) {
        supercap_over_temp_error_timeout.reset();
      }
      canzero_set_error_supercap_over_temperature(
          supercap_over_temp_error_timeout.timed_out() ? error_flag_ERROR
                                                       : error_flag_OK);
      if (supercap_temp <
          Temperature::from_celcius(
              canzero_get_warn_supercap_over_temperature_thresh())) {
        supercap_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_supercap_over_temperature(
          supercap_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                      : error_flag_OK);
    }
    // ==================== Buck Converter Temperature ========
    if (InputBoard::has_next<AIN_BUCK_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_BUCK_TEMP>();
      const Temperature buck_temp = BUCK_NTC_EQ.apply(ntc_r);
      canzero_set_buck_temperature(static_cast<float>(buck_temp) + 273.15f);
      if (buck_temp < Temperature::from_celcius(
                          canzero_get_error_buck_over_temperature_thresh())) {
        buck_over_temp_error_timeout.reset();
      }
      canzero_set_error_buck_over_temperature(
          buck_over_temp_error_timeout.timed_out() ? error_flag_ERROR
                                                   : error_flag_OK);
      if (buck_temp < Temperature::from_celcius(
                          canzero_get_warn_buck_over_temperature_thresh())) {
        buck_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_buck_over_temperature(
          buck_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                  : error_flag_OK);
    }
    // ==================== Cooling Cycle Temperature =========
    if (InputBoard::has_next<AIN_COOLING_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_COOLING_TEMP>();
      const Temperature cooling_temp = COOLING_NTC_EQ.apply(ntc_r);
      canzero_set_cooling_cycle_temperature(static_cast<float>(cooling_temp) +
                                            273.15f);
      if (cooling_temp <
          Temperature::from_celcius(
              canzero_get_error_cooling_cycle_over_temperature_thresh())) {
        cooling_over_temp_error_timeout.reset();
      }
      canzero_set_error_cooling_cycle_over_temperature(
          cooling_over_temp_error_timeout.timed_out() ? error_flag_ERROR
                                                      : error_flag_OK);
      if (cooling_temp <
          Temperature::from_celcius(
              canzero_get_warn_cooling_cycle_over_temperature_thresh())) {
        cooling_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_cooling_cycle_over_temperature(
          cooling_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                     : error_flag_OK);
    }
    // ==================== Ambient Temperature ===============
    if (InputBoard::has_next<AIN_AMBIENT_TEMP>()) {
      const Resistance ntc_r = InputBoard::read_mux<AIN_AMBIENT_TEMP>();
      const Temperature ambient_temp = AMBIENT_NTC_EQ.apply(ntc_r);
      canzero_set_ambient_temperature(static_cast<float>(ambient_temp) +
                                      273.15f);
      if (ambient_temp <
          Temperature::from_celcius(
              canzero_get_error_ambient_over_temperature_thresh())) {
        ambient_over_temp_error_timeout.reset();
      }
      canzero_set_error_ambient_over_temperature(
          ambient_over_temp_error_timeout.timed_out() ? error_flag_ERROR
                                                      : error_flag_OK);
      if (ambient_temp <
          Temperature::from_celcius(
              canzero_get_warn_ambient_over_temperature_thresh())) {
        ambient_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_ambient_over_temperature(
          ambient_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                     : error_flag_OK);
    }

    // ==================== Cooling Pressure ==================
    if (InputBoard::has_next<AIN_COOLING_PRESSURE>()) {
      const Current i = InputBoard::read_mux<AIN_COOLING_PRESSURE>();
      // Note that we are using a bar here as the unit!
      // Therefor literals will not compare correctly because they are based on
      // Pascal (Pa)
      const Pressure p_bar = Pressure(((i - 4_mA) / 16_mA));
      canzero_set_cooling_cycle_pressure(static_cast<float>(p_bar));
      if (p_bar <
          Pressure(canzero_get_error_cooling_cycle_over_pressure_thresh())) {
        cooling_over_pressure_error_timeout.reset();
      }
      canzero_set_error_cooling_cycle_over_pressure(
          cooling_over_pressure_error_timeout.timed_out() ? error_flag_ERROR
                                                          : error_flag_OK);
      if (p_bar >
          Pressure(canzero_get_error_cooling_cycle_low_pressure_thresh())) {
        cooling_low_pressure_error_timeout.reset();
      }
      canzero_set_error_cooling_cycle_low_pressure(
          cooling_low_pressure_error_timeout.timed_out() ? error_flag_ERROR
                                                         : error_flag_OK);
      if (p_bar <
          Pressure(canzero_get_warn_cooling_cycle_over_pressure_thresh())) {
        cooling_over_temp_warn_timeout.reset();
      }
      canzero_set_warn_cooling_cycle_over_pressure(
          cooling_over_temp_warn_timeout.timed_out() ? error_flag_ERROR
                                                     : error_flag_OK);
      if (p_bar >
          Pressure(canzero_get_warn_cooling_cycle_low_pressure_thresh())) {
        cooling_low_pressure_warn_timeout.reset();
      }
      canzero_set_warn_cooling_cycle_low_pressure(
          cooling_low_pressure_warn_timeout.timed_out() ? error_flag_ERROR
                                                        : error_flag_OK);
    }

    // ==================== 24V Bat ===========================
    if (bat24_meas_interval.next()) {
      const Voltage bat_u = InputBoard::read<AIN_BAT_VOLTAGE>();
      const Voltage bat_i_meas = InputBoard::read<AIN_BAT_CURRENT>();
      // see https://cdn-reichelt.de/documents/datenblatt/A300/ME068.pdf
      const Current bat_i = -30_A + static_cast<Current>(bat_i_meas) * 60.0f;

      canzero_set_bat24_voltage(static_cast<float>(bat_u));
      canzero_set_bat24_current(static_cast<float>(bat_i));

      canzero_set_error_bat24_over_volt(
          bat_u >= Voltage(canzero_get_error_bat24_over_volt_thresh())
              ? error_flag_ERROR
              : error_flag_OK);
      canzero_set_warn_bat24_over_volt(
          bat_u >= Voltage(canzero_get_warn_bat24_over_volt_thresh())
              ? error_flag_ERROR
              : error_flag_OK);

      canzero_set_error_bat24_under_volt(
          bat_u <= Voltage(canzero_get_error_bat24_under_volt_thresh())
              ? error_flag_ERROR
              : error_flag_OK);
      canzero_set_warn_bat24_under_volt(
          bat_u <= Voltage(canzero_get_warn_bat24_under_volt_thresh())
              ? error_flag_ERROR
              : error_flag_OK);

      canzero_set_error_bat24_over_current(
          bat_i >= Current(canzero_get_error_bat24_over_current_thresh())
              ? error_flag_ERROR
              : error_flag_OK);
      canzero_set_warn_bat24_over_current(
          bat_i >= Current(canzero_get_warn_bat24_over_current_thresh())
              ? error_flag_ERROR
              : error_flag_OK);
    }

    // ==================== 24V Link ==========================
    if (link24_meas_interval.next()) {
      const Voltage link24_u = InputBoard::read<AIN_24LINK_VOLTAGE>();
      const Voltage link24_i_meas = InputBoard::read<AIN_24LINK_CURRENT>();
      // see https://cdn-reichelt.de/documents/datenblatt/A300/ME068.pdf
      const Current link24_i =
          -30_A + static_cast<Current>(link24_i_meas) * 60.0f;
      canzero_set_link24_voltage(static_cast<float>(link24_u));
      canzero_set_link24_current(static_cast<float>(link24_i));
    }

    // ==================== 45V Link ==========================
    if (link45_meas_interval.next()) {
      const Voltage link45_u = InputBoard::read<AIN_45LINK_VOLTAGE>();
      const Voltage link45_i_meas = InputBoard::read<AIN_45LINK_CURRENT>();
      // see https://docs.rs-online.com/173f/0900766b8146d231.pdf
      const Current link45_i = 0_A; // <-- TODO
      canzero_set_link45_voltage(static_cast<float>(link45_u));
      canzero_set_link45_current(static_cast<float>(link45_i));
    }

    // ==================== State Estimation ==================
    StateEstimation::update();

    const Distance pos = StateEstimation::getPosition();
    const Velocity vel = StateEstimation::getVelocity();
    const Acceleration accel = StateEstimation::getAcceleration();
    canzero_set_position_estimation(static_cast<float>(pos));
    canzero_set_velocity_estimation(static_cast<float>(vel));
    canzero_set_acceleration_estimation(static_cast<float>(accel));

    // -- Error handling (State estimation)
    canzero_set_error_invalid_position(
        (pos < 0_m || pos > Distance(canzero_get_track_length()))
            ? error_flag_ERROR
            : error_flag_OK);
    /*
    0.5 * v²/a_brake is the brake distance
    (derived from the integral of v(t) = v0 - at)
    */
    Distance min_brake_distance = 0.5 * (vel * vel) / 1_mps2; // signed value!
    if (vel < 0_mps) {
      min_brake_distance = -min_brake_distance;
    }
    Distance expected_stop = pos + min_brake_distance;
    canzero_set_error_invalid_velocity_profile(
        expected_stop < 0_m ||
                expected_stop > Distance(canzero_get_track_length())
            ? error_flag_ERROR
            : error_flag_OK);

    canzero_set_error_invalid_acceleration(
        accel.abs() > 10_mps2 ? error_flag_ERROR : error_flag_OK);

    canzero_update_continue(canzero_get_time());

    canzero_set_state(input_board_state_RUNNING);
  }
}
