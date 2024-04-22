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
  input_board_state_INIT = 0,
  input_board_state_RUNNING = 1,
} input_board_state;
typedef enum {
  error_level_OK = 0,
  error_level_INFO = 1,
  error_level_WARNING = 2,
  error_level_ERROR = 3,
} error_level;
typedef enum {
  bool_t_FALSE = 0,
  bool_t_TRUE = 1,
} bool_t;
typedef struct {
  float info_thresh;
  float info_timeout;
  float warning_thresh;
  float warning_timeout;
  float error_thresh;
  float error_timeout;
} error_level_config;
typedef enum {
  error_flag_OK = 0,
  error_flag_ERROR = 1,
} error_flag;
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
static inline bool_t canzero_get_expect_link45_online() {
  extern bool_t __oe_expect_link45_online;
  return __oe_expect_link45_online;
}
static inline float canzero_get_position_estimation() {
  extern float __oe_position_estimation;
  return __oe_position_estimation;
}
static inline error_level canzero_get_error_level_position_estimation() {
  extern error_level __oe_error_level_position_estimation;
  return __oe_error_level_position_estimation;
}
static inline float canzero_get_velocity_estimation() {
  extern float __oe_velocity_estimation;
  return __oe_velocity_estimation;
}
static inline error_level canzero_get_error_level_velocity_estimation() {
  extern error_level __oe_error_level_velocity_estimation;
  return __oe_error_level_velocity_estimation;
}
static inline float canzero_get_acceleration_estimation() {
  extern float __oe_acceleration_estimation;
  return __oe_acceleration_estimation;
}
static inline error_level canzero_get_error_level_acceleration_estimation() {
  extern error_level __oe_error_level_acceleration_estimation;
  return __oe_error_level_acceleration_estimation;
}
static inline float canzero_get_track_length() {
  extern float __oe_track_length;
  return __oe_track_length;
}
static inline float canzero_get_bat24_voltage() {
  extern float __oe_bat24_voltage;
  return __oe_bat24_voltage;
}
static inline error_level canzero_get_error_level_bat24_under_voltage() {
  extern error_level __oe_error_level_bat24_under_voltage;
  return __oe_error_level_bat24_under_voltage;
}
static inline error_level_config canzero_get_error_level_config_bat24_under_voltage() {
  extern error_level_config __oe_error_level_config_bat24_under_voltage;
  return __oe_error_level_config_bat24_under_voltage;
}
static inline error_level canzero_get_error_level_bat24_over_voltage() {
  extern error_level __oe_error_level_bat24_over_voltage;
  return __oe_error_level_bat24_over_voltage;
}
static inline error_level_config canzero_get_error_level_config_bat24_over_voltage() {
  extern error_level_config __oe_error_level_config_bat24_over_voltage;
  return __oe_error_level_config_bat24_over_voltage;
}
static inline float canzero_get_bat24_current() {
  extern float __oe_bat24_current;
  return __oe_bat24_current;
}
static inline error_level canzero_get_error_level_bat24_over_current() {
  extern error_level __oe_error_level_bat24_over_current;
  return __oe_error_level_bat24_over_current;
}
static inline error_level_config canzero_get_error_level_config_bat24_over_current() {
  extern error_level_config __oe_error_level_config_bat24_over_current;
  return __oe_error_level_config_bat24_over_current;
}
static inline float canzero_get_link24_voltage() {
  extern float __oe_link24_voltage;
  return __oe_link24_voltage;
}
static inline error_level canzero_get_error_level_link24_under_voltage() {
  extern error_level __oe_error_level_link24_under_voltage;
  return __oe_error_level_link24_under_voltage;
}
static inline error_level_config canzero_get_error_level_config_link24_under_voltage() {
  extern error_level_config __oe_error_level_config_link24_under_voltage;
  return __oe_error_level_config_link24_under_voltage;
}
static inline error_level canzero_get_error_level_link24_over_voltage() {
  extern error_level __oe_error_level_link24_over_voltage;
  return __oe_error_level_link24_over_voltage;
}
static inline error_level_config canzero_get_error_level_config_link24_over_voltage() {
  extern error_level_config __oe_error_level_config_link24_over_voltage;
  return __oe_error_level_config_link24_over_voltage;
}
static inline float canzero_get_link24_current() {
  extern float __oe_link24_current;
  return __oe_link24_current;
}
static inline error_level canzero_get_error_level_link24_over_current() {
  extern error_level __oe_error_level_link24_over_current;
  return __oe_error_level_link24_over_current;
}
static inline error_level_config canzero_get_error_level_config_link24_over_current() {
  extern error_level_config __oe_error_level_config_link24_over_current;
  return __oe_error_level_config_link24_over_current;
}
static inline float canzero_get_link45_voltage() {
  extern float __oe_link45_voltage;
  return __oe_link45_voltage;
}
static inline error_level canzero_get_error_level_link45_under_voltage() {
  extern error_level __oe_error_level_link45_under_voltage;
  return __oe_error_level_link45_under_voltage;
}
static inline error_level_config canzero_get_error_level_config_link45_under_voltage() {
  extern error_level_config __oe_error_level_config_link45_under_voltage;
  return __oe_error_level_config_link45_under_voltage;
}
static inline error_level canzero_get_error_level_link45_over_voltage() {
  extern error_level __oe_error_level_link45_over_voltage;
  return __oe_error_level_link45_over_voltage;
}
static inline error_level_config canzero_get_error_level_config_link45_over_voltage() {
  extern error_level_config __oe_error_level_config_link45_over_voltage;
  return __oe_error_level_config_link45_over_voltage;
}
static inline float canzero_get_link45_current() {
  extern float __oe_link45_current;
  return __oe_link45_current;
}
static inline error_level canzero_get_error_level_link45_over_current() {
  extern error_level __oe_error_level_link45_over_current;
  return __oe_error_level_link45_over_current;
}
static inline error_level_config canzero_get_error_level_config_link45_over_current() {
  extern error_level_config __oe_error_level_config_link45_over_current;
  return __oe_error_level_config_link45_over_current;
}
static inline sdc_status canzero_get_sdc_status() {
  extern sdc_status __oe_sdc_status;
  return __oe_sdc_status;
}
static inline float canzero_get_cooling_cycle_pressure() {
  extern float __oe_cooling_cycle_pressure;
  return __oe_cooling_cycle_pressure;
}
static inline error_level canzero_get_error_level_cooling_cycle_under_pressure() {
  extern error_level __oe_error_level_cooling_cycle_under_pressure;
  return __oe_error_level_cooling_cycle_under_pressure;
}
static inline error_level_config canzero_get_error_level_config_cooling_cycle_under_pressure() {
  extern error_level_config __oe_error_level_config_cooling_cycle_under_pressure;
  return __oe_error_level_config_cooling_cycle_under_pressure;
}
static inline error_level canzero_get_error_level_cooling_cycle_over_pressure() {
  extern error_level __oe_error_level_cooling_cycle_over_pressure;
  return __oe_error_level_cooling_cycle_over_pressure;
}
static inline error_level_config canzero_get_error_level_config_cooling_cycle_over_pressure() {
  extern error_level_config __oe_error_level_config_cooling_cycle_over_pressure;
  return __oe_error_level_config_cooling_cycle_over_pressure;
}
static inline int16_t canzero_get_fiducial_count1() {
  extern int16_t __oe_fiducial_count1;
  return __oe_fiducial_count1;
}
static inline int16_t canzero_get_fiducial_count2() {
  extern int16_t __oe_fiducial_count2;
  return __oe_fiducial_count2;
}
static inline float canzero_get_mcu_temperature() {
  extern float __oe_mcu_temperature;
  return __oe_mcu_temperature;
}
static inline error_level canzero_get_error_level_mcu_temperature() {
  extern error_level __oe_error_level_mcu_temperature;
  return __oe_error_level_mcu_temperature;
}
static inline error_level_config canzero_get_error_level_config_mcu_temperature() {
  extern error_level_config __oe_error_level_config_mcu_temperature;
  return __oe_error_level_config_mcu_temperature;
}
static inline float canzero_get_cooling_cycle_temperature() {
  extern float __oe_cooling_cycle_temperature;
  return __oe_cooling_cycle_temperature;
}
static inline error_level canzero_get_error_level_cooling_cycle_temperature() {
  extern error_level __oe_error_level_cooling_cycle_temperature;
  return __oe_error_level_cooling_cycle_temperature;
}
static inline error_level_config canzero_get_error_level_config_cooling_temperature() {
  extern error_level_config __oe_error_level_config_cooling_temperature;
  return __oe_error_level_config_cooling_temperature;
}
static inline float canzero_get_bat24_temperature() {
  extern float __oe_bat24_temperature;
  return __oe_bat24_temperature;
}
static inline error_level canzero_get_error_level_bat24_temperature() {
  extern error_level __oe_error_level_bat24_temperature;
  return __oe_error_level_bat24_temperature;
}
static inline error_level_config canzero_get_error_level_config_bat24_temperature() {
  extern error_level_config __oe_error_level_config_bat24_temperature;
  return __oe_error_level_config_bat24_temperature;
}
static inline float canzero_get_supercap_temperature() {
  extern float __oe_supercap_temperature;
  return __oe_supercap_temperature;
}
static inline error_level canzero_get_error_level_supercap_temperature() {
  extern error_level __oe_error_level_supercap_temperature;
  return __oe_error_level_supercap_temperature;
}
static inline error_level_config canzero_get_error_level_config_supercap_temperature() {
  extern error_level_config __oe_error_level_config_supercap_temperature;
  return __oe_error_level_config_supercap_temperature;
}
static inline float canzero_get_buck_temperature() {
  extern float __oe_buck_temperature;
  return __oe_buck_temperature;
}
static inline error_level canzero_get_error_level_buck_temperature() {
  extern error_level __oe_error_level_buck_temperature;
  return __oe_error_level_buck_temperature;
}
static inline error_level_config canzero_get_error_level_config_buck_temperature() {
  extern error_level_config __oe_error_level_config_buck_temperature;
  return __oe_error_level_config_buck_temperature;
}
static inline float canzero_get_ebox_temperature() {
  extern float __oe_ebox_temperature;
  return __oe_ebox_temperature;
}
static inline error_level canzero_get_error_level_ebox_temperature() {
  extern error_level __oe_error_level_ebox_temperature;
  return __oe_error_level_ebox_temperature;
}
static inline error_level_config canzero_get_error_level_config_ebox_temperature() {
  extern error_level_config __oe_error_level_config_ebox_temperature;
  return __oe_error_level_config_ebox_temperature;
}
static inline float canzero_get_ambient_temperature() {
  extern float __oe_ambient_temperature;
  return __oe_ambient_temperature;
}
static inline error_level canzero_get_error_level_ambient_temperature() {
  extern error_level __oe_error_level_ambient_temperature;
  return __oe_error_level_ambient_temperature;
}
static inline error_level_config canzero_get_error_level_config_ambient_temperature() {
  extern error_level_config __oe_error_level_config_ambient_temperature;
  return __oe_error_level_config_ambient_temperature;
}
static inline error_flag canzero_get_assertion_fault() {
  extern error_flag __oe_assertion_fault;
  return __oe_assertion_fault;
}
static inline uint8_t canzero_get_battery_24V_temperature() {
  extern uint8_t __oe_battery_24V_temperature;
  return __oe_battery_24V_temperature;
}
static inline uint8_t canzero_get_error_level_bat24_over_currrent() {
  extern uint8_t __oe_error_level_bat24_over_currrent;
  return __oe_error_level_bat24_over_currrent;
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
  sdc_status sdc_status;
  input_board_state state;
} canzero_message_input_board_stream_state;
static const uint32_t canzero_message_input_board_stream_state_id = 0x9A;
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
  error_level error_level_position_estimation;
  error_level error_level_velocity_estimation;
  error_level error_level_acceleration_estimation;
  error_level error_level_bat24_under_voltage;
  error_level error_level_bat24_over_voltage;
  uint8_t error_level_bat24_over_currrent;
  error_level error_level_link24_under_voltage;
  error_level error_level_link24_over_voltage;
  error_level error_level_link24_over_current;
  error_level error_level_link45_under_voltage;
  error_level error_level_link45_over_voltage;
  error_level error_level_link45_over_current;
  error_level error_level_cooling_cycle_under_pressure;
  error_level error_level_cooling_cycle_over_pressure;
  error_level error_level_mcu_temperature;
  error_level error_level_cooling_cycle_temperature;
  error_level error_level_bat24_temperature;
  error_level error_level_supercap_temperature;
  error_level error_level_buck_temperature;
  error_level error_level_ebox_temperature;
  error_level error_level_ambient_temperature;
} canzero_message_input_board_stream_errors;
static const uint32_t canzero_message_input_board_stream_errors_id = 0x5A;
typedef struct {
  sdc_status sdc_status;
} canzero_message_input_board_stream_sdc_status;
static const uint32_t canzero_message_input_board_stream_sdc_status_id = 0x7A;
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
static void canzero_serialize_canzero_message_input_board_stream_state(canzero_message_input_board_stream_state* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x9A;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->sdc_status & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->state & (0xFF >> (8 - 1))) << 1;
}
static void canzero_serialize_canzero_message_input_board_stream_state_estimation(canzero_message_input_board_stream_state_estimation* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0xBA;
  frame->dlc = 8;
  float position_estimation_0 = (msg->position_estimation - -100) / 0.00000004656612874161595;
  if (position_estimation_0 > 4294967296.000) {
    position_estimation_0 = 4294967296.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) position_estimation_0;
  float velocity_estimation_32 = (msg->velocity_estimation - -10) / 0.00030518043793392844;
  if (velocity_estimation_32 > 4294901760.000) {
    velocity_estimation_32 = 4294901760.000;
  }
  ((uint32_t*)data)[1] = (uint32_t) velocity_estimation_32;
  float acceleration_estimation_48 = (msg->acceleration_estimation - -5) / 0.00008392462043183032;
  if (acceleration_estimation_48 > 4294901760.000) {
    acceleration_estimation_48 = 4294901760.000;
  }
  ((uint32_t*)data)[1] |= (uint32_t) acceleration_estimation_48 << 16;
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
static void canzero_serialize_canzero_message_input_board_stream_errors(canzero_message_input_board_stream_errors* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x5A;
  frame->dlc = 6;
  ((uint32_t*)data)[0] = (uint8_t)(msg->error_level_position_estimation & (0xFF >> (8 - 2)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_velocity_estimation & (0xFF >> (8 - 2))) << 2;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_acceleration_estimation & (0xFF >> (8 - 2))) << 4;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_bat24_under_voltage & (0xFF >> (8 - 2))) << 6;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_bat24_over_voltage & (0xFF >> (8 - 2))) << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_bat24_over_currrent & (0xFF >> (8 - 1))) << 10;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_link24_under_voltage & (0xFF >> (8 - 2))) << 11;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_link24_over_voltage & (0xFF >> (8 - 2))) << 13;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_link24_over_current & (0xFF >> (8 - 2))) << 15;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_link45_under_voltage & (0xFF >> (8 - 2))) << 17;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_link45_over_voltage & (0xFF >> (8 - 2))) << 19;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_link45_over_current & (0xFF >> (8 - 2))) << 21;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_cooling_cycle_under_pressure & (0xFF >> (8 - 2))) << 23;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_cooling_cycle_over_pressure & (0xFF >> (8 - 2))) << 25;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_mcu_temperature & (0xFF >> (8 - 2))) << 27;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->error_level_cooling_cycle_temperature & (0xFF >> (8 - 2))) << 29;
  ((uint64_t*)data)[0] |= ((uint64_t)(uint8_t)(msg->error_level_bat24_temperature & (0xFF >> (8 - 2)))) << 31 ;
  ((uint32_t*)data)[1] |= (uint8_t)(msg->error_level_supercap_temperature & (0xFF >> (8 - 2))) << 1;
  ((uint32_t*)data)[1] |= (uint8_t)(msg->error_level_buck_temperature & (0xFF >> (8 - 2))) << 3;
  ((uint32_t*)data)[1] |= (uint8_t)(msg->error_level_ebox_temperature & (0xFF >> (8 - 2))) << 5;
  ((uint32_t*)data)[1] |= (uint8_t)(msg->error_level_ambient_temperature & (0xFF >> (8 - 2))) << 7;
}
static void canzero_serialize_canzero_message_input_board_stream_sdc_status(canzero_message_input_board_stream_sdc_status* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x7A;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->sdc_status & (0xFF >> (8 - 1)));
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
static void canzero_deserialize_canzero_message_input_board_stream_state(canzero_frame* frame, canzero_message_input_board_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->sdc_status = (sdc_status)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->state = (input_board_state)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_input_board_stream_state_estimation(canzero_frame* frame, canzero_message_input_board_stream_state_estimation* msg) {
  uint8_t* data = frame->data;
  msg->position_estimation = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100;
  msg->velocity_estimation = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10;
  msg->acceleration_estimation = ((((uint32_t*)data)[1] >> 16) & (0xFFFFFFFF >> (32 - 16))) * 0.00008392462043183032 + -5;
}
static void canzero_deserialize_canzero_message_input_board_stream_safety_sensors(canzero_frame* frame, canzero_message_input_board_stream_safety_sensors* msg) {
  uint8_t* data = frame->data;
  msg->mcu_temperature = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->cooling_cycle_temperature = ((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->battery_24V_temperature = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 1)));
  msg->ebox_temperature = ((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->cooling_cycle_pressure = ((((uint64_t*)data)[0] >> 25) & (0xFFFFFFFFFFFFFFFF >> (64 - 8))) * 0.0392156862745098 + -1;
}
static void canzero_deserialize_canzero_message_input_board_stream_errors(canzero_frame* frame, canzero_message_input_board_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->error_level_position_estimation = (error_level)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_velocity_estimation = (error_level)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_acceleration_estimation = (error_level)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_bat24_under_voltage = (error_level)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_bat24_over_voltage = (error_level)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_bat24_over_currrent = ((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->error_level_link24_under_voltage = (error_level)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_link24_over_voltage = (error_level)((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_link24_over_current = (error_level)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_link45_under_voltage = (error_level)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_link45_over_voltage = (error_level)((((uint32_t*)data)[0] >> 19) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_link45_over_current = (error_level)((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_cooling_cycle_under_pressure = (error_level)((((uint32_t*)data)[0] >> 23) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_cooling_cycle_over_pressure = (error_level)((((uint32_t*)data)[0] >> 25) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 27) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_cooling_cycle_temperature = (error_level)((((uint32_t*)data)[0] >> 29) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_bat24_temperature = (error_level)((((uint64_t*)data)[0] >> 31) & (0xFFFFFFFFFFFFFFFF >> (64 - 2)));
  msg->error_level_supercap_temperature = (error_level)((((uint32_t*)data)[1] >> 1) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_buck_temperature = (error_level)((((uint32_t*)data)[1] >> 3) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_ebox_temperature = (error_level)((((uint32_t*)data)[1] >> 5) & (0xFFFFFFFF >> (32 - 2)));
  msg->error_level_ambient_temperature = (error_level)((((uint32_t*)data)[1] >> 7) & (0xFFFFFFFF >> (32 - 2)));
}
static void canzero_deserialize_canzero_message_input_board_stream_sdc_status(canzero_frame* frame, canzero_message_input_board_stream_sdc_status* msg) {
  uint8_t* data = frame->data;
  msg->sdc_status = (sdc_status)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
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
static inline void canzero_set_expect_link45_online(bool_t value){
  extern bool_t __oe_expect_link45_online;
  __oe_expect_link45_online = value;
}
static inline void canzero_set_position_estimation(float value){
  extern float __oe_position_estimation;
  __oe_position_estimation = value;
}
void canzero_set_error_level_position_estimation(error_level value);
static inline void canzero_set_velocity_estimation(float value){
  extern float __oe_velocity_estimation;
  __oe_velocity_estimation = value;
}
void canzero_set_error_level_velocity_estimation(error_level value);
static inline void canzero_set_acceleration_estimation(float value){
  extern float __oe_acceleration_estimation;
  __oe_acceleration_estimation = value;
}
void canzero_set_error_level_acceleration_estimation(error_level value);
static inline void canzero_set_track_length(float value){
  extern float __oe_track_length;
  __oe_track_length = value;
}
static inline void canzero_set_bat24_voltage(float value){
  extern float __oe_bat24_voltage;
  __oe_bat24_voltage = value;
}
void canzero_set_error_level_bat24_under_voltage(error_level value);
static inline void canzero_set_error_level_config_bat24_under_voltage(error_level_config value){
  extern error_level_config __oe_error_level_config_bat24_under_voltage;
  __oe_error_level_config_bat24_under_voltage = value;
}
void canzero_set_error_level_bat24_over_voltage(error_level value);
static inline void canzero_set_error_level_config_bat24_over_voltage(error_level_config value){
  extern error_level_config __oe_error_level_config_bat24_over_voltage;
  __oe_error_level_config_bat24_over_voltage = value;
}
static inline void canzero_set_bat24_current(float value){
  extern float __oe_bat24_current;
  __oe_bat24_current = value;
}
static inline void canzero_set_error_level_bat24_over_current(error_level value){
  extern error_level __oe_error_level_bat24_over_current;
  __oe_error_level_bat24_over_current = value;
}
static inline void canzero_set_error_level_config_bat24_over_current(error_level_config value){
  extern error_level_config __oe_error_level_config_bat24_over_current;
  __oe_error_level_config_bat24_over_current = value;
}
static inline void canzero_set_link24_voltage(float value){
  extern float __oe_link24_voltage;
  __oe_link24_voltage = value;
}
void canzero_set_error_level_link24_under_voltage(error_level value);
static inline void canzero_set_error_level_config_link24_under_voltage(error_level_config value){
  extern error_level_config __oe_error_level_config_link24_under_voltage;
  __oe_error_level_config_link24_under_voltage = value;
}
void canzero_set_error_level_link24_over_voltage(error_level value);
static inline void canzero_set_error_level_config_link24_over_voltage(error_level_config value){
  extern error_level_config __oe_error_level_config_link24_over_voltage;
  __oe_error_level_config_link24_over_voltage = value;
}
static inline void canzero_set_link24_current(float value){
  extern float __oe_link24_current;
  __oe_link24_current = value;
}
void canzero_set_error_level_link24_over_current(error_level value);
static inline void canzero_set_error_level_config_link24_over_current(error_level_config value){
  extern error_level_config __oe_error_level_config_link24_over_current;
  __oe_error_level_config_link24_over_current = value;
}
static inline void canzero_set_link45_voltage(float value){
  extern float __oe_link45_voltage;
  __oe_link45_voltage = value;
}
void canzero_set_error_level_link45_under_voltage(error_level value);
static inline void canzero_set_error_level_config_link45_under_voltage(error_level_config value){
  extern error_level_config __oe_error_level_config_link45_under_voltage;
  __oe_error_level_config_link45_under_voltage = value;
}
void canzero_set_error_level_link45_over_voltage(error_level value);
static inline void canzero_set_error_level_config_link45_over_voltage(error_level_config value){
  extern error_level_config __oe_error_level_config_link45_over_voltage;
  __oe_error_level_config_link45_over_voltage = value;
}
static inline void canzero_set_link45_current(float value){
  extern float __oe_link45_current;
  __oe_link45_current = value;
}
void canzero_set_error_level_link45_over_current(error_level value);
static inline void canzero_set_error_level_config_link45_over_current(error_level_config value){
  extern error_level_config __oe_error_level_config_link45_over_current;
  __oe_error_level_config_link45_over_current = value;
}
void canzero_set_sdc_status(sdc_status value);
static inline void canzero_set_cooling_cycle_pressure(float value){
  extern float __oe_cooling_cycle_pressure;
  __oe_cooling_cycle_pressure = value;
}
void canzero_set_error_level_cooling_cycle_under_pressure(error_level value);
static inline void canzero_set_error_level_config_cooling_cycle_under_pressure(error_level_config value){
  extern error_level_config __oe_error_level_config_cooling_cycle_under_pressure;
  __oe_error_level_config_cooling_cycle_under_pressure = value;
}
void canzero_set_error_level_cooling_cycle_over_pressure(error_level value);
static inline void canzero_set_error_level_config_cooling_cycle_over_pressure(error_level_config value){
  extern error_level_config __oe_error_level_config_cooling_cycle_over_pressure;
  __oe_error_level_config_cooling_cycle_over_pressure = value;
}
static inline void canzero_set_fiducial_count1(int16_t value){
  extern int16_t __oe_fiducial_count1;
  __oe_fiducial_count1 = value;
}
static inline void canzero_set_fiducial_count2(int16_t value){
  extern int16_t __oe_fiducial_count2;
  __oe_fiducial_count2 = value;
}
static inline void canzero_set_mcu_temperature(float value){
  extern float __oe_mcu_temperature;
  __oe_mcu_temperature = value;
}
void canzero_set_error_level_mcu_temperature(error_level value);
static inline void canzero_set_error_level_config_mcu_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_mcu_temperature;
  __oe_error_level_config_mcu_temperature = value;
}
static inline void canzero_set_cooling_cycle_temperature(float value){
  extern float __oe_cooling_cycle_temperature;
  __oe_cooling_cycle_temperature = value;
}
void canzero_set_error_level_cooling_cycle_temperature(error_level value);
static inline void canzero_set_error_level_config_cooling_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_cooling_temperature;
  __oe_error_level_config_cooling_temperature = value;
}
static inline void canzero_set_bat24_temperature(float value){
  extern float __oe_bat24_temperature;
  __oe_bat24_temperature = value;
}
void canzero_set_error_level_bat24_temperature(error_level value);
static inline void canzero_set_error_level_config_bat24_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_bat24_temperature;
  __oe_error_level_config_bat24_temperature = value;
}
static inline void canzero_set_supercap_temperature(float value){
  extern float __oe_supercap_temperature;
  __oe_supercap_temperature = value;
}
void canzero_set_error_level_supercap_temperature(error_level value);
static inline void canzero_set_error_level_config_supercap_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_supercap_temperature;
  __oe_error_level_config_supercap_temperature = value;
}
static inline void canzero_set_buck_temperature(float value){
  extern float __oe_buck_temperature;
  __oe_buck_temperature = value;
}
void canzero_set_error_level_buck_temperature(error_level value);
static inline void canzero_set_error_level_config_buck_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_buck_temperature;
  __oe_error_level_config_buck_temperature = value;
}
static inline void canzero_set_ebox_temperature(float value){
  extern float __oe_ebox_temperature;
  __oe_ebox_temperature = value;
}
void canzero_set_error_level_ebox_temperature(error_level value);
static inline void canzero_set_error_level_config_ebox_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_ebox_temperature;
  __oe_error_level_config_ebox_temperature = value;
}
static inline void canzero_set_ambient_temperature(float value){
  extern float __oe_ambient_temperature;
  __oe_ambient_temperature = value;
}
void canzero_set_error_level_ambient_temperature(error_level value);
static inline void canzero_set_error_level_config_ambient_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_ambient_temperature;
  __oe_error_level_config_ambient_temperature = value;
}
static inline void canzero_set_assertion_fault(error_flag value){
  extern error_flag __oe_assertion_fault;
  __oe_assertion_fault = value;
}
static inline void canzero_set_battery_24V_temperature(uint8_t value){
  extern uint8_t __oe_battery_24V_temperature;
  __oe_battery_24V_temperature = value;
}
void canzero_set_error_level_bat24_over_currrent(uint8_t value);
#endif