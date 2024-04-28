#ifndef CANZERO_H
#define CANZERO_H
#include <cinttypes>
#include <cstddef>
typedef struct {
  uint16_t m_od_index;
  uint8_t m_client_id;
  uint8_t m_server_id;
} get_req_header;
typedef struct {
  uint8_t m_sof;
  uint8_t m_eof;
  uint8_t m_toggle;
  uint16_t m_od_index;
  uint8_t m_client_id;
  uint8_t m_server_id;
} set_req_header;
typedef enum {
  node_id_motor_driver = 0,
  node_id_input_board = 1,
  node_id_guidance_board_front = 2,
  node_id_guidance_board_back = 3,
  node_id_levitation_board_front = 4,
  node_id_levitation_board_middle = 5,
  node_id_levitation_board_back = 6,
} node_id;
typedef struct {
  uint8_t m_sof;
  uint8_t m_eof;
  uint8_t m_toggle;
  uint16_t m_od_index;
  uint8_t m_client_id;
  uint8_t m_server_id;
} get_resp_header;
typedef enum {
  set_resp_erno_Success = 0,
  set_resp_erno_Error = 1,
} set_resp_erno;
typedef struct {
  uint16_t m_od_index;
  uint8_t m_client_id;
  uint8_t m_server_id;
  set_resp_erno m_erno;
} set_resp_header;
typedef enum {
  input_board_state_INIT = 0,
  input_board_state_RUNNING = 1,
} input_board_state;
typedef enum {
  sdc_status_OPEN = 0,
  sdc_status_CLOSED = 1,
} sdc_status;
typedef enum {
  error_level_OK = 0,
  error_level_INFO = 1,
  error_level_WARNING = 2,
  error_level_ERROR = 3,
} error_level;
typedef enum {
  error_flag_OK = 0,
  error_flag_ERROR = 1,
} error_flag;
typedef enum {
  bool_t_FALSE = 0,
  bool_t_TRUE = 1,
} bool_t;
typedef struct {
  bool_t m_ignore_info;
  float m_info_thresh;
  float m_info_timeout;
  bool_t m_ignore_warning;
  float m_warning_thresh;
  float m_warning_timeout;
  bool_t m_ignore_error;
  float m_error_thresh;
  float m_error_timeout;
} error_level_config;
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
static inline sdc_status canzero_get_sdc_status() {
  extern sdc_status __oe_sdc_status;
  return __oe_sdc_status;
}
static inline float canzero_get_position() {
  extern float __oe_position;
  return __oe_position;
}
static inline float canzero_get_velocity() {
  extern float __oe_velocity;
  return __oe_velocity;
}
static inline float canzero_get_acceleration() {
  extern float __oe_acceleration;
  return __oe_acceleration;
}
static inline uint16_t canzero_get_linear_encoder_count() {
  extern uint16_t __oe_linear_encoder_count;
  return __oe_linear_encoder_count;
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
static inline bool_t canzero_get_link45_expect_online() {
  extern bool_t __oe_link45_expect_online;
  return __oe_link45_expect_online;
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
typedef struct {
  get_resp_header m_header;
  uint32_t m_data;
} canzero_message_get_resp;
static const uint32_t canzero_message_get_resp_id = 0x7D;
typedef struct {
  set_resp_header m_header;
} canzero_message_set_resp;
static const uint32_t canzero_message_set_resp_id = 0x7C;
typedef struct {
  input_board_state m_state;
  sdc_status m_sdc_status;
} canzero_message_input_board_stream_state;
static const uint32_t canzero_message_input_board_stream_state_id = 0x4F;
typedef struct {
  float m_position;
  float m_velocity;
  float m_acceleration;
  uint16_t m_linear_encoder_count;
} canzero_message_input_board_stream_position_estimation;
static const uint32_t canzero_message_input_board_stream_position_estimation_id = 0x50;
typedef struct {
  float m_bat24_voltage;
  float m_bat24_current;
} canzero_message_input_board_stream_bat24;
static const uint32_t canzero_message_input_board_stream_bat24_id = 0x55;
typedef struct {
  float m_link24_voltage;
  float m_link24_current;
} canzero_message_input_board_stream_link24;
static const uint32_t canzero_message_input_board_stream_link24_id = 0x52;
typedef struct {
  float m_link45_voltage;
  float m_link45_current;
} canzero_message_input_board_stream_link45;
static const uint32_t canzero_message_input_board_stream_link45_id = 0x51;
typedef struct {
  float m_cooling_cycle_pressure;
  float m_cooling_cycle_temperature;
} canzero_message_input_board_stream_cooling;
static const uint32_t canzero_message_input_board_stream_cooling_id = 0x54;
typedef struct {
  float m_mcu_temperature;
  float m_bat24_temperature;
  float m_supercap_temperature;
  float m_buck_temperature;
  float m_ebox_temperature;
  float m_ambient_temperature;
} canzero_message_input_board_stream_temperatures;
static const uint32_t canzero_message_input_board_stream_temperatures_id = 0x4E;
typedef struct {
  error_level m_error_level_bat24_under_voltage;
  error_level m_error_level_bat24_over_voltage;
  error_level m_error_level_bat24_over_current;
  error_level m_error_level_link24_under_voltage;
  error_level m_error_level_link24_over_voltage;
  error_level m_error_level_link24_over_current;
  error_level m_error_level_link45_under_voltage;
  error_level m_error_level_link45_over_voltage;
  error_level m_error_level_link45_over_current;
  error_level m_error_level_cooling_cycle_under_pressure;
  error_level m_error_level_cooling_cycle_over_pressure;
  error_level m_error_level_mcu_temperature;
  error_level m_error_level_cooling_cycle_temperature;
  error_level m_error_level_bat24_temperature;
  error_level m_error_level_supercap_temperature;
  error_level m_error_level_buck_temperature;
  error_level m_error_level_ebox_temperature;
  error_level m_error_level_ambient_temperature;
  error_flag m_assertion_fault;
} canzero_message_input_board_stream_errors;
static const uint32_t canzero_message_input_board_stream_errors_id = 0x53;
typedef struct {
  node_id m_node_id;
} canzero_message_heartbeat;
static const uint32_t canzero_message_heartbeat_id = 0x9F;
typedef struct {
  get_req_header m_header;
} canzero_message_get_req;
static const uint32_t canzero_message_get_req_id = 0x7F;
typedef struct {
  set_req_header m_header;
  uint32_t m_data;
} canzero_message_set_req;
static const uint32_t canzero_message_set_req_id = 0x7E;
static void canzero_serialize_canzero_message_get_resp(canzero_message_get_resp* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x7D;
  frame->dlc = 8;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_header.m_sof & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_eof & (0xFF >> (8 - 1))) << 1;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_toggle & (0xFF >> (8 - 1))) << 2;
  ((uint32_t*)data)[0] |= (uint16_t)(msg->m_header.m_od_index & (0xFFFF >> (16 - 13))) << 3;
  ((uint32_t*)data)[0] |= msg->m_header.m_client_id << 16;
  ((uint32_t*)data)[0] |= msg->m_header.m_server_id << 24;
  ((uint32_t*)data)[1] = msg->m_data;
}
static void canzero_serialize_canzero_message_set_resp(canzero_message_set_resp* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x7C;
  frame->dlc = 4;
  ((uint32_t*)data)[0] = (uint16_t)(msg->m_header.m_od_index & (0xFFFF >> (16 - 13)));
  ((uint32_t*)data)[0] |= msg->m_header.m_client_id << 13;
  ((uint32_t*)data)[0] |= msg->m_header.m_server_id << 21;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_erno & (0xFF >> (8 - 1))) << 29;
}
static void canzero_serialize_canzero_message_input_board_stream_state(canzero_message_input_board_stream_state* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x4F;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_state & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_sdc_status & (0xFF >> (8 - 1))) << 1;
}
static void canzero_serialize_canzero_message_input_board_stream_position_estimation(canzero_message_input_board_stream_position_estimation* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x50;
  frame->dlc = 8;
  float position_0 = (msg->m_position - -0) / 0.0007629510948348211;
  if (position_0 > 4294901760.000) {
    position_0 = 4294901760.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) position_0;
  float velocity_16 = (msg->m_velocity - -10) / 0.00030518043793392844;
  if (velocity_16 > 4294901760.000) {
    velocity_16 = 4294901760.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) velocity_16 << 16;
  float acceleration_32 = (msg->m_acceleration - -5) / 0.00008392462043183032;
  if (acceleration_32 > 4294901760.000) {
    acceleration_32 = 4294901760.000;
  }
  ((uint32_t*)data)[1] = (uint32_t) acceleration_32;
  ((uint32_t*)data)[1] |= msg->m_linear_encoder_count << 16;
}
static void canzero_serialize_canzero_message_input_board_stream_bat24(canzero_message_input_board_stream_bat24* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x55;
  frame->dlc = 8;
  float bat24_voltage_0 = (msg->m_bat24_voltage - 0) / 0.000000011641532185403987;
  if (bat24_voltage_0 > 4294967296.000) {
    bat24_voltage_0 = 4294967296.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) bat24_voltage_0;
  float bat24_current_32 = (msg->m_bat24_current - -30) / 0.000000013969838622484784;
  if (bat24_current_32 > 4294967296.000) {
    bat24_current_32 = 4294967296.000;
  }
  ((uint32_t*)data)[1] = (uint32_t) bat24_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_link24(canzero_message_input_board_stream_link24* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x52;
  frame->dlc = 8;
  float link24_voltage_0 = (msg->m_link24_voltage - 0) / 0.000000011641532185403987;
  if (link24_voltage_0 > 4294967296.000) {
    link24_voltage_0 = 4294967296.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) link24_voltage_0;
  float link24_current_32 = (msg->m_link24_current - -30) / 0.000000013969838622484784;
  if (link24_current_32 > 4294967296.000) {
    link24_current_32 = 4294967296.000;
  }
  ((uint32_t*)data)[1] = (uint32_t) link24_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_link45(canzero_message_input_board_stream_link45* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x51;
  frame->dlc = 8;
  float link45_voltage_0 = (msg->m_link45_voltage - 0) / 0.00000023283064370807974;
  if (link45_voltage_0 > 4294967296.000) {
    link45_voltage_0 = 4294967296.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) link45_voltage_0;
  float link45_current_32 = (msg->m_link45_current - -1000) / 0.0000004656612874161595;
  if (link45_current_32 > 4294967296.000) {
    link45_current_32 = 4294967296.000;
  }
  ((uint32_t*)data)[1] = (uint32_t) link45_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_cooling(canzero_message_input_board_stream_cooling* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x54;
  frame->dlc = 2;
  float cooling_cycle_pressure_0 = (msg->m_cooling_cycle_pressure - -1) / 0.0392156862745098;
  if (cooling_cycle_pressure_0 > 4278190080.000) {
    cooling_cycle_pressure_0 = 4278190080.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) cooling_cycle_pressure_0;
  float cooling_cycle_temperature_8 = (msg->m_cooling_cycle_temperature - -1) / 0.592156862745098;
  if (cooling_cycle_temperature_8 > 4278190080.000) {
    cooling_cycle_temperature_8 = 4278190080.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) cooling_cycle_temperature_8 << 8;
}
static void canzero_serialize_canzero_message_input_board_stream_temperatures(canzero_message_input_board_stream_temperatures* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x4E;
  frame->dlc = 6;
  float mcu_temperature_0 = (msg->m_mcu_temperature - -1) / 0.592156862745098;
  if (mcu_temperature_0 > 4278190080.000) {
    mcu_temperature_0 = 4278190080.000;
  }
  ((uint32_t*)data)[0] = (uint32_t) mcu_temperature_0;
  float bat24_temperature_8 = (msg->m_bat24_temperature - -1) / 0.592156862745098;
  if (bat24_temperature_8 > 4278190080.000) {
    bat24_temperature_8 = 4278190080.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) bat24_temperature_8 << 8;
  float supercap_temperature_16 = (msg->m_supercap_temperature - -1) / 0.592156862745098;
  if (supercap_temperature_16 > 4278190080.000) {
    supercap_temperature_16 = 4278190080.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) supercap_temperature_16 << 16;
  float buck_temperature_24 = (msg->m_buck_temperature - -1) / 0.592156862745098;
  if (buck_temperature_24 > 4278190080.000) {
    buck_temperature_24 = 4278190080.000;
  }
  ((uint32_t*)data)[0] |= (uint32_t) buck_temperature_24 << 24;
  float ebox_temperature_32 = (msg->m_ebox_temperature - -1) / 0.592156862745098;
  if (ebox_temperature_32 > 4278190080.000) {
    ebox_temperature_32 = 4278190080.000;
  }
  ((uint32_t*)data)[1] = (uint32_t) ebox_temperature_32;
  float ambient_temperature_40 = (msg->m_ambient_temperature - -1) / 0.592156862745098;
  if (ambient_temperature_40 > 4278190080.000) {
    ambient_temperature_40 = 4278190080.000;
  }
  ((uint32_t*)data)[1] |= (uint32_t) ambient_temperature_40 << 8;
}
static void canzero_serialize_canzero_message_input_board_stream_errors(canzero_message_input_board_stream_errors* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x53;
  frame->dlc = 5;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_error_level_bat24_under_voltage & (0xFF >> (8 - 2)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_over_voltage & (0xFF >> (8 - 2))) << 2;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_over_current & (0xFF >> (8 - 2))) << 4;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link24_under_voltage & (0xFF >> (8 - 2))) << 6;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link24_over_voltage & (0xFF >> (8 - 2))) << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link24_over_current & (0xFF >> (8 - 2))) << 10;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_under_voltage & (0xFF >> (8 - 2))) << 12;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_over_voltage & (0xFF >> (8 - 2))) << 14;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_over_current & (0xFF >> (8 - 2))) << 16;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_cooling_cycle_under_pressure & (0xFF >> (8 - 2))) << 18;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_cooling_cycle_over_pressure & (0xFF >> (8 - 2))) << 20;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_mcu_temperature & (0xFF >> (8 - 2))) << 22;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_cooling_cycle_temperature & (0xFF >> (8 - 2))) << 24;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_temperature & (0xFF >> (8 - 2))) << 26;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_supercap_temperature & (0xFF >> (8 - 2))) << 28;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_buck_temperature & (0xFF >> (8 - 2))) << 30;
  ((uint32_t*)data)[1] = (uint8_t)(msg->m_error_level_ebox_temperature & (0xFF >> (8 - 2)));
  ((uint32_t*)data)[1] |= (uint8_t)(msg->m_error_level_ambient_temperature & (0xFF >> (8 - 2))) << 2;
  ((uint32_t*)data)[1] |= (uint8_t)(msg->m_assertion_fault & (0xFF >> (8 - 1))) << 4;
}
static void canzero_serialize_canzero_message_heartbeat(canzero_message_heartbeat* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x9F;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_node_id & (0xFF >> (8 - 3)));
}
static void canzero_serialize_canzero_message_get_req(canzero_message_get_req* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x7F;
  frame->dlc = 4;
  ((uint32_t*)data)[0] = (uint16_t)(msg->m_header.m_od_index & (0xFFFF >> (16 - 13)));
  ((uint32_t*)data)[0] |= msg->m_header.m_client_id << 13;
  ((uint32_t*)data)[0] |= msg->m_header.m_server_id << 21;
}
static void canzero_serialize_canzero_message_set_req(canzero_message_set_req* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  frame->id = 0x7E;
  frame->dlc = 8;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_header.m_sof & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_eof & (0xFF >> (8 - 1))) << 1;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_toggle & (0xFF >> (8 - 1))) << 2;
  ((uint32_t*)data)[0] |= (uint16_t)(msg->m_header.m_od_index & (0xFFFF >> (16 - 13))) << 3;
  ((uint32_t*)data)[0] |= msg->m_header.m_client_id << 16;
  ((uint32_t*)data)[0] |= msg->m_header.m_server_id << 24;
  ((uint32_t*)data)[1] = msg->m_data;
}
static void canzero_deserialize_canzero_message_get_resp(canzero_frame* frame, canzero_message_get_resp* msg) {
  uint8_t* data = frame->data;
  msg->m_header.m_sof = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_header.m_eof = ((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_header.m_toggle = ((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_header.m_od_index = ((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 13)));
  msg->m_header.m_client_id = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_header.m_server_id = ((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_data = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 32)));
}
static void canzero_deserialize_canzero_message_set_resp(canzero_frame* frame, canzero_message_set_resp* msg) {
  uint8_t* data = frame->data;
  msg->m_header.m_od_index = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 13)));
  msg->m_header.m_client_id = ((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_header.m_server_id = ((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_header.m_erno = (set_resp_erno)((((uint32_t*)data)[0] >> 29) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_input_board_stream_state(canzero_frame* frame, canzero_message_input_board_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (input_board_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_input_board_stream_position_estimation(canzero_frame* frame, canzero_message_input_board_stream_position_estimation* msg) {
  uint8_t* data = frame->data;
  msg->m_position = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 16))) * 0.0007629510948348211 + -0;
  msg->m_velocity = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10;
  msg->m_acceleration = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 16))) * 0.00008392462043183032 + -5;
  msg->m_linear_encoder_count = ((((uint32_t*)data)[1] >> 16) & (0xFFFFFFFF >> (32 - 16)));
}
static void canzero_deserialize_canzero_message_input_board_stream_bat24(canzero_frame* frame, canzero_message_input_board_stream_bat24* msg) {
  uint8_t* data = frame->data;
  msg->m_bat24_voltage = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0;
  msg->m_bat24_current = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30;
}
static void canzero_deserialize_canzero_message_input_board_stream_link24(canzero_frame* frame, canzero_message_input_board_stream_link24* msg) {
  uint8_t* data = frame->data;
  msg->m_link24_voltage = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0;
  msg->m_link24_current = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30;
}
static void canzero_deserialize_canzero_message_input_board_stream_link45(canzero_frame* frame, canzero_message_input_board_stream_link45* msg) {
  uint8_t* data = frame->data;
  msg->m_link45_voltage = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 32))) * 0.00000023283064370807974 + 0;
  msg->m_link45_current = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 32))) * 0.0000004656612874161595 + -1000;
}
static void canzero_deserialize_canzero_message_input_board_stream_cooling(canzero_frame* frame, canzero_message_input_board_stream_cooling* msg) {
  uint8_t* data = frame->data;
  msg->m_cooling_cycle_pressure = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 8))) * 0.0392156862745098 + -1;
  msg->m_cooling_cycle_temperature = ((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
}
static void canzero_deserialize_canzero_message_input_board_stream_temperatures(canzero_frame* frame, canzero_message_input_board_stream_temperatures* msg) {
  uint8_t* data = frame->data;
  msg->m_mcu_temperature = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->m_bat24_temperature = ((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->m_supercap_temperature = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->m_buck_temperature = ((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->m_ebox_temperature = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
  msg->m_ambient_temperature = ((((uint32_t*)data)[1] >> 8) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1;
}
static void canzero_deserialize_canzero_message_input_board_stream_errors(canzero_frame* frame, canzero_message_input_board_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_error_level_bat24_under_voltage = (error_level)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_bat24_over_voltage = (error_level)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_bat24_over_current = (error_level)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_link24_under_voltage = (error_level)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_link24_over_voltage = (error_level)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_link24_over_current = (error_level)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_link45_under_voltage = (error_level)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_link45_over_voltage = (error_level)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_link45_over_current = (error_level)((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_cooling_cycle_under_pressure = (error_level)((((uint32_t*)data)[0] >> 18) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_cooling_cycle_over_pressure = (error_level)((((uint32_t*)data)[0] >> 20) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 22) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_cooling_cycle_temperature = (error_level)((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_bat24_temperature = (error_level)((((uint32_t*)data)[0] >> 26) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_supercap_temperature = (error_level)((((uint32_t*)data)[0] >> 28) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_buck_temperature = (error_level)((((uint32_t*)data)[0] >> 30) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_ebox_temperature = (error_level)(((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_ambient_temperature = (error_level)((((uint32_t*)data)[1] >> 2) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_assertion_fault = (error_flag)((((uint32_t*)data)[1] >> 4) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_heartbeat(canzero_frame* frame, canzero_message_heartbeat* msg) {
  uint8_t* data = frame->data;
  msg->m_node_id = (node_id)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 3)));
}
static void canzero_deserialize_canzero_message_get_req(canzero_frame* frame, canzero_message_get_req* msg) {
  uint8_t* data = frame->data;
  msg->m_header.m_od_index = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 13)));
  msg->m_header.m_client_id = ((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_header.m_server_id = ((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 8)));
}
static void canzero_deserialize_canzero_message_set_req(canzero_frame* frame, canzero_message_set_req* msg) {
  uint8_t* data = frame->data;
  msg->m_header.m_sof = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_header.m_eof = ((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_header.m_toggle = ((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_header.m_od_index = ((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 13)));
  msg->m_header.m_client_id = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_header.m_server_id = ((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_data = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 32)));
}
void canzero_can0_poll();
void canzero_can1_poll();
uint32_t canzero_update_continue(uint32_t delta_time);
void canzero_init();
void canzero_set_state(input_board_state value);
void canzero_set_sdc_status(sdc_status value);
static inline void canzero_set_position(float value){
  extern float __oe_position;
  __oe_position = value;
}
static inline void canzero_set_velocity(float value){
  extern float __oe_velocity;
  __oe_velocity = value;
}
static inline void canzero_set_acceleration(float value){
  extern float __oe_acceleration;
  __oe_acceleration = value;
}
static inline void canzero_set_linear_encoder_count(uint16_t value){
  extern uint16_t __oe_linear_encoder_count;
  __oe_linear_encoder_count = value;
}
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
void canzero_set_error_level_bat24_over_current(error_level value);
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
static inline void canzero_set_link45_expect_online(bool_t value){
  extern bool_t __oe_link45_expect_online;
  __oe_link45_expect_online = value;
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
void canzero_set_assertion_fault(error_flag value);
#endif