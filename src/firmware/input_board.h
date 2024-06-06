#pragma once

#include "firmware/pinout.h"
#include "util/metrics.h"
#include "util/timestamp.h"
#include <cinttypes>
#include <tuple>

namespace input_board {

void begin();

Voltage sync_read(ain_pin pin);

Voltage sync_read(mux_pin pin);

Temperature read_mcu_temperature();

void set_sdc(bool close);

void mux_select(uint8_t sel);

bool register_periodic_reading(const Time &period, ain_pin pin,
                               void (*on_value)(const Voltage &));

inline bool register_periodic_reading(const Frequency &frequency, ain_pin pin,
                                      void (*on_value)(const Voltage &)) {
  return input_board::register_periodic_reading(1.0f / frequency, pin,
                                                on_value);
}

bool register_periodic_reading(const Time &period, mux_pin pin,
                               void (*on_value)(const Voltage &));

inline bool register_periodic_reading(const Frequency &frequency, mux_pin pin,
                                      void (*on_value)(const Voltage &)) {
  return input_board::register_periodic_reading(1.0f / frequency, pin,
                                                on_value);
}

enum AccelerometerRange {
  ACCEL_RANGE_05G,
  ACCEL_RANGE_1G,
  ACCEL_RANGE_2G,
  ACCEL_RANGE_4G,
};

bool register_periodic_accelerometer_reading(
    const Frequency &frequency,
    AccelerometerRange range,
    void (*on_value)(const Acceleration &x, const Acceleration &y,
                     const Acceleration &z));

inline bool register_periodic_accelerometer_reading(
    const Time &period,
    AccelerometerRange range,
    void (*on_value)(const Acceleration &x, const Acceleration &y,
                     const Acceleration &z)) {
  return input_board::register_periodic_accelerometer_reading(1.0f / period, range,
                                                              on_value);
}

std::tuple<Acceleration, Acceleration, Acceleration> sync_read_acceleration();

void update_continue();

void delay(const Duration &ms);

enum ExtiEdge { ANY_EDGE, RISING_EDGE, FALLING_EDGE };

bool read_digital(din_pin pin);

void register_exit(din_pin pin, ExtiEdge edge, void (*on_exti)());

struct InterruptLock {
public:
  static InterruptLock acquire();
  void release();
  ~InterruptLock();
  InterruptLock(const InterruptLock &) = delete;
  InterruptLock(InterruptLock &&o) = delete;

  InterruptLock &operator=(const InterruptLock &) = delete;
  InterruptLock &operator=(InterruptLock &&o) = delete;
private:
  InterruptLock() : m_acquried(true) {}
  bool m_acquried;
};

}; // namespace input_board
