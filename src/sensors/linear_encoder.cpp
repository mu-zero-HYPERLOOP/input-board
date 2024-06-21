#include "sensors/linear_encoder.h"
#include "firmware/input_board.h"
#include "print.h"
#include "state_estimation.h"
#include "util/circular_queue.h"
#include <avr/pgmspace.h>
#include <cassert>

DMAMEM static volatile sensors::linear_encoder::Direction m_dir;
DMAMEM static CircularQueue<sensors::linear_encoder::LinearEncoderEvent, 16>
    m_event_queue {};

void FASTRUN back_pin_isr() {
  using namespace sensors::linear_encoder;
  debugPrintf("BACK_PIN_ISR\n");

  bool left = input_board::read_digital(PIN_BACK);
  bool right = input_board::read_digital(PIN_FRONT);
  Direction dir = static_cast<Direction>(left == right);
  assert(dir != DIRECTION_NONE);

  Timestamp now = Timestamp::now();

  if (dir == m_dir) {
    if (dir == DIRECTION_LEFT) {
      auto _lock = input_board::InterruptLock::acquire();
      m_event_queue.enqueue(LinearEncoderEvent{
          .m_tag = LinearEncoderEventTag::COUNT_DECREMENT,
          .m_timestamp = std::move(now),
      });
    } else {
      assert(dir == DIRECTION_RIGHT);
      auto _lock = input_board::InterruptLock::acquire();
      m_event_queue.enqueue(LinearEncoderEvent{
          .m_tag = LinearEncoderEventTag::COUNT_INCREMENT,
          .m_timestamp = std::move(now),
      });
    }
  } else {
    auto _lock = input_board::InterruptLock::acquire();
    m_event_queue.enqueue(LinearEncoderEvent{
        .m_tag = LinearEncoderEventTag::COUNT_NONE,
        .m_timestamp = std::move(now),
    });
  }
  m_dir = dir;
}

static void FASTRUN front_pin_isr() {
  using namespace sensors::linear_encoder;
  debugPrintf("FRONT_PIN_ISR\n");

  bool left = input_board::read_digital(PIN_BACK);
  bool right = input_board::read_digital(PIN_FRONT);
  Direction dir = static_cast<Direction>(left != right);
  assert(dir != DIRECTION_NONE);

  Timestamp now = Timestamp::now();

  if (dir == m_dir) {
    if (dir == DIRECTION_LEFT) {
      m_event_queue.enqueue(LinearEncoderEvent{
          .m_tag = LinearEncoderEventTag::COUNT_DECREMENT,
          .m_timestamp = std::move(now),
      });
    } else {
      assert(dir == DIRECTION_RIGHT);
      m_event_queue.enqueue(LinearEncoderEvent{
          .m_tag = LinearEncoderEventTag::COUNT_INCREMENT,
          .m_timestamp = std::move(now),
      });
    }
  } else {
    m_event_queue.enqueue(LinearEncoderEvent{
        .m_tag = LinearEncoderEventTag::COUNT_NONE,
        .m_timestamp = std::move(now),
    });
  }
  m_dir = dir;
}

void FASTRUN end_detection_front_isr() {
  using namespace sensors::linear_encoder;
  m_event_queue.enqueue(LinearEncoderEvent{
      .m_tag = LinearEncoderEventTag::END_DETECTION_FRONT,
      .m_timestamp = Timestamp::now(),
  });
}
void FASTRUN end_detection_back_isr() {
  using namespace sensors::linear_encoder;
  m_event_queue.enqueue(LinearEncoderEvent{
      .m_tag = LinearEncoderEventTag::END_DETECTION_BACK,
      .m_timestamp = Timestamp::now(),
  });
}

void FLASHMEM sensors::linear_encoder::begin() {
  input_board::register_exit(PIN_FRONT, input_board::ANY_EDGE, front_pin_isr);
  input_board::register_exit(PIN_BACK, input_board::ANY_EDGE, back_pin_isr);
  input_board::register_exit(PIN_END_DETECTION_FRONT, input_board::ANY_EDGE,
                             end_detection_front_isr);
  input_board::register_exit(PIN_END_DETECTION_BACK, input_board::ANY_EDGE,
                             end_detection_back_isr);
}

void PROGMEM sensors::linear_encoder::calibrate() {
  // pass
}

void FASTRUN sensors::linear_encoder::update() {
  for (unsigned int i = 0; i < 100; ++i) {
    auto lock = input_board::InterruptLock::acquire();
    std::optional<LinearEncoderEvent> event = m_event_queue.dequeue();
    lock.release();
    if (!event.has_value()) {
      return;
    }
    state_estimation::linear_encoder_update(event.value());
  }
  assert(false);
}
