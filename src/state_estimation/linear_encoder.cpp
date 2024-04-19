#include "linear_encoder.h"
#include <cassert>
#include <iostream>

/**
 * Some interessting notes here
 * the principle is really simple
 * we have 2 pins, where we attach a interrupt to one
 * when the interrupt is triggered we perform
 * left == right if this is true we are moving to the right otherwise we
 * are moving to the left.
 *
 * Now immagine, we are not moving at all, but the sensors are placed on stop of
 * a edge. this will leads to a lot of interrupts. e.g, moving left, moving
 * right, moving left moving right. For position estimation this would kind of
 * suck. Therefor it is designed with the following invariant. If we cross a
 * stripe edge from the left. we can assume that we are right from the current
 * stripe count value and if we cross it from the right we are at the left side
 * of the stripe count value.
 *
 * This is implemented by m_dir. Here we only change m_stripe_count if we move
 * at least 2 times in one direction. Therefor move left, move-right, move-left
 * would not be reflected in the stripe_count value!
 */

volatile int LinearEncoder::m_back_pin;
volatile int LinearEncoder::m_front_pin;
volatile int LinearEncoder::m_back_edge_pin;
volatile int LinearEncoder::m_front_edge_pin;
volatile int32_t LinearEncoder::m_stripe_count;
volatile LinearEncoder::Direction LinearEncoder::m_dir;
volatile Timestamp LinearEncoder::m_last_isr = Timestamp::now();
volatile Velocity LinearEncoder::m_velocity;
volatile Distance LinearEncoder::m_stride;
volatile int LinearEncoder::m_max_stripe_count;

void LinearEncoder::encoder_back_isr() {
  uint8_t left = digitalReadFast(m_back_pin);
  uint8_t right = digitalReadFast(m_front_pin);
  enum Direction dir = static_cast<enum Direction>(left == right);
  assert(dir != DIRECTION_NONE);

  Timestamp now = Timestamp::now();
  Duration delta = now - m_last_isr;
  m_last_isr = now;

  if (dir == m_dir) {
    if (dir == DIRECTION_LEFT) {
      m_stripe_count -= 1;
      m_velocity = -((m_stride * 0.5) / static_cast<Time>(delta));
    } else {
      assert(dir == DIRECTION_RIGHT);
      m_stripe_count += 1;
      m_velocity = ((m_stride * 0.5) / static_cast<Time>(delta));
    }
  } else {
    m_velocity = 0_mps;
  }
  m_dir = dir;
}

void LinearEncoder::encoder_front_isr() {
  uint8_t left = digitalReadFast(m_back_pin);
  uint8_t right = digitalReadFast(m_front_pin);
  enum Direction dir = static_cast<enum Direction>(left != right);
  assert(dir != DIRECTION_NONE);

  Timestamp now = Timestamp::now();
  Duration delta = now - m_last_isr;
  m_last_isr = now;

  if (dir == m_dir) {
    if (dir == DIRECTION_LEFT) {
      m_stripe_count -= 1;
      m_velocity = -((m_stride * 0.5) / static_cast<Time>(delta));
    } else {
      assert(dir == DIRECTION_RIGHT);
      m_stripe_count += 1;
      m_velocity = ((m_stride * 0.5) / static_cast<Time>(delta));
    }
  } else {
    m_velocity = 0_mps;
  }
  m_dir = dir;
}

void LinearEncoder::encoder_front_edge_isr() { m_stripe_count = 0; }
void LinearEncoder::encoder_back_edge_isr() {
  m_stripe_count = m_max_stripe_count;
}
