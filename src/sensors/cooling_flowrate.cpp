#include "./cooling_flowrate.h"
#include "canzero/canzero.h"
#include "firmware/input_board.h"
#include "util/metrics.h"
#include "util/timing.h"


IntervalTiming beginTiming;
IntervalTiming endTiming;

Timestamp lastBeginInterrupt;
Timestamp lastEndInterrupt;

const auto& rpmT = sensors::cooling_flowrate::rpmTable;
const auto& lphT = sensors::cooling_flowrate::lphTable;
const int size = sensors::cooling_flowrate::tableSize;

void on_flow_rate_begin_edge() {
  beginTiming.tick();
  lastBeginInterrupt = Timestamp::now();
}

void on_flow_rate_end_edge() {
  endTiming.tick();
  lastEndInterrupt = Timestamp::now();
}


void sensors::cooling_flowrate::begin() {
  input_board::register_exit(FLOW_RATE_BEGIN_PIN, input_board::ExtiEdge::ANY_EDGE, on_flow_rate_begin_edge);
  input_board::register_exit(FLOW_RATE_END_PIN, input_board::ExtiEdge::ANY_EDGE, on_flow_rate_end_edge);
}

float frequencyToFlowRate(Frequency frequency) {
  unsigned long rpm = static_cast<unsigned long>(static_cast<float>(frequency) * 60);

  if (rpm <= rpmT[0]) return static_cast<float> (lphT[0]);
  if (rpm >= rpmT[size - 1]) return static_cast<float>(lphT[size - 1]);

  for (int i = 0; i < size - 1; i++) {
    if (rpmT[i] <= rpm && rpm < rpmT[i + 1]) {
      float slope = (float)(lphT[i + 1] - lphT[i]) / (rpmT[i + 1] - rpmT[i]);
      return static_cast<float>(lphT[i] + slope * (rpm - rpmT[i]));
    }
  }

  return 0.0f;
}

void sensors::cooling_flowrate::update() {
  Frequency beginFrequency = beginTiming.frequency();
  Frequency endFrequency = endTiming.frequency();

  Duration timeSinceLastBeginInterrupt = Timestamp::now() - lastBeginInterrupt;
  Duration timeSinceLastEndInterrupt = Timestamp::now() - lastEndInterrupt;
  

  float beginFlowRate = frequencyToFlowRate(beginFrequency);
  float endFlowRate = frequencyToFlowRate(endFrequency);
  if (timeSinceLastBeginInterrupt > 3_s) {
    // beginTiming.reset();
    beginFlowRate = 0.0f;
  }
  if (timeSinceLastEndInterrupt > 3_s) {
    // endTiming.reset();
    endFlowRate = 0.0f;
  }

  canzero_set_cooling_flow_rate_begin(beginFlowRate);
  canzero_set_cooling_flow_rate_end(endFlowRate);

  float diff = std::abs(beginFlowRate - endFlowRate);
  bool mismatch = diff > 30;
  canzero_set_error_cooling_flow_rate_mismatch(mismatch ? error_flag_ERROR : error_flag_OK);


  canzero_set_error_cooling_flow_rate_low(error_flag_OK);
}

