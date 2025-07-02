#include "./cooling_flowrate.h"
#include "canzero/canzero.h"
#include "firmware/input_board.h"
#include "util/metrics.h"
#include "util/timing.h"


IntervalTiming beginTiming;
IntervalTiming endTiming;

Timestamp lastBeginInterrupt;
Timestamp lastEndInterrupt;

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
    beginTiming.reset();
    beginFlowRate = 0.0f;
  }
  if (timeSinceLastEndInterrupt > 3_s) {
    endTiming.reset();
    endFlowRate = 0.0f;
  }

  canzero_set_cooling_flow_rate_begin(beginFlowRate);
  canzero_set_cooling_flow_rate_end(endFlowRate);

  float diff = std::abs(beginFlowRate - endFlowRate);
  bool mismatch = diff > 30;
  canzero_set_error_cooling_flow_rate_mismatch(mismatch ? error_flag_ERROR : error_flag_OK);


  canzero_set_error_cooling_flow_rate_low(error_flag_OK);
}

