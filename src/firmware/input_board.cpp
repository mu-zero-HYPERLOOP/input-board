#include "firmware/input_board.h"
#include "core_pins.h"
#include "firmware/ain_scheduler.h"
#include "firmware/mux_scheduler.h"
#include "firmware/pinout.h"
#include "imxrt.h"
#include "print.h"

#include <InternalTemperature.h>
#include <SparkFunADXL313.h>
#include <tuple>
#include <avr/pgmspace.h>

constexpr size_t MAX_AIN_PERIODIC_JOBS = 6;
constexpr size_t MAX_MUX_PERIODIC_JOBS = 16;

static AinScheduler<MAX_AIN_PERIODIC_JOBS> m_ain_scheduler{};
static MuxScheduler<MAX_MUX_PERIODIC_JOBS> m_mux_scheduler{};

void FLASHMEM input_board::begin() { 
  analogReadResolution(12); 
  analogReadAveraging(32);
  pinMode(din_2, INPUT);
  pinMode(din_3, INPUT);
  pinMode(din_4, INPUT);
  pinMode(din_5, INPUT);
  pinMode(din_6, INPUT);
}

Voltage FASTRUN input_board::sync_read(ain_pin pin) {
  return analogRead(pin) * 3.3_V / 4095.0f;
}

Voltage FASTRUN input_board::sync_read(mux_pin pin) {
  return m_mux_scheduler.sync_read(pin);
}

Temperature PROGMEM input_board::read_mcu_temperature() {
  float temp = InternalTemperature.readTemperatureC();
  float temp_kelvin = temp - 273.15f;
  return Temperature(temp_kelvin);
}

void FASTRUN input_board::set_sdc(bool close) { digitalWrite(sdc_ctrl, close); }

void FASTRUN input_board::mux_select(uint8_t sel) {
  digitalWrite(mux_sel0, sel & 0x1);
  digitalWrite(mux_sel1, sel & 0x2);
  digitalWrite(mux_sel2, sel & 0x4);
}

bool FLASHMEM input_board::register_periodic_reading(const Time &period, ain_pin pin,
                                            void (*on_value)(const Voltage &)) {
  return m_ain_scheduler.register_periodic(period, pin, on_value);
}

bool FLASHMEM input_board::register_periodic_reading(const Time &period, mux_pin pin,
                                            void (*on_value)(const Voltage &)) {
  return m_mux_scheduler.register_periodic(period, pin, on_value);
}

/// sends the input board to sleep for at least ms amount of milliseconds.
void FASTRUN input_board::delay(const Duration &dt) {
  delayMicroseconds(dt.as_us());
}

static ADXL313 m_adxl;
static void (*m_accelerometer_on_value)(const Acceleration &x,
                                        const Acceleration &y,
                                        const Acceleration &z);


bool FLASHMEM input_board::register_periodic_accelerometer_reading(
    const Frequency &frequency, AccelerometerRange range,
    void (*on_value)(const Acceleration &x, const Acceleration &y,
                     const Acceleration &z)) {
  if (m_accelerometer_on_value != nullptr) {
    return false;
  }
  m_accelerometer_on_value = on_value;
  assert(m_adxl.beginSPI(ctrl_pin::accel_cs));
  m_adxl.setRange(range);
  m_adxl.setFullResBit(true);
  m_adxl.setFifoMode(ADXL313_FIFO_MODE_STREAM);
  m_adxl.setAxisOffset(0, 0, 0);
  m_adxl.setRate(static_cast<float>(frequency));
  m_adxl.clearFifo();
  m_adxl.measureModeOn();
  return true;
}

static constexpr Acceleration G = Acceleration(9.80665f);
static constexpr float RESOLUTION = 1024;


std::tuple<Acceleration, Acceleration, Acceleration> FASTRUN input_board::sync_read_acceleration() {
  while (!m_adxl.dataReady()) {
  }
  m_adxl.readAccel();
  return std::make_tuple((m_adxl.x / RESOLUTION) * G,
                         (m_adxl.y / RESOLUTION) * G,
                         (m_adxl.z / RESOLUTION) * G);
}

void FASTRUN input_board::update_continue() {

  m_mux_scheduler.update_continue();
  m_ain_scheduler.update_continue();

  if (m_accelerometer_on_value != nullptr) {
    if (m_adxl.dataReady()) {
      m_adxl.readAccel();
      m_accelerometer_on_value((m_adxl.x / RESOLUTION) * G,
                               (m_adxl.y / RESOLUTION) * G,
                               (m_adxl.z / RESOLUTION) * G);
    }
  }
}

bool FASTRUN input_board::read_digital(din_pin pin) {
  return digitalReadFast(pin) != 0;
}

void FLASHMEM input_board::register_exit(din_pin pin, input_board::ExtiEdge edge,
                                void (*on_exti)()) {
  switch (edge) {
  case ANY_EDGE:
    attachInterrupt(pin, on_exti, CHANGE);
    break;
  case RISING_EDGE:
    attachInterrupt(pin, on_exti, RISING);
    break;
  case FALLING_EDGE:
    attachInterrupt(pin, on_exti, FALLING);
    break;
  }
}

input_board::InterruptLock FASTRUN input_board::InterruptLock::acquire() {
  __disable_irq();
  return InterruptLock();
}

void FASTRUN input_board::InterruptLock::release() {
  if (m_acquried) {
    __enable_irq();
  }
  m_acquried = false;
}
FASTRUN input_board::InterruptLock::~InterruptLock() {
  if (m_acquried) {
    __enable_irq();
  }
  m_acquried = false;
}
