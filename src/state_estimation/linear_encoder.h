#pragma once

#include "util/metrics.h"
#include "util/timestamp.h"
#include <Arduino.h>

struct LinearEncoderBeginInfo {
  int back_pin;
  int front_pin;
  int back_edge_pin;
  int front_edge_pin;
  int stripe_count;
  Distance stride;
};

struct LinearEncoder {
private:
  enum Direction : uint8_t {
    DIRECTION_LEFT = 0,
    DIRECTION_RIGHT = 1,
    DIRECTION_NONE = 2,
  };
  LinearEncoder() = delete;

public:
  static inline void begin(const LinearEncoderBeginInfo &beginInfo) {
    m_back_pin = beginInfo.back_pin;
    m_front_pin = beginInfo.front_pin;
    m_front_edge_pin = beginInfo.front_edge_pin;
    m_back_edge_pin = beginInfo.back_edge_pin;
    m_stride = beginInfo.stride;
    m_max_stripe_count = beginInfo.stripe_count;

    pinMode(m_back_pin, INPUT_PULLDOWN);
    attachInterrupt(m_back_pin, LinearEncoder::encoder_back_isr, CHANGE);

    pinMode(m_front_pin, INPUT_PULLDOWN);
    attachInterrupt(m_front_pin, LinearEncoder::encoder_front_isr, CHANGE);

    pinMode(m_front_edge_pin, INPUT_PULLDOWN);
    attachInterrupt(m_front_edge_pin, LinearEncoder::encoder_front_edge_isr,
                    CHANGE);

    pinMode(m_front_pin, INPUT_PULLDOWN);
    attachInterrupt(m_front_pin, LinearEncoder::encoder_front_isr, CHANGE);

    pinMode(m_back_edge_pin, INPUT_PULLDOWN);
    attachInterrupt(m_back_edge_pin, LinearEncoder::encoder_front_edge_isr,
                    CHANGE);

    m_stripe_count = 0;
    m_dir = DIRECTION_NONE;
    m_last_isr = Timestamp::now();
  }

  static inline void reset(uint16_t stripe_count = 0) {
    m_stripe_count = stripe_count;
    m_dir = DIRECTION_NONE;
    m_velocity = 0_mps;
    m_last_isr = Timestamp::now();
  }

  static inline int32_t stripe_count() { return m_stripe_count; }

  static inline Distance position() {
    return m_stride * static_cast<float>(m_stripe_count) / 2.0;
  }

  static inline Velocity velocity() { return m_velocity; }

  static inline Direction direction() { return m_dir; }
  static inline Timestamp last_isr() { return m_last_isr; }

private:
  static void encoder_back_isr();
  static void encoder_front_isr();

  static void encoder_front_edge_isr();
  static void encoder_back_edge_isr();

  static volatile int m_back_pin;
  static volatile int m_front_pin;
  static volatile int m_back_edge_pin;
  static volatile int m_front_edge_pin;
  static volatile int32_t m_stripe_count;
  static volatile enum Direction m_dir;
  static volatile Timestamp m_last_isr;
  static volatile Velocity m_velocity;
  static volatile Distance m_stride;
  static volatile int m_max_stripe_count;
};
