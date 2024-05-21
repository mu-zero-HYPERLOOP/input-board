#include "sensors/mass_flow_rate.h"
#include "boxcar.h"
#include "firmware/input_board.h"
#include "util/timing.h"
#include "canzero/canzero.h"
#include <iostream>


static volatile IntervalTiming m_interval_timer(1.0);

constexpr auto VOLUME_PER_TRIG = 50_ml;

static BoxcarFilter<FlowRate, 10> filter(0_l / 1_s);
static Timestamp last_trig = Timestamp::now();

static void on_exti() {
  last_trig = Timestamp::now();
  m_interval_timer.tick();
  Frequency frequency = m_interval_timer.frequency();
  FlowRate flow_rate = VOLUME_PER_TRIG * frequency;
  filter.push(flow_rate);
  canzero_set_cooling_cycle_flow_rate(static_cast<float>(filter.get() / 1_l));
}

void sensors::mass_flow_rate::begin() {
  input_board::register_exit(PIN, input_board::FALLING_EDGE, on_exti);
}

void sensors::mass_flow_rate::calibrate() {
  // pass
}

void sensors::mass_flow_rate::update() {
  if (Timestamp::now() - last_trig > 1_s) {
    // pull value down if no exti trig for the last second.
    filter.push(0_l / 1_s);
    last_trig = last_trig + 100_ms;
    canzero_set_cooling_cycle_flow_rate(static_cast<float>(filter.get() / 1_l));
  }
}
