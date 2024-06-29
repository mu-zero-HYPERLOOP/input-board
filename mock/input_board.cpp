#include "firmware/input_board.h"
#include "canzero/canzero.h"
#include "firmware/ain_scheduler.h"
#include "firmware/mux_scheduler.h"
#include "firmware/pinout.h"
#include "print.h"
#include "sensors/accelerometer.h"
#include "sensors/ambient_temperature.h"
#include "sensors/bat24_temperature.h"
#include "sensors/bat24_voltage.h"
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <random>
#include <thread>
#include <tuple>

#include "sensors/bat24_current.h"
#include "sensors/bat24_voltage.h"
#include "sensors/buck_temperature.h"
#include "sensors/cooling_pressure.h"
#include "sensors/cooling_temperature.h"
#include "sensors/ebox_temperature.h"
#include "sensors/formulas/hall_sensors.h"
#include "sensors/formulas/isolated_voltage.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/sick_pbt.h"
#include "sensors/formulas/voltage_divider.h"
#include "sensors/linear_encoder.h"
#include "sensors/link24_current.h"
#include "sensors/supercap_voltage.h"
#include "sensors/link45_current.h"
#include "sensors/link45_voltage.h"
#include "sensors/mass_flow_rate.h"
#include "sensors/supercap_temperature.h"
#include "state_estimation.h"
#include "util/interval.h"
#include "util/timing.h"
#include <iostream>

using namespace std::chrono;

constexpr size_t MAX_AIN_PERIODIC_JOBS = 6;
constexpr size_t MAX_MUX_PERIODIC_JOBS = 16;

constexpr Acceleration G = 9.80665_mps2;

static AinScheduler<MAX_AIN_PERIODIC_JOBS> m_ain_scheduler;
static MuxScheduler<MAX_MUX_PERIODIC_JOBS> m_mux_scheduler;

static std::random_device rd{};
static std::mt19937 gen{rd()};

static std::normal_distribution mcu_temperature{35.0, 2.0};

