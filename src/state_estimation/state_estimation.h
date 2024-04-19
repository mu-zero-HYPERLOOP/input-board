#pragma once
#include "util/metrics.h"
#include "util/timestamp.h"

class StateEstimation {
public:
  static void begin();
  static void update();
  static Distance getPosition();
  static Velocity getVelocity();
  static Acceleration getAcceleration();

private:
  StateEstimation() = delete;
  static void position_update(const Distance& pos, const Timestamp& timstamp);
  static void acceleration_update(const Acceleration& acc, const Timestamp& timestamp);
};
