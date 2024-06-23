#ifndef CANZERO_H
#define CANZERO_H
#include <cinttypes>
#include <cstddef>
#define MAX_DYN_HEARTBEATS 10
typedef enum {
  node_id_gamepad = 0,
  node_id_mother_board = 1,
  node_id_motor_driver = 2,
  node_id_guidance_board_front = 3,
  node_id_guidance_board_back = 4,
  node_id_levitation_board1 = 5,
  node_id_levitation_board2 = 6,
  node_id_levitation_board3 = 7,
  node_id_input_board = 8,
  node_id_power_board12 = 9,
  node_id_power_board24 = 10,
  node_id_count = 11,
} node_id;
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
  motor_command_NONE = 0,
  motor_command_ARM45 = 1,
  motor_command_PRECHARGE = 2,
  motor_command_START = 3,
  motor_command_STOP = 4,
  motor_command_ABORT = 5,
  motor_command_DISARM45 = 6,
} motor_command;
typedef enum {
  input_board_command_NONE = 0,
  input_board_command_CALIBRATE = 1,
} input_board_command;
typedef enum {
  bool_t_FALSE = 0,
  bool_t_TRUE = 1,
} bool_t;
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
  error_flag_OK = 0,
  error_flag_ERROR = 1,
} error_flag;
typedef enum {
  error_level_OK = 0,
  error_level_INFO = 1,
  error_level_WARNING = 2,
  error_level_ERROR = 3,
} error_level;
typedef struct {
  uint16_t m_year;
  uint8_t m_month;
  uint8_t m_day;
  uint8_t m_hour;
  uint8_t m_min;
  uint8_t m_sec;
} date_time;
typedef enum {
  calibration_mode_USE_OFFSET = 0,
  calibration_mode_USE_TARGET = 1,
  calibration_mode_DISABLE = 2,
} calibration_mode;
typedef struct {
  float m_info_thresh;
  float m_info_timeout;
  float m_warning_thresh;
  float m_warning_timeout;
  float m_error_thresh;
  float m_error_timeout;
  bool_t m_ignore_info;
  bool_t m_ignore_warning;
  bool_t m_ignore_error;
} error_level_config;
static const node_id CANZERO_NODE_ID = node_id_input_board;
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
static inline error_flag canzero_get_error_acceleration_out_of_range() {
  extern error_flag __oe_error_acceleration_out_of_range;
  return __oe_error_acceleration_out_of_range;
}
static inline double canzero_get_acceleration_calibration_variance() {
  extern double __oe_acceleration_calibration_variance;
  return __oe_acceleration_calibration_variance;
}
static inline double canzero_get_acceleration_calibration_offset() {
  extern double __oe_acceleration_calibration_offset;
  return __oe_acceleration_calibration_offset;
}
static inline double canzero_get_acceleration_calibration_target() {
  extern double __oe_acceleration_calibration_target;
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
static inline error_flag canzero_get_error_lateral_acceleration_out_of_range() {
  extern error_flag __oe_error_lateral_acceleration_out_of_range;
  return __oe_error_lateral_acceleration_out_of_range;
}
static inline double canzero_get_lateral_acceleration_calibration_variance() {
  extern double __oe_lateral_acceleration_calibration_variance;
  return __oe_lateral_acceleration_calibration_variance;
}
static inline double canzero_get_lateral_acceleration_calibration_offset() {
  extern double __oe_lateral_acceleration_calibration_offset;
  return __oe_lateral_acceleration_calibration_offset;
}
static inline double canzero_get_lateral_acceleration_calibration_target() {
  extern double __oe_lateral_acceleration_calibration_target;
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
static inline error_flag canzero_get_error_vertical_acceleration_out_of_range() {
  extern error_flag __oe_error_vertical_acceleration_out_of_range;
  return __oe_error_vertical_acceleration_out_of_range;
}
static inline double canzero_get_vertical_acceleration_calibration_variance() {
  extern double __oe_vertical_acceleration_calibration_variance;
  return __oe_vertical_acceleration_calibration_variance;
}
static inline double canzero_get_vertical_acceleration_calibration_offset() {
  extern double __oe_vertical_acceleration_calibration_offset;
  return __oe_vertical_acceleration_calibration_offset;
}
static inline double canzero_get_vertical_acceleration_calibration_target() {
  extern double __oe_vertical_acceleration_calibration_target;
  return __oe_vertical_acceleration_calibration_target;
}
static inline error_flag canzero_get_error_acceleration_calibration_failed() {
  extern error_flag __oe_error_acceleration_calibration_failed;
  return __oe_error_acceleration_calibration_failed;
}
static inline float canzero_get_track_length() {
  extern float __oe_track_length;
  return __oe_track_length;
}
static inline float canzero_get_bat24_voltage() {
  extern float __oe_bat24_voltage;
  return __oe_bat24_voltage;
}
static inline calibration_mode canzero_get_bat24_voltage_calibration_mode() {
  extern calibration_mode __oe_bat24_voltage_calibration_mode;
  return __oe_bat24_voltage_calibration_mode;
}
static inline float canzero_get_bat24_voltage_calibration_offset() {
  extern float __oe_bat24_voltage_calibration_offset;
  return __oe_bat24_voltage_calibration_offset;
}
static inline float canzero_get_bat24_voltage_calibration_target() {
  extern float __oe_bat24_voltage_calibration_target;
  return __oe_bat24_voltage_calibration_target;
}
static inline error_flag canzero_get_error_bat24_voltage_invalid() {
  extern error_flag __oe_error_bat24_voltage_invalid;
  return __oe_error_bat24_voltage_invalid;
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
static inline calibration_mode canzero_get_bat24_current_calibration_mode() {
  extern calibration_mode __oe_bat24_current_calibration_mode;
  return __oe_bat24_current_calibration_mode;
}
static inline error_flag canzero_get_error_bat24_current_invalid() {
  extern error_flag __oe_error_bat24_current_invalid;
  return __oe_error_bat24_current_invalid;
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
static inline calibration_mode canzero_get_link24_voltage_calibration_mode() {
  extern calibration_mode __oe_link24_voltage_calibration_mode;
  return __oe_link24_voltage_calibration_mode;
}
static inline float canzero_get_link24_voltage_calibration_offset() {
  extern float __oe_link24_voltage_calibration_offset;
  return __oe_link24_voltage_calibration_offset;
}
static inline float canzero_get_link24_voltage_calibration_target() {
  extern float __oe_link24_voltage_calibration_target;
  return __oe_link24_voltage_calibration_target;
}
static inline error_flag canzero_get_error_link24_voltage_invalid() {
  extern error_flag __oe_error_link24_voltage_invalid;
  return __oe_error_link24_voltage_invalid;
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
static inline calibration_mode canzero_get_link24_current_calibration_mode() {
  extern calibration_mode __oe_link24_current_calibration_mode;
  return __oe_link24_current_calibration_mode;
}
static inline float canzero_get_link24_current_calibration_offset() {
  extern float __oe_link24_current_calibration_offset;
  return __oe_link24_current_calibration_offset;
}
static inline float canzero_get_link24_current_calibration_target() {
  extern float __oe_link24_current_calibration_target;
  return __oe_link24_current_calibration_target;
}
static inline error_flag canzero_get_error_link24_current_invalid() {
  extern error_flag __oe_error_link24_current_invalid;
  return __oe_error_link24_current_invalid;
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
static inline calibration_mode canzero_get_link45_voltage_calibration_mode() {
  extern calibration_mode __oe_link45_voltage_calibration_mode;
  return __oe_link45_voltage_calibration_mode;
}
static inline float canzero_get_link45_voltage_calibration_offset() {
  extern float __oe_link45_voltage_calibration_offset;
  return __oe_link45_voltage_calibration_offset;
}
static inline float canzero_get_link45_voltage_calibration_target() {
  extern float __oe_link45_voltage_calibration_target;
  return __oe_link45_voltage_calibration_target;
}
static inline error_flag canzero_get_error_link45_voltage_invalid() {
  extern error_flag __oe_error_link45_voltage_invalid;
  return __oe_error_link45_voltage_invalid;
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
static inline calibration_mode canzero_get_link45_current_calibration_mode() {
  extern calibration_mode __oe_link45_current_calibration_mode;
  return __oe_link45_current_calibration_mode;
}
static inline float canzero_get_link45_current_calibration_offset() {
  extern float __oe_link45_current_calibration_offset;
  return __oe_link45_current_calibration_offset;
}
static inline float canzero_get_link45_current_calibration_target() {
  extern float __oe_link45_current_calibration_target;
  return __oe_link45_current_calibration_target;
}
static inline error_flag canzero_get_error_link45_current_invalid() {
  extern error_flag __oe_error_link45_current_invalid;
  return __oe_error_link45_current_invalid;
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
static inline calibration_mode canzero_get_cooling_cycle_pressure_calibration_mode() {
  extern calibration_mode __oe_cooling_cycle_pressure_calibration_mode;
  return __oe_cooling_cycle_pressure_calibration_mode;
}
static inline float canzero_get_cooling_cycle_pressure_calibration_offset() {
  extern float __oe_cooling_cycle_pressure_calibration_offset;
  return __oe_cooling_cycle_pressure_calibration_offset;
}
static inline float canzero_get_cooling_cycle_pressure_calibration_target() {
  extern float __oe_cooling_cycle_pressure_calibration_target;
  return __oe_cooling_cycle_pressure_calibration_target;
}
static inline error_flag canzero_get_error_cooling_cycle_pressure_invalid() {
  extern error_flag __oe_error_cooling_cycle_pressure_invalid;
  return __oe_error_cooling_cycle_pressure_invalid;
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
static inline error_flag canzero_get_error_mcu_temperature_invalid() {
  extern error_flag __oe_error_mcu_temperature_invalid;
  return __oe_error_mcu_temperature_invalid;
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
static inline error_flag canzero_get_error_cooling_cycle_temperature_invalid() {
  extern error_flag __oe_error_cooling_cycle_temperature_invalid;
  return __oe_error_cooling_cycle_temperature_invalid;
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
static inline error_flag canzero_get_error_bat24_temperature_invalid() {
  extern error_flag __oe_error_bat24_temperature_invalid;
  return __oe_error_bat24_temperature_invalid;
}
static inline float canzero_get_supercap_temperature() {
  extern float __oe_supercap_temperature;
  return __oe_supercap_temperature;
}
static inline error_flag canzero_get_error_supercap_temperature_invalid() {
  extern error_flag __oe_error_supercap_temperature_invalid;
  return __oe_error_supercap_temperature_invalid;
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
static inline error_flag canzero_get_error_buck_temperature_invalid() {
  extern error_flag __oe_error_buck_temperature_invalid;
  return __oe_error_buck_temperature_invalid;
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
static inline error_flag canzero_get_error_ebox_temperature_invalid() {
  extern error_flag __oe_error_ebox_temperature_invalid;
  return __oe_error_ebox_temperature_invalid;
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
static inline error_flag canzero_get_error_ambient_temperature_invalid() {
  extern error_flag __oe_error_ambient_temperature_invalid;
  return __oe_error_ambient_temperature_invalid;
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
static inline float canzero_get_loop_frequency() {
  extern float __oe_loop_frequency;
  return __oe_loop_frequency;
}
static inline error_flag canzero_get_assertion_fault() {
  extern error_flag __oe_assertion_fault;
  return __oe_assertion_fault;
}
static inline error_flag canzero_get_error_heartbeat_miss() {
  extern error_flag __oe_error_heartbeat_miss;
  return __oe_error_heartbeat_miss;
}
typedef struct {
  get_resp_header m_header;
  uint32_t m_data;
} canzero_message_get_resp;
static const uint32_t canzero_message_get_resp_id = 0x17D;
typedef struct {
  set_resp_header m_header;
} canzero_message_set_resp;
static const uint32_t canzero_message_set_resp_id = 0x1BD;
typedef struct {
  input_board_state m_state;
  sdc_status m_sdc_status;
} canzero_message_input_board_stream_state;
static const uint32_t canzero_message_input_board_stream_state_id = 0xA8;
typedef struct {
  float m_position;
  float m_velocity;
  float m_acceleration;
} canzero_message_input_board_stream_position_estimation;
static const uint32_t canzero_message_input_board_stream_position_estimation_id = 0x129;
typedef struct {
  int16_t m_linear_encoder_count;
} canzero_message_input_board_stream_linear_encoder;
static const uint32_t canzero_message_input_board_stream_linear_encoder_id = 0xB9;
typedef struct {
  float m_raw_acceleration;
  float m_lateral_acceleration;
  float m_vertical_acceleration;
} canzero_message_input_board_stream_accelerations;
static const uint32_t canzero_message_input_board_stream_accelerations_id = 0x13B;
typedef struct {
  float m_bat24_voltage;
  float m_bat24_current;
} canzero_message_input_board_stream_bat24;
static const uint32_t canzero_message_input_board_stream_bat24_id = 0xBA;
typedef struct {
  float m_link24_voltage;
  float m_link24_current;
} canzero_message_input_board_stream_link24;
static const uint32_t canzero_message_input_board_stream_link24_id = 0xF9;
typedef struct {
  float m_link45_voltage;
  float m_link45_current;
} canzero_message_input_board_stream_link45;
static const uint32_t canzero_message_input_board_stream_link45_id = 0x139;
typedef struct {
  float m_cooling_cycle_pressure;
  float m_cooling_cycle_temperature;
} canzero_message_input_board_stream_cooling;
static const uint32_t canzero_message_input_board_stream_cooling_id = 0xFA;
typedef struct {
  float m_mcu_temperature;
  float m_bat24_temperature;
  float m_supercap_temperature;
  float m_buck_temperature;
  float m_ebox_temperature;
  float m_ambient_temperature;
} canzero_message_input_board_stream_temperatures;
static const uint32_t canzero_message_input_board_stream_temperatures_id = 0xB8;
typedef struct {
  error_flag m_error_acceleration_out_of_range;
  error_flag m_error_acceleration_calibration_failed;
  error_flag m_error_lateral_acceleration_out_of_range;
  error_flag m_error_vertical_acceleration_out_of_range;
  error_flag m_error_bat24_voltage_invalid;
  error_level m_error_level_bat24_under_voltage;
  error_level m_error_level_bat24_over_voltage;
  error_flag m_error_bat24_current_invalid;
  error_level m_error_level_bat24_over_current;
  error_flag m_error_link24_voltage_invalid;
  error_level m_error_level_link24_under_voltage;
  error_level m_error_level_link24_over_voltage;
  error_flag m_error_link24_current_invalid;
  error_level m_error_level_link24_over_current;
  error_flag m_error_link45_voltage_invalid;
  error_level m_error_level_link45_under_voltage;
  error_level m_error_level_link45_over_voltage;
  error_flag m_error_link45_current_invalid;
  error_level m_error_level_link45_over_current;
  error_flag m_error_cooling_cycle_pressure_invalid;
  error_level m_error_level_cooling_cycle_over_pressure;
  error_flag m_error_mcu_temperature_invalid;
  error_level m_error_level_mcu_temperature;
  error_flag m_error_cooling_cycle_temperature_invalid;
  error_level m_error_level_cooling_cycle_temperature;
  error_flag m_error_bat24_temperature_invalid;
  error_level m_error_level_bat24_temperature;
  error_flag m_error_supercap_temperature_invalid;
  error_level m_error_level_supercap_temperature;
  error_flag m_error_buck_temperature_invalid;
  error_level m_error_level_buck_temperature;
  error_flag m_error_ebox_temperature_invalid;
  error_level m_error_level_ebox_temperature;
  error_flag m_error_ambient_temperature_invalid;
  error_level m_error_level_ambient_temperature;
  error_flag m_error_heartbeat_miss;
  error_flag m_assertion_fault;
} canzero_message_input_board_stream_errors;
static const uint32_t canzero_message_input_board_stream_errors_id = 0x13A;
typedef struct {
  uint8_t m_node_id;
  uint8_t m_unregister;
  uint8_t m_ticks_next;
} canzero_message_heartbeat_can0;
static const uint32_t canzero_message_heartbeat_can0_id = 0x1E5;
typedef struct {
  uint8_t m_node_id;
  uint8_t m_unregister;
  uint8_t m_ticks_next;
} canzero_message_heartbeat_can1;
static const uint32_t canzero_message_heartbeat_can1_id = 0x1E4;
typedef struct {
  get_req_header m_header;
} canzero_message_get_req;
static const uint32_t canzero_message_get_req_id = 0x17E;
typedef struct {
  set_req_header m_header;
  uint32_t m_data;
} canzero_message_set_req;
static const uint32_t canzero_message_set_req_id = 0x1BE;
typedef struct {
  float m_target_acceleration;
  motor_command m_motor_driver_command;
} canzero_message_mother_board_stream_motor_command;
static const uint32_t canzero_message_mother_board_stream_motor_command_id = 0xA0;
typedef struct {
  input_board_command m_input_board_command;
  bool_t m_input_board_assert_45V_online;
} canzero_message_mother_board_stream_input_board_command;
static const uint32_t canzero_message_mother_board_stream_input_board_command_id = 0xA2;
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

void canzero_set_error_acceleration_out_of_range(error_flag value);

static inline void canzero_set_acceleration_calibration_variance(double value){
  extern double __oe_acceleration_calibration_variance;
  __oe_acceleration_calibration_variance = value;
}

static inline void canzero_set_acceleration_calibration_offset(double value){
  extern double __oe_acceleration_calibration_offset;
  __oe_acceleration_calibration_offset = value;
}

static inline void canzero_set_acceleration_calibration_target(double value){
  extern double __oe_acceleration_calibration_target;
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

void canzero_set_error_lateral_acceleration_out_of_range(error_flag value);

static inline void canzero_set_lateral_acceleration_calibration_variance(double value){
  extern double __oe_lateral_acceleration_calibration_variance;
  __oe_lateral_acceleration_calibration_variance = value;
}

static inline void canzero_set_lateral_acceleration_calibration_offset(double value){
  extern double __oe_lateral_acceleration_calibration_offset;
  __oe_lateral_acceleration_calibration_offset = value;
}

static inline void canzero_set_lateral_acceleration_calibration_target(double value){
  extern double __oe_lateral_acceleration_calibration_target;
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

void canzero_set_error_vertical_acceleration_out_of_range(error_flag value);

static inline void canzero_set_vertical_acceleration_calibration_variance(double value){
  extern double __oe_vertical_acceleration_calibration_variance;
  __oe_vertical_acceleration_calibration_variance = value;
}

static inline void canzero_set_vertical_acceleration_calibration_offset(double value){
  extern double __oe_vertical_acceleration_calibration_offset;
  __oe_vertical_acceleration_calibration_offset = value;
}

static inline void canzero_set_vertical_acceleration_calibration_target(double value){
  extern double __oe_vertical_acceleration_calibration_target;
  __oe_vertical_acceleration_calibration_target = value;
}

void canzero_set_error_acceleration_calibration_failed(error_flag value);

static inline void canzero_set_track_length(float value){
  extern float __oe_track_length;
  __oe_track_length = value;
}

static inline void canzero_set_bat24_voltage(float value){
  extern float __oe_bat24_voltage;
  __oe_bat24_voltage = value;
}

static inline void canzero_set_bat24_voltage_calibration_mode(calibration_mode value){
  extern calibration_mode __oe_bat24_voltage_calibration_mode;
  __oe_bat24_voltage_calibration_mode = value;
}

static inline void canzero_set_bat24_voltage_calibration_offset(float value){
  extern float __oe_bat24_voltage_calibration_offset;
  __oe_bat24_voltage_calibration_offset = value;
}

static inline void canzero_set_bat24_voltage_calibration_target(float value){
  extern float __oe_bat24_voltage_calibration_target;
  __oe_bat24_voltage_calibration_target = value;
}

void canzero_set_error_bat24_voltage_invalid(error_flag value);

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

static inline void canzero_set_bat24_current_calibration_mode(calibration_mode value){
  extern calibration_mode __oe_bat24_current_calibration_mode;
  __oe_bat24_current_calibration_mode = value;
}

void canzero_set_error_bat24_current_invalid(error_flag value);

void canzero_set_error_level_bat24_over_current(error_level value);

static inline void canzero_set_error_level_config_bat24_over_current(error_level_config value){
  extern error_level_config __oe_error_level_config_bat24_over_current;
  __oe_error_level_config_bat24_over_current = value;
}

static inline void canzero_set_link24_voltage(float value){
  extern float __oe_link24_voltage;
  __oe_link24_voltage = value;
}

static inline void canzero_set_link24_voltage_calibration_mode(calibration_mode value){
  extern calibration_mode __oe_link24_voltage_calibration_mode;
  __oe_link24_voltage_calibration_mode = value;
}

static inline void canzero_set_link24_voltage_calibration_offset(float value){
  extern float __oe_link24_voltage_calibration_offset;
  __oe_link24_voltage_calibration_offset = value;
}

static inline void canzero_set_link24_voltage_calibration_target(float value){
  extern float __oe_link24_voltage_calibration_target;
  __oe_link24_voltage_calibration_target = value;
}

void canzero_set_error_link24_voltage_invalid(error_flag value);

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

static inline void canzero_set_link24_current_calibration_mode(calibration_mode value){
  extern calibration_mode __oe_link24_current_calibration_mode;
  __oe_link24_current_calibration_mode = value;
}

static inline void canzero_set_link24_current_calibration_offset(float value){
  extern float __oe_link24_current_calibration_offset;
  __oe_link24_current_calibration_offset = value;
}

static inline void canzero_set_link24_current_calibration_target(float value){
  extern float __oe_link24_current_calibration_target;
  __oe_link24_current_calibration_target = value;
}

void canzero_set_error_link24_current_invalid(error_flag value);

void canzero_set_error_level_link24_over_current(error_level value);

static inline void canzero_set_error_level_config_link24_over_current(error_level_config value){
  extern error_level_config __oe_error_level_config_link24_over_current;
  __oe_error_level_config_link24_over_current = value;
}

static inline void canzero_set_link45_voltage(float value){
  extern float __oe_link45_voltage;
  __oe_link45_voltage = value;
}

static inline void canzero_set_link45_voltage_calibration_mode(calibration_mode value){
  extern calibration_mode __oe_link45_voltage_calibration_mode;
  __oe_link45_voltage_calibration_mode = value;
}

static inline void canzero_set_link45_voltage_calibration_offset(float value){
  extern float __oe_link45_voltage_calibration_offset;
  __oe_link45_voltage_calibration_offset = value;
}

static inline void canzero_set_link45_voltage_calibration_target(float value){
  extern float __oe_link45_voltage_calibration_target;
  __oe_link45_voltage_calibration_target = value;
}

void canzero_set_error_link45_voltage_invalid(error_flag value);

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

static inline void canzero_set_link45_current_calibration_mode(calibration_mode value){
  extern calibration_mode __oe_link45_current_calibration_mode;
  __oe_link45_current_calibration_mode = value;
}

static inline void canzero_set_link45_current_calibration_offset(float value){
  extern float __oe_link45_current_calibration_offset;
  __oe_link45_current_calibration_offset = value;
}

static inline void canzero_set_link45_current_calibration_target(float value){
  extern float __oe_link45_current_calibration_target;
  __oe_link45_current_calibration_target = value;
}

void canzero_set_error_link45_current_invalid(error_flag value);

void canzero_set_error_level_link45_over_current(error_level value);

static inline void canzero_set_error_level_config_link45_over_current(error_level_config value){
  extern error_level_config __oe_error_level_config_link45_over_current;
  __oe_error_level_config_link45_over_current = value;
}

static inline void canzero_set_cooling_cycle_pressure(float value){
  extern float __oe_cooling_cycle_pressure;
  __oe_cooling_cycle_pressure = value;
}

static inline void canzero_set_cooling_cycle_pressure_calibration_mode(calibration_mode value){
  extern calibration_mode __oe_cooling_cycle_pressure_calibration_mode;
  __oe_cooling_cycle_pressure_calibration_mode = value;
}

static inline void canzero_set_cooling_cycle_pressure_calibration_offset(float value){
  extern float __oe_cooling_cycle_pressure_calibration_offset;
  __oe_cooling_cycle_pressure_calibration_offset = value;
}

static inline void canzero_set_cooling_cycle_pressure_calibration_target(float value){
  extern float __oe_cooling_cycle_pressure_calibration_target;
  __oe_cooling_cycle_pressure_calibration_target = value;
}

void canzero_set_error_cooling_cycle_pressure_invalid(error_flag value);

void canzero_set_error_level_cooling_cycle_over_pressure(error_level value);

static inline void canzero_set_error_level_config_cooling_cycle_over_pressure(error_level_config value){
  extern error_level_config __oe_error_level_config_cooling_cycle_over_pressure;
  __oe_error_level_config_cooling_cycle_over_pressure = value;
}

static inline void canzero_set_mcu_temperature(float value){
  extern float __oe_mcu_temperature;
  __oe_mcu_temperature = value;
}

void canzero_set_error_mcu_temperature_invalid(error_flag value);

void canzero_set_error_level_mcu_temperature(error_level value);

static inline void canzero_set_error_level_config_mcu_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_mcu_temperature;
  __oe_error_level_config_mcu_temperature = value;
}

static inline void canzero_set_cooling_cycle_temperature(float value){
  extern float __oe_cooling_cycle_temperature;
  __oe_cooling_cycle_temperature = value;
}

void canzero_set_error_cooling_cycle_temperature_invalid(error_flag value);

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

void canzero_set_error_bat24_temperature_invalid(error_flag value);

static inline void canzero_set_supercap_temperature(float value){
  extern float __oe_supercap_temperature;
  __oe_supercap_temperature = value;
}

void canzero_set_error_supercap_temperature_invalid(error_flag value);

void canzero_set_error_level_supercap_temperature(error_level value);

static inline void canzero_set_error_level_config_supercap_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_supercap_temperature;
  __oe_error_level_config_supercap_temperature = value;
}

static inline void canzero_set_buck_temperature(float value){
  extern float __oe_buck_temperature;
  __oe_buck_temperature = value;
}

void canzero_set_error_buck_temperature_invalid(error_flag value);

void canzero_set_error_level_buck_temperature(error_level value);

static inline void canzero_set_error_level_config_buck_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_buck_temperature;
  __oe_error_level_config_buck_temperature = value;
}

static inline void canzero_set_ebox_temperature(float value){
  extern float __oe_ebox_temperature;
  __oe_ebox_temperature = value;
}

void canzero_set_error_ebox_temperature_invalid(error_flag value);

void canzero_set_error_level_ebox_temperature(error_level value);

static inline void canzero_set_error_level_config_ebox_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_ebox_temperature;
  __oe_error_level_config_ebox_temperature = value;
}

static inline void canzero_set_ambient_temperature(float value){
  extern float __oe_ambient_temperature;
  __oe_ambient_temperature = value;
}

void canzero_set_error_ambient_temperature_invalid(error_flag value);

void canzero_set_error_level_ambient_temperature(error_level value);

static inline void canzero_set_error_level_config_ambient_temperature(error_level_config value){
  extern error_level_config __oe_error_level_config_ambient_temperature;
  __oe_error_level_config_ambient_temperature = value;
}

static inline void canzero_set_cooling_cycle_flow_rate(float value){
  extern float __oe_cooling_cycle_flow_rate;
  __oe_cooling_cycle_flow_rate = value;
}

static inline void canzero_set_loop_frequency(float value){
  extern float __oe_loop_frequency;
  __oe_loop_frequency = value;
}

void canzero_set_assertion_fault(error_flag value);

void canzero_set_error_heartbeat_miss(error_flag value);

void canzero_send_config_hash();

void canzero_send_build_time();

void canzero_send_state();

void canzero_send_sdc_status();

void canzero_send_position();

void canzero_send_velocity();

void canzero_send_acceleration();

void canzero_send_command();

void canzero_send_target_acceleration();

void canzero_send_assert_45V_system_online();

void canzero_send_linear_encoder_count();

void canzero_send_raw_acceleration();

void canzero_send_error_acceleration_out_of_range();

void canzero_send_acceleration_calibration_variance();

void canzero_send_acceleration_calibration_offset();

void canzero_send_acceleration_calibration_target();

void canzero_send_raw_lateral_acceleration();

void canzero_send_lateral_acceleration();

void canzero_send_error_lateral_acceleration_out_of_range();

void canzero_send_lateral_acceleration_calibration_variance();

void canzero_send_lateral_acceleration_calibration_offset();

void canzero_send_lateral_acceleration_calibration_target();

void canzero_send_raw_vertical_acceleration();

void canzero_send_vertical_acceleration();

void canzero_send_error_vertical_acceleration_out_of_range();

void canzero_send_vertical_acceleration_calibration_variance();

void canzero_send_vertical_acceleration_calibration_offset();

void canzero_send_vertical_acceleration_calibration_target();

void canzero_send_error_acceleration_calibration_failed();

void canzero_send_track_length();

void canzero_send_bat24_voltage();

void canzero_send_bat24_voltage_calibration_mode();

void canzero_send_bat24_voltage_calibration_offset();

void canzero_send_bat24_voltage_calibration_target();

void canzero_send_error_bat24_voltage_invalid();

void canzero_send_error_level_bat24_under_voltage();

void canzero_send_error_level_config_bat24_under_voltage();

void canzero_send_error_level_bat24_over_voltage();

void canzero_send_error_level_config_bat24_over_voltage();

void canzero_send_bat24_current();

void canzero_send_bat24_current_calibration_offset();

void canzero_send_bat24_current_calibration_target();

void canzero_send_bat24_current_calibration_mode();

void canzero_send_error_bat24_current_invalid();

void canzero_send_error_level_bat24_over_current();

void canzero_send_error_level_config_bat24_over_current();

void canzero_send_link24_voltage();

void canzero_send_link24_voltage_calibration_mode();

void canzero_send_link24_voltage_calibration_offset();

void canzero_send_link24_voltage_calibration_target();

void canzero_send_error_link24_voltage_invalid();

void canzero_send_error_level_link24_under_voltage();

void canzero_send_error_level_config_link24_under_voltage();

void canzero_send_error_level_link24_over_voltage();

void canzero_send_error_level_config_link24_over_voltage();

void canzero_send_link24_current();

void canzero_send_link24_current_calibration_mode();

void canzero_send_link24_current_calibration_offset();

void canzero_send_link24_current_calibration_target();

void canzero_send_error_link24_current_invalid();

void canzero_send_error_level_link24_over_current();

void canzero_send_error_level_config_link24_over_current();

void canzero_send_link45_voltage();

void canzero_send_link45_voltage_calibration_mode();

void canzero_send_link45_voltage_calibration_offset();

void canzero_send_link45_voltage_calibration_target();

void canzero_send_error_link45_voltage_invalid();

void canzero_send_error_level_link45_under_voltage();

void canzero_send_error_level_config_link45_under_voltage();

void canzero_send_error_level_link45_over_voltage();

void canzero_send_error_level_config_link45_over_voltage();

void canzero_send_link45_current();

void canzero_send_link45_current_calibration_mode();

void canzero_send_link45_current_calibration_offset();

void canzero_send_link45_current_calibration_target();

void canzero_send_error_link45_current_invalid();

void canzero_send_error_level_link45_over_current();

void canzero_send_error_level_config_link45_over_current();

void canzero_send_cooling_cycle_pressure();

void canzero_send_cooling_cycle_pressure_calibration_mode();

void canzero_send_cooling_cycle_pressure_calibration_offset();

void canzero_send_cooling_cycle_pressure_calibration_target();

void canzero_send_error_cooling_cycle_pressure_invalid();

void canzero_send_error_level_cooling_cycle_over_pressure();

void canzero_send_error_level_config_cooling_cycle_over_pressure();

void canzero_send_mcu_temperature();

void canzero_send_error_mcu_temperature_invalid();

void canzero_send_error_level_mcu_temperature();

void canzero_send_error_level_config_mcu_temperature();

void canzero_send_cooling_cycle_temperature();

void canzero_send_error_cooling_cycle_temperature_invalid();

void canzero_send_error_level_cooling_cycle_temperature();

void canzero_send_error_level_config_cooling_temperature();

void canzero_send_bat24_temperature();

void canzero_send_error_level_bat24_temperature();

void canzero_send_error_level_config_bat24_temperature();

void canzero_send_error_bat24_temperature_invalid();

void canzero_send_supercap_temperature();

void canzero_send_error_supercap_temperature_invalid();

void canzero_send_error_level_supercap_temperature();

void canzero_send_error_level_config_supercap_temperature();

void canzero_send_buck_temperature();

void canzero_send_error_buck_temperature_invalid();

void canzero_send_error_level_buck_temperature();

void canzero_send_error_level_config_buck_temperature();

void canzero_send_ebox_temperature();

void canzero_send_error_ebox_temperature_invalid();

void canzero_send_error_level_ebox_temperature();

void canzero_send_error_level_config_ebox_temperature();

void canzero_send_ambient_temperature();

void canzero_send_error_ambient_temperature_invalid();

void canzero_send_error_level_ambient_temperature();

void canzero_send_error_level_config_ambient_temperature();

void canzero_send_cooling_cycle_flow_rate();

void canzero_send_loop_frequency();

void canzero_send_assertion_fault();

void canzero_send_error_heartbeat_miss();

#endif