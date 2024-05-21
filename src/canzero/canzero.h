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
  node_id_mother_board = 0,
  node_id_motor_driver = 1,
  node_id_guidance_board_front = 2,
  node_id_guidance_board_back = 3,
  node_id_levitation_board1 = 4,
  node_id_levitation_board2 = 5,
  node_id_levitation_board3 = 6,
  node_id_levitation_board4 = 7,
  node_id_levitation_board5 = 8,
  node_id_levitation_board6 = 9,
  node_id_input_board = 10,
  node_id_power_board12 = 11,
  node_id_power_board24 = 12,
  node_id_count = 13,
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
  input_board_state_CALIBRATION = 1,
  input_board_state_RUNNING = 2,
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
typedef struct {
  uint16_t m_year;
  uint8_t m_month;
  uint8_t m_day;
  uint8_t m_hour;
  uint8_t m_min;
  uint8_t m_sec;
} date_time;
typedef enum {
  input_board_command_NONE = 0,
  input_board_command_CALIBRATE = 1,
} input_board_command;
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
static inline uint64_t canzero_get_config_hash() {
  extern uint64_t __oe_config_hash;
  return __oe_config_hash;
}
static inline date_time canzero_get_build_time() {
  extern date_time __oe_build_time;
  return __oe_build_time;
}
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
static inline input_board_command canzero_get_command() {
  extern input_board_command __oe_command;
  return __oe_command;
}
static inline float canzero_get_target_acceleration() {
  extern float __oe_target_acceleration;
  return __oe_target_acceleration;
}
static inline bool_t canzero_get_assert_45V_system_online() {
  extern bool_t __oe_assert_45V_system_online;
  return __oe_assert_45V_system_online;
}
static inline int16_t canzero_get_linear_encoder_count() {
  extern int16_t __oe_linear_encoder_count;
  return __oe_linear_encoder_count;
}
static inline float canzero_get_raw_acceleration() {
  extern float __oe_raw_acceleration;
  return __oe_raw_acceleration;
}
static inline float canzero_get_acceleration_calibration_variance() {
  extern float __oe_acceleration_calibration_variance;
  return __oe_acceleration_calibration_variance;
}
static inline float canzero_get_acceleration_calibration_offset() {
  extern float __oe_acceleration_calibration_offset;
  return __oe_acceleration_calibration_offset;
}
static inline float canzero_get_acceleration_calibration_target() {
  extern float __oe_acceleration_calibration_target;
  return __oe_acceleration_calibration_target;
}
static inline float canzero_get_raw_lateral_acceleration() {
  extern float __oe_raw_lateral_acceleration;
  return __oe_raw_lateral_acceleration;
}
static inline float canzero_get_lateral_acceleration() {
  extern float __oe_lateral_acceleration;
  return __oe_lateral_acceleration;
}
static inline float canzero_get_lateral_acceleration_calibration_variance() {
  extern float __oe_lateral_acceleration_calibration_variance;
  return __oe_lateral_acceleration_calibration_variance;
}
static inline float canzero_get_lateral_acceleration_calibration_offset() {
  extern float __oe_lateral_acceleration_calibration_offset;
  return __oe_lateral_acceleration_calibration_offset;
}
static inline float canzero_get_lateral_acceleration_calibration_target() {
  extern float __oe_lateral_acceleration_calibration_target;
  return __oe_lateral_acceleration_calibration_target;
}
static inline float canzero_get_raw_vertical_acceleration() {
  extern float __oe_raw_vertical_acceleration;
  return __oe_raw_vertical_acceleration;
}
static inline float canzero_get_vertical_acceleration() {
  extern float __oe_vertical_acceleration;
  return __oe_vertical_acceleration;
}
static inline float canzero_get_vertical_acceleration_calibration_variance() {
  extern float __oe_vertical_acceleration_calibration_variance;
  return __oe_vertical_acceleration_calibration_variance;
}
static inline float canzero_get_vertical_acceleration_calibration_offset() {
  extern float __oe_vertical_acceleration_calibration_offset;
  return __oe_vertical_acceleration_calibration_offset;
}
static inline float canzero_get_vertical_acceleration_calibration_target() {
  extern float __oe_vertical_acceleration_calibration_target;
  return __oe_vertical_acceleration_calibration_target;
}
static inline float canzero_get_track_length() {
  extern float __oe_track_length;
  return __oe_track_length;
}
static inline float canzero_get_bat24_voltage() {
  extern float __oe_bat24_voltage;
  return __oe_bat24_voltage;
}
static inline float canzero_get_bat24_voltage_calibration_offset() {
  extern float __oe_bat24_voltage_calibration_offset;
  return __oe_bat24_voltage_calibration_offset;
}
static inline float canzero_get_bat24_voltage_calibration_target() {
  extern float __oe_bat24_voltage_calibration_target;
  return __oe_bat24_voltage_calibration_target;
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
static inline float canzero_get_bat24_current_calibration_offset() {
  extern float __oe_bat24_current_calibration_offset;
  return __oe_bat24_current_calibration_offset;
}
static inline float canzero_get_bat24_current_calibration_target() {
  extern float __oe_bat24_current_calibration_target;
  return __oe_bat24_current_calibration_target;
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
static inline float canzero_get_link24_voltage_calibration_offset() {
  extern float __oe_link24_voltage_calibration_offset;
  return __oe_link24_voltage_calibration_offset;
}
static inline float canzero_get_link24_voltage_calibration_target() {
  extern float __oe_link24_voltage_calibration_target;
  return __oe_link24_voltage_calibration_target;
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
static inline float canzero_get_link24_current_calibration_offset() {
  extern float __oe_link24_current_calibration_offset;
  return __oe_link24_current_calibration_offset;
}
static inline float canzero_get_link24_current_calibration_target() {
  extern float __oe_link24_current_calibration_target;
  return __oe_link24_current_calibration_target;
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
static inline float canzero_get_link45_voltage_calibration_offset() {
  extern float __oe_link45_voltage_calibration_offset;
  return __oe_link45_voltage_calibration_offset;
}
static inline float canzero_get_link45_voltage_calibration_target() {
  extern float __oe_link45_voltage_calibration_target;
  return __oe_link45_voltage_calibration_target;
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
static inline float canzero_get_link45_current_calibration_offset() {
  extern float __oe_link45_current_calibration_offset;
  return __oe_link45_current_calibration_offset;
}
static inline float canzero_get_link45_current_calibration_target() {
  extern float __oe_link45_current_calibration_target;
  return __oe_link45_current_calibration_target;
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
static inline float canzero_get_cooling_cycle_pressure_calibration_offset() {
  extern float __oe_cooling_cycle_pressure_calibration_offset;
  return __oe_cooling_cycle_pressure_calibration_offset;
}
static inline float canzero_get_cooling_cycle_pressure_calibration_target() {
  extern float __oe_cooling_cycle_pressure_calibration_target;
  return __oe_cooling_cycle_pressure_calibration_target;
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
static inline float canzero_get_cooling_cycle_flow_rate() {
  extern float __oe_cooling_cycle_flow_rate;
  return __oe_cooling_cycle_flow_rate;
}
static inline error_flag canzero_get_assertion_fault() {
  extern error_flag __oe_assertion_fault;
  return __oe_assertion_fault;
}
typedef struct {
  get_resp_header m_header;
  uint32_t m_data;
} canzero_message_get_resp;
static const uint32_t canzero_message_get_resp_id = 0xBE;
typedef struct {
  set_resp_header m_header;
} canzero_message_set_resp;
static const uint32_t canzero_message_set_resp_id = 0xDE;
typedef struct {
  input_board_state m_state;
  sdc_status m_sdc_status;
} canzero_message_input_board_stream_state;
static const uint32_t canzero_message_input_board_stream_state_id = 0x4D;
typedef struct {
  float m_position;
  float m_velocity;
  float m_acceleration;
} canzero_message_input_board_stream_position_estimation;
static const uint32_t canzero_message_input_board_stream_position_estimation_id = 0x8E;
typedef struct {
  int16_t m_linear_encoder_count;
} canzero_message_input_board_stream_linear_encoder;
static const uint32_t canzero_message_input_board_stream_linear_encoder_id = 0x7B;
typedef struct {
  float m_raw_acceleration;
  float m_lateral_acceleration;
  float m_vertical_acceleration;
} canzero_message_input_board_stream_accelerations;
static const uint32_t canzero_message_input_board_stream_accelerations_id = 0x5C;
typedef struct {
  float m_bat24_voltage;
  float m_bat24_current;
} canzero_message_input_board_stream_bat24;
static const uint32_t canzero_message_input_board_stream_bat24_id = 0x7C;
typedef struct {
  float m_link24_voltage;
  float m_link24_current;
} canzero_message_input_board_stream_link24;
static const uint32_t canzero_message_input_board_stream_link24_id = 0x9B;
typedef struct {
  float m_link45_voltage;
  float m_link45_current;
} canzero_message_input_board_stream_link45;
static const uint32_t canzero_message_input_board_stream_link45_id = 0x5A;
typedef struct {
  float m_cooling_cycle_pressure;
  float m_cooling_cycle_temperature;
} canzero_message_input_board_stream_cooling;
static const uint32_t canzero_message_input_board_stream_cooling_id = 0x9C;
typedef struct {
  float m_mcu_temperature;
  float m_bat24_temperature;
  float m_supercap_temperature;
  float m_buck_temperature;
  float m_ebox_temperature;
  float m_ambient_temperature;
} canzero_message_input_board_stream_temperatures;
static const uint32_t canzero_message_input_board_stream_temperatures_id = 0x7A;
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
static const uint32_t canzero_message_input_board_stream_errors_id = 0x5B;
typedef struct {
  node_id m_node_id;
  uint8_t m_unregister;
  uint8_t m_ticks_next;
} canzero_message_heartbeat_can0;
static const uint32_t canzero_message_heartbeat_can0_id = 0xE9;
typedef struct {
  node_id m_node_id;
  uint8_t m_unregister;
  uint8_t m_ticks_next;
} canzero_message_heartbeat_can1;
static const uint32_t canzero_message_heartbeat_can1_id = 0xE8;
typedef struct {
  get_req_header m_header;
} canzero_message_get_req;
static const uint32_t canzero_message_get_req_id = 0xBF;
typedef struct {
  set_req_header m_header;
  uint32_t m_data;
} canzero_message_set_req;
static const uint32_t canzero_message_set_req_id = 0xDF;
void canzero_can0_poll();
void canzero_can1_poll();
uint32_t canzero_update_continue(uint32_t delta_time);
void canzero_init();
static inline void canzero_set_config_hash(uint64_t value){
  extern uint64_t __oe_config_hash;
  __oe_config_hash = value;
}
static inline void canzero_set_build_time(date_time value){
  extern date_time __oe_build_time;
  __oe_build_time = value;
}
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
static inline void canzero_set_command(input_board_command value){
  extern input_board_command __oe_command;
  __oe_command = value;
}
static inline void canzero_set_target_acceleration(float value){
  extern float __oe_target_acceleration;
  __oe_target_acceleration = value;
}
static inline void canzero_set_assert_45V_system_online(bool_t value){
  extern bool_t __oe_assert_45V_system_online;
  __oe_assert_45V_system_online = value;
}
void canzero_set_linear_encoder_count(int16_t value);
static inline void canzero_set_raw_acceleration(float value){
  extern float __oe_raw_acceleration;
  __oe_raw_acceleration = value;
}
static inline void canzero_set_acceleration_calibration_variance(float value){
  extern float __oe_acceleration_calibration_variance;
  __oe_acceleration_calibration_variance = value;
}
static inline void canzero_set_acceleration_calibration_offset(float value){
  extern float __oe_acceleration_calibration_offset;
  __oe_acceleration_calibration_offset = value;
}
static inline void canzero_set_acceleration_calibration_target(float value){
  extern float __oe_acceleration_calibration_target;
  __oe_acceleration_calibration_target = value;
}
static inline void canzero_set_raw_lateral_acceleration(float value){
  extern float __oe_raw_lateral_acceleration;
  __oe_raw_lateral_acceleration = value;
}
static inline void canzero_set_lateral_acceleration(float value){
  extern float __oe_lateral_acceleration;
  __oe_lateral_acceleration = value;
}
static inline void canzero_set_lateral_acceleration_calibration_variance(float value){
  extern float __oe_lateral_acceleration_calibration_variance;
  __oe_lateral_acceleration_calibration_variance = value;
}
static inline void canzero_set_lateral_acceleration_calibration_offset(float value){
  extern float __oe_lateral_acceleration_calibration_offset;
  __oe_lateral_acceleration_calibration_offset = value;
}
static inline void canzero_set_lateral_acceleration_calibration_target(float value){
  extern float __oe_lateral_acceleration_calibration_target;
  __oe_lateral_acceleration_calibration_target = value;
}
static inline void canzero_set_raw_vertical_acceleration(float value){
  extern float __oe_raw_vertical_acceleration;
  __oe_raw_vertical_acceleration = value;
}
static inline void canzero_set_vertical_acceleration(float value){
  extern float __oe_vertical_acceleration;
  __oe_vertical_acceleration = value;
}
static inline void canzero_set_vertical_acceleration_calibration_variance(float value){
  extern float __oe_vertical_acceleration_calibration_variance;
  __oe_vertical_acceleration_calibration_variance = value;
}
static inline void canzero_set_vertical_acceleration_calibration_offset(float value){
  extern float __oe_vertical_acceleration_calibration_offset;
  __oe_vertical_acceleration_calibration_offset = value;
}
static inline void canzero_set_vertical_acceleration_calibration_target(float value){
  extern float __oe_vertical_acceleration_calibration_target;
  __oe_vertical_acceleration_calibration_target = value;
}
static inline void canzero_set_track_length(float value){
  extern float __oe_track_length;
  __oe_track_length = value;
}
static inline void canzero_set_bat24_voltage(float value){
  extern float __oe_bat24_voltage;
  __oe_bat24_voltage = value;
}
static inline void canzero_set_bat24_voltage_calibration_offset(float value){
  extern float __oe_bat24_voltage_calibration_offset;
  __oe_bat24_voltage_calibration_offset = value;
}
static inline void canzero_set_bat24_voltage_calibration_target(float value){
  extern float __oe_bat24_voltage_calibration_target;
  __oe_bat24_voltage_calibration_target = value;
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
static inline void canzero_set_bat24_current_calibration_offset(float value){
  extern float __oe_bat24_current_calibration_offset;
  __oe_bat24_current_calibration_offset = value;
}
static inline void canzero_set_bat24_current_calibration_target(float value){
  extern float __oe_bat24_current_calibration_target;
  __oe_bat24_current_calibration_target = value;
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
static inline void canzero_set_link24_voltage_calibration_offset(float value){
  extern float __oe_link24_voltage_calibration_offset;
  __oe_link24_voltage_calibration_offset = value;
}
static inline void canzero_set_link24_voltage_calibration_target(float value){
  extern float __oe_link24_voltage_calibration_target;
  __oe_link24_voltage_calibration_target = value;
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
static inline void canzero_set_link24_current_calibration_offset(float value){
  extern float __oe_link24_current_calibration_offset;
  __oe_link24_current_calibration_offset = value;
}
static inline void canzero_set_link24_current_calibration_target(float value){
  extern float __oe_link24_current_calibration_target;
  __oe_link24_current_calibration_target = value;
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
static inline void canzero_set_link45_voltage_calibration_offset(float value){
  extern float __oe_link45_voltage_calibration_offset;
  __oe_link45_voltage_calibration_offset = value;
}
static inline void canzero_set_link45_voltage_calibration_target(float value){
  extern float __oe_link45_voltage_calibration_target;
  __oe_link45_voltage_calibration_target = value;
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
static inline void canzero_set_link45_current_calibration_offset(float value){
  extern float __oe_link45_current_calibration_offset;
  __oe_link45_current_calibration_offset = value;
}
static inline void canzero_set_link45_current_calibration_target(float value){
  extern float __oe_link45_current_calibration_target;
  __oe_link45_current_calibration_target = value;
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
static inline void canzero_set_cooling_cycle_pressure_calibration_offset(float value){
  extern float __oe_cooling_cycle_pressure_calibration_offset;
  __oe_cooling_cycle_pressure_calibration_offset = value;
}
static inline void canzero_set_cooling_cycle_pressure_calibration_target(float value){
  extern float __oe_cooling_cycle_pressure_calibration_target;
  __oe_cooling_cycle_pressure_calibration_target = value;
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
static inline void canzero_set_cooling_cycle_flow_rate(float value){
  extern float __oe_cooling_cycle_flow_rate;
  __oe_cooling_cycle_flow_rate = value;
}
void canzero_set_assertion_fault(error_flag value);
#endif