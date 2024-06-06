#include "sensors/mass_flow_rate.h"
#include "boxcar.h"
#include "firmware/input_board.h"
#include "util/timing.h"
#include "canzero/canzero.h"
#include <avr/pgmspace.h>


static volatile DMAMEM IntervalTiming m_interval_timer(1.0);

constexpr auto VOLUME_PER_TRIG = 1_l / 553;

static DMAMEM BoxcarFilter<FlowRate, 10> filter(0_l / 1_s);
static DMAMEM Timestamp last_trig = Timestamp::now();

static void FASTRUN on_exti() {
  last_trig = Timestamp::now();
  m_interval_timer.tick();
  Frequency frequency = m_interval_timer.frequency();
  FlowRate flow_rate = VOLUME_PER_TRIG * frequency;
  filter.push(flow_rate);
  // TODO actually update canzero (not not from a ISR).
  /* canzero_set_cooling_cycle_flow_rate(static_cast<float>(filter.get() / 1_l)); */
}

void FLASHMEM sensors::mass_flow_rate::begin() {
  canzero_set_cooling_cycle_flow_rate(0);
  input_board::register_exit(PIN, input_board::ExtiEdge::ANY_EDGE, on_exti);
}

void PROGMEM sensors::mass_flow_rate::calibrate() {
  // pass
}

void FASTRUN sensors::mass_flow_rate::update() {
  if (Timestamp::now() - last_trig > 1_s) {
    filter.push(0_l / 1_s);
    last_trig = last_trig + 100_ms;
  }
  canzero_set_cooling_cycle_flow_rate(static_cast<float>(filter.get()));
}
