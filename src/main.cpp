/**
 * @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

#include "canzero/canzero.h"
#include "core_pins.h"
#include "firmware/input_board.h"
#include "util/ema.hpp"
#include "util/metrics.h"

int main() {

  Frequency f = 1_Hz;
  /* Duration x = 1.0f / f; */

  canzero_set_state(input_board_state_INIT);
  canzero_init();

  InputBoard::begin();

  ExponentialMovingAverage<Voltage> vmeas1_filter(0.1, 0_V);
  ExponentialMovingAverage<Voltage> vmeas2_filter(0.1, 0_V);
  ExponentialMovingAverage<Voltage> vmeas3_filter(0.1, 0_V);

  ExponentialMovingAverage<Current> ain1_filter(0.1, 0_A);
  ExponentialMovingAverage<Resistance> ain2_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain3_filter(0.1, 0_Ohm);

  ExponentialMovingAverage<Resistance> ntc1_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc2_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc3_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc4_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc5_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc6_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc7_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ntc8_filter(0.1, 0_Ohm);

  ExponentialMovingAverage<Voltage> ain_mux1_filter(0.1, 0_V);
  ExponentialMovingAverage<Voltage> ain_mux2_filter(0.1, 0_V);
  ExponentialMovingAverage<Current> ain_mux3_filter(0.1, 0_A);
  ExponentialMovingAverage<Resistance> ain_mux4_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux5_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux6_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux7_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux8_filter(0.1, 0_Ohm);
  ExponentialMovingAverage<Resistance> ain_mux9_filter(0.1, 0_Ohm);

  Timestamp last_sdc_trig = Timestamp::now();
  Timestamp last_log = Timestamp::now();

  bool sdc_trig = false;

  while (true) {

    canzero_can0_poll();
    canzero_can1_poll();

    Timestamp now = Timestamp::now();
    if (now - last_sdc_trig > 5_s) {
      sdc_trig = !sdc_trig;
      last_sdc_trig = now;
    }

    InputBoard::set_sdc_status(sdc_trig);

    InputBoard::update();

    // Isolated voltage meas filtering
    if (InputBoard::has_next<VMEAS1>()) {
      vmeas1_filter.push(InputBoard::get_ain<VMEAS1>());
    }
    if (InputBoard::has_next<VMEAS2>()) {
      vmeas2_filter.push(InputBoard::get_ain<VMEAS2>());
    }
    if (InputBoard::has_next<VMEAS3>()) {
      vmeas3_filter.push(InputBoard::get_ain<VMEAS3>());
    }

    // direct AIN filtering
    if (InputBoard::has_next<AIN1>()) {
      ain1_filter.push(InputBoard::get_ain<AIN1>());
    }
    if (InputBoard::has_next<AIN2>()) {
      ain2_filter.push(InputBoard::get_ain<AIN2>());
    }
    if (InputBoard::has_next<AIN3>()) {
      ain3_filter.push(InputBoard::get_ain<AIN3>());
    }

    // NTC filtering
    if (InputBoard::has_next<NTC1>()) {
      ntc1_filter.push(InputBoard::get_ain<NTC1>());
    }
    if (InputBoard::has_next<NTC2>()) {
      ntc2_filter.push(InputBoard::get_ain<NTC2>());
    }
    if (InputBoard::has_next<NTC3>()) {
      ntc3_filter.push(InputBoard::get_ain<NTC3>());
    }
    if (InputBoard::has_next<NTC4>()) {
      ntc4_filter.push(InputBoard::get_ain<NTC4>());
    }
    if (InputBoard::has_next<NTC5>()) {
      ntc5_filter.push(InputBoard::get_ain<NTC5>());
    }
    if (InputBoard::has_next<NTC6>()) {
      ntc6_filter.push(InputBoard::get_ain<NTC6>());
    }
    if (InputBoard::has_next<NTC7>()) {
      ntc7_filter.push(InputBoard::get_ain<NTC7>());
    }
    if (InputBoard::has_next<NTC8>()) {
      ntc8_filter.push(InputBoard::get_ain<NTC8>());
    }

    // AIN Mux filtering
    if (InputBoard::has_next<AIN_MUX1>()) {
      ain_mux1_filter.push(InputBoard::get_ain<AIN_MUX1>());
    }
    if (InputBoard::has_next<AIN_MUX2>()) {
      ain_mux2_filter.push(InputBoard::get_ain<AIN_MUX2>());
    }
    if (InputBoard::has_next<AIN_MUX3>()) {
      ain_mux3_filter.push(InputBoard::get_ain<AIN_MUX3>());
    }
    if (InputBoard::has_next<AIN_MUX4>()) {
      ain_mux4_filter.push(InputBoard::get_ain<AIN_MUX4>());
    }
    if (InputBoard::has_next<AIN_MUX5>()) {
      ain_mux5_filter.push(InputBoard::get_ain<AIN_MUX5>());
    }
    if (InputBoard::has_next<AIN_MUX6>()) {
      ain_mux6_filter.push(InputBoard::get_ain<AIN_MUX6>());
    }
    if (InputBoard::has_next<AIN_MUX7>()) {
      ain_mux7_filter.push(InputBoard::get_ain<AIN_MUX7>());
    }
    if (InputBoard::has_next<AIN_MUX8>()) {
      ain_mux8_filter.push(InputBoard::get_ain<AIN_MUX8>());
    }

    bool din2 = digitalRead(PIN_DIN2);
    bool din3 = digitalRead(PIN_DIN3);
    bool din4 = digitalRead(PIN_DIN4);
    bool din5 = digitalRead(PIN_DIN5);

    float vmeas1 = static_cast<float>(vmeas1_filter.get());
    float vmeas2 = static_cast<float>(vmeas2_filter.get());
    float vmeas3 = static_cast<float>(vmeas3_filter.get());

    float ain1 = static_cast<float>(ain1_filter.get());
    float ain2 = static_cast<float>(ain2_filter.get());
    float ain3 = static_cast<float>(ain3_filter.get());

    float ntc1 = static_cast<float>(ntc1_filter.get());
    float ntc2 = static_cast<float>(ntc2_filter.get());
    float ntc3 = static_cast<float>(ntc3_filter.get());
    float ntc4 = static_cast<float>(ntc4_filter.get());
    float ntc5 = static_cast<float>(ntc5_filter.get());
    float ntc6 = static_cast<float>(ntc6_filter.get());
    float ntc7 = static_cast<float>(ntc7_filter.get());
    float ntc8 = static_cast<float>(ntc8_filter.get());

    float ain_mux1 = static_cast<float>(ain_mux1_filter.get());
    float ain_mux2 = static_cast<float>(ain_mux2_filter.get());
    float ain_mux3 = static_cast<float>(ain_mux3_filter.get());
    float ain_mux4 = static_cast<float>(ain_mux4_filter.get());
    float ain_mux5 = static_cast<float>(ain_mux5_filter.get());
    float ain_mux6 = static_cast<float>(ain_mux6_filter.get());
    float ain_mux7 = static_cast<float>(ain_mux7_filter.get());
    float ain_mux8 = static_cast<float>(ain_mux8_filter.get());

    if (now - last_log > 100_ms) {
      last_log = now;
      Serial.println("===============ANALOG-DEBUG==============");

      Serial.printf("-VMEAS1..... %fV\n", vmeas1);
      Serial.printf("-VMEAS2..... %fV\n", vmeas2);
      Serial.printf("-VMEAS3..... %fV\n", vmeas3);

      Serial.printf("-AIN1....... %fA\n", ain1);
      Serial.printf("-AIN2....... %fR\n", ain2);
      Serial.printf("-AIN3....... %fR\n", ain3);

      Serial.printf("-NTC1....... %fR\n", ntc1);
      Serial.printf("-NTC2....... %fR\n", ntc2);
      Serial.printf("-NTC3....... %fR\n", ntc3);
      Serial.printf("-NTC4....... %fR\n", ntc4);
      Serial.printf("-NTC5....... %fR\n", ntc5);
      Serial.printf("-NTC6....... %fR\n", ntc6);
      Serial.printf("-NTC7....... %fR\n", ntc7);
      Serial.printf("-NTC8....... %fR\n", ntc8);

      Serial.printf("-AIN_MUX1... %fV\n", ain_mux1);
      Serial.printf("-AIN_MUX2... %fV\n", ain_mux2);
      Serial.printf("-AIN_MUX3... %fA\n", ain_mux3);
      Serial.printf("-AIN_MUX4... %fR\n", ain_mux4);
      Serial.printf("-AIN_MUX5... %fR\n", ain_mux5);
      Serial.printf("-AIN_MUX6... %fR\n", ain_mux6);
      Serial.printf("-AIN_MUX7... %fR\n", ain_mux7);
      Serial.printf("-AIN_MUX8... %fR\n", ain_mux8);

      Serial.println("==============DIGITAL-DEBUG==============");
      Serial.printf("-DIN2....... %s\n", din2 ? "high" : "low");
      Serial.printf("-DIN3....... %s\n", din3 ? "high" : "low");
      Serial.printf("-DIN4....... %s\n", din4 ? "high" : "low");
      Serial.printf("-DIN5....... %s\n", din5 ? "high" : "low");
      Serial.printf("-SDC-TRIG... %s\n", sdc_trig ? "high" : "low");
    }

    canzero_update_continue(canzero_get_time());

    canzero_set_state(input_board_state_RUNNING);
  }
}
