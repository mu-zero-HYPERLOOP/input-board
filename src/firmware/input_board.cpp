#include "input_board.h"

InputBoard::AnalogReading InputBoard::m_readings[AIN_COUNT];
bool InputBoard::m_new_value[AIN_COUNT];
uint8_t InputBoard::m_mux_sel;
Timestamp InputBoard::m_last_meas[AIN15 + 1]; // not for mux inputs
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

  m_readings[VMEAS21] = read<VMEAS21>();

  m_readings[VMEAS20] = read<VMEAS20>();

  m_readings[VMEAS19] = read<VMEAS19>();

  m_readings[AIN17] = read<AIN17>();

  m_readings[AIN16] = read<AIN16>();

  m_readings[AIN15] = read<AIN15>();

  if (now - m_last_mux_transition > MUX_TRANSITION_TIME) {
    m_last_mux_transition = m_last_mux_transition + MUX_TRANSITION_TIME;
    switch (m_mux_sel) {
    case 0:
      m_readings[NTC18_1] = read_internal<NTC18_1>();
      m_readings[AIN14_1] = read_internal<AIN14_1>();
      break;
    case 1:
      m_readings[NTC18_2] = read_internal<NTC18_2>();
      m_readings[AIN14_2] = read_internal<AIN14_2>();
      break;
    case 2:
      m_readings[NTC18_3] = read_internal<NTC18_3>();
      m_readings[AIN14_3] = read_internal<AIN14_3>();
      break;
    case 3:
      m_readings[NTC18_4] = read_internal<NTC18_4>();
      m_readings[AIN14_4] = read_internal<AIN14_4>();
      break;
    case 4:
      m_readings[NTC18_5] = read_internal<NTC18_5>();
      m_readings[AIN14_5] = read_internal<AIN14_5>();
      break;
    case 5:
      m_readings[NTC18_6] = read_internal<NTC18_6>();
      m_readings[AIN14_6] = read_internal<AIN14_6>();
      break;
    case 6:
      m_readings[NTC18_7] = read_internal<NTC18_7>();
      m_readings[AIN14_7] = read_internal<AIN14_7>();
      break;
    case 7:
      m_readings[NTC18_8] = read_internal<NTC18_8>();
      m_readings[AIN14_8] = read_internal<AIN14_8>();
      break;
    }
    m_mux_sel = (m_mux_sel + 1) & 0x7;
    set_mux_sel(m_mux_sel);
  }
}
