#include "input_board.h"

InputBoard::AnalogReading InputBoard::m_readings[AIN_COUNT];
bool InputBoard::m_new_value[AIN_COUNT];
uint8_t InputBoard::m_mux_sel;
Timestamp InputBoard::m_last_meas[AIN3 + 1]; // not for mux inputs
Timestamp InputBoard::m_last_mux_transition;

void InputBoard::begin() {
  for (size_t i = 0; i < AIN_COUNT; ++i) {
    m_new_value[i] = false;
    m_readings[i].u = Voltage(0.0f);
  }
  m_mux_sel = 0;
  set_mux_sel(m_mux_sel);
  m_last_mux_transition = Timestamp::now();
  for (size_t i = 0; i < sizeof(m_last_meas) / sizeof(Timestamp); i++) {
    m_last_meas[i] = Timestamp::now();
  }
}

void InputBoard::update() {
  const Timestamp now = Timestamp::now();

  if (now - m_last_meas[VMEAS1] > ANALOG_CONFIGS[VMEAS1].period()) {
    m_last_meas[VMEAS1] = m_last_meas[VMEAS1] + ANALOG_CONFIGS[VMEAS1].period();
    m_readings[VMEAS1] = read<VMEAS1>();
  }
  if (now - m_last_meas[VMEAS2] > ANALOG_CONFIGS[VMEAS2].period()) {
    m_last_meas[VMEAS2] = m_last_meas[VMEAS2] + ANALOG_CONFIGS[VMEAS2].period();
    m_readings[VMEAS2] = read<VMEAS2>();
  }
  if (now - m_last_meas[VMEAS3] > ANALOG_CONFIGS[VMEAS3].period()) {
    m_last_meas[VMEAS3] = m_last_meas[VMEAS3] + ANALOG_CONFIGS[VMEAS3].period();
    m_readings[VMEAS3] = read<VMEAS3>();
  }

  if (now - m_last_meas[AIN1] > ANALOG_CONFIGS[AIN1].period()) {
    m_last_meas[AIN1] = m_last_meas[AIN1] + ANALOG_CONFIGS[AIN1].period();
    m_readings[AIN1] = read<AIN1>();
  }
  if (now - m_last_meas[AIN2] > ANALOG_CONFIGS[AIN2].period()) {
    m_last_meas[AIN2] = m_last_meas[AIN2] + ANALOG_CONFIGS[AIN2].period();
    m_readings[AIN2] = read<AIN2>();
  }
  if (now - m_last_meas[AIN3] > ANALOG_CONFIGS[AIN3].period()) {
    m_last_meas[AIN3] = m_last_meas[AIN3] + ANALOG_CONFIGS[AIN3].period();
    m_readings[AIN3] = read<AIN3>();
  }

  if (now - m_last_mux_transition > MUX_TRANSITION_TIME) {
    m_last_mux_transition = m_last_mux_transition + MUX_TRANSITION_TIME;
    switch (m_mux_sel) {
    case 0:
      m_readings[NTC1] = read<NTC1>();
      m_readings[AIN_MUX1] = read<AIN_MUX1>();
      break;
    case 1:
      m_readings[NTC2] = read<NTC2>();
      m_readings[AIN_MUX2] = read<AIN_MUX2>();
      break;
    case 2:
      m_readings[NTC3] = read<NTC3>();
      m_readings[AIN_MUX3] = read<AIN_MUX3>();
      break;
    case 3:
      m_readings[NTC4] = read<NTC4>();
      m_readings[AIN_MUX4] = read<AIN_MUX4>();
      break;
    case 4:
      m_readings[NTC5] = read<NTC5>();
      m_readings[AIN_MUX5] = read<AIN_MUX5>();
      break;
    case 5:
      m_readings[NTC6] = read<NTC6>();
      m_readings[AIN_MUX6] = read<AIN_MUX6>();
      break;
    case 6:
      m_readings[NTC7] = read<NTC7>();
      m_readings[AIN_MUX7] = read<AIN_MUX7>();
      break;
    case 7:
      m_readings[NTC8] = read<NTC8>();
      m_readings[AIN_MUX8] = read<AIN_MUX8>();
      break;
    }
    m_mux_sel = (m_mux_sel + 1) & 0x7;
    set_mux_sel(m_mux_sel);
  }
}
