#ifndef CANZERO_H
#define CANZERO_H
#include "inttypes.h"
#include "stddef.h"
typedef struct {
  uint16_t od_index;
  uint8_t client_id;
  uint8_t server_id;
} get_req_header;
typedef struct {
  uint8_t sof;
  uint8_t eof;
  uint8_t toggle;
  uint16_t od_index;
  uint8_t client_id;
  uint8_t server_id;
} set_req_header;
typedef enum {
  node_id_mlu1 = 0,
  node_id_master = 1,
  node_id_mlu2 = 2,
  node_id_mlu3 = 3,
  node_id_mlu4 = 4,
  node_id_mlu5 = 5,
  node_id_mlu6 = 6,
  node_id_mgu1 = 7,
  node_id_mgu2 = 8,
  node_id_motor_driver = 9,
  node_id_pdu24 = 10,
  node_id_pdu12 = 11,
  node_id_input_board = 12,
  node_id_gamepad = 13,
} node_id;
typedef struct {
  uint8_t sof;
  uint8_t eof;
  uint8_t toggle;
  uint16_t od_index;
  uint8_t client_id;
  uint8_t server_id;
} get_resp_header;
typedef enum {
  set_resp_erno_Success = 0,
  set_resp_erno_Error = 1,
} set_resp_erno;
typedef struct {
  uint16_t od_index;
  uint8_t client_id;
  uint8_t server_id;
  set_resp_erno erno;
} set_resp_header;
typedef enum {
  sdc_status_OPEN = 0,
  sdc_status_CLOSED = 1,
} sdc_status;
typedef enum {
  error_flag_OK = 0,
  error_flag_ERROR = 1,
} error_flag;
typedef enum {
  input_board_state_INIT = 0,
  input_board_state_RUNNING = 1,
} input_board_state;
typedef struct {
  uint32_t id;
  uint8_t dlc;
  uint8_t data[8];
} canzero_frame;
typedef enum : uint32_t {
  CANZERO_FRAME_IDE_BIT = 0x40000000, // 1 << 30
  CANZERO_FRAME_RTR_BIT = 0x80000000, // 1 << 31
} can_frame_id_bits;
typedef struct {
  uint32_t mask;
  uint32_t id;
} canzero_can_filter;
extern void canzero_can0_setup(uint32_t baudrate, canzero_can_filter* filters, int filter_count);
extern void canzero_can0_send(canzero_frame* frame);
extern int canzero_can0_recv(canzero_frame* frame);
extern void canzero_can1_setup(uint32_t baudrate, canzero_can_filter* filters, int filter_count);
extern void canzero_can1_send(canzero_frame* frame);
extern int canzero_can1_recv(canzero_frame* frame);
extern void canzero_request_update(uint32_t time);
extern uint32_t canzero_get_time();
extern void canzero_enter_critical();
extern void canzero_exit_critical();
static inline input_board_state canzero_get_state() {
  extern input_board_state __oe_state;
  return __oe_state;
}
static inline float canzero_get_position_estimation() {
  extern float __oe_position_estimation;
  return __oe_position_estimation;
}
static inline float canzero_get_velocity_estimation() {
  extern float __oe_velocity_estimation;
  return __oe_velocity_estimation;
}
static inline float canzero_get_acceleration_estimation() {
  extern float __oe_acceleration_estimation;
  return __oe_acceleration_estimation;
}
static inline float canzero_get_track_length() {
  extern float __oe_track_length;
  return __oe_track_length;
}
static inline float canzero_get_bat24_voltage() {
  extern float __oe_bat24_voltage;
  return __oe_bat24_voltage;
}
static inline float canzero_get_bat24_current() {
  extern float __oe_bat24_current;
  return __oe_bat24_current;
}
static inline float canzero_get_link24_voltage() {
  extern float __oe_link24_voltage;
  return __oe_link24_voltage;
}
static inline float canzero_get_link24_current() {
  extern float __oe_link24_current;
  return __oe_link24_current;
}
static inline float canzero_get_link45_voltage() {
  extern float __oe_link45_voltage;
  return __oe_link45_voltage;
}
static inline float canzero_get_link45_current() {
  extern float __oe_link45_current;
  return __oe_link45_current;
}
static inline sdc_status canzero_get_sdc_status() {
  extern sdc_status __oe_sdc_status;
  return __oe_sdc_status;
}
static inline float canzero_get_mcu_temperature() {
  extern float __oe_mcu_temperature;
  return __oe_mcu_temperature;
}
static inline float canzero_get_cooling_cycle_temperature() {
  extern float __oe_cooling_cycle_temperature;
  return __oe_cooling_cycle_temperature;
}
static inline float canzero_get_bat24_temperature() {
  extern float __oe_bat24_temperature;
  return __oe_bat24_temperature;
}
static inline float canzero_get_supercap_temperature() {
  extern float __oe_supercap_temperature;
  return __oe_supercap_temperature;
}
static inline float canzero_get_buck_temperature() {
  extern float __oe_buck_temperature;
  return __oe_buck_temperature;
}
static inline float canzero_get_ebox_temperature() {
  extern float __oe_ebox_temperature;
  return __oe_ebox_temperature;
}
static inline float canzero_get_ambient_temperature() {
  extern float __oe_ambient_temperature;
  return __oe_ambient_temperature;
}
static inline float canzero_get_cooling_cycle_pressure() {
  extern float __oe_cooling_cycle_pressure;
  return __oe_cooling_cycle_pressure;
}
static inline int16_t canzero_get_fiducial_count1() {
  extern int16_t __oe_fiducial_count1;
  return __oe_fiducial_count1;
}
static inline int16_t canzero_get_fiducial_count2() {
  extern int16_t __oe_fiducial_count2;
  return __oe_fiducial_count2;
}
static inline error_flag canzero_get_error_invalid_position() {
  extern error_flag __oe_error_invalid_position;
  return __oe_error_invalid_position;
}
static inline error_flag canzero_get_error_invalid_velocity_profile() {
  extern error_flag __oe_error_invalid_velocity_profile;
  return __oe_error_invalid_velocity_profile;
}
static inline error_flag canzero_get_error_invalid_acceleration() {
  extern error_flag __oe_error_invalid_acceleration;
  return __oe_error_invalid_acceleration;
}
static inline error_flag canzero_get_error_bat24_over_temperature() {
  extern error_flag __oe_error_bat24_over_temperature;
  return __oe_error_bat24_over_temperature;
}
static inline float canzero_get_error_bat24_over_temperature_thresh() {
  extern float __oe_error_bat24_over_temperature_thresh;
  return __oe_error_bat24_over_temperature_thresh;
}
static inline float canzero_get_error_bat24_over_temperature_timeout() {
  extern float __oe_error_bat24_over_temperature_timeout;
  return __oe_error_bat24_over_temperature_timeout;
}
static inline error_flag canzero_get_error_supercap_over_temperature() {
  extern error_flag __oe_error_supercap_over_temperature;
  return __oe_error_supercap_over_temperature;
}
static inline float canzero_get_error_supercap_over_temperature_thresh() {
  extern float __oe_error_supercap_over_temperature_thresh;
  return __oe_error_supercap_over_temperature_thresh;
}
static inline float canzero_get_error_supercap_over_temperature_timeout() {
  extern float __oe_error_supercap_over_temperature_timeout;
  return __oe_error_supercap_over_temperature_timeout;
}
static inline error_flag canzero_get_error_buck_over_temperature() {
  extern error_flag __oe_error_buck_over_temperature;
  return __oe_error_buck_over_temperature;
}
static inline float canzero_get_error_buck_over_temperature_thresh() {
  extern float __oe_error_buck_over_temperature_thresh;
  return __oe_error_buck_over_temperature_thresh;
}
static inline float canzero_get_error_buck_over_temperature_timeout() {
  extern float __oe_error_buck_over_temperature_timeout;
  return __oe_error_buck_over_temperature_timeout;
}
static inline error_flag canzero_get_error_ambient_over_temperature() {
  extern error_flag __oe_error_ambient_over_temperature;
  return __oe_error_ambient_over_temperature;
}
static inline float canzero_get_error_ambient_over_temperature_thresh() {
  extern float __oe_error_ambient_over_temperature_thresh;
  return __oe_error_ambient_over_temperature_thresh;
}
static inline float canzero_get_error_ambient_over_temperature_timeout() {
  extern float __oe_error_ambient_over_temperature_timeout;
  return __oe_error_ambient_over_temperature_timeout;
}
static inline error_flag canzero_get_error_cooling_cycle_over_pressure() {
  extern error_flag __oe_error_cooling_cycle_over_pressure;
  return __oe_error_cooling_cycle_over_pressure;
}
static inline float canzero_get_error_cooling_cycle_over_pressure_thresh() {
  extern float __oe_error_cooling_cycle_over_pressure_thresh;
  return __oe_error_cooling_cycle_over_pressure_thresh;
}
static inline float canzero_get_error_cooling_cycle_over_pressure_timeout() {
  extern float __oe_error_cooling_cycle_over_pressure_timeout;
  return __oe_error_cooling_cycle_over_pressure_timeout;
}
static inline error_flag canzero_get_error_cooling_cycle_low_pressure() {
  extern error_flag __oe_error_cooling_cycle_low_pressure;
  return __oe_error_cooling_cycle_low_pressure;
}
static inline float canzero_get_error_cooling_cycle_low_pressure_thresh() {
  extern float __oe_error_cooling_cycle_low_pressure_thresh;
  return __oe_error_cooling_cycle_low_pressure_thresh;
}
static inline float canzero_get_error_cooling_cycle_low_pressure_timeout() {
  extern float __oe_error_cooling_cycle_low_pressure_timeout;
  return __oe_error_cooling_cycle_low_pressure_timeout;
}
static inline error_flag canzero_get_error_mcu_over_temperature() {
  extern error_flag __oe_error_mcu_over_temperature;
  return __oe_error_mcu_over_temperature;
}
static inline float canzero_get_error_mcu_over_temperature_thresh() {
  extern float __oe_error_mcu_over_temperature_thresh;
  return __oe_error_mcu_over_temperature_thresh;
}
static inline float canzero_get_error_mcu_over_temperature_timeout() {
  extern float __oe_error_mcu_over_temperature_timeout;
  return __oe_error_mcu_over_temperature_timeout;
}
static inline error_flag canzero_get_error_ebox_over_temperature() {
  extern error_flag __oe_error_ebox_over_temperature;
  return __oe_error_ebox_over_temperature;
}
static inline float canzero_get_error_ebox_over_temperature_thresh() {
  extern float __oe_error_ebox_over_temperature_thresh;
  return __oe_error_ebox_over_temperature_thresh;
}
static inline float canzero_get_error_ebox_over_temperature_timeout() {
  extern float __oe_error_ebox_over_temperature_timeout;
  return __oe_error_ebox_over_temperature_timeout;
}
static inline error_flag canzero_get_error_cooling_cycle_over_temperature() {
  extern error_flag __oe_error_cooling_cycle_over_temperature;
  return __oe_error_cooling_cycle_over_temperature;
}
static inline float canzero_get_error_cooling_cycle_over_temperature_thresh() {
  extern float __oe_error_cooling_cycle_over_temperature_thresh;
  return __oe_error_cooling_cycle_over_temperature_thresh;
}
static inline float canzero_get_error_cooling_cycle_over_temperature_timeout() {
  extern float __oe_error_cooling_cycle_over_temperature_timeout;
  return __oe_error_cooling_cycle_over_temperature_timeout;
}
static inline error_flag canzero_get_warn_bat24_over_volt() {
  extern error_flag __oe_warn_bat24_over_volt;
  return __oe_warn_bat24_over_volt;
}
static inline float canzero_get_warn_bat24_over_volt_thresh() {
  extern float __oe_warn_bat24_over_volt_thresh;
  return __oe_warn_bat24_over_volt_thresh;
}
static inline error_flag canzero_get_warn_bat24_under_volt() {
  extern error_flag __oe_warn_bat24_under_volt;
  return __oe_warn_bat24_under_volt;
}
static inline float canzero_get_warn_bat24_under_volt_thresh() {
  extern float __oe_warn_bat24_under_volt_thresh;
  return __oe_warn_bat24_under_volt_thresh;
}
static inline error_flag canzero_get_warn_bat24_over_current() {
  extern error_flag __oe_warn_bat24_over_current;
  return __oe_warn_bat24_over_current;
}
static inline float canzero_get_warn_bat24_over_current_thresh() {
  extern float __oe_warn_bat24_over_current_thresh;
  return __oe_warn_bat24_over_current_thresh;
}
static inline error_flag canzero_get_warn_invalid_position_estimation() {
  extern error_flag __oe_warn_invalid_position_estimation;
  return __oe_warn_invalid_position_estimation;
}
static inline error_flag canzero_get_warn_invalid_position() {
  extern error_flag __oe_warn_invalid_position;
  return __oe_warn_invalid_position;
}
static inline error_flag canzero_get_warn_invalid_velocity_profile() {
  extern error_flag __oe_warn_invalid_velocity_profile;
  return __oe_warn_invalid_velocity_profile;
}
static inline error_flag canzero_get_warn_invalid_acceleration_profile() {
  extern error_flag __oe_warn_invalid_acceleration_profile;
  return __oe_warn_invalid_acceleration_profile;
}
static inline error_flag canzero_get_warn_bat24_over_temperature() {
  extern error_flag __oe_warn_bat24_over_temperature;
  return __oe_warn_bat24_over_temperature;
}
static inline float canzero_get_warn_bat24_over_temperature_thresh() {
  extern float __oe_warn_bat24_over_temperature_thresh;
  return __oe_warn_bat24_over_temperature_thresh;
}
static inline float canzero_get_warn_bat24_over_temperature_timeout() {
  extern float __oe_warn_bat24_over_temperature_timeout;
  return __oe_warn_bat24_over_temperature_timeout;
}
static inline error_flag canzero_get_warn_cooling_cycle_over_pressure() {
  extern error_flag __oe_warn_cooling_cycle_over_pressure;
  return __oe_warn_cooling_cycle_over_pressure;
}
static inline float canzero_get_warn_cooling_cycle_over_pressure_thresh() {
  extern float __oe_warn_cooling_cycle_over_pressure_thresh;
  return __oe_warn_cooling_cycle_over_pressure_thresh;
}
static inline float canzero_get_warn_cooling_cycle_over_pressure_timeout() {
  extern float __oe_warn_cooling_cycle_over_pressure_timeout;
  return __oe_warn_cooling_cycle_over_pressure_timeout;
}
static inline error_flag canzero_get_warn_cooling_cycle_low_pressure() {
  extern error_flag __oe_warn_cooling_cycle_low_pressure;
  return __oe_warn_cooling_cycle_low_pressure;
}
static inline float canzero_get_warn_cooling_cycle_low_pressure_thresh() {
  extern float __oe_warn_cooling_cycle_low_pressure_thresh;
  return __oe_warn_cooling_cycle_low_pressure_thresh;
}
static inline float canzero_get_warn_cooling_cycle_low_pressure_timeout() {
  extern float __oe_warn_cooling_cycle_low_pressure_timeout;
  return __oe_warn_cooling_cycle_low_pressure_timeout;
}
static inline error_flag canzero_get_warn_mcu_over_temperature() {
  extern error_flag __oe_warn_mcu_over_temperature;
  return __oe_warn_mcu_over_temperature;
}
static inline float canzero_get_warn_mcu_over_temperature_thresh() {
  extern float __oe_warn_mcu_over_temperature_thresh;
  return __oe_warn_mcu_over_temperature_thresh;
}
static inline float canzero_get_warn_mcu_over_temperature_timeout() {
  extern float __oe_warn_mcu_over_temperature_timeout;
  return __oe_warn_mcu_over_temperature_timeout;
}
static inline error_flag canzero_get_warn_ebox_over_temperature() {
  extern error_flag __oe_warn_ebox_over_temperature;
  return __oe_warn_ebox_over_temperature;
}
static inline float canzero_get_warn_ebox_over_temperature_thresh() {
  extern float __oe_warn_ebox_over_temperature_thresh;
  return __oe_warn_ebox_over_temperature_thresh;
}
static inline float canzero_get_warn_ebox_over_temperature_timeout() {
  extern float __oe_warn_ebox_over_temperature_timeout;
  return __oe_warn_ebox_over_temperature_timeout;
}
static inline error_flag canzero_get_warn_supercap_over_temperature() {
  extern error_flag __oe_warn_supercap_over_temperature;
  return __oe_warn_supercap_over_temperature;
}
static inline float canzero_get_warn_supercap_over_temperature_thresh() {
  extern float __oe_warn_supercap_over_temperature_thresh;
  return __oe_warn_supercap_over_temperature_thresh;
}
static inline float canzero_get_warn_supercap_over_temperature_timeout() {
  extern float __oe_warn_supercap_over_temperature_timeout;
  return __oe_warn_supercap_over_temperature_timeout;
}
static inline error_flag canzero_get_warn_buck_over_temperature() {
  extern error_flag __oe_warn_buck_over_temperature;
  return __oe_warn_buck_over_temperature;
}
static inline float canzero_get_warn_buck_over_temperature_thresh() {
  extern float __oe_warn_buck_over_temperature_thresh;
  return __oe_warn_buck_over_temperature_thresh;
}
static inline float canzero_get_warn_buck_over_temperature_timeout() {
  extern float __oe_warn_buck_over_temperature_timeout;
  return __oe_warn_buck_over_temperature_timeout;
}
static inline error_flag canzero_get_error_bat24_over_volt() {
  extern error_flag __oe_error_bat24_over_volt;
  return __oe_error_bat24_over_volt;
}
static inline float canzero_get_error_bat24_over_volt_thresh() {
  extern float __oe_error_bat24_over_volt_thresh;
  return __oe_error_bat24_over_volt_thresh;
}
static inline error_flag canzero_get_error_bat24_under_volt() {
  extern error_flag __oe_error_bat24_under_volt;
  return __oe_error_bat24_under_volt;
}
static inline float canzero_get_error_bat24_under_volt_thresh() {
  extern float __oe_error_bat24_under_volt_thresh;
  return __oe_error_bat24_under_volt_thresh;
}
static inline error_flag canzero_get_error_bat24_over_current() {
  extern error_flag __oe_error_bat24_over_current;
  return __oe_error_bat24_over_current;
}
static inline float canzero_get_error_bat24_over_current_thresh() {
  extern float __oe_error_bat24_over_current_thresh;
  return __oe_error_bat24_over_current_thresh;
}
static inline error_flag canzero_get_warn_ambient_over_temperature() {
  extern error_flag __oe_warn_ambient_over_temperature;
  return __oe_warn_ambient_over_temperature;
}
static inline float canzero_get_warn_ambient_over_temperature_thresh() {
  extern float __oe_warn_ambient_over_temperature_thresh;
  return __oe_warn_ambient_over_temperature_thresh;
}
static inline float canzero_get_warn_ambient_over_temperature_timeout() {
  extern float __oe_warn_ambient_over_temperature_timeout;
  return __oe_warn_ambient_over_temperature_timeout;
}
static inline error_flag canzero_get_warn_cooling_cycle_over_temperature() {
  extern error_flag __oe_warn_cooling_cycle_over_temperature;
  return __oe_warn_cooling_cycle_over_temperature;
}
static inline float canzero_get_warn_cooling_cycle_over_temperature_thresh() {
  extern float __oe_warn_cooling_cycle_over_temperature_thresh;
  return __oe_warn_cooling_cycle_over_temperature_thresh;
}
static inline float canzero_get_warn_cooling_cycle_over_temperature_timeout() {
  extern float __oe_warn_cooling_cycle_over_temperature_timeout;
  return __oe_warn_cooling_cycle_over_temperature_timeout;
}
static inline uint8_t canzero_get_battery_24V_temperature() {
  extern uint8_t __oe_battery_24V_temperature;
  return __oe_battery_24V_temperature;
}
static inline uint8_t canzero_get_error_battery_over_temperature() {
  extern uint8_t __oe_error_battery_over_temperature;
  return __oe_error_battery_over_temperature;
}
static inline uint8_t canzero_get_warn_battery_over_temperature() {
  extern uint8_t __oe_warn_battery_over_temperature;
  return __oe_warn_battery_over_temperature;
}
typedef struct {
  get_resp_header header;
  uint32_t data;
} canzero_message_get_resp;
static const uint32_t canzero_message_get_resp_id = 0x13F;
typedef struct {
  set_resp_header header;
} canzero_message_set_resp;
static const uint32_t canzero_message_set_resp_id = 0x15F;
typedef struct {
  float position_estimation;
  float velocity_estimation;
  float acceleration_estimation;
} canzero_message_input_board_stream_state_estimation;
static const uint32_t canzero_message_input_board_stream_state_estimation_id = 0xBA;
typedef struct {
  float mcu_temperature;
  float cooling_cycle_temperature;
  uint8_t battery_24V_temperature;
  float ebox_temperature;
  float cooling_cycle_pressure;
} canzero_message_input_board_stream_safety_sensors;
static const uint32_t canzero_message_input_board_stream_safety_sensors_id = 0x7F;
typedef struct {
  sdc_status sdc_status;
} canzero_message_input_board_stream_sdc_status;
static const uint32_t canzero_message_input_board_stream_sdc_status_id = 0x7A;
typedef struct {
  error_flag error_mcu_over_temperature;
  error_flag error_invalid_position;
  error_flag error_invalid_velocity_profile;
  error_flag error_invalid_acceleration;
  uint8_t error_battery_over_temperature;
  error_flag error_cooling_cycle_over_pressure;
  error_flag error_cooling_cycle_low_pressure;
  error_flag error_ebox_over_temperature;
  error_flag error_cooling_cycle_over_temperature;
  error_flag warn_invalid_position_estimation;
  error_flag warn_invalid_position;
  error_flag warn_invalid_velocity_profile;
  error_flag warn_invalid_acceleration_profile;
  uint8_t warn_battery_over_temperature;
  error_flag warn_cooling_cycle_over_pressure;
  error_flag warn_cooling_cycle_low_pressure;
  error_flag warn_mcu_over_temperature;
  error_flag warn_ebox_over_temperature;
  error_flag warn_cooling_cycle_over_temperature;
} canzero_message_input_board_stream_errors;
static const uint32_t canzero_message_input_board_stream_errors_id = 0x5A;
typedef struct {
  input_board_state state;
} canzero_message_input_board_stream_state;
static const uint32_t canzero_message_input_board_stream_state_id = 0x9A;
typedef struct {
  node_id node_id;
} canzero_message_heartbeat;
static const uint32_t canzero_message_heartbeat_id = 0x17B;
typedef struct {
  get_req_header header;
} canzero_message_get_req;
static const uint32_t canzero_message_get_req_id = 0x13B;
typedef struct {
  set_req_header header;
  uint32_t data;
} canzero_message_set_req;
static const uint32_t canzero_message_set_req_id = 0x15B;
static void canzero_serialize_canzero_message_get_resp(canzero_message_get_resp* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x13F;
  frame->dlc = 8;
  ((uint32_t*)data)[0] = (uint8_t)(msg->header.sof & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->header.eof & (0xFF >> (8 - 1))) << 1;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->header.toggle & (0xFF >> (8 - 1))) << 2;
  ((uint32_t*)data)[0] |= (uint16_t)(msg->header.od_index & (0xFFFF >> (16 - 13))) << 3;
  ((uint32_t*)data)[0] |= msg->header.client_id << 16;
  ((uint32_t*)data)[0] |= msg->header.server_id << 24;
  ((uint32_t*)data)[1] = msg->data;
}
static void canzero_serialize_canzero_message_set_resp(canzero_message_set_resp* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x15F;
  frame->dlc = 4;
  ((uint32_t*)data)[0] = (uint16_t)(msg->header.od_index & (0xFFFF >> (16 - 13)));
  ((uint32_t*)data)[0] |= msg->header.client_id << 13;
  ((uint32_t*)data)[0] |= msg->header.server_id << 21;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->header.erno & (0xFF >> (8 - 1))) << 29;
}
static void canzero_serialize_canzero_message_input_board_stream_state_estimation(canzero_message_input_board_stream_state_estimation* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0xBA;
  frame->dlc = 6;
  float position_estimation_0 = (msg->position_estimation - -100) / 0.0030518043793392844;
  if (position_estimation_0 > 4294901760.000) {
    position_estimation_0 = 4294901760.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) position_estimation_0;
  float velocity_estimation_16 = (msg->velocity_estimation - -10) / 0.00030518043793392844;
  if (velocity_estimation_16 > 4294901760.000) {
    velocity_estimation_16 = 4294901760.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) velocity_estimation_16 << 16;
  float acceleration_estimation_32 = (msg->acceleration_estimation - -5) / 0.00008392462043183032;
  if (acceleration_estimation_32 > 4294901760.000) {
    acceleration_estimation_32 = 4294901760.000;
  }
  ((uint32_t*)data)[1] = (uint32_t) acceleration_estimation_32;
}
static void canzero_serialize_canzero_message_input_board_stream_safety_sensors(canzero_message_input_board_stream_safety_sensors* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x7F;
  frame->dlc = 5;
  float mcu_temperature_0 = (msg->mcu_temperature - -1) / 0.592156862745098;
  if (mcu_temperature_0 > 4278190080.000) {
    mcu_temperature_0 = 4278190080.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) mcu_temperature_0;
  float cooling_cycle_temperature_8 = (msg->cooling_cycle_temperature - -1) / 0.592156862745098;
  if (cooling_cycle_temperature_8 > 4278190080.000) {
    cooling_cycle_temperature_8 = 4278190080.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) cooling_cycle_temperature_8 << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->battery_24V_temperature & (0xFF >> (8 - 1))) << 16;
  float ebox_temperature_17 = (msg->ebox_temperature - -1) / 0.592156862745098;
  if (ebox_temperature_17 > 4278190080.000) {
    ebox_temperature_17 = 4278190080.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) ebox_temperature_17 << 17;
  float cooling_cycle_pressure_25 = (msg->cooling_cycle_pressure - -1) / 0.0392156862745098;
  if (cooling_cycle_pressure_25 > 4278190080.000) {
    cooling_cycle_pressure_25 = 4278190080.000;
  }
  ((uint64_t*)data)[0] |= ((uint64_t)(uint32_t) cooling_cycle_pressure_25) << 25 ;
}
static void canzero_serialize_canzero_message_input_board_stream_sdc_status(canzero_message_input_board_stream_sdc_status* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x7A;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->sdc_status & (0xFF >> (8 - 1)));
}
static void canzero_serialize_canzero_message_input_board_stream_errors(canzero_message_input_board_stream_errors* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x5A;
  frame->dlc = 3;
  ((uint32_t*)data)[0] = (uint8_t)(msg->error_mcu_over_temperature & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_invalid_position & (0xFF >> (8 - 1))) << 1;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_invalid_velocity_profile & (0xFF >> (8 - 1))) << 2;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_invalid_acceleration & (0xFF >> (8 - 1))) << 3;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_battery_over_temperature & (0xFF >> (8 - 1))) << 4;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_cooling_cycle_over_pressure & (0xFF >> (8 - 1))) << 5;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_cooling_cycle_low_pressure & (0xFF >> (8 - 1))) << 6;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_ebox_over_temperature & (0xFF >> (8 - 1))) << 7;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_cooling_cycle_over_temperature & (0xFF >> (8 - 1))) << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_invalid_position_estimation & (0xFF >> (8 - 1))) << 9;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_invalid_position & (0xFF >> (8 - 1))) << 10;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_invalid_velocity_profile & (0xFF >> (8 - 1))) << 11;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_invalid_acceleration_profile & (0xFF >> (8 - 1))) << 12;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_battery_over_temperature & (0xFF >> (8 - 1))) << 13;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_cooling_cycle_over_pressure & (0xFF >> (8 - 1))) << 14;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_cooling_cycle_low_pressure & (0xFF >> (8 - 1))) << 15;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_mcu_over_temperature & (0xFF >> (8 - 1))) << 16;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_ebox_over_temperature & (0xFF >> (8 - 1))) << 17;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->warn_cooling_cycle_over_temperature & (0xFF >> (8 - 1))) << 18;
}
static void canzero_serialize_canzero_message_input_board_stream_state(canzero_message_input_board_stream_state* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x9A;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->state & (0xFF >> (8 - 1)));
}
static void canzero_serialize_canzero_message_heartbeat(canzero_message_heartbeat* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x17B;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->node_id & (0xFF >> (8 - 4)));
}
static void canzero_serialize_canzero_message_get_req(canzero_message_get_req* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x13B;
  frame->dlc = 4;
  ((uint32_t*)data)[0] = (uint16_t)(msg->header.od_index & (0xFFFF >> (16 - 13)));
  ((uint32_t*)data)[0] |= msg->header.client_id << 13;
  ((uint32_t*)data)[0] |= msg->header.server_id << 21;
}
static void canzero_serialize_canzero_message_set_req(canzero_message_set_req* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x15B;
  frame->dlc = 8;
  ((uint32_t*)data)[0] = (uint8_t)(msg->header.sof & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->header.eof & (0xFF >> (8 - 1))) << 1;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->header.toggle & (0xFF >> (8 - 1))) << 2;
  ((uint32_t*)data)[0] |= (uint16_t)(msg->header.od_index & (0xFFFF >> (16 - 13))) << 3;
  ((uint32_t*)data)[0] |= msg->header.client_id << 16;
  ((uint32_t*)data)[0] |= msg->header.server_id << 24;
  ((uint32_t*)data)[1] = msg->data;
}
static void canzero_deserialize_canzero_message_get_resp(canzero_frame* frame, canzero_message_get_resp* msg) {
  uint8_t* data = frame->data;
  msg->header.sof = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->header.eof = ((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->header.toggle = ((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->header.od_index = ((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 13)));
  msg->header.client_id = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 8)));
  msg->header.server_id = ((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 8)));
  msg->data = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 32)));
}
static void canzero_deserialize_canzero_message_set_resp(canzero_frame* frame, canzero_message_set_resp* msg) {
  uint8_t* data = frame->data;
  msg->header.od_index = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 13)));
  msg->header.client_id = ((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 8)));
  msg->header.server_id = ((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 8)));
  msg->header.erno = (set_resp_erno)((((uint32_t*)data)[0] >> 29) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_input_board_stream_state_estimation(canzero_frame* frame, canzero_message_input_board_stream_state_estimation* msg) {
  uint8_t* data = frame->data;
  msg->position_estimation = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 16))) * 0.0030518043793392844 + -100;
  msg->velocity_estimation = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10;
  msg->acceleration_estimation = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 16))) * 0.00008392462043183032 + -5;
}
static void canzero_deserialize_canzero_message_input_board_stream_safety_sensors(canzero_frame* frame, canzero_message_input_board_stream_safety_sensors* msg) {
  uint8_t* data = frame->data;
  msg->mcu_temperature = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->cooling_cycle_temperature = ((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->battery_24V_temperature = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 1)));
  msg->ebox_temperature = ((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->cooling_cycle_pressure = ((((uint64_t*)data)[0] >> 25) & (0xFFFFFFFFFFFFFFFF >> (64 - 8))) * 0.0392156862745098 + -1;
}
static void canzero_deserialize_canzero_message_input_board_stream_sdc_status(canzero_frame* frame, canzero_message_input_board_stream_sdc_status* msg) {
  uint8_t* data = frame->data;
  msg->sdc_status = (sdc_status)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_input_board_stream_errors(canzero_frame* frame, canzero_message_input_board_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->error_mcu_over_temperature = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->error_invalid_position = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_invalid_velocity_profile = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_invalid_acceleration = (error_flag)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_battery_over_temperature = ((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_cooling_cycle_over_pressure = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_cooling_cycle_low_pressure = (error_flag)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_ebox_over_temperature = (error_flag)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_cooling_cycle_over_temperature = (error_flag)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_invalid_position_estimation = (error_flag)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_invalid_position = (error_flag)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_invalid_velocity_profile = (error_flag)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_invalid_acceleration_profile = (error_flag)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_battery_over_temperature = ((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_cooling_cycle_over_pressure = (error_flag)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_cooling_cycle_low_pressure = (error_flag)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_mcu_over_temperature = (error_flag)((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_ebox_over_temperature = (error_flag)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 1)));
  msg->warn_cooling_cycle_over_temperature = (error_flag)((((uint32_t*)data)[0] >> 18) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_input_board_stream_state(canzero_frame* frame, canzero_message_input_board_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->state = (input_board_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_heartbeat(canzero_frame* frame, canzero_message_heartbeat* msg) {
  uint8_t* data = frame->data;
  msg->node_id = (node_id)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 4)));
}
static void canzero_deserialize_canzero_message_get_req(canzero_frame* frame, canzero_message_get_req* msg) {
  uint8_t* data = frame->data;
  msg->header.od_index = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 13)));
  msg->header.client_id = ((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 8)));
  msg->header.server_id = ((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 8)));
}
static void canzero_deserialize_canzero_message_set_req(canzero_frame* frame, canzero_message_set_req* msg) {
  uint8_t* data = frame->data;
  msg->header.sof = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->header.eof = ((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->header.toggle = ((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->header.od_index = ((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 13)));
  msg->header.client_id = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 8)));
  msg->header.server_id = ((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 8)));
  msg->data = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 32)));
}
void canzero_can0_poll();
void canzero_can1_poll();
uint32_t canzero_update_continue(uint32_t delta_time);
void canzero_init();
void canzero_set_state(input_board_state value);
static inline void canzero_set_position_estimation(float value){
  extern float __oe_position_estimation;
  __oe_position_estimation = value;
}
static inline void canzero_set_velocity_estimation(float value){
  extern float __oe_velocity_estimation;
  __oe_velocity_estimation = value;
}
static inline void canzero_set_acceleration_estimation(float value){
  extern float __oe_acceleration_estimation;
  __oe_acceleration_estimation = value;
}
static inline void canzero_set_track_length(float value){
  extern float __oe_track_length;
  __oe_track_length = value;
}
static inline void canzero_set_bat24_voltage(float value){
  extern float __oe_bat24_voltage;
  __oe_bat24_voltage = value;
}
static inline void canzero_set_bat24_current(float value){
  extern float __oe_bat24_current;
  __oe_bat24_current = value;
}
static inline void canzero_set_link24_voltage(float value){
  extern float __oe_link24_voltage;
  __oe_link24_voltage = value;
}
static inline void canzero_set_link24_current(float value){
  extern float __oe_link24_current;
  __oe_link24_current = value;
}
static inline void canzero_set_link45_voltage(float value){
  extern float __oe_link45_voltage;
  __oe_link45_voltage = value;
}
static inline void canzero_set_link45_current(float value){
  extern float __oe_link45_current;
  __oe_link45_current = value;
}
void canzero_set_sdc_status(sdc_status value);
static inline void canzero_set_mcu_temperature(float value){
  extern float __oe_mcu_temperature;
  __oe_mcu_temperature = value;
}
static inline void canzero_set_cooling_cycle_temperature(float value){
  extern float __oe_cooling_cycle_temperature;
  __oe_cooling_cycle_temperature = value;
}
static inline void canzero_set_bat24_temperature(float value){
  extern float __oe_bat24_temperature;
  __oe_bat24_temperature = value;
}
static inline void canzero_set_supercap_temperature(float value){
  extern float __oe_supercap_temperature;
  __oe_supercap_temperature = value;
}
static inline void canzero_set_buck_temperature(float value){
  extern float __oe_buck_temperature;
  __oe_buck_temperature = value;
}
static inline void canzero_set_ebox_temperature(float value){
  extern float __oe_ebox_temperature;
  __oe_ebox_temperature = value;
}
static inline void canzero_set_ambient_temperature(float value){
  extern float __oe_ambient_temperature;
  __oe_ambient_temperature = value;
}
static inline void canzero_set_cooling_cycle_pressure(float value){
  extern float __oe_cooling_cycle_pressure;
  __oe_cooling_cycle_pressure = value;
}
static inline void canzero_set_fiducial_count1(int16_t value){
  extern int16_t __oe_fiducial_count1;
  __oe_fiducial_count1 = value;
}
static inline void canzero_set_fiducial_count2(int16_t value){
  extern int16_t __oe_fiducial_count2;
  __oe_fiducial_count2 = value;
}
void canzero_set_error_invalid_position(error_flag value);
void canzero_set_error_invalid_velocity_profile(error_flag value);
void canzero_set_error_invalid_acceleration(error_flag value);
static inline void canzero_set_error_bat24_over_temperature(error_flag value){
  extern error_flag __oe_error_bat24_over_temperature;
  __oe_error_bat24_over_temperature = value;
}
static inline void canzero_set_error_bat24_over_temperature_thresh(float value){
  extern float __oe_error_bat24_over_temperature_thresh;
  __oe_error_bat24_over_temperature_thresh = value;
}
static inline void canzero_set_error_bat24_over_temperature_timeout(float value){
  extern float __oe_error_bat24_over_temperature_timeout;
  __oe_error_bat24_over_temperature_timeout = value;
}
static inline void canzero_set_error_supercap_over_temperature(error_flag value){
  extern error_flag __oe_error_supercap_over_temperature;
  __oe_error_supercap_over_temperature = value;
}
static inline void canzero_set_error_supercap_over_temperature_thresh(float value){
  extern float __oe_error_supercap_over_temperature_thresh;
  __oe_error_supercap_over_temperature_thresh = value;
}
static inline void canzero_set_error_supercap_over_temperature_timeout(float value){
  extern float __oe_error_supercap_over_temperature_timeout;
  __oe_error_supercap_over_temperature_timeout = value;
}
static inline void canzero_set_error_buck_over_temperature(error_flag value){
  extern error_flag __oe_error_buck_over_temperature;
  __oe_error_buck_over_temperature = value;
}
static inline void canzero_set_error_buck_over_temperature_thresh(float value){
  extern float __oe_error_buck_over_temperature_thresh;
  __oe_error_buck_over_temperature_thresh = value;
}
static inline void canzero_set_error_buck_over_temperature_timeout(float value){
  extern float __oe_error_buck_over_temperature_timeout;
  __oe_error_buck_over_temperature_timeout = value;
}
static inline void canzero_set_error_ambient_over_temperature(error_flag value){
  extern error_flag __oe_error_ambient_over_temperature;
  __oe_error_ambient_over_temperature = value;
}
static inline void canzero_set_error_ambient_over_temperature_thresh(float value){
  extern float __oe_error_ambient_over_temperature_thresh;
  __oe_error_ambient_over_temperature_thresh = value;
}
static inline void canzero_set_error_ambient_over_temperature_timeout(float value){
  extern float __oe_error_ambient_over_temperature_timeout;
  __oe_error_ambient_over_temperature_timeout = value;
}
void canzero_set_error_cooling_cycle_over_pressure(error_flag value);
static inline void canzero_set_error_cooling_cycle_over_pressure_thresh(float value){
  extern float __oe_error_cooling_cycle_over_pressure_thresh;
  __oe_error_cooling_cycle_over_pressure_thresh = value;
}
static inline void canzero_set_error_cooling_cycle_over_pressure_timeout(float value){
  extern float __oe_error_cooling_cycle_over_pressure_timeout;
  __oe_error_cooling_cycle_over_pressure_timeout = value;
}
void canzero_set_error_cooling_cycle_low_pressure(error_flag value);
static inline void canzero_set_error_cooling_cycle_low_pressure_thresh(float value){
  extern float __oe_error_cooling_cycle_low_pressure_thresh;
  __oe_error_cooling_cycle_low_pressure_thresh = value;
}
static inline void canzero_set_error_cooling_cycle_low_pressure_timeout(float value){
  extern float __oe_error_cooling_cycle_low_pressure_timeout;
  __oe_error_cooling_cycle_low_pressure_timeout = value;
}
void canzero_set_error_mcu_over_temperature(error_flag value);
static inline void canzero_set_error_mcu_over_temperature_thresh(float value){
  extern float __oe_error_mcu_over_temperature_thresh;
  __oe_error_mcu_over_temperature_thresh = value;
}
static inline void canzero_set_error_mcu_over_temperature_timeout(float value){
  extern float __oe_error_mcu_over_temperature_timeout;
  __oe_error_mcu_over_temperature_timeout = value;
}
void canzero_set_error_ebox_over_temperature(error_flag value);
static inline void canzero_set_error_ebox_over_temperature_thresh(float value){
  extern float __oe_error_ebox_over_temperature_thresh;
  __oe_error_ebox_over_temperature_thresh = value;
}
static inline void canzero_set_error_ebox_over_temperature_timeout(float value){
  extern float __oe_error_ebox_over_temperature_timeout;
  __oe_error_ebox_over_temperature_timeout = value;
}
void canzero_set_error_cooling_cycle_over_temperature(error_flag value);
static inline void canzero_set_error_cooling_cycle_over_temperature_thresh(float value){
  extern float __oe_error_cooling_cycle_over_temperature_thresh;
  __oe_error_cooling_cycle_over_temperature_thresh = value;
}
static inline void canzero_set_error_cooling_cycle_over_temperature_timeout(float value){
  extern float __oe_error_cooling_cycle_over_temperature_timeout;
  __oe_error_cooling_cycle_over_temperature_timeout = value;
}
static inline void canzero_set_warn_bat24_over_volt(error_flag value){
  extern error_flag __oe_warn_bat24_over_volt;
  __oe_warn_bat24_over_volt = value;
}
static inline void canzero_set_warn_bat24_over_volt_thresh(float value){
  extern float __oe_warn_bat24_over_volt_thresh;
  __oe_warn_bat24_over_volt_thresh = value;
}
static inline void canzero_set_warn_bat24_under_volt(error_flag value){
  extern error_flag __oe_warn_bat24_under_volt;
  __oe_warn_bat24_under_volt = value;
}
static inline void canzero_set_warn_bat24_under_volt_thresh(float value){
  extern float __oe_warn_bat24_under_volt_thresh;
  __oe_warn_bat24_under_volt_thresh = value;
}
static inline void canzero_set_warn_bat24_over_current(error_flag value){
  extern error_flag __oe_warn_bat24_over_current;
  __oe_warn_bat24_over_current = value;
}
static inline void canzero_set_warn_bat24_over_current_thresh(float value){
  extern float __oe_warn_bat24_over_current_thresh;
  __oe_warn_bat24_over_current_thresh = value;
}
void canzero_set_warn_invalid_position_estimation(error_flag value);
void canzero_set_warn_invalid_position(error_flag value);
void canzero_set_warn_invalid_velocity_profile(error_flag value);
void canzero_set_warn_invalid_acceleration_profile(error_flag value);
static inline void canzero_set_warn_bat24_over_temperature(error_flag value){
  extern error_flag __oe_warn_bat24_over_temperature;
  __oe_warn_bat24_over_temperature = value;
}
static inline void canzero_set_warn_bat24_over_temperature_thresh(float value){
  extern float __oe_warn_bat24_over_temperature_thresh;
  __oe_warn_bat24_over_temperature_thresh = value;
}
static inline void canzero_set_warn_bat24_over_temperature_timeout(float value){
  extern float __oe_warn_bat24_over_temperature_timeout;
  __oe_warn_bat24_over_temperature_timeout = value;
}
void canzero_set_warn_cooling_cycle_over_pressure(error_flag value);
static inline void canzero_set_warn_cooling_cycle_over_pressure_thresh(float value){
  extern float __oe_warn_cooling_cycle_over_pressure_thresh;
  __oe_warn_cooling_cycle_over_pressure_thresh = value;
}
static inline void canzero_set_warn_cooling_cycle_over_pressure_timeout(float value){
  extern float __oe_warn_cooling_cycle_over_pressure_timeout;
  __oe_warn_cooling_cycle_over_pressure_timeout = value;
}
void canzero_set_warn_cooling_cycle_low_pressure(error_flag value);
static inline void canzero_set_warn_cooling_cycle_low_pressure_thresh(float value){
  extern float __oe_warn_cooling_cycle_low_pressure_thresh;
  __oe_warn_cooling_cycle_low_pressure_thresh = value;
}
static inline void canzero_set_warn_cooling_cycle_low_pressure_timeout(float value){
  extern float __oe_warn_cooling_cycle_low_pressure_timeout;
  __oe_warn_cooling_cycle_low_pressure_timeout = value;
}
void canzero_set_warn_mcu_over_temperature(error_flag value);
static inline void canzero_set_warn_mcu_over_temperature_thresh(float value){
  extern float __oe_warn_mcu_over_temperature_thresh;
  __oe_warn_mcu_over_temperature_thresh = value;
}
static inline void canzero_set_warn_mcu_over_temperature_timeout(float value){
  extern float __oe_warn_mcu_over_temperature_timeout;
  __oe_warn_mcu_over_temperature_timeout = value;
}
void canzero_set_warn_ebox_over_temperature(error_flag value);
static inline void canzero_set_warn_ebox_over_temperature_thresh(float value){
  extern float __oe_warn_ebox_over_temperature_thresh;
  __oe_warn_ebox_over_temperature_thresh = value;
}
static inline void canzero_set_warn_ebox_over_temperature_timeout(float value){
  extern float __oe_warn_ebox_over_temperature_timeout;
  __oe_warn_ebox_over_temperature_timeout = value;
}
static inline void canzero_set_warn_supercap_over_temperature(error_flag value){
  extern error_flag __oe_warn_supercap_over_temperature;
  __oe_warn_supercap_over_temperature = value;
}
static inline void canzero_set_warn_supercap_over_temperature_thresh(float value){
  extern float __oe_warn_supercap_over_temperature_thresh;
  __oe_warn_supercap_over_temperature_thresh = value;
}
static inline void canzero_set_warn_supercap_over_temperature_timeout(float value){
  extern float __oe_warn_supercap_over_temperature_timeout;
  __oe_warn_supercap_over_temperature_timeout = value;
}
static inline void canzero_set_warn_buck_over_temperature(error_flag value){
  extern error_flag __oe_warn_buck_over_temperature;
  __oe_warn_buck_over_temperature = value;
}
static inline void canzero_set_warn_buck_over_temperature_thresh(float value){
  extern float __oe_warn_buck_over_temperature_thresh;
  __oe_warn_buck_over_temperature_thresh = value;
}
static inline void canzero_set_warn_buck_over_temperature_timeout(float value){
  extern float __oe_warn_buck_over_temperature_timeout;
  __oe_warn_buck_over_temperature_timeout = value;
}
static inline void canzero_set_error_bat24_over_volt(error_flag value){
  extern error_flag __oe_error_bat24_over_volt;
  __oe_error_bat24_over_volt = value;
}
static inline void canzero_set_error_bat24_over_volt_thresh(float value){
  extern float __oe_error_bat24_over_volt_thresh;
  __oe_error_bat24_over_volt_thresh = value;
}
static inline void canzero_set_error_bat24_under_volt(error_flag value){
  extern error_flag __oe_error_bat24_under_volt;
  __oe_error_bat24_under_volt = value;
}
static inline void canzero_set_error_bat24_under_volt_thresh(float value){
  extern float __oe_error_bat24_under_volt_thresh;
  __oe_error_bat24_under_volt_thresh = value;
}
static inline void canzero_set_error_bat24_over_current(error_flag value){
  extern error_flag __oe_error_bat24_over_current;
  __oe_error_bat24_over_current = value;
}
static inline void canzero_set_error_bat24_over_current_thresh(float value){
  extern float __oe_error_bat24_over_current_thresh;
  __oe_error_bat24_over_current_thresh = value;
}
static inline void canzero_set_warn_ambient_over_temperature(error_flag value){
  extern error_flag __oe_warn_ambient_over_temperature;
  __oe_warn_ambient_over_temperature = value;
}
static inline void canzero_set_warn_ambient_over_temperature_thresh(float value){
  extern float __oe_warn_ambient_over_temperature_thresh;
  __oe_warn_ambient_over_temperature_thresh = value;
}
static inline void canzero_set_warn_ambient_over_temperature_timeout(float value){
  extern float __oe_warn_ambient_over_temperature_timeout;
  __oe_warn_ambient_over_temperature_timeout = value;
}
void canzero_set_warn_cooling_cycle_over_temperature(error_flag value);
static inline void canzero_set_warn_cooling_cycle_over_temperature_thresh(float value){
  extern float __oe_warn_cooling_cycle_over_temperature_thresh;
  __oe_warn_cooling_cycle_over_temperature_thresh = value;
}
static inline void canzero_set_warn_cooling_cycle_over_temperature_timeout(float value){
  extern float __oe_warn_cooling_cycle_over_temperature_timeout;
  __oe_warn_cooling_cycle_over_temperature_timeout = value;
}
static inline void canzero_set_battery_24V_temperature(uint8_t value){
  extern uint8_t __oe_battery_24V_temperature;
  __oe_battery_24V_temperature = value;
}
void canzero_set_error_battery_over_temperature(uint8_t value);
void canzero_set_warn_battery_over_temperature(uint8_t value);
#endif