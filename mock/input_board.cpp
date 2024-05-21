#include "firmware/input_board.h"
#include "canzero/canzero.h"
#include "firmware/ain_scheduler.h"
#include "firmware/mux_scheduler.h"
#include "firmware/pinout.h"
#include "sensors/bat24_voltage.h"
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <random>
#include <thread>
#include <tuple>

#include "sensors/bat24_current.h"
#include "sensors/bat24_voltage.h"
#include "sensors/cooling_pressure.h"
#include "sensors/formulas/hall_sensors.h"
#include "sensors/formulas/isolated_voltage.h"
#include "sensors/linear_encoder.h"
#include "sensors/link24_current.h"
#include "sensors/link24_voltage.h"
#include "sensors/link45_current.h"
#include "sensors/link45_voltage.h"
#include "sensors/mass_flow_rate.h"
#include "state_estimation.h"
#include "util/interval.h"
#include "util/timing.h"

using namespace std::chrono;

constexpr size_t MAX_AIN_PERIODIC_JOBS = 6;
constexpr size_t MAX_MUX_PERIODIC_JOBS = 16;

static AinScheduler<MAX_AIN_PERIODIC_JOBS> m_ain_scheduler;
static MuxScheduler<MAX_MUX_PERIODIC_JOBS> m_mux_scheduler;

static std::random_device rd{};
static std::mt19937 gen{rd()};

static std::normal_distribution cooling_pressure{0.75, 0.005};

static std::normal_distribution mcu_temperature{24.15 + 273.15, 1.0};

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
    assert(high_resolution_clock::now() - last_mux_switch >=
           MuxScheduler<MAX_MUX_PERIODIC_JOBS>::MIN_MUX_SWITCH_CHRONO_DURATION);
  }

  switch (pin) {
  case sensors::bat24_voltage::PIN: {
    constexpr Voltage mock = 24_V;
    Voltage v = sensors::formula::inv_isolated_voltage_meas(
        mock, sensors::bat24_voltage::R1, sensors::bat24_voltage::R2);
    std::normal_distribution bat24_voltage_dist{static_cast<float>(v), 0.015f};
    return Voltage(bat24_voltage_dist(gen));
  }
  case sensors::bat24_current::PIN: {
    if (canzero_get_assert_45V_system_online() == bool_t_TRUE) {
      std::normal_distribution bat24_current_dist{0.0f, 0.015f};
      return Voltage(bat24_current_dist(gen));
    } else {
      constexpr Current mock = 7.5_A;
      Voltage v = sensors::formula::inv_hall_effect_sensor(
          mock, sensors::bat24_current::VOLT_PER_AMP,
          Current(canzero_get_bat24_current_calibration_offset()));

      std::normal_distribution bat24_current_dist{static_cast<float>(v),
                                                  0.015f};
      return Voltage(bat24_current_dist(gen));
    }
  }
  case sensors::link24_current::PIN: {
    constexpr Current mock = 7.5_A;
    Voltage v = sensors::formula::inv_hall_effect_sensor(
        mock, sensors::link24_current::VOLT_PER_AMP,
        Current(canzero_get_link24_current_calibration_offset()));

    std::normal_distribution link24_current_dist{static_cast<float>(v), 0.015f};
    return Voltage(link24_current_dist(gen));
  }
  case sensors::link24_voltage::PIN: {
    constexpr Voltage mock = 24_V;
    Voltage v = sensors::formula::inv_isolated_voltage_meas(
        mock, sensors::link24_voltage::R1, sensors::link24_voltage::R2);
    std::normal_distribution link24_voltage_dist{static_cast<float>(v), 0.015f};
    return Voltage(link24_voltage_dist(gen));
  }
  case sensors::link45_current::PIN: {
    constexpr Current mock = 7.5_A;
    Voltage v = sensors::formula::inv_hall_effect_sensor(
        mock, sensors::link45_current::VOLT_PER_AMP,
        Current(canzero_get_link45_current_calibration_offset()));

    std::normal_distribution link45_current_dist{static_cast<float>(v), 0.015f};
    return Voltage(link45_current_dist(gen));
  }
  case sensors::link45_voltage::PIN: {
    if (canzero_get_assert_45V_system_online() == bool_t_TRUE) {
      constexpr Voltage mock = 45_V;
      Voltage v = sensors::formula::inv_isolated_voltage_meas(
          mock, sensors::link45_voltage::R1, sensors::link45_voltage::R2);
      std::normal_distribution link45_voltage_dist{static_cast<float>(v),
                                                   0.015f};
      return Voltage(link45_voltage_dist(gen));
    } else {
      std::normal_distribution link45_voltage_dist{0.0f, 0.015f};
      return Voltage(link45_voltage_dist(gen));
    }
  }
  case ain_pin::ain_ntc_mux:
  case ain_pin::ain_mux:
    if (mux_helper(pin, sensors::cooling_pressure::PIN)) {
      return Voltage(cooling_pressure(gen));
    } else {
      return 0_V;
    }
  default:
    return 0_V;
  }
}

Voltage sync_read(mux_pin pin) { return m_mux_scheduler.sync_read(pin); }

Temperature read_mcu_temperature() { return Temperature(mcu_temperature(gen)); }

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
    const Frequency &frequency,
    AccelerometerRange range,
    void (*on_value)(const Acceleration &x, const Acceleration &y,
                     const Acceleration &z)) {
  enable_accel = true;
  accel_interval = Interval(frequency);
  accel_callback = on_value;
  return true;
}

static std::normal_distribution lateral{0.0f, 0.1f};
static std::normal_distribution vertical{0.0f, 0.1f};

std::tuple<Acceleration, Acceleration, Acceleration> sync_read_acceleration() {

  std::normal_distribution accel{canzero_get_target_acceleration(), 0.1f};

  return std::make_tuple(Acceleration(accel(gen)), Acceleration(vertical(gen)),
                         Acceleration(lateral(gen)));
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
    /* std::cout << "calling exti: " << pin << std::endl; */
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
    velocity +=
        Acceleration(canzero_get_target_acceleration()) * dt / STEP_COUNT;
    if (velocity > 3_mps) {
      velocity = 3_mps;
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
    std::normal_distribution accel{canzero_get_target_acceleration(), 0.1f};
    accel_callback(Acceleration(accel(gen)), Acceleration(vertical(gen)),
                   Acceleration(lateral(gen)));
  }
}

}; // namespace input_board