namespace input_board {
static void set_digtal_state(din_pin pin, bool v);
static void mock_update();

time_point<high_resolution_clock> last_mux_switch;
uint8_t mux_sel = 0;

void begin() { last_mux_switch = high_resolution_clock::now(); }

static bool mux_helper(ain_pin pin, mux_pin mux_pin) {
  int mux_pin_pin = (mux_pin & MUX_PIN_MASK) >> MUX_PIN_SHR;
  int mux_pin_sel = (mux_pin & MUX_SEL_MASK) >> MUX_SEL_SHR;
  return mux_pin_pin == pin && mux_pin_sel == mux_sel;
}

Voltage sync_read(ain_pin pin) {

  if (pin == ain_pin::ain_mux || pin == ain_pin::ain_ntc_mux) {
    if (high_resolution_clock::now() - last_mux_switch <=
        MuxScheduler<MAX_MUX_PERIODIC_JOBS>::MIN_MUX_SWITCH_CHRONO_DURATION -
            1ms) {
      /* std::cout << "trying to read a pin without waiting for the mutex to
       * switch" << std::endl; */
    }
  }

  switch (pin) {
  case sensors::bat24_voltage::PIN: {
    constexpr Voltage mock = 26_V + sensors::bat24_voltage::DEFAULT_OFFSET;
    const Voltage v = sensors::formula::inv_isolated_voltage_meas(
        mock, sensors::bat24_voltage::R1, sensors::bat24_voltage::R2);
    std::normal_distribution bat24_voltage_dist{static_cast<float>(v), 0.015f};
    return Voltage(bat24_voltage_dist(gen));
  }
  case sensors::bat24_current::PIN: {
    if (canzero_get_assert_45V_system_online() == bool_t_TRUE) {
      std::normal_distribution bat24_current_dist{0.0f, 0.015f};
      const Voltage v = sensors::formula::inv_hall_effect_sensor(
          Current(bat24_current_dist(gen)),
          sensors::bat24_current::VOLT_PER_AMP,
          sensors::bat24_current::ZERO_A_READING +
              Current(canzero_get_bat24_current_calibration_offset()));
      const Voltage v_uc = sensors::formula::vout_of_voltage_divider(
          v, sensors::link24_current::R1_V_DIV,
          sensors::bat24_current::R2_V_DIV);
      return v_uc;
    } else {
      constexpr Current mock = 7.5_A;
      const Voltage v = sensors::formula::inv_hall_effect_sensor(
          mock, sensors::bat24_current::VOLT_PER_AMP,
          sensors::bat24_current::ZERO_A_READING +
              Current(canzero_get_bat24_current_calibration_offset()));
      const Voltage v_uc = sensors::formula::vout_of_voltage_divider(
          v, sensors::bat24_current::R1_V_DIV,
          sensors::bat24_current::R2_V_DIV);
      std::normal_distribution bat24_current_dist{static_cast<float>(v_uc),
                                                  0.015f};
      return Voltage(bat24_current_dist(gen));
    }
  }
  case sensors::link24_current::PIN: {
    constexpr Current mock = 7.5_A;
    const Voltage v = sensors::formula::inv_hall_effect_sensor(
        mock, sensors::link24_current::VOLT_PER_AMP,
        sensors::link24_current::ZERO_A_READING +
            Current(canzero_get_link24_current_calibration_offset()));
    const Voltage v_uc = sensors::formula::vout_of_voltage_divider(
        v, sensors::link24_current::R1_V_DIV,
        sensors::link24_current::R2_V_DIV);

    std::normal_distribution link24_current_dist{static_cast<float>(v_uc),
                                                 0.015f};
    return Voltage(link24_current_dist(gen));
  }
  case sensors::supercap_voltage::PIN: {
    constexpr Voltage mock = 45_V + sensors::supercap_voltage::DEFAULT_OFFSET;
    Voltage v = sensors::formula::inv_isolated_voltage_meas(
        mock, sensors::supercap_voltage::R1, sensors::supercap_voltage::R2);
    std::normal_distribution supercap_voltage_dist{static_cast<float>(v), 0.0001f};
    return Voltage(supercap_voltage_dist(gen));
  }
  case sensors::link45_current::PIN: {
    if (canzero_get_assert_45V_system_online() == bool_t_TRUE) {
      constexpr Current mock = 100_A;
      const Voltage v = sensors::formula::inv_hall_effect_sensor(
          mock, sensors::link45_current::VOLT_PER_AMP,
          sensors::link45_current::ZERO_A_READING +
              Current(canzero_get_link45_current_calibration_offset()));
      const Voltage v_uc = sensors::formula::vout_of_voltage_divider(
          v, sensors::link45_current::R1_V_DIV,
          sensors::link45_current::R2_V_DIV);
      std::normal_distribution link45_current_dist{static_cast<float>(v_uc),
                                                   0.015f};
      return Voltage(link45_current_dist(gen));
    } else {
      constexpr Current mock = 0_A;
      const Voltage v = sensors::formula::inv_hall_effect_sensor(
          mock, sensors::link45_current::VOLT_PER_AMP,
          sensors::link45_current::ZERO_A_READING +
              Current(canzero_get_link45_current_calibration_offset()));
      const Voltage v_uc = sensors::formula::vout_of_voltage_divider(
          v, sensors::link45_current::R1_V_DIV,
          sensors::link45_current::R2_V_DIV);
      std::normal_distribution link45_current_dist{static_cast<float>(v_uc),
                                                   0.015f};
      return Voltage(link45_current_dist(gen));
    }
  }
  case sensors::link45_voltage::PIN: {
    if (canzero_get_state() == input_board_state_RUNNING) {
      constexpr Voltage mock = 45_V;
      const Voltage v = sensors::formula::inv_isolated_voltage_meas(
          mock, sensors::link45_voltage::R1, sensors::link45_voltage::R2);
      std::normal_distribution link45_voltage_dist{static_cast<float>(v),
                                                   0.015f};
      return Voltage(link45_voltage_dist(gen));
    } else {
      constexpr Voltage mock = 0_V;
      const Voltage v = sensors::formula::inv_isolated_voltage_meas(
          mock, sensors::link45_voltage::R1, sensors::link45_voltage::R2);
      std::normal_distribution link45_voltage_dist{static_cast<float>(v),
                                                   0.015f};
      return Voltage(link45_voltage_dist(gen));
    }
  }
  case ain_pin::ain_ntc_mux:
  case ain_pin::ain_mux:
    if (mux_helper(pin, sensors::cooling_pressure::PIN)) {
      constexpr Pressure mock = 1_bar;
      constexpr Current i_mock = sensors::formula::inv_sick_pbt(mock);
      constexpr Voltage v_mock = i_mock * sensors::cooling_pressure::R_MEAS;
      std::normal_distribution dist{static_cast<float>(v_mock), 0.05f};
      return Voltage(dist(gen));
    } else if (mux_helper(pin, sensors::cooling_temperature::PIN)) {
      constexpr Temperature mock = 24_Celcius;
      const Resistance r_ntc = sensors::formula::inv_ntc_beta(
          mock, sensors::cooling_temperature::NTC_BETA,
          sensors::cooling_temperature::NTC_R_REF,
          sensors::cooling_temperature::NTC_T_REF);
      const Voltage v = sensors::formula::vout_of_voltage_divider(
          5_V, r_ntc, sensors::cooling_temperature::R_MEAS);
      std::normal_distribution dist{static_cast<float>(v), 0.1f};
      return Voltage(dist(gen));
    } else if (mux_helper(pin, sensors::ebox_temperature::PIN)) {
      constexpr Temperature mock = 24_Celcius;
      const Resistance r_ntc = sensors::formula::inv_ntc_beta(
          mock, sensors::ebox_temperature::NTC_BETA,
          sensors::ebox_temperature::NTC_R_REF,
          sensors::ebox_temperature::NTC_T_REF);
      const Voltage v = sensors::formula::vout_of_voltage_divider(
          5_V, r_ntc, sensors::ebox_temperature::R_MEAS);
      std::normal_distribution dist{static_cast<float>(v), 0.1f};
      return Voltage(dist(gen));
    } else if (mux_helper(pin, sensors::supercap_temperature::PIN)) {
      constexpr Temperature mock = 24_Celcius;
      const Resistance r_ntc = sensors::formula::inv_ntc_beta(
          mock, sensors::supercap_temperature::NTC_BETA,
          sensors::supercap_temperature::NTC_R_REF,
          sensors::supercap_temperature::NTC_T_REF);
      const Voltage v = sensors::formula::vout_of_voltage_divider(
          5_V, r_ntc, sensors::supercap_temperature::R_MEAS);
      std::normal_distribution dist{static_cast<float>(v), 0.1f};
      return Voltage(dist(gen));
    } else if (mux_helper(pin, sensors::bat24_temperature::PIN)) {
      constexpr Temperature mock = 24_Celcius;
      const Resistance r_ntc = sensors::formula::inv_ntc_beta(
          mock, sensors::bat24_temperature::NTC_BETA,
          sensors::bat24_temperature::NTC_R_REF,
          sensors::bat24_temperature::NTC_T_REF);
      const Voltage v = sensors::formula::vout_of_voltage_divider(
          5_V, r_ntc, sensors::bat24_temperature::R_MEAS);
      std::normal_distribution dist{static_cast<float>(v), 0.1f};
      return Voltage(dist(gen));
    } else if (mux_helper(pin, sensors::ambient_temperature::PIN)) {
      constexpr Temperature mock = 24_Celcius;
      const Resistance r_ntc = sensors::formula::inv_ntc_beta(
          mock, sensors::ambient_temperature::NTC_BETA,
          sensors::ambient_temperature::NTC_R_REF,
          sensors::ambient_temperature::NTC_T_REF);
      const Voltage v = sensors::formula::vout_of_voltage_divider(
          5_V, r_ntc, sensors::ambient_temperature::R_MEAS);
      std::normal_distribution dist{static_cast<float>(v), 0.1f};
      return Voltage(dist(gen));
    } else if (mux_helper(pin, sensors::buck_temperature::PIN)) {
      constexpr Temperature mock = 24_Celcius;
      const Resistance r_ntc = sensors::formula::inv_ntc_beta(
          mock, sensors::buck_temperature::NTC_BETA,
          sensors::buck_temperature::NTC_R_REF,
          sensors::buck_temperature::NTC_T_REF);
      const Voltage v = sensors::formula::vout_of_voltage_divider(
          5_V, r_ntc, sensors::buck_temperature::R_MEAS);
      std::normal_distribution dist{static_cast<float>(v), 0.1f};
      return Voltage(dist(gen));
    } else {
      return 0_V;
    }
  default:
    return 0_V;
  }
}

Voltage sync_read(mux_pin pin) { return m_mux_scheduler.sync_read(pin); }

Temperature read_mcu_temperature() {
  return Temperature(mcu_temperature(gen)) + 0_Celcius;
}

void set_sdc(bool close) {
  if (close) {
    assert(canzero_get_sdc_status() == sdc_status_CLOSED);
  } else {
    assert(canzero_get_sdc_status() == sdc_status_OPEN);
  }
}

void mux_select(uint8_t sel) {
  if (sel != mux_sel) {
    last_mux_switch = high_resolution_clock::now();
    mux_sel = sel;
  }
}

bool register_periodic_reading(const Time &period, ain_pin pin,
                               void (*on_value)(const Voltage &)) {
  return m_ain_scheduler.register_periodic(period, pin, on_value);
}

bool register_periodic_reading(const Time &period, mux_pin pin,
                               void (*on_value)(const Voltage &)) {
  return m_mux_scheduler.register_periodic(period, pin, on_value);
}

void update_continue() {
  m_ain_scheduler.update_continue();
  m_mux_scheduler.update_continue();
  mock_update();
}

void delay(const Duration &time) {
  if (time < 1_ms) {
    std::this_thread::sleep_for(
        std::chrono::duration<unsigned int, std::milli>(1));
  } else {
    std::this_thread::sleep_for(
        std::chrono::duration<unsigned int, std::milli>(time.as_ms()));
  }
}

static Interval accel_interval(0_s);
static bool enable_accel = false;
static void (*accel_callback)(const Acceleration &, const Acceleration &,
                              const Acceleration &);

bool register_periodic_accelerometer_reading(
    const Frequency &frequency, AccelerometerRange range,
    void (*on_value)(const Acceleration &x, const Acceleration &y,
                     const Acceleration &z)) {
  enable_accel = true;
  accel_interval = Interval(frequency);
  accel_callback = on_value;
  return true;
}

static constexpr float ACCEL_VARAIANCE = 0.1f;
static std::normal_distribution lateral{0.0f, ACCEL_VARAIANCE};
static std::normal_distribution vertical{static_cast<float>(G),
                                         ACCEL_VARAIANCE};

std::tuple<Acceleration, Acceleration, Acceleration> sync_read_acceleration() {

  std::normal_distribution accel{canzero_get_target_acceleration(),
                                 ACCEL_VARAIANCE};

  Acceleration fwd = Acceleration(accel(gen));
  Acceleration vert = Acceleration(vertical(gen));
  Acceleration lat = Acceleration(lateral(gen));
  switch (sensors::accelerometer::range) {
  case ACCEL_RANGE_05G:
    if (fwd >= 0.5 * G) {
      fwd = 0.5 * G;
    } else if (fwd <= -0.5 * G) {
      fwd = -0.5 * G;
    }
    if (vert >= 0.5 * G) {
      vert = 0.5 * G;
    } else if (vert <= -0.5 * G) {
      vert = -0.5 * G;
    }
    if (lat >= 0.5 * G) {
      lat = 0.5 * G;
    } else if (lat <= -0.5 * G) {
      lat = -0.5 * G;
    }
    break;
  case ACCEL_RANGE_1G:
    if (fwd >= G) {
      fwd = G;
    } else if (fwd <= -G) {
      fwd = -G;
    }
    if (vert >= G) {
      vert = G;
    } else if (vert <= -G) {
      vert = -G;
    }
    if (lat >= G) {
      lat = G;
    } else if (lat <= -G) {
      lat = -G;
    }
    break;
  case ACCEL_RANGE_2G:
    if (fwd >= 2 * G) {
      fwd = 2 * G;
    } else if (fwd <= -2 * G) {
      fwd = -2 * G;
    }
    if (vert >= 2 * G) {
      vert = 2 * G;
    } else if (vert <= -2 * G) {
      vert = -2 * G;
    }
    if (lat >= 2 * G) {
      lat = 2 * G;
    } else if (lat <= -2 * G) {
      lat = -2 * G;
    }
    break;
  case ACCEL_RANGE_4G:
    if (fwd >= 4 * G) {
      fwd = 4 * G;
    } else if (fwd <= -4 * G) {
      fwd = -4 * G;
    }
    if (vert >= 4 * G) {
      vert = 4 * G;
    } else if (vert <= -4 * G) {
      vert = -4 * G;
    }
    if (lat >= 4 * G) {
      lat = 4 * G;
    } else if (lat <= -4 * G) {
      lat = -4 * G;
    }
    break;
  }

  return std::make_tuple(fwd, vert, lat);
}

std::tuple<Acceleration, Acceleration, Acceleration> sync_read_acceleration();

static std::array<bool, din_COUNT> digital_states;
struct ExtiMock {
  bool m_active = false;
  ExtiEdge m_edge = ANY_EDGE;
  void (*m_on_exti)() = nullptr;
};
static std::array<ExtiMock, din_COUNT> exti_mocks;

static void set_digtal_state(din_pin pin, bool v) {
  if (digital_states[pin] != v) {
    bool trig_exti = false;
    if (exti_mocks[pin].m_active) {
      if (digital_states[pin] && !v &&
          (exti_mocks[pin].m_edge == ANY_EDGE ||
           exti_mocks[pin].m_edge == FALLING_EDGE)) {
        trig_exti = true;
      }
      if (!digital_states[pin] && v &&
          (exti_mocks[pin].m_edge == ANY_EDGE ||
           exti_mocks[pin].m_edge == RISING_EDGE)) {
        trig_exti = true;
      }
    }
    digital_states[pin] = v;
    if (trig_exti && exti_mocks[pin].m_on_exti != nullptr) {
      exti_mocks[pin].m_on_exti();
    }
  }
}

input_board::InterruptLock input_board::InterruptLock::acquire() {
  return InterruptLock();
}

void input_board::InterruptLock::release() {}
input_board::InterruptLock::~InterruptLock() {}

bool read_digital(din_pin pin) { return digital_states[pin]; }

void register_exit(din_pin pin, ExtiEdge edge, void (*on_exti)()) {
  exti_mocks[pin].m_active = true;
  exti_mocks[pin].m_edge = edge;
  exti_mocks[pin].m_on_exti = on_exti;
}

Interval m_mass_flow_interval(100_Hz);

static Distance position = 0_m;
static Velocity velocity = 0_mps;
static IntervalTiming mock_interval_timing(1.0f);

void mock_position() {
  mock_interval_timing.tick();
  Time dt = mock_interval_timing.period();

  constexpr size_t STEP_COUNT = 1;
  for (unsigned int i = 0; i < STEP_COUNT; ++i) {
    if (canzero_get_pod_grounded()) {
      velocity = 0_mps;
    } else {
      velocity +=
          Acceleration(canzero_get_target_acceleration()) * dt / STEP_COUNT;
      if (velocity > 3_mps) {
        velocity = 3_mps;
      }
    }
    position += velocity * dt / STEP_COUNT;

    int stripes_front = std::floor(position / state_estimation::STRIPE_STRIDE);
    set_digtal_state(sensors::linear_encoder::PIN_FRONT,
                     stripes_front % 2 != 0);

    int stripes_back =
        std::floor((position + state_estimation::STRIPE_STRIDE * 0.25) /
                   state_estimation::STRIPE_STRIDE);
    set_digtal_state(sensors::linear_encoder::PIN_BACK, stripes_back % 2 == 0);
  }
}

void mock_update() {
  if (m_mass_flow_interval.next()) {
    set_digtal_state(sensors::mass_flow_rate::PIN,
                     !read_digital(sensors::mass_flow_rate::PIN));
  }
  mock_position();
  if (enable_accel && accel_interval.next()) {

    const auto &[x, y, z] = sync_read_acceleration();
    accel_callback(x, y, z);
  }
}

}; // namespace input_board
