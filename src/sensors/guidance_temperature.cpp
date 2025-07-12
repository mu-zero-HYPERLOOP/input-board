#include "sensors/guidance_temperature.h"
#include "avr/pgmspace.h"
#include "canzero/canzero.h"
#include "error_level_range_checks.h"
#include "firmware/input_board.h"
#include "sensors/formulas/ntc_north_star.h"
#include "sensors/formulas/voltage_divider.h"
#include "util/boxcar.h"
#include <cassert>
#include "print.h"

using sensors::guidance_temperature::NTC_BETA;
using sensors::guidance_temperature::NTC_R_REF;
using sensors::guidance_temperature::NTC_T_REF;
using sensors::guidance_temperature::R_MEAS;
using sensors::guidance_temperature::PIN_MGU_FRONT_LEFT;
using sensors::guidance_temperature::PIN_MGU_FRONT_RIGHT;
using sensors::guidance_temperature::PIN_MGU_BACK_LEFT;
using sensors::guidance_temperature::PIN_MGU_BACK_RIGHT;

static DMAMEM BoxcarFilter<Temperature, 100> filter_front_left(24_Celcius);
static DMAMEM BoxcarFilter<Temperature, 100> filter_front_right(24_Celcius);
static DMAMEM BoxcarFilter<Temperature, 100> filter_back_left(24_Celcius);
static DMAMEM BoxcarFilter<Temperature, 100> filter_back_right(24_Celcius);


struct SensorConfig {
    BoxcarFilter<Temperature, 100>* filter;
    mux_pin PIN;
    void (*set_temperature)(float);
    void (*set_error_invalid)(error_flag);
    void (*set_error_level)(error_level);
};

static SensorConfig sensor_array[] = {
  {
    &filter_front_left,
    PIN_MGU_FRONT_LEFT,
    &canzero_set_guidance_front_magnet_temperature_left,
    &canzero_set_error_guidance_front_magnet_temperature_left_invalid,
    &canzero_set_error_level_guidance_front_magnet_temperature_left
  },
  {
    &filter_front_right,
    PIN_MGU_FRONT_RIGHT,
    &canzero_set_guidance_front_magnet_temperature_right,
    &canzero_set_error_guidance_front_magnet_temperature_right_invalid,
    &canzero_set_error_level_guidance_front_magnet_temperature_right
  }, {
    &filter_back_left,
    PIN_MGU_BACK_LEFT,
    &canzero_set_guidance_back_magnet_temperature_left,
    &canzero_set_error_guidance_back_magnet_temperature_left_invalid,
    &canzero_set_error_level_guidance_back_magnet_temperature_left
  },
  {
    &filter_back_right,
    PIN_MGU_BACK_RIGHT,
    &canzero_set_guidance_back_magnet_temperature_right,
    &canzero_set_error_guidance_back_magnet_temperature_right_invalid,
    &canzero_set_error_level_guidance_back_magnet_temperature_right
  }
};

constexpr size_t NUM_SENSORS = sizeof(sensor_array) / sizeof(sensor_array[0]);


static void FASTRUN process_temperature_reading(const Voltage &v, SensorConfig &config) {
    if (v < 0.1_V) {
        config.set_error_invalid(error_flag_ERROR);
        config.set_temperature(0);
        return;
    }
    
    config.set_error_invalid(error_flag_OK);
    const Resistance r_ntc = sensors::formula::r1_of_voltage_divider(5_V, v, R_MEAS);
    const Temperature temperature = sensors::formula::ntc_beta(r_ntc, NTC_BETA, NTC_R_REF, NTC_T_REF);
    config.filter->push(temperature);
    config.set_temperature(static_cast<float>(config.filter->get() - 0_Celcius));
}


static void FASTRUN on_value_front_left(const Voltage &v) {
    process_temperature_reading(v, sensor_array[0]);
}

static void FASTRUN on_value_front_right(const Voltage &v) {
    process_temperature_reading(v, sensor_array[1]);
}

static void FASTRUN on_value_back_left(const Voltage &v) {
    process_temperature_reading(v, sensor_array[2]);
}

static void FASTRUN on_value_back_right(const Voltage &v) {
    process_temperature_reading(v, sensor_array[3]);
}

static void (*sensor_callbacks[])(const Voltage &v){
  on_value_front_left,
  on_value_front_right,
  on_value_back_left,
  on_value_back_right
};


static void calibrate_sensor(SensorConfig &config) {
    for (size_t i = 0; i < config.filter->size(); ++i) {
        process_temperature_reading(input_board::sync_read(config.PIN), config);
        canzero_update_continue(canzero_get_time());
        input_board::delay(1_ms);
    }
    
    const Temperature reading = config.filter->get();
    bool invalid_reading = reading >= 100_Celcius || reading <= 0_Celcius;
    config.set_error_invalid(invalid_reading ? error_flag_ERROR : error_flag_OK);
}


void FLASHMEM sensors::guidance_temperature::begin() {

  canzero_set_error_level_config_magnet_temperature(error_level_config{
      .m_info_thresh = 40,  // 45
      .m_info_timeout = 5,
      .m_warning_thresh = 50, // 60
      .m_warning_timeout = 5,
      .m_error_thresh = 60,  // 70
      .m_error_timeout = 5,
      .m_ignore_info = bool_t_FALSE,
      .m_ignore_warning = bool_t_FALSE,
      .m_ignore_error = bool_t_FALSE,
  });
  
  for (size_t i = 0; i<NUM_SENSORS; i++) {
    sensor_array[i].set_temperature(20);
    sensor_array[i].set_error_level(error_level_OK);
    assert(input_board::register_periodic_reading(FREQUENCY, sensor_array[i].PIN, sensor_callbacks[i]));
  }
}

void PROGMEM sensors::guidance_temperature::calibrate() {
    for (size_t i = 0; i < NUM_SENSORS; ++i) {
        calibrate_sensor(sensor_array[i]);
    }
}
 
void FASTRUN sensors::guidance_temperature::update() {
  // TODO: ERROR CHECK, MAX, etc
}
