#pragma once

#include "firmware/pinout.h"
#include "util/timestamp.h"
#include <cinttypes>

namespace sensors::linear_encoder {

enum LinearEncoderEventTag {
  COUNT_INCREMENT,
  COUNT_DECREMENT,
  COUNT_NONE,
  END_DETECTION_FRONT,
  END_DETECTION_BACK,
};

struct LinearEncoderEvent {
  LinearEncoderEventTag m_tag;
  Timestamp m_timestamp;
};

enum Direction : uint8_t {
  DIRECTION_LEFT = 0,
  DIRECTION_RIGHT = 1,
  DIRECTION_NONE = 2,
};

constexpr din_pin PIN_FRONT = din_pin::din_2;
constexpr din_pin PIN_BACK = din_pin::din_3;
constexpr din_pin PIN_END_DETECTION_FRONT = din_pin::din_4;
constexpr din_pin PIN_END_DETECTION_BACK = din_pin::din_5;

void begin();

void calibrate();

void update();

}; // namespace sensors::linear_encoder
