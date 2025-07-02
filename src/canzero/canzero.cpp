#include "canzero.h"
#include <avr/pgmspace.h>
uint32_t min_u32(uint32_t v, uint32_t max) {
    if (v > max) {
        return max;
    }
    return v;
}
uint64_t min_u64(uint64_t v, uint64_t max) {
    if (v > max) {
        return max;
    }
    return v;
}
uint64_t DMAMEM __oe_config_hash;
date_time DMAMEM __oe_build_time;
motor_command DMAMEM __oe_motor_driver_command;
float DMAMEM __oe_target_acceleration;
bool_t DMAMEM __oe_ignore_45v;
global_state DMAMEM __oe_global_state;
global_command DMAMEM __oe_global_command;
sdc_status DMAMEM __oe_system_sdc_status;
bool_t DMAMEM __oe_pod_grounded;
float DMAMEM __oe_system_power_consumption;
float DMAMEM __oe_communication_power_consumption;
float DMAMEM __oe_track_length;
float DMAMEM __oe_brake_margin;
float DMAMEM __oe_emergency_brake_margin;
bool_t DMAMEM __oe_assert_45V_system_online;
sdc_status DMAMEM __oe_sdc_status;
float DMAMEM __oe_loop_frequency;
error_flag DMAMEM __oe_assertion_fault;
error_flag DMAMEM __oe_error_heartbeat_miss;
uint8_t DMAMEM __oe_last_node_missed;
float DMAMEM __oe_acceleration_target_velocity;
pid_parameters DMAMEM __oe_velocity_pid;
float DMAMEM __oe_position;
float DMAMEM __oe_velocity;
float DMAMEM __oe_acceleration;
int16_t DMAMEM __oe_linear_encoder_count;
bool_t DMAMEM __oe_absolute_position_known;
float DMAMEM __oe_absolute_position_offset;
float DMAMEM __oe_raw_acceleration;
error_flag DMAMEM __oe_error_acceleration_out_of_range;
double DMAMEM __oe_acceleration_calibration_variance;
double DMAMEM __oe_acceleration_calibration_offset;
double DMAMEM __oe_acceleration_calibration_target;
float DMAMEM __oe_raw_lateral_acceleration;
float DMAMEM __oe_lateral_acceleration;
error_flag DMAMEM __oe_error_lateral_acceleration_out_of_range;
double DMAMEM __oe_lateral_acceleration_calibration_variance;
double DMAMEM __oe_lateral_acceleration_calibration_offset;
double DMAMEM __oe_lateral_acceleration_calibration_target;
float DMAMEM __oe_raw_vertical_acceleration;
float DMAMEM __oe_vertical_acceleration;
error_flag DMAMEM __oe_error_vertical_acceleration_out_of_range;
double DMAMEM __oe_vertical_acceleration_calibration_variance;
double DMAMEM __oe_vertical_acceleration_calibration_offset;
double DMAMEM __oe_vertical_acceleration_calibration_target;
error_flag DMAMEM __oe_error_acceleration_calibration_failed;
float DMAMEM __oe_bat24_voltage;
calibration_mode DMAMEM __oe_bat24_voltage_calibration_mode;
float DMAMEM __oe_bat24_voltage_calibration_offset;
float DMAMEM __oe_bat24_voltage_calibration_target;
error_flag DMAMEM __oe_error_bat24_voltage_invalid;
error_level DMAMEM __oe_error_level_bat24_under_voltage;
error_level_config DMAMEM __oe_error_level_config_bat24_under_voltage;
error_level DMAMEM __oe_error_level_bat24_over_voltage;
error_level_config DMAMEM __oe_error_level_config_bat24_over_voltage;
float DMAMEM __oe_bat24_current;
float DMAMEM __oe_bat24_current_calibration_offset;
float DMAMEM __oe_bat24_current_calibration_target;
calibration_mode DMAMEM __oe_bat24_current_calibration_mode;
error_flag DMAMEM __oe_error_bat24_current_invalid;
error_level DMAMEM __oe_error_level_bat24_over_current;
error_level_config DMAMEM __oe_error_level_config_bat24_over_current;
float DMAMEM __oe_supercap_voltage;
calibration_mode DMAMEM __oe_supercap_voltage_calibration_mode;
float DMAMEM __oe_supercap_voltage_calibration_offset;
float DMAMEM __oe_supercap_voltage_calibration_target;
error_flag DMAMEM __oe_error_supercap_voltage_invalid;
error_level DMAMEM __oe_error_level_supercap_under_voltage;
error_level_config DMAMEM __oe_error_level_config_supercap_under_voltage;
error_level DMAMEM __oe_error_level_supercap_over_voltage;
error_level_config DMAMEM __oe_error_level_config_supercap_over_voltage;
float DMAMEM __oe_link24_current;
calibration_mode DMAMEM __oe_link24_current_calibration_mode;
float DMAMEM __oe_link24_current_calibration_offset;
float DMAMEM __oe_link24_current_calibration_target;
error_flag DMAMEM __oe_error_link24_current_invalid;
error_level DMAMEM __oe_error_level_link24_over_current;
error_level_config DMAMEM __oe_error_level_config_link24_over_current;
float DMAMEM __oe_link45_voltage;
calibration_mode DMAMEM __oe_link45_voltage_calibration_mode;
float DMAMEM __oe_link45_voltage_calibration_offset;
float DMAMEM __oe_link45_voltage_calibration_target;
error_flag DMAMEM __oe_error_link45_voltage_invalid;
error_level DMAMEM __oe_error_level_link45_under_voltage;
error_level_config DMAMEM __oe_error_level_config_link45_under_voltage;
error_level DMAMEM __oe_error_level_link45_over_voltage;
error_level_config DMAMEM __oe_error_level_config_link45_over_voltage;
float DMAMEM __oe_link45_current;
calibration_mode DMAMEM __oe_link45_current_calibration_mode;
float DMAMEM __oe_link45_current_calibration_offset;
float DMAMEM __oe_link45_current_calibration_target;
error_flag DMAMEM __oe_error_link45_current_invalid;
error_level DMAMEM __oe_error_level_link45_over_current;
error_level_config DMAMEM __oe_error_level_config_link45_over_current;
float DMAMEM __oe_mcu_temperature;
error_flag DMAMEM __oe_error_mcu_temperature_invalid;
error_level DMAMEM __oe_error_level_mcu_temperature;
error_level_config DMAMEM __oe_error_level_config_mcu_temperature;
float DMAMEM __oe_bat24_cell_temperature_1;
float DMAMEM __oe_bat24_cell_temperature_2;
float DMAMEM __oe_bat24_temperature_max;
error_flag DMAMEM __oe_error_bat24_cell_temperature_1_invalid;
error_flag DMAMEM __oe_error_bat24_cell_temperature_2_invalid;
error_level DMAMEM __oe_error_level_bat24_temperature;
error_level_config DMAMEM __oe_error_level_config_bat24_temperature;
float DMAMEM __oe_supercap_temperature;
error_flag DMAMEM __oe_error_supercap_temperature_invalid;
error_level DMAMEM __oe_error_level_supercap_temperature;
error_level_config DMAMEM __oe_error_level_config_supercap_temperature;
float DMAMEM __oe_sac_ebox_temperature;
error_flag DMAMEM __oe_error_sac_ebox_temperature_invalid;
error_level DMAMEM __oe_error_level_sac_ebox_temperature;
error_level_config DMAMEM __oe_error_level_config_sac_ebox_temperature;
float DMAMEM __oe_power_ebox_temperature;
error_flag DMAMEM __oe_error_power_ebox_temperature_invalid;
error_level DMAMEM __oe_error_level_power_ebox_temperature;
error_level_config DMAMEM __oe_error_level_config_power_ebox_temperature;
float DMAMEM __oe_ambient_temperature_1;
float DMAMEM __oe_ambient_temperature_2;
float DMAMEM __oe_ambient_temperature_3;
float DMAMEM __oe_ambient_temperature_avg;
float DMAMEM __oe_ambient_temperature_max;
error_flag DMAMEM __oe_error_ambient_temperature_1_invalid;
error_flag DMAMEM __oe_error_ambient_temperature_2_invalid;
error_flag DMAMEM __oe_error_ambient_temperature_3_invalid;
error_level DMAMEM __oe_error_level_ambient_temperature;
error_level_config DMAMEM __oe_error_level_config_ambient_temperature;
float DMAMEM __oe_cooling_flow_rate_begin;
float DMAMEM __oe_cooling_flow_rate_end;
error_flag DMAMEM __oe_error_cooling_flow_rate_low;
error_flag DMAMEM __oe_error_cooling_flow_rate_mismatch;
float DMAMEM __oe_cooling_cycle_temp_begin;
float DMAMEM __oe_cooling_cycle_temp_end;
error_flag DMAMEM __oe_error_cooling_cycle_temp_begin_invalid;
error_flag DMAMEM __oe_error_cooling_cycle_temp_end_invalid;
error_level DMAMEM __oe_error_level_cooling_cycle_overtemp;
motor_state DMAMEM __oe_motor_driver_state;
sdc_status DMAMEM __oe_motor_driver_sdc_status;
uint64_t DMAMEM __oe_motor_driver_config_hash;
error_flag DMAMEM __oe_motor_driver_assertion_fault;
error_flag DMAMEM __oe_motor_driver_error_arming_failed;
error_flag DMAMEM __oe_motor_driver_error_precharge_failed;
error_flag DMAMEM __oe_motor_driver_error_acceleration_out_of_range;
error_flag DMAMEM __oe_motor_driver_error_acceleration_calibration_failed;
error_flag DMAMEM __oe_motor_driver_error_invalid_target_acceleration;
error_flag DMAMEM __oe_motor_driver_error_vdc_voltage_invalid;
error_flag DMAMEM __oe_motor_driver_error_board_temperature1_invalid;
error_flag DMAMEM __oe_motor_driver_error_board_temperature2_invalid;
error_flag DMAMEM __oe_motor_driver_error_board_temperature3_invalid;
error_flag DMAMEM __oe_motor_driver_error_mcu_temperature_invalid;
error_flag DMAMEM __oe_motor_driver_error_lim_temperature1_invalid;
error_flag DMAMEM __oe_motor_driver_error_lim_temperature2_invalid;
error_flag DMAMEM __oe_motor_driver_error_lim_temperature3_invalid;
error_flag DMAMEM __oe_motor_driver_error_lim_temperature4_invalid;
error_flag DMAMEM __oe_motor_driver_error_heartbeat_miss;
error_flag DMAMEM __oe_motor_driver_error_phase_current_unexpected;
error_flag DMAMEM __oe_motor_driver_error_sdc_brake;
error_level DMAMEM __oe_motor_driver_error_level_current_u1;
error_level DMAMEM __oe_motor_driver_error_level_current_v1;
error_level DMAMEM __oe_motor_driver_error_level_current_w1;
error_level DMAMEM __oe_motor_driver_error_level_current_u2;
error_level DMAMEM __oe_motor_driver_error_level_current_v2;
error_level DMAMEM __oe_motor_driver_error_level_current_w2;
error_level DMAMEM __oe_motor_driver_error_level_vdc_voltage;
error_level DMAMEM __oe_motor_driver_error_level_board_temperature;
error_level DMAMEM __oe_motor_driver_error_level_mcu_temperature;
error_level DMAMEM __oe_motor_driver_error_level_lim_temperature;
error_flag DMAMEM __oe_motor_driver_phase_current_unexpected;
guidance_command DMAMEM __oe_guidance_command;
guidance_state DMAMEM __oe_guidance_board_front_state;
sdc_status DMAMEM __oe_guidance_board_front_sdc_status;
uint64_t DMAMEM __oe_guidance_board_front_config_hash;
error_flag DMAMEM __oe_guidance_board_front_assertion_fault;
error_flag DMAMEM __oe_guidance_board_front_error_arming_failed;
error_flag DMAMEM __oe_guidance_board_front_error_precharge_failed;
error_flag DMAMEM __oe_guidance_board_front_error_heartbeat_miss;
error_flag DMAMEM __oe_guidance_board_front_error_outer_airgap_left_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_inner_airgap_left_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_outer_airgap_right_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_inner_airgap_right_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_vdc_voltage_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_magnet_current_left_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_magnet_current_right_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_input_current_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_magnet_temperature_left_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_magnet_temperature_right_invalid;
error_flag DMAMEM __oe_guidance_board_front_error_mcu_temperature_invalid;
error_level DMAMEM __oe_guidance_board_front_error_level_vdc_voltage;
error_level DMAMEM __oe_guidance_board_front_error_level_magnet_current_left;
error_level DMAMEM __oe_guidance_board_front_error_level_magnet_current_right;
error_level DMAMEM __oe_guidance_board_front_error_level_input_current;
error_level DMAMEM __oe_guidance_board_front_error_level_magnet_temperature_left;
error_level DMAMEM __oe_guidance_board_front_error_level_magnet_temperature_right;
error_level DMAMEM __oe_guidance_board_front_error_level_mcu_temperature;
guidance_state DMAMEM __oe_guidance_board_back_state;
sdc_status DMAMEM __oe_guidance_board_back_sdc_status;
uint64_t DMAMEM __oe_guidance_board_back_config_hash;
error_flag DMAMEM __oe_guidance_board_back_assertion_fault;
error_flag DMAMEM __oe_guidance_board_back_error_arming_failed;
error_flag DMAMEM __oe_guidance_board_back_error_precharge_failed;
error_flag DMAMEM __oe_guidance_board_back_error_heartbeat_miss;
error_flag DMAMEM __oe_guidance_board_back_error_outer_airgap_left_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_inner_airgap_left_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_outer_airgap_right_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_inner_airgap_right_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_vdc_voltage_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_magnet_current_left_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_magnet_current_right_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_input_current_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_magnet_temperature_left_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_magnet_temperature_right_invalid;
error_flag DMAMEM __oe_guidance_board_back_error_mcu_temperature_invalid;
error_level DMAMEM __oe_guidance_board_back_error_level_vdc_voltage;
error_level DMAMEM __oe_guidance_board_back_error_level_magnet_current_left;
error_level DMAMEM __oe_guidance_board_back_error_level_magnet_current_right;
error_level DMAMEM __oe_guidance_board_back_error_level_input_current;
error_level DMAMEM __oe_guidance_board_back_error_level_magnet_temperature_left;
error_level DMAMEM __oe_guidance_board_back_error_level_magnet_temperature_right;
error_level DMAMEM __oe_guidance_board_back_error_level_mcu_temperature;
levitation_command DMAMEM __oe_levitation_command;
levitation_state DMAMEM __oe_levitation_board1_state;
sdc_status DMAMEM __oe_levitation_board1_sdc_status;
uint64_t DMAMEM __oe_levitation_board1_config_hash;
error_flag DMAMEM __oe_levitation_board1_assertion_fault;
error_flag DMAMEM __oe_levitation_board1_error_airgap_left_invalid;
error_flag DMAMEM __oe_levitation_board1_error_airgap_right_invalid;
error_flag DMAMEM __oe_levitation_board1_error_vdc_voltage_invalid;
error_flag DMAMEM __oe_levitation_board1_error_magnet_current_left_invalid;
error_flag DMAMEM __oe_levitation_board1_error_magnet_current_right_invalid;
error_flag DMAMEM __oe_levitation_board1_error_magnet_temperature_left_invalid;
error_flag DMAMEM __oe_levitation_board1_error_magnet_temperature_right_invalid;
error_flag DMAMEM __oe_levitation_board1_error_mcu_temperature_invalid;
error_flag DMAMEM __oe_levitation_board1_error_arming_failed;
error_flag DMAMEM __oe_levitation_board1_error_precharge_failed;
error_flag DMAMEM __oe_levitation_board1_error_heartbeat_miss;
error_level DMAMEM __oe_levitation_board1_error_level_vdc_voltage;
error_level DMAMEM __oe_levitation_board1_error_level_magnet_current_left;
error_level DMAMEM __oe_levitation_board1_error_level_magnet_current_right;
error_level DMAMEM __oe_levitation_board1_error_level_input_current;
error_level DMAMEM __oe_levitation_board1_error_level_magnet_temperature_left;
error_level DMAMEM __oe_levitation_board1_error_level_magnet_temperature_right;
error_level DMAMEM __oe_levitation_board1_error_level_mcu_temperature;
levitation_state DMAMEM __oe_levitation_board2_state;
sdc_status DMAMEM __oe_levitation_board2_sdc_status;
uint64_t DMAMEM __oe_levitation_board2_config_hash;
error_flag DMAMEM __oe_levitation_board2_assertion_fault;
error_flag DMAMEM __oe_levitation_board2_error_airgap_left_invalid;
error_flag DMAMEM __oe_levitation_board2_error_airgap_right_invalid;
error_flag DMAMEM __oe_levitation_board2_error_vdc_voltage_invalid;
error_flag DMAMEM __oe_levitation_board2_error_magnet_current_left_invalid;
error_flag DMAMEM __oe_levitation_board2_error_magnet_current_right_invalid;
error_flag DMAMEM __oe_levitation_board2_error_magnet_temperature_left_invalid;
error_flag DMAMEM __oe_levitation_board2_error_magnet_temperature_right_invalid;
error_flag DMAMEM __oe_levitation_board2_error_mcu_temperature_invalid;
error_flag DMAMEM __oe_levitation_board2_error_arming_failed;
error_flag DMAMEM __oe_levitation_board2_error_precharge_failed;
error_flag DMAMEM __oe_levitation_board2_error_heartbeat_miss;
error_level DMAMEM __oe_levitation_board2_error_level_vdc_voltage;
error_level DMAMEM __oe_levitation_board2_error_level_magnet_current_left;
error_level DMAMEM __oe_levitation_board2_error_level_magnet_current_right;
error_level DMAMEM __oe_levitation_board2_error_level_input_current;
error_level DMAMEM __oe_levitation_board2_error_level_magnet_temperature_left;
error_level DMAMEM __oe_levitation_board2_error_level_magnet_temperature_right;
error_level DMAMEM __oe_levitation_board2_error_level_mcu_temperature;
levitation_state DMAMEM __oe_levitation_board3_state;
sdc_status DMAMEM __oe_levitation_board3_sdc_status;
uint64_t DMAMEM __oe_levitation_board3_config_hash;
error_flag DMAMEM __oe_levitation_board3_assertion_fault;
error_flag DMAMEM __oe_levitation_board3_error_airgap_left_invalid;
error_flag DMAMEM __oe_levitation_board3_error_airgap_right_invalid;
error_flag DMAMEM __oe_levitation_board3_error_vdc_voltage_invalid;
error_flag DMAMEM __oe_levitation_board3_error_magnet_current_left_invalid;
error_flag DMAMEM __oe_levitation_board3_error_magnet_current_right_invalid;
error_flag DMAMEM __oe_levitation_board3_error_magnet_temperature_left_invalid;
error_flag DMAMEM __oe_levitation_board3_error_magnet_temperature_right_invalid;
error_flag DMAMEM __oe_levitation_board3_error_mcu_temperature_invalid;
error_flag DMAMEM __oe_levitation_board3_error_arming_failed;
error_flag DMAMEM __oe_levitation_board3_error_precharge_failed;
error_flag DMAMEM __oe_levitation_board3_error_heartbeat_miss;
error_level DMAMEM __oe_levitation_board3_error_level_vdc_voltage;
error_level DMAMEM __oe_levitation_board3_error_level_magnet_current_left;
error_level DMAMEM __oe_levitation_board3_error_level_magnet_current_right;
error_level DMAMEM __oe_levitation_board3_error_level_input_current;
error_level DMAMEM __oe_levitation_board3_error_level_magnet_temperature_left;
error_level DMAMEM __oe_levitation_board3_error_level_magnet_temperature_right;
error_level DMAMEM __oe_levitation_board3_error_level_mcu_temperature;
pdu_12v_state DMAMEM __oe_power_board12_state;
pdu_12v_command DMAMEM __oe_power_board12_command;
sdc_status DMAMEM __oe_power_board12_sdc_status;
uint64_t DMAMEM __oe_power_board12_config_hash;
error_flag DMAMEM __oe_power_board12_assertion_fault;
error_flag DMAMEM __oe_power_board12_error_any_short;
error_flag DMAMEM __oe_power_board12_error_heartbeat_miss;
error_level DMAMEM __oe_power_board12_error_level_mcu_temperature;
pdu_24v_state DMAMEM __oe_power_board24_state;
pdu_24v_command DMAMEM __oe_power_board24_command;
sdc_status DMAMEM __oe_power_board24_sdc_status;
bool_t DMAMEM __oe_power_board24_cooling_pump_channel_ctrl;
uint64_t DMAMEM __oe_power_board24_config_hash;
error_flag DMAMEM __oe_power_board24_assertion_fault;
error_flag DMAMEM __oe_power_board24_error_any_short;
error_flag DMAMEM __oe_power_board24_error_heartbeat_miss;
error_level DMAMEM __oe_power_board24_error_level_mcu_temperature;
led_board_state DMAMEM __oe_led_board_state;
led_board_command DMAMEM __oe_led_board_command;
sdc_status DMAMEM __oe_led_board_sdc_status;
uint64_t DMAMEM __oe_led_board_config_hash;
error_flag DMAMEM __oe_led_board_assertion_fault;
error_flag DMAMEM __oe_led_board_error_heartbeat_miss;
error_level DMAMEM __oe_led_board_error_level_mcu_temperature;
float DMAMEM __oe_gamepad_max_acceleration;
float DMAMEM __oe_gamepad_lt2;
float DMAMEM __oe_gamepad_rt2;
float DMAMEM __oe_target_airgap;
float DMAMEM __oe_airgap_transition_duration;
airgap_transition_mode DMAMEM __oe_airgap_transition_mode;
error_flag DMAMEM __oe_guidance_board_front_error_sdc_brake;
error_flag DMAMEM __oe_guidance_board_front_error_magnet_current_left_unexpected;
error_flag DMAMEM __oe_guidance_board_front_error_magnet_current_right_unexpected;
error_flag DMAMEM __oe_guidance_board_back_error_sdc_brake;
error_flag DMAMEM __oe_guidance_board_back_error_magnet_current_left_unexpected;
error_flag DMAMEM __oe_guidance_board_back_error_magnet_current_right_unexpected;
error_flag DMAMEM __oe_levitation_board1_error_sdc_brake;
error_flag DMAMEM __oe_levitation_board1_error_magnet_current_left_unexpected;
error_flag DMAMEM __oe_levitation_board1_error_magnet_current_right_unexpected;
error_flag DMAMEM __oe_levitation_board2_error_sdc_brake;
error_flag DMAMEM __oe_levitation_board2_error_magnet_current_left_unexpected;
error_flag DMAMEM __oe_levitation_board2_error_magnet_current_right_unexpected;
error_flag DMAMEM __oe_levitation_board3_error_sdc_brake;
error_flag DMAMEM __oe_levitation_board3_error_magnet_current_left_unexpected;
error_flag DMAMEM __oe_levitation_board3_error_magnet_current_right_unexpected;
error_level DMAMEM __oe_error_level_config_consistency;
error_level DMAMEM __oe_error_any;
error_level DMAMEM __oe_error_level_over_temperature_system;
static void canzero_serialize_canzero_message_get_resp(canzero_message_get_resp* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x13D;
  frame->dlc = 8;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_header.m_sof & (0xFF >> (8 - 1)));
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_eof & (0xFF >> (8 - 1))) << 1;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_toggle & (0xFF >> (8 - 1))) << 2;
  ((volatile uint32_t*)data)[0] |= (uint16_t)(msg->m_header.m_od_index & (0xFFFF >> (16 - 13))) << 3;
  ((volatile uint32_t*)data)[0] |= msg->m_header.m_client_id << 16;
  ((volatile uint32_t*)data)[0] |= msg->m_header.m_server_id << 24;
  ((volatile uint32_t*)data)[1] = msg->m_data;
}
static void canzero_serialize_canzero_message_set_resp(canzero_message_set_resp* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x15D;
  frame->dlc = 4;
  ((volatile uint32_t*)data)[0] = (uint16_t)(msg->m_header.m_od_index & (0xFFFF >> (16 - 13)));
  ((volatile uint32_t*)data)[0] |= msg->m_header.m_client_id << 13;
  ((volatile uint32_t*)data)[0] |= msg->m_header.m_server_id << 21;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_erno & (0xFF >> (8 - 1))) << 29;
}
static void canzero_serialize_canzero_message_input_board_stream_motor_command(canzero_message_input_board_stream_motor_command* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x4A;
  frame->dlc = 5;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_motor_driver_command & (0xFF >> (8 - 3)));
  uint32_t target_acceleration_3 = ((msg->m_target_acceleration - -50) / 0.000000023283064370807974) + 0.5f;
  if (target_acceleration_3 > 0xFFFFFFFF) {
    target_acceleration_3 = 0xFFFFFFFF;
  }
  ((volatile uint64_t*)data)[0] |= ((uint64_t)target_acceleration_3) << 3 ;
  ((volatile uint32_t*)data)[1] |= (uint8_t)(msg->m_pod_grounded & (0xFF >> (8 - 1))) << 3;
}
static void canzero_serialize_canzero_message_input_board_stream_debug_settings(canzero_message_input_board_stream_debug_settings* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x4D;
  frame->dlc = 1;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_ignore_45v & (0xFF >> (8 - 1)));
}
static void canzero_serialize_canzero_message_input_board_stream_position_estimation(canzero_message_input_board_stream_position_estimation* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x9A;
  frame->dlc = 6;
  uint32_t position_0 = ((msg->m_position - -10) / 0.0007629510948348211) + 0.5f;
  if (position_0 > 0xFFFF) {
    position_0 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] = position_0;
  uint32_t velocity_16 = ((msg->m_velocity - -10) / 0.00030518043793392844) + 0.5f;
  if (velocity_16 > 0xFFFF) {
    velocity_16 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] |= velocity_16 << 16;
  uint32_t acceleration_32 = ((msg->m_acceleration - -50) / 0.0015259021896696422) + 0.5f;
  if (acceleration_32 > 0xFFFF) {
    acceleration_32 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[1] = acceleration_32;
}
static void canzero_serialize_canzero_message_input_board_stream_linear_encoder(canzero_message_input_board_stream_linear_encoder* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xFB;
  frame->dlc = 5;
  ((volatile uint32_t*)data)[0] = msg->m_linear_encoder_count;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_absolute_position_known & (0xFF >> (8 - 1))) << 16;
  uint32_t absolute_position_offset_17 = ((msg->m_absolute_position_offset - -10) / 0.0006103608758678569) + 0.5f;
  if (absolute_position_offset_17 > 0xFFFF) {
    absolute_position_offset_17 = 0xFFFF;
  }
  ((volatile uint64_t*)data)[0] |= ((uint64_t)absolute_position_offset_17) << 17 ;
}
static void canzero_serialize_canzero_message_input_board_stream_accelerations(canzero_message_input_board_stream_accelerations* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x7C;
  frame->dlc = 6;
  uint32_t raw_acceleration_0 = ((msg->m_raw_acceleration - -50) / 0.0015259021896696422) + 0.5f;
  if (raw_acceleration_0 > 0xFFFF) {
    raw_acceleration_0 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] = raw_acceleration_0;
  uint32_t lateral_acceleration_16 = ((msg->m_lateral_acceleration - -10) / 0.00030518043793392844) + 0.5f;
  if (lateral_acceleration_16 > 0xFFFF) {
    lateral_acceleration_16 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] |= lateral_acceleration_16 << 16;
  uint32_t vertical_acceleration_32 = ((msg->m_vertical_acceleration - -10) / 0.00030518043793392844) + 0.5f;
  if (vertical_acceleration_32 > 0xFFFF) {
    vertical_acceleration_32 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[1] = vertical_acceleration_32;
}
static void canzero_serialize_canzero_message_input_board_stream_bat24(canzero_message_input_board_stream_bat24* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xBC;
  frame->dlc = 8;
  uint32_t bat24_voltage_0 = ((msg->m_bat24_voltage - 0) / 0.000000011641532185403987) + 0.5f;
  if (bat24_voltage_0 > 0xFFFFFFFF) {
    bat24_voltage_0 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[0] = bat24_voltage_0;
  uint32_t bat24_current_32 = ((msg->m_bat24_current - -30) / 0.000000013969838622484784) + 0.5f;
  if (bat24_current_32 > 0xFFFFFFFF) {
    bat24_current_32 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[1] = bat24_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_link24(canzero_message_input_board_stream_link24* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x11B;
  frame->dlc = 8;
  uint32_t supercap_voltage_0 = ((msg->m_supercap_voltage - 0) / 0.000000011641532185403987) + 0.5f;
  if (supercap_voltage_0 > 0xFFFFFFFF) {
    supercap_voltage_0 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[0] = supercap_voltage_0;
  uint32_t link24_current_32 = ((msg->m_link24_current - -30) / 0.000000013969838622484784) + 0.5f;
  if (link24_current_32 > 0xFFFFFFFF) {
    link24_current_32 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[1] = link24_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_link45(canzero_message_input_board_stream_link45* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x5A;
  frame->dlc = 8;
  uint32_t link45_voltage_0 = ((msg->m_link45_voltage - -100) / 0.00000004656612874161595) + 0.5f;
  if (link45_voltage_0 > 0xFFFFFFFF) {
    link45_voltage_0 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[0] = link45_voltage_0;
  uint32_t link45_current_32 = ((msg->m_link45_current - -1000) / 0.0000004656612874161595) + 0.5f;
  if (link45_current_32 > 0xFFFFFFFF) {
    link45_current_32 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[1] = link45_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_mics_temperatures(canzero_message_input_board_stream_mics_temperatures* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x7A;
  frame->dlc = 4;
  uint32_t mcu_temperature_0 = ((msg->m_mcu_temperature - -1) / 0.592156862745098) + 0.5f;
  if (mcu_temperature_0 > 0xFF) {
    mcu_temperature_0 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] = mcu_temperature_0;
  uint32_t supercap_temperature_8 = ((msg->m_supercap_temperature - -1) / 0.592156862745098) + 0.5f;
  if (supercap_temperature_8 > 0xFF) {
    supercap_temperature_8 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= supercap_temperature_8 << 8;
  uint32_t sac_ebox_temperature_16 = ((msg->m_sac_ebox_temperature - -1) / 0.592156862745098) + 0.5f;
  if (sac_ebox_temperature_16 > 0xFF) {
    sac_ebox_temperature_16 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= sac_ebox_temperature_16 << 16;
  uint32_t power_ebox_temperature_24 = ((msg->m_power_ebox_temperature - -1) / 0.592156862745098) + 0.5f;
  if (power_ebox_temperature_24 > 0xFF) {
    power_ebox_temperature_24 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= power_ebox_temperature_24 << 24;
}
static void canzero_serialize_canzero_message_input_board_stream_bat_temperatures(canzero_message_input_board_stream_bat_temperatures* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xDC;
  frame->dlc = 3;
  uint32_t bat24_cell_temperature_1_0 = ((msg->m_bat24_cell_temperature_1 - -1) / 0.592156862745098) + 0.5f;
  if (bat24_cell_temperature_1_0 > 0xFF) {
    bat24_cell_temperature_1_0 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] = bat24_cell_temperature_1_0;
  uint32_t bat24_cell_temperature_2_8 = ((msg->m_bat24_cell_temperature_2 - -1) / 0.592156862745098) + 0.5f;
  if (bat24_cell_temperature_2_8 > 0xFF) {
    bat24_cell_temperature_2_8 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= bat24_cell_temperature_2_8 << 8;
  uint32_t bat24_temperature_max_16 = ((msg->m_bat24_temperature_max - -1) / 0.592156862745098) + 0.5f;
  if (bat24_temperature_max_16 > 0xFF) {
    bat24_temperature_max_16 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= bat24_temperature_max_16 << 16;
}
static void canzero_serialize_canzero_message_input_board_stream_cooling_cycle(canzero_message_input_board_stream_cooling_cycle* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x11C;
  frame->dlc = 6;
  uint32_t cooling_flow_rate_begin_0 = ((msg->m_cooling_flow_rate_begin - 0) / 0.006103608758678569) + 0.5f;
  if (cooling_flow_rate_begin_0 > 0xFFFF) {
    cooling_flow_rate_begin_0 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] = cooling_flow_rate_begin_0;
  uint32_t cooling_flow_rate_end_16 = ((msg->m_cooling_flow_rate_end - 0) / 0.006103608758678569) + 0.5f;
  if (cooling_flow_rate_end_16 > 0xFFFF) {
    cooling_flow_rate_end_16 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] |= cooling_flow_rate_end_16 << 16;
  uint32_t cooling_cycle_temp_begin_32 = ((msg->m_cooling_cycle_temp_begin - -1) / 0.592156862745098) + 0.5f;
  if (cooling_cycle_temp_begin_32 > 0xFF) {
    cooling_cycle_temp_begin_32 = 0xFF;
  }
  ((volatile uint32_t*)data)[1] = cooling_cycle_temp_begin_32;
  uint32_t cooling_cycle_temp_end_40 = ((msg->m_cooling_cycle_temp_end - -1) / 0.592156862745098) + 0.5f;
  if (cooling_cycle_temp_end_40 > 0xFF) {
    cooling_cycle_temp_end_40 = 0xFF;
  }
  ((volatile uint32_t*)data)[1] |= cooling_cycle_temp_end_40 << 8;
}
static void canzero_serialize_canzero_message_input_board_stream_ambient_temperatures(canzero_message_input_board_stream_ambient_temperatures* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x9C;
  frame->dlc = 6;
  uint32_t ambient_temperature_1_0 = ((msg->m_ambient_temperature_1 - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_1_0 > 0xFF) {
    ambient_temperature_1_0 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] = ambient_temperature_1_0;
  uint32_t ambient_temperature_2_8 = ((msg->m_ambient_temperature_2 - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_2_8 > 0xFF) {
    ambient_temperature_2_8 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= ambient_temperature_2_8 << 8;
  uint32_t ambient_temperature_3_16 = ((msg->m_ambient_temperature_3 - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_3_16 > 0xFF) {
    ambient_temperature_3_16 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= ambient_temperature_3_16 << 16;
  uint32_t ambient_temperature_max_24 = ((msg->m_ambient_temperature_max - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_max_24 > 0xFF) {
    ambient_temperature_max_24 = 0xFF;
  }
  ((volatile uint32_t*)data)[0] |= ambient_temperature_max_24 << 24;
  uint32_t ambient_temperature_avg_32 = ((msg->m_ambient_temperature_avg - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_avg_32 > 0xFF) {
    ambient_temperature_avg_32 = 0xFF;
  }
  ((volatile uint32_t*)data)[1] = ambient_temperature_avg_32;
  uint32_t supercap_temperature_40 = ((msg->m_supercap_temperature - -1) / 0.592156862745098) + 0.5f;
  if (supercap_temperature_40 > 0xFF) {
    supercap_temperature_40 = 0xFF;
  }
  ((volatile uint32_t*)data)[1] |= supercap_temperature_40 << 8;
}
static void canzero_serialize_canzero_message_input_board_stream_power_consumption(canzero_message_input_board_stream_power_consumption* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xBA;
  frame->dlc = 4;
  uint32_t system_power_consumption_0 = ((msg->m_system_power_consumption - 0) / 0.15259021896696423) + 0.5f;
  if (system_power_consumption_0 > 0xFFFF) {
    system_power_consumption_0 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] = system_power_consumption_0;
  uint32_t communication_power_consumption_16 = ((msg->m_communication_power_consumption - 0) / 0.007629510948348211) + 0.5f;
  if (communication_power_consumption_16 > 0xFFFF) {
    communication_power_consumption_16 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[0] |= communication_power_consumption_16 << 16;
}
static void canzero_serialize_canzero_message_input_board_stream_errors(canzero_message_input_board_stream_errors* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x5B;
  frame->dlc = 4;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_assertion_fault & (0xFF >> (8 - 1)));
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_acceleration_out_of_range & (0xFF >> (8 - 1))) << 1;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_lateral_acceleration_out_of_range & (0xFF >> (8 - 1))) << 2;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_vertical_acceleration_out_of_range & (0xFF >> (8 - 1))) << 3;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_acceleration_calibration_failed & (0xFF >> (8 - 1))) << 4;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_voltage_invalid & (0xFF >> (8 - 1))) << 5;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_current_invalid & (0xFF >> (8 - 1))) << 6;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_supercap_voltage_invalid & (0xFF >> (8 - 1))) << 7;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_link24_current_invalid & (0xFF >> (8 - 1))) << 8;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_link45_voltage_invalid & (0xFF >> (8 - 1))) << 9;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_link45_current_invalid & (0xFF >> (8 - 1))) << 10;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_mcu_temperature_invalid & (0xFF >> (8 - 1))) << 11;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_sac_ebox_temperature_invalid & (0xFF >> (8 - 1))) << 12;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_power_ebox_temperature_invalid & (0xFF >> (8 - 1))) << 13;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_cell_temperature_1_invalid & (0xFF >> (8 - 1))) << 14;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_cell_temperature_2_invalid & (0xFF >> (8 - 1))) << 15;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_supercap_temperature_invalid & (0xFF >> (8 - 1))) << 16;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_ambient_temperature_1_invalid & (0xFF >> (8 - 1))) << 17;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_ambient_temperature_2_invalid & (0xFF >> (8 - 1))) << 18;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_ambient_temperature_3_invalid & (0xFF >> (8 - 1))) << 19;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_heartbeat_miss & (0xFF >> (8 - 1))) << 20;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_under_voltage & (0xFF >> (8 - 2))) << 21;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_over_voltage & (0xFF >> (8 - 2))) << 23;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_over_current & (0xFF >> (8 - 2))) << 25;
}
static void canzero_serialize_canzero_message_input_board_stream_errors2(canzero_message_input_board_stream_errors2* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x7B;
  frame->dlc = 4;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_error_level_supercap_under_voltage & (0xFF >> (8 - 2)));
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_supercap_over_voltage & (0xFF >> (8 - 2))) << 2;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link24_over_current & (0xFF >> (8 - 2))) << 4;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_under_voltage & (0xFF >> (8 - 2))) << 6;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_over_voltage & (0xFF >> (8 - 2))) << 8;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_over_current & (0xFF >> (8 - 2))) << 10;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_mcu_temperature & (0xFF >> (8 - 2))) << 12;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_temperature & (0xFF >> (8 - 2))) << 14;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_supercap_temperature & (0xFF >> (8 - 2))) << 16;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_sac_ebox_temperature & (0xFF >> (8 - 2))) << 18;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_power_ebox_temperature & (0xFF >> (8 - 2))) << 20;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_ambient_temperature & (0xFF >> (8 - 2))) << 22;
  ((volatile uint32_t*)data)[0] |= msg->m_last_node_missed << 24;
}
static void canzero_serialize_canzero_message_input_board_stream_errors3(canzero_message_input_board_stream_errors3* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x9B;
  frame->dlc = 1;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_error_cooling_flow_rate_low & (0xFF >> (8 - 1)));
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_cooling_flow_rate_mismatch & (0xFF >> (8 - 1))) << 1;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_cooling_cycle_temp_begin_invalid & (0xFF >> (8 - 1))) << 2;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_cooling_cycle_temp_end_invalid & (0xFF >> (8 - 1))) << 3;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_cooling_cycle_overtemp & (0xFF >> (8 - 2))) << 4;
}
static void canzero_serialize_canzero_message_input_board_stream_config_hash(canzero_message_input_board_stream_config_hash* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xFC;
  frame->dlc = 8;
  ((volatile uint64_t*)data)[0] = msg->m_config_hash;
}
static void canzero_serialize_canzero_message_input_board_stream_state(canzero_message_input_board_stream_state* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xDA;
  frame->dlc = 2;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_global_state & (0xFF >> (8 - 5)));
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_global_command & (0xFF >> (8 - 4))) << 5;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_system_sdc_status & (0xFF >> (8 - 1))) << 9;
}
static void canzero_serialize_canzero_message_input_board_stream_guidance_command(canzero_message_input_board_stream_guidance_command* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x4C;
  frame->dlc = 1;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_guidance_command & (0xFF >> (8 - 3)));
}
static void canzero_serialize_canzero_message_input_board_stream_levitation_command(canzero_message_input_board_stream_levitation_command* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x4B;
  frame->dlc = 1;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_levitation_command & (0xFF >> (8 - 3)));
}
static void canzero_serialize_canzero_message_input_board_stream_levitation_conifg(canzero_message_input_board_stream_levitation_conifg* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xDB;
  frame->dlc = 7;
  uint32_t target_airgap_0 = ((msg->m_target_airgap - 0) / 0.000000003492459655621196) + 0.5f;
  if (target_airgap_0 > 0xFFFFFFFF) {
    target_airgap_0 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[0] = target_airgap_0;
  uint32_t airgap_transition_duration_32 = ((msg->m_airgap_transition_duration - 0) / 0.0009155413138017853) + 0.5f;
  if (airgap_transition_duration_32 > 0xFFFF) {
    airgap_transition_duration_32 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[1] = airgap_transition_duration_32;
  ((volatile uint32_t*)data)[1] |= (uint8_t)(msg->m_airgap_transition_mode & (0xFF >> (8 - 2))) << 16;
}
static void canzero_serialize_canzero_message_input_board_stream_pdu_12v_command(canzero_message_input_board_stream_pdu_12v_command* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x49;
  frame->dlc = 1;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_power_board12_command & (0xFF >> (8 - 3)));
}
static void canzero_serialize_canzero_message_input_board_stream_pdu_24v_command(canzero_message_input_board_stream_pdu_24v_command* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x48;
  frame->dlc = 1;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_power_board24_command & (0xFF >> (8 - 2)));
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_power_board24_cooling_pump_channel_ctrl & (0xFF >> (8 - 1))) << 2;
}
static void canzero_serialize_canzero_message_input_board_stream_global_fsm_errors(canzero_message_input_board_stream_global_fsm_errors* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xBB;
  frame->dlc = 2;
  ((volatile uint32_t*)data)[0] = (uint8_t)(msg->m_error_heartbeat_miss & (0xFF >> (8 - 1)));
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_any & (0xFF >> (8 - 2))) << 1;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_over_temperature_system & (0xFF >> (8 - 2))) << 3;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_config_consistency & (0xFF >> (8 - 2))) << 5;
  ((volatile uint32_t*)data)[0] |= msg->m_last_node_missed << 7;
}
static void canzero_serialize_canzero_message_input_board_stream_levitation_config(canzero_message_input_board_stream_levitation_config* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x6B;
  frame->dlc = 7;
  uint32_t target_airgap_0 = ((msg->m_target_airgap - 0) / 0.000000003492459655621196) + 0.5f;
  if (target_airgap_0 > 0xFFFFFFFF) {
    target_airgap_0 = 0xFFFFFFFF;
  }
  ((volatile uint32_t*)data)[0] = target_airgap_0;
  uint32_t airgap_transition_duration_32 = ((msg->m_airgap_transition_duration - 0) / 0.0009155413138017853) + 0.5f;
  if (airgap_transition_duration_32 > 0xFFFF) {
    airgap_transition_duration_32 = 0xFFFF;
  }
  ((volatile uint32_t*)data)[1] = airgap_transition_duration_32;
  ((volatile uint32_t*)data)[1] |= (uint8_t)(msg->m_airgap_transition_mode & (0xFF >> (8 - 2))) << 16;
}
static void canzero_serialize_canzero_message_heartbeat_can0(canzero_message_heartbeat_can0* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x16F;
  frame->dlc = 2;
  ((volatile uint32_t*)data)[0] = msg->m_node_id;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_unregister & (0xFF >> (8 - 1))) << 8;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_ticks_next & (0xFF >> (8 - 7))) << 9;
}
static void canzero_serialize_canzero_message_heartbeat_can1(canzero_message_heartbeat_can1* msg, canzero_frame* frame) {
  volatile uint8_t* data = (volatile uint8_t*)frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x16E;
  frame->dlc = 2;
  ((volatile uint32_t*)data)[0] = msg->m_node_id;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_unregister & (0xFF >> (8 - 1))) << 8;
  ((volatile uint32_t*)data)[0] |= (uint8_t)(msg->m_ticks_next & (0xFF >> (8 - 7))) << 9;
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
static void canzero_deserialize_canzero_message_motor_driver_stream_state(canzero_frame* frame, canzero_message_motor_driver_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (motor_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 3)));
  msg->m_command = (motor_command)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 3)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_control_active = (bool_t)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_precharge_status = (sdc_status)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_feedthrough_status = (sdc_status)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_motor_driver_stream_config_hash(canzero_frame* frame, canzero_message_motor_driver_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_motor_driver_stream_errors(canzero_frame* frame, canzero_message_motor_driver_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_arming_failed = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_precharge_failed = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_acceleration_out_of_range = (error_flag)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_acceleration_calibration_failed = (error_flag)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_invalid_target_acceleration = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_vdc_voltage_invalid = (error_flag)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_board_temperature1_invalid = (error_flag)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_board_temperature2_invalid = (error_flag)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_board_temperature3_invalid = (error_flag)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_lim_temperature1_invalid = (error_flag)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_lim_temperature2_invalid = (error_flag)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_lim_temperature3_invalid = (error_flag)((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_lim_temperature4_invalid = (error_flag)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_phase_current_unexpected = (error_flag)((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_sdc_brake = (error_flag)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_current_u1 = (error_level)((((uint32_t*)data)[0] >> 18) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_current_v1 = (error_level)((((uint32_t*)data)[0] >> 20) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_current_w1 = (error_level)((((uint32_t*)data)[0] >> 22) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_current_u2 = (error_level)((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_current_v2 = (error_level)((((uint32_t*)data)[0] >> 26) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_current_w2 = (error_level)((((uint32_t*)data)[0] >> 28) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_vdc_voltage = (error_level)((((uint32_t*)data)[0] >> 30) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_board_temperature = (error_level)(((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[1] >> 2) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_lim_temperature = (error_level)((((uint32_t*)data)[1] >> 4) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_last_node_missed = ((((uint32_t*)data)[1] >> 6) & (0xFFFFFFFF >> (32 - 8)));
  msg->m_phase_current_unexpected = (error_flag)((((uint32_t*)data)[1] >> 14) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_guidance_board_front_stream_state(canzero_frame* frame, canzero_message_guidance_board_front_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (guidance_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 3)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_command = (guidance_command)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 3)));
  msg->m_control_active = (bool_t)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_precharge_status = (sdc_status)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_feedthrough_status = (sdc_status)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_guidance_board_front_stream_config_hash(canzero_frame* frame, canzero_message_guidance_board_front_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_guidance_board_front_stream_errors(canzero_frame* frame, canzero_message_guidance_board_front_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_arming_failed = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_precharge_failed = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_outer_airgap_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_inner_airgap_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_outer_airgap_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_inner_airgap_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_vdc_voltage_invalid = (error_flag)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_input_current_invalid = (error_flag)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_sdc_brake = (error_flag)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_unexpected = (error_flag)((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_unexpected = (error_flag)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_vdc_voltage = (error_level)((((uint32_t*)data)[0] >> 18) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_left = (error_level)((((uint32_t*)data)[0] >> 20) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_right = (error_level)((((uint32_t*)data)[0] >> 22) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_input_current = (error_level)((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_left = (error_level)((((uint32_t*)data)[0] >> 26) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_right = (error_level)((((uint32_t*)data)[0] >> 28) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 30) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_last_node_missed = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 8)));
}
static void canzero_deserialize_canzero_message_guidance_board_back_stream_state(canzero_frame* frame, canzero_message_guidance_board_back_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (guidance_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 3)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_command = (guidance_command)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 3)));
  msg->m_control_active = (bool_t)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_precharge_status = (sdc_status)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_feedthrough_status = (sdc_status)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_guidance_board_back_stream_config_hash(canzero_frame* frame, canzero_message_guidance_board_back_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_guidance_board_back_stream_errors(canzero_frame* frame, canzero_message_guidance_board_back_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_arming_failed = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_precharge_failed = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_outer_airgap_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_inner_airgap_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_outer_airgap_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_inner_airgap_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_vdc_voltage_invalid = (error_flag)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_input_current_invalid = (error_flag)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_sdc_brake = (error_flag)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_unexpected = (error_flag)((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_unexpected = (error_flag)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_vdc_voltage = (error_level)((((uint32_t*)data)[0] >> 18) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_left = (error_level)((((uint32_t*)data)[0] >> 20) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_right = (error_level)((((uint32_t*)data)[0] >> 22) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_input_current = (error_level)((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_left = (error_level)((((uint32_t*)data)[0] >> 26) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_right = (error_level)((((uint32_t*)data)[0] >> 28) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 30) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_last_node_missed = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 8)));
}
static void canzero_deserialize_canzero_message_levitation_board1_stream_state(canzero_frame* frame, canzero_message_levitation_board1_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (levitation_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 4)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_command = (levitation_command)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 3)));
  msg->m_control_active = (bool_t)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_precharge_status = (sdc_status)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_feedthrough_status = (sdc_status)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_levitation_board1_stream_config_hash(canzero_frame* frame, canzero_message_levitation_board1_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_levitation_board1_stream_errors(canzero_frame* frame, canzero_message_levitation_board1_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_airgap_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_airgap_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_vdc_voltage_invalid = (error_flag)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_arming_failed = (error_flag)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_precharge_failed = (error_flag)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_sdc_brake = (error_flag)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_unexpected = (error_flag)((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_unexpected = (error_flag)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_vdc_voltage = (error_level)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_left = (error_level)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_right = (error_level)((((uint32_t*)data)[0] >> 19) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_input_current = (error_level)((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_left = (error_level)((((uint32_t*)data)[0] >> 23) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_right = (error_level)((((uint32_t*)data)[0] >> 25) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 27) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_last_node_missed = ((((uint64_t*)data)[0] >> 29) & (0xFFFFFFFFFFFFFFFF >> (64 - 8)));
}
static void canzero_deserialize_canzero_message_levitation_board2_stream_state(canzero_frame* frame, canzero_message_levitation_board2_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (levitation_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 4)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_command = (levitation_command)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 3)));
  msg->m_control_active = (bool_t)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_precharge_status = (sdc_status)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_feedthrough_status = (sdc_status)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_levitation_board2_stream_config_hash(canzero_frame* frame, canzero_message_levitation_board2_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_levitation_board2_stream_errors(canzero_frame* frame, canzero_message_levitation_board2_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_airgap_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_airgap_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_vdc_voltage_invalid = (error_flag)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_arming_failed = (error_flag)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_precharge_failed = (error_flag)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_sdc_brake = (error_flag)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_unexpected = (error_flag)((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_unexpected = (error_flag)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_vdc_voltage = (error_level)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_left = (error_level)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_right = (error_level)((((uint32_t*)data)[0] >> 19) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_input_current = (error_level)((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_left = (error_level)((((uint32_t*)data)[0] >> 23) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_right = (error_level)((((uint32_t*)data)[0] >> 25) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 27) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_last_node_missed = ((((uint64_t*)data)[0] >> 29) & (0xFFFFFFFFFFFFFFFF >> (64 - 8)));
}
static void canzero_deserialize_canzero_message_levitation_board3_stream_state(canzero_frame* frame, canzero_message_levitation_board3_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (levitation_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 4)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_command = (levitation_command)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 3)));
  msg->m_control_active = (bool_t)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_precharge_status = (sdc_status)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_feedthrough_status = (sdc_status)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_levitation_board3_stream_config_hash(canzero_frame* frame, canzero_message_levitation_board3_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_levitation_board3_stream_errors(canzero_frame* frame, canzero_message_levitation_board3_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_airgap_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_airgap_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_vdc_voltage_invalid = (error_flag)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 4) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_left_invalid = (error_flag)((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_temperature_right_invalid = (error_flag)((((uint32_t*)data)[0] >> 7) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_arming_failed = (error_flag)((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_precharge_failed = (error_flag)((((uint32_t*)data)[0] >> 10) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 11) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_sdc_brake = (error_flag)((((uint32_t*)data)[0] >> 12) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_left_unexpected = (error_flag)((((uint32_t*)data)[0] >> 13) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_magnet_current_right_unexpected = (error_flag)((((uint32_t*)data)[0] >> 14) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_vdc_voltage = (error_level)((((uint32_t*)data)[0] >> 15) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_left = (error_level)((((uint32_t*)data)[0] >> 17) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_current_right = (error_level)((((uint32_t*)data)[0] >> 19) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_input_current = (error_level)((((uint32_t*)data)[0] >> 21) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_left = (error_level)((((uint32_t*)data)[0] >> 23) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_magnet_temperature_right = (error_level)((((uint32_t*)data)[0] >> 25) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 27) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_last_node_missed = ((((uint64_t*)data)[0] >> 29) & (0xFFFFFFFFFFFFFFFF >> (64 - 8)));
}
static void canzero_deserialize_canzero_message_power_board12_stream_state(canzero_frame* frame, canzero_message_power_board12_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (pdu_12v_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 3)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_power_board12_stream_config_hash(canzero_frame* frame, canzero_message_power_board12_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_power_board12_stream_errors(canzero_frame* frame, canzero_message_power_board12_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_any_short = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_last_node_missed = ((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 8)));
}
static void canzero_deserialize_canzero_message_power_board24_stream_state(canzero_frame* frame, canzero_message_power_board24_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (pdu_24v_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 2)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_power_board24_stream_config_hash(canzero_frame* frame, canzero_message_power_board24_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_power_board24_stream_errors(canzero_frame* frame, canzero_message_power_board24_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_any_short = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 2)));
  msg->m_error_mcu_temperature_invalid = (error_flag)((((uint32_t*)data)[0] >> 5) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_last_node_missed = ((((uint32_t*)data)[0] >> 6) & (0xFFFFFFFF >> (32 - 8)));
}
static void canzero_deserialize_canzero_message_led_board_stream_state(canzero_frame* frame, canzero_message_led_board_stream_state* msg) {
  uint8_t* data = frame->data;
  msg->m_state = (led_board_state)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 3)));
  msg->m_sdc_status = (sdc_status)((((uint32_t*)data)[0] >> 3) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_led_board_stream_config_hash(canzero_frame* frame, canzero_message_led_board_stream_config_hash* msg) {
  uint8_t* data = frame->data;
  msg->m_config_hash = (((uint64_t*)data)[0] & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
}
static void canzero_deserialize_canzero_message_led_board_stream_errors(canzero_frame* frame, canzero_message_led_board_stream_errors* msg) {
  uint8_t* data = frame->data;
  msg->m_assertion_fault = (error_flag)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_heartbeat_miss = (error_flag)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_error_level_mcu_temperature = (error_level)((((uint32_t*)data)[0] >> 2) & (0xFFFFFFFF >> (32 - 2)));
}
static void canzero_deserialize_canzero_message_gamepad_stream_input(canzero_frame* frame, canzero_message_gamepad_stream_input* msg) {
  uint8_t* data = frame->data;
  msg->m_lt2 = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 8))) * 0.00392156862745098 + 0;
  msg->m_rt2 = ((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 8))) * 0.00392156862745098 + 0;
  msg->m_lsb_x = ((((uint32_t*)data)[0] >> 16) & (0xFFFFFFFF >> (32 - 8))) * 0.00784313725490196 + -1;
  msg->m_lsb_y = ((((uint32_t*)data)[0] >> 24) & (0xFFFFFFFF >> (32 - 8))) * 0.00784313725490196 + -1;
  msg->m_rsb_x = (((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 8))) * 0.00784313725490196 + -1;
  msg->m_rsb_y = ((((uint32_t*)data)[1] >> 8) & (0xFFFFFFFF >> (32 - 8))) * 0.00784313725490196 + -1;
  msg->m_lt1_down = (bool_t)((((uint32_t*)data)[1] >> 16) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_rt1_down = (bool_t)((((uint32_t*)data)[1] >> 17) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_x_down = (bool_t)((((uint32_t*)data)[1] >> 18) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_y_down = (bool_t)((((uint32_t*)data)[1] >> 19) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_b_down = (bool_t)((((uint32_t*)data)[1] >> 20) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_a_down = (bool_t)((((uint32_t*)data)[1] >> 21) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_lsb_down = (bool_t)((((uint32_t*)data)[1] >> 22) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_rsb_down = (bool_t)((((uint32_t*)data)[1] >> 23) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_heartbeat_can0(canzero_frame* frame, canzero_message_heartbeat_can0* msg) {
  uint8_t* data = frame->data;
  msg->m_node_id = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 8)));
  msg->m_unregister = ((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_ticks_next = ((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 7)));
}
static void canzero_deserialize_canzero_message_heartbeat_can1(canzero_frame* frame, canzero_message_heartbeat_can1* msg) {
  uint8_t* data = frame->data;
  msg->m_node_id = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 8)));
  msg->m_unregister = ((((uint32_t*)data)[0] >> 8) & (0xFFFFFFFF >> (32 - 1)));
  msg->m_ticks_next = ((((uint32_t*)data)[0] >> 9) & (0xFFFFFFFF >> (32 - 7)));
}
__attribute__((weak)) void canzero_can0_wdg_timeout(uint8_t node_id) {}
__attribute__((weak)) void canzero_can0_wdg_recovered(uint8_t node_id) {}
__attribute__((weak)) void canzero_can1_wdg_timeout(uint8_t node_id) {}
__attribute__((weak)) void canzero_can1_wdg_recovered(uint8_t node_id) {}

typedef enum {
  HEARTBEAT_JOB_TAG = 0,
  HEARTBEAT_WDG_JOB_TAG = 1,
  GET_RESP_FRAGMENTATION_JOB_TAG = 2,
  STREAM_INTERVAL_JOB_TAG = 3,
} job_tag;

typedef struct {
  uint32_t *buffer;
  uint8_t offset;
  uint8_t size;
  uint8_t od_index;
  uint8_t client_id;
} get_resp_fragmentation_job;

typedef struct {
  uint32_t last_schedule; 
  uint32_t stream_id;
} stream_interval_job;

typedef struct {
  unsigned int* can0_static_wdg_armed;
  int* can0_static_tick_countdowns;
  unsigned int* can0_dynamic_wdg_armed;
  int* can0_dynamic_tick_countdowns;

  unsigned int* can1_static_wdg_armed;
  int* can1_static_tick_countdowns;
  unsigned int* can1_dynamic_wdg_armed;
  int* can1_dynamic_tick_countdowns;
} heartbeat_wdg_job_t;

typedef struct {
  uint32_t climax;
  uint32_t position;
  job_tag tag;
  union {
    get_resp_fragmentation_job get_fragmentation_job;
    stream_interval_job stream_job;
    heartbeat_wdg_job_t wdg_job;
  } job;
} job_t;

union job_pool_allocator_entry {
  job_t job;
  union job_pool_allocator_entry *next;
};

typedef struct {
  union job_pool_allocator_entry job[64];
  union job_pool_allocator_entry *freelist;
} job_pool_allocator;

static job_pool_allocator DMAMEM job_allocator;
static void job_pool_allocator_init() {
  for (uint8_t i = 1; i < 64; i++) {
    job_allocator.job[i - 1].next = job_allocator.job + i;
  }
  job_allocator.job[64 - 1].next = NULL;
  job_allocator.freelist = job_allocator.job;
}

static job_t *job_pool_allocator_alloc() {
  if (job_allocator.freelist != NULL) {
    job_t *job = &job_allocator.freelist->job;
    job_allocator.freelist = job_allocator.freelist->next;
    return job;
  } else {
    return NULL;
  }
}

static void job_pool_allocator_free(job_t *job) {
  union job_pool_allocator_entry *entry = (union job_pool_allocator_entry *)job;
  entry->next = job_allocator.freelist;
  job_allocator.freelist = entry;
}

#define SCHEDULER_HEAP_SIZE 91
typedef struct {
  job_t *heap[SCHEDULER_HEAP_SIZE]; // job**
  uint32_t size;
} job_scheduler_t;

static job_scheduler_t DMAMEM scheduler;
static void scheduler_promote_job(job_t *job) {
  int index = job->position;
  if (index == 0) {
    return;
  }
  int parent = (job->position - 1) / 2;
  while (scheduler.heap[parent]->climax > scheduler.heap[index]->climax) {
    job_t *tmp = scheduler.heap[parent];
    scheduler.heap[parent] = scheduler.heap[index];
    scheduler.heap[index] = tmp;
    scheduler.heap[parent]->position = parent;
    scheduler.heap[index]->position = index;
    index = parent;
    parent = (index - 1) / 2;
  }
  if (index == 0) {
    canzero_request_update(job->climax);
  }
}

static void scheduler_schedule(job_t *job) {
  if (scheduler.size >= SCHEDULER_HEAP_SIZE) {
    return;
  }
  job->position = scheduler.size;
  scheduler.heap[scheduler.size] = job;
  scheduler.size += 1;
  scheduler_promote_job(job);
}

static int scheduler_continue(job_t **job, uint32_t time) {
  *job = scheduler.heap[0];
  return scheduler.heap[0]->climax <= time;
}

static void scheduler_reschedule(uint32_t climax) {
  job_t *job = scheduler.heap[0];
  job->climax = climax;
  int index = 0;
  int hsize = scheduler.size / 2;
  while (index < hsize) {
    int left = index * 2 + 1;
    int right = left + 1;
    int min;
    if (right < scheduler.size &&
        scheduler.heap[left]->climax >= scheduler.heap[right]->climax) {
      min = right;
    } else {
    min = left;
    }
    if (climax <= scheduler.heap[min]->climax) {
      break;
    }
    scheduler.heap[index] = scheduler.heap[min];
    scheduler.heap[index]->position = index;
    index = min;
  }
  scheduler.heap[index] = job;
  scheduler.heap[index]->position = index;
}
static void scheduler_unschedule() {
  scheduler.heap[0] = scheduler.heap[scheduler.size - 1];
  scheduler.heap[0]->position = 0;
  scheduler.size -= 1;
  scheduler_reschedule(scheduler.heap[0]->climax);
}
static const uint32_t get_resp_fragmentation_interval = 100;
static void schedule_get_resp_fragmentation_job(uint32_t *fragmentation_buffer, uint8_t size, uint8_t od_index, uint8_t client_id) {
  job_t *fragmentation_job = job_pool_allocator_alloc();
  fragmentation_job->climax = canzero_get_time() + get_resp_fragmentation_interval;
  fragmentation_job->tag = GET_RESP_FRAGMENTATION_JOB_TAG;
  fragmentation_job->job.get_fragmentation_job.buffer = fragmentation_buffer;
  fragmentation_job->job.get_fragmentation_job.offset = 1;
  fragmentation_job->job.get_fragmentation_job.size = size;
  fragmentation_job->job.get_fragmentation_job.od_index = od_index;
  fragmentation_job->job.get_fragmentation_job.client_id = client_id;
  scheduler_schedule(fragmentation_job);
}

static job_t heartbeat_job;
static const uint32_t heartbeat_interval = 100 + 3 * CANZERO_NODE_ID;
static void schedule_heartbeat_job() {
  heartbeat_job.climax = canzero_get_time();
  heartbeat_job.tag = HEARTBEAT_JOB_TAG;
  scheduler_schedule(&heartbeat_job);
}

static job_t heartbeat_wdg_job;
static const uint32_t heartbeat_wdg_tick_duration = 50;
unsigned int wdg_job_can0_static_wdg_armed[node_id_count];
int wdg_job_can0_static_tick_countdowns[node_id_count];
unsigned int wdg_job_can0_dynamic_wdg_armed[MAX_DYN_HEARTBEATS];
int wdg_job_can0_dynamic_tick_countdowns[MAX_DYN_HEARTBEATS];
unsigned int wdg_job_can1_static_wdg_armed[node_id_count];
int wdg_job_can1_static_tick_countdowns[node_id_count];
unsigned int wdg_job_can1_dynamic_wdg_armed[MAX_DYN_HEARTBEATS];
int wdg_job_can1_dynamic_tick_countdowns[MAX_DYN_HEARTBEATS];

static void schedule_heartbeat_wdg_job() {
  heartbeat_wdg_job.climax = canzero_get_time() + 100;
  heartbeat_wdg_job.tag = HEARTBEAT_WDG_JOB_TAG;
  heartbeat_wdg_job.job.wdg_job.can0_static_wdg_armed = wdg_job_can0_static_wdg_armed;
  heartbeat_wdg_job.job.wdg_job.can0_static_tick_countdowns = wdg_job_can0_static_tick_countdowns;
  heartbeat_wdg_job.job.wdg_job.can0_dynamic_wdg_armed = wdg_job_can0_dynamic_wdg_armed;
  heartbeat_wdg_job.job.wdg_job.can0_dynamic_tick_countdowns = wdg_job_can0_dynamic_tick_countdowns;
  heartbeat_wdg_job.job.wdg_job.can1_static_wdg_armed = wdg_job_can1_static_wdg_armed;
  heartbeat_wdg_job.job.wdg_job.can1_static_tick_countdowns = wdg_job_can1_static_tick_countdowns;
  heartbeat_wdg_job.job.wdg_job.can1_dynamic_wdg_armed = wdg_job_can1_dynamic_wdg_armed;
  heartbeat_wdg_job.job.wdg_job.can1_dynamic_tick_countdowns = wdg_job_can1_dynamic_tick_countdowns;
  for (unsigned int i = 0; i < node_id_count; ++i) {
    heartbeat_wdg_job.job.wdg_job.can0_static_tick_countdowns[i] = 10;
    heartbeat_wdg_job.job.wdg_job.can0_static_wdg_armed[i] = 0;
    heartbeat_wdg_job.job.wdg_job.can1_static_tick_countdowns[i] = 10;
    heartbeat_wdg_job.job.wdg_job.can1_static_wdg_armed[i] = 0;
  }
  for (unsigned int i = 0; i < MAX_DYN_HEARTBEATS; ++i) {
    heartbeat_wdg_job.job.wdg_job.can0_dynamic_tick_countdowns[i] = 4;
    heartbeat_wdg_job.job.wdg_job.can0_dynamic_wdg_armed[i] = 0;
    heartbeat_wdg_job.job.wdg_job.can1_dynamic_tick_countdowns[i] = 4;
    heartbeat_wdg_job.job.wdg_job.can1_dynamic_wdg_armed[i] = 0;
  }
  scheduler_schedule(&heartbeat_wdg_job);
}

static job_t motor_command_interval_job;
static const uint32_t motor_command_interval = 1;
static void schedule_motor_command_interval_job(){
  uint32_t time = canzero_get_time();
  motor_command_interval_job.climax = time + motor_command_interval;
  motor_command_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  motor_command_interval_job.job.stream_job.stream_id = 0;
  motor_command_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&motor_command_interval_job);
}
static job_t debug_settings_interval_job;
static const uint32_t debug_settings_interval = 1;
static void schedule_debug_settings_interval_job(){
  uint32_t time = canzero_get_time();
  debug_settings_interval_job.climax = time + debug_settings_interval;
  debug_settings_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  debug_settings_interval_job.job.stream_job.stream_id = 1;
  debug_settings_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&debug_settings_interval_job);
}
static job_t position_estimation_interval_job;
static const uint32_t position_estimation_interval = 10;
static void schedule_position_estimation_interval_job(){
  uint32_t time = canzero_get_time();
  position_estimation_interval_job.climax = time + position_estimation_interval;
  position_estimation_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  position_estimation_interval_job.job.stream_job.stream_id = 2;
  position_estimation_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&position_estimation_interval_job);
}
static job_t linear_encoder_interval_job;
static const uint32_t linear_encoder_interval = 50;
static void schedule_linear_encoder_interval_job(){
  uint32_t time = canzero_get_time();
  linear_encoder_interval_job.climax = time + linear_encoder_interval;
  linear_encoder_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  linear_encoder_interval_job.job.stream_job.stream_id = 3;
  linear_encoder_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&linear_encoder_interval_job);
}
static job_t accelerations_interval_job;
static const uint32_t accelerations_interval = 50;
static void schedule_accelerations_interval_job(){
  uint32_t time = canzero_get_time();
  accelerations_interval_job.climax = time + accelerations_interval;
  accelerations_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  accelerations_interval_job.job.stream_job.stream_id = 4;
  accelerations_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&accelerations_interval_job);
}
static job_t bat24_interval_job;
static const uint32_t bat24_interval = 100;
static void schedule_bat24_interval_job(){
  uint32_t time = canzero_get_time();
  bat24_interval_job.climax = time + bat24_interval;
  bat24_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  bat24_interval_job.job.stream_job.stream_id = 5;
  bat24_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&bat24_interval_job);
}
static job_t link24_interval_job;
static const uint32_t link24_interval = 100;
static void schedule_link24_interval_job(){
  uint32_t time = canzero_get_time();
  link24_interval_job.climax = time + link24_interval;
  link24_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  link24_interval_job.job.stream_job.stream_id = 6;
  link24_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&link24_interval_job);
}
static job_t link45_interval_job;
static const uint32_t link45_interval = 100;
static void schedule_link45_interval_job(){
  uint32_t time = canzero_get_time();
  link45_interval_job.climax = time + link45_interval;
  link45_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  link45_interval_job.job.stream_job.stream_id = 7;
  link45_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&link45_interval_job);
}
static job_t mics_temperatures_interval_job;
static const uint32_t mics_temperatures_interval = 500;
static void schedule_mics_temperatures_interval_job(){
  uint32_t time = canzero_get_time();
  mics_temperatures_interval_job.climax = time + mics_temperatures_interval;
  mics_temperatures_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  mics_temperatures_interval_job.job.stream_job.stream_id = 8;
  mics_temperatures_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&mics_temperatures_interval_job);
}
static job_t bat_temperatures_interval_job;
static const uint32_t bat_temperatures_interval = 500;
static void schedule_bat_temperatures_interval_job(){
  uint32_t time = canzero_get_time();
  bat_temperatures_interval_job.climax = time + bat_temperatures_interval;
  bat_temperatures_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  bat_temperatures_interval_job.job.stream_job.stream_id = 9;
  bat_temperatures_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&bat_temperatures_interval_job);
}
static job_t cooling_cycle_interval_job;
static const uint32_t cooling_cycle_interval = 1000;
static void schedule_cooling_cycle_interval_job(){
  uint32_t time = canzero_get_time();
  cooling_cycle_interval_job.climax = time + cooling_cycle_interval;
  cooling_cycle_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  cooling_cycle_interval_job.job.stream_job.stream_id = 10;
  cooling_cycle_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&cooling_cycle_interval_job);
}
static job_t ambient_temperatures_interval_job;
static const uint32_t ambient_temperatures_interval = 500;
static void schedule_ambient_temperatures_interval_job(){
  uint32_t time = canzero_get_time();
  ambient_temperatures_interval_job.climax = time + ambient_temperatures_interval;
  ambient_temperatures_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  ambient_temperatures_interval_job.job.stream_job.stream_id = 11;
  ambient_temperatures_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&ambient_temperatures_interval_job);
}
static job_t power_consumption_interval_job;
static const uint32_t power_consumption_interval = 500;
static void schedule_power_consumption_interval_job(){
  uint32_t time = canzero_get_time();
  power_consumption_interval_job.climax = time + power_consumption_interval;
  power_consumption_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  power_consumption_interval_job.job.stream_job.stream_id = 12;
  power_consumption_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&power_consumption_interval_job);
}
static job_t errors_interval_job;
static const uint32_t errors_interval = 0;
static void schedule_errors_interval_job(){
  uint32_t time = canzero_get_time();
  errors_interval_job.climax = time + errors_interval;
  errors_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  errors_interval_job.job.stream_job.stream_id = 13;
  errors_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&errors_interval_job);
}
static job_t errors2_interval_job;
static const uint32_t errors2_interval = 1;
static void schedule_errors2_interval_job(){
  uint32_t time = canzero_get_time();
  errors2_interval_job.climax = time + errors2_interval;
  errors2_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  errors2_interval_job.job.stream_job.stream_id = 14;
  errors2_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&errors2_interval_job);
}
static job_t errors3_interval_job;
static const uint32_t errors3_interval = 1;
static void schedule_errors3_interval_job(){
  uint32_t time = canzero_get_time();
  errors3_interval_job.climax = time + errors3_interval;
  errors3_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  errors3_interval_job.job.stream_job.stream_id = 15;
  errors3_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&errors3_interval_job);
}
static job_t config_hash_interval_job;
static const uint32_t config_hash_interval = 0;
static void schedule_config_hash_interval_job(){
  uint32_t time = canzero_get_time();
  config_hash_interval_job.climax = time + config_hash_interval;
  config_hash_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  config_hash_interval_job.job.stream_job.stream_id = 16;
  config_hash_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&config_hash_interval_job);
}
static job_t state_interval_job;
static const uint32_t state_interval = 1;
static void schedule_state_interval_job(){
  uint32_t time = canzero_get_time();
  state_interval_job.climax = time + state_interval;
  state_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  state_interval_job.job.stream_job.stream_id = 17;
  state_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&state_interval_job);
}
static job_t guidance_command_interval_job;
static const uint32_t guidance_command_interval = 1;
static void schedule_guidance_command_interval_job(){
  uint32_t time = canzero_get_time();
  guidance_command_interval_job.climax = time + guidance_command_interval;
  guidance_command_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  guidance_command_interval_job.job.stream_job.stream_id = 18;
  guidance_command_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&guidance_command_interval_job);
}
static job_t levitation_command_interval_job;
static const uint32_t levitation_command_interval = 1;
static void schedule_levitation_command_interval_job(){
  uint32_t time = canzero_get_time();
  levitation_command_interval_job.climax = time + levitation_command_interval;
  levitation_command_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  levitation_command_interval_job.job.stream_job.stream_id = 19;
  levitation_command_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&levitation_command_interval_job);
}
static job_t levitation_conifg_interval_job;
static const uint32_t levitation_conifg_interval = 1;
static void schedule_levitation_conifg_interval_job(){
  uint32_t time = canzero_get_time();
  levitation_conifg_interval_job.climax = time + levitation_conifg_interval;
  levitation_conifg_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  levitation_conifg_interval_job.job.stream_job.stream_id = 20;
  levitation_conifg_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&levitation_conifg_interval_job);
}
static job_t pdu_12v_command_interval_job;
static const uint32_t pdu_12v_command_interval = 1;
static void schedule_pdu_12v_command_interval_job(){
  uint32_t time = canzero_get_time();
  pdu_12v_command_interval_job.climax = time + pdu_12v_command_interval;
  pdu_12v_command_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  pdu_12v_command_interval_job.job.stream_job.stream_id = 21;
  pdu_12v_command_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&pdu_12v_command_interval_job);
}
static job_t pdu_24v_command_interval_job;
static const uint32_t pdu_24v_command_interval = 1;
static void schedule_pdu_24v_command_interval_job(){
  uint32_t time = canzero_get_time();
  pdu_24v_command_interval_job.climax = time + pdu_24v_command_interval;
  pdu_24v_command_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  pdu_24v_command_interval_job.job.stream_job.stream_id = 22;
  pdu_24v_command_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&pdu_24v_command_interval_job);
}
static job_t global_fsm_errors_interval_job;
static const uint32_t global_fsm_errors_interval = 0;
static void schedule_global_fsm_errors_interval_job(){
  uint32_t time = canzero_get_time();
  global_fsm_errors_interval_job.climax = time + global_fsm_errors_interval;
  global_fsm_errors_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  global_fsm_errors_interval_job.job.stream_job.stream_id = 23;
  global_fsm_errors_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&global_fsm_errors_interval_job);
}
static job_t levitation_config_interval_job;
static const uint32_t levitation_config_interval = 50;
static void schedule_levitation_config_interval_job(){
  uint32_t time = canzero_get_time();
  levitation_config_interval_job.climax = time + levitation_config_interval;
  levitation_config_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  levitation_config_interval_job.job.stream_job.stream_id = 24;
  levitation_config_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&levitation_config_interval_job);
}

static void schedule_jobs(uint32_t time) {
  for (uint8_t i = 0; i < 100; ++i) {
    canzero_enter_critical();
    job_t *job;
    if (!scheduler_continue(&job, time)) {
      canzero_exit_critical();
      return;
    }
    switch (job->tag) {
      case STREAM_INTERVAL_JOB_TAG: {
        switch (job->job.stream_job.stream_id) {
      case 0: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_motor_command stream_message;
        stream_message.m_motor_driver_command = __oe_motor_driver_command;
        stream_message.m_target_acceleration = __oe_target_acceleration;
        stream_message.m_pod_grounded = __oe_pod_grounded;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_motor_command(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 1: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 10000);
        canzero_exit_critical();
        canzero_message_input_board_stream_debug_settings stream_message;
        stream_message.m_ignore_45v = __oe_ignore_45v;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_debug_settings(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 2: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 10);
        canzero_exit_critical();
        canzero_message_input_board_stream_position_estimation stream_message;
        stream_message.m_position = __oe_position;
        stream_message.m_velocity = __oe_velocity;
        stream_message.m_acceleration = __oe_acceleration;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_position_estimation(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 3: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_linear_encoder stream_message;
        stream_message.m_linear_encoder_count = __oe_linear_encoder_count;
        stream_message.m_absolute_position_known = __oe_absolute_position_known;
        stream_message.m_absolute_position_offset = __oe_absolute_position_offset;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_linear_encoder(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 4: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 50);
        canzero_exit_critical();
        canzero_message_input_board_stream_accelerations stream_message;
        stream_message.m_raw_acceleration = __oe_raw_acceleration;
        stream_message.m_lateral_acceleration = __oe_lateral_acceleration;
        stream_message.m_vertical_acceleration = __oe_vertical_acceleration;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_accelerations(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 5: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 100);
        canzero_exit_critical();
        canzero_message_input_board_stream_bat24 stream_message;
        stream_message.m_bat24_voltage = __oe_bat24_voltage;
        stream_message.m_bat24_current = __oe_bat24_current;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_bat24(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 6: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 100);
        canzero_exit_critical();
        canzero_message_input_board_stream_link24 stream_message;
        stream_message.m_supercap_voltage = __oe_supercap_voltage;
        stream_message.m_link24_current = __oe_link24_current;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_link24(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 7: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 100);
        canzero_exit_critical();
        canzero_message_input_board_stream_link45 stream_message;
        stream_message.m_link45_voltage = __oe_link45_voltage;
        stream_message.m_link45_current = __oe_link45_current;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_link45(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 8: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_mics_temperatures stream_message;
        stream_message.m_mcu_temperature = __oe_mcu_temperature;
        stream_message.m_supercap_temperature = __oe_supercap_temperature;
        stream_message.m_sac_ebox_temperature = __oe_sac_ebox_temperature;
        stream_message.m_power_ebox_temperature = __oe_power_ebox_temperature;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_mics_temperatures(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 9: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_bat_temperatures stream_message;
        stream_message.m_bat24_cell_temperature_1 = __oe_bat24_cell_temperature_1;
        stream_message.m_bat24_cell_temperature_2 = __oe_bat24_cell_temperature_2;
        stream_message.m_bat24_temperature_max = __oe_bat24_temperature_max;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_bat_temperatures(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 10: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_cooling_cycle stream_message;
        stream_message.m_cooling_flow_rate_begin = __oe_cooling_flow_rate_begin;
        stream_message.m_cooling_flow_rate_end = __oe_cooling_flow_rate_end;
        stream_message.m_cooling_cycle_temp_begin = __oe_cooling_cycle_temp_begin;
        stream_message.m_cooling_cycle_temp_end = __oe_cooling_cycle_temp_end;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_cooling_cycle(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 11: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_ambient_temperatures stream_message;
        stream_message.m_ambient_temperature_1 = __oe_ambient_temperature_1;
        stream_message.m_ambient_temperature_2 = __oe_ambient_temperature_2;
        stream_message.m_ambient_temperature_3 = __oe_ambient_temperature_3;
        stream_message.m_ambient_temperature_max = __oe_ambient_temperature_max;
        stream_message.m_ambient_temperature_avg = __oe_ambient_temperature_avg;
        stream_message.m_supercap_temperature = __oe_supercap_temperature;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_ambient_temperatures(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 12: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_power_consumption stream_message;
        stream_message.m_system_power_consumption = __oe_system_power_consumption;
        stream_message.m_communication_power_consumption = __oe_communication_power_consumption;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_power_consumption(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 13: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_errors stream_message;
        stream_message.m_assertion_fault = __oe_assertion_fault;
        stream_message.m_error_acceleration_out_of_range = __oe_error_acceleration_out_of_range;
        stream_message.m_error_lateral_acceleration_out_of_range = __oe_error_lateral_acceleration_out_of_range;
        stream_message.m_error_vertical_acceleration_out_of_range = __oe_error_vertical_acceleration_out_of_range;
        stream_message.m_error_acceleration_calibration_failed = __oe_error_acceleration_calibration_failed;
        stream_message.m_error_bat24_voltage_invalid = __oe_error_bat24_voltage_invalid;
        stream_message.m_error_bat24_current_invalid = __oe_error_bat24_current_invalid;
        stream_message.m_error_supercap_voltage_invalid = __oe_error_supercap_voltage_invalid;
        stream_message.m_error_link24_current_invalid = __oe_error_link24_current_invalid;
        stream_message.m_error_link45_voltage_invalid = __oe_error_link45_voltage_invalid;
        stream_message.m_error_link45_current_invalid = __oe_error_link45_current_invalid;
        stream_message.m_error_mcu_temperature_invalid = __oe_error_mcu_temperature_invalid;
        stream_message.m_error_sac_ebox_temperature_invalid = __oe_error_sac_ebox_temperature_invalid;
        stream_message.m_error_power_ebox_temperature_invalid = __oe_error_power_ebox_temperature_invalid;
        stream_message.m_error_bat24_cell_temperature_1_invalid = __oe_error_bat24_cell_temperature_1_invalid;
        stream_message.m_error_bat24_cell_temperature_2_invalid = __oe_error_bat24_cell_temperature_2_invalid;
        stream_message.m_error_supercap_temperature_invalid = __oe_error_supercap_temperature_invalid;
        stream_message.m_error_ambient_temperature_1_invalid = __oe_error_ambient_temperature_1_invalid;
        stream_message.m_error_ambient_temperature_2_invalid = __oe_error_ambient_temperature_2_invalid;
        stream_message.m_error_ambient_temperature_3_invalid = __oe_error_ambient_temperature_3_invalid;
        stream_message.m_error_heartbeat_miss = __oe_error_heartbeat_miss;
        stream_message.m_error_level_bat24_under_voltage = __oe_error_level_bat24_under_voltage;
        stream_message.m_error_level_bat24_over_voltage = __oe_error_level_bat24_over_voltage;
        stream_message.m_error_level_bat24_over_current = __oe_error_level_bat24_over_current;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_errors(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 14: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_errors2 stream_message;
        stream_message.m_error_level_supercap_under_voltage = __oe_error_level_supercap_under_voltage;
        stream_message.m_error_level_supercap_over_voltage = __oe_error_level_supercap_over_voltage;
        stream_message.m_error_level_link24_over_current = __oe_error_level_link24_over_current;
        stream_message.m_error_level_link45_under_voltage = __oe_error_level_link45_under_voltage;
        stream_message.m_error_level_link45_over_voltage = __oe_error_level_link45_over_voltage;
        stream_message.m_error_level_link45_over_current = __oe_error_level_link45_over_current;
        stream_message.m_error_level_mcu_temperature = __oe_error_level_mcu_temperature;
        stream_message.m_error_level_bat24_temperature = __oe_error_level_bat24_temperature;
        stream_message.m_error_level_supercap_temperature = __oe_error_level_supercap_temperature;
        stream_message.m_error_level_sac_ebox_temperature = __oe_error_level_sac_ebox_temperature;
        stream_message.m_error_level_power_ebox_temperature = __oe_error_level_power_ebox_temperature;
        stream_message.m_error_level_ambient_temperature = __oe_error_level_ambient_temperature;
        stream_message.m_last_node_missed = __oe_last_node_missed;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_errors2(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 15: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_errors3 stream_message;
        stream_message.m_error_cooling_flow_rate_low = __oe_error_cooling_flow_rate_low;
        stream_message.m_error_cooling_flow_rate_mismatch = __oe_error_cooling_flow_rate_mismatch;
        stream_message.m_error_cooling_cycle_temp_begin_invalid = __oe_error_cooling_cycle_temp_begin_invalid;
        stream_message.m_error_cooling_cycle_temp_end_invalid = __oe_error_cooling_cycle_temp_end_invalid;
        stream_message.m_error_level_cooling_cycle_overtemp = __oe_error_level_cooling_cycle_overtemp;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_errors3(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 16: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 5000);
        canzero_exit_critical();
        canzero_message_input_board_stream_config_hash stream_message;
        stream_message.m_config_hash = __oe_config_hash;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_config_hash(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 17: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_state stream_message;
        stream_message.m_global_state = __oe_global_state;
        stream_message.m_global_command = __oe_global_command;
        stream_message.m_system_sdc_status = __oe_system_sdc_status;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_state(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 18: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_guidance_command stream_message;
        stream_message.m_guidance_command = __oe_guidance_command;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_guidance_command(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 19: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_levitation_command stream_message;
        stream_message.m_levitation_command = __oe_levitation_command;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_levitation_command(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 20: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 10000);
        canzero_exit_critical();
        canzero_message_input_board_stream_levitation_conifg stream_message;
        stream_message.m_target_airgap = __oe_target_airgap;
        stream_message.m_airgap_transition_duration = __oe_airgap_transition_duration;
        stream_message.m_airgap_transition_mode = __oe_airgap_transition_mode;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_levitation_conifg(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 21: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_pdu_12v_command stream_message;
        stream_message.m_power_board12_command = __oe_power_board12_command;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_pdu_12v_command(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 22: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_pdu_24v_command stream_message;
        stream_message.m_power_board24_command = __oe_power_board24_command;
        stream_message.m_power_board24_cooling_pump_channel_ctrl = __oe_power_board24_cooling_pump_channel_ctrl;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_pdu_24v_command(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 23: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_global_fsm_errors stream_message;
        stream_message.m_error_heartbeat_miss = __oe_error_heartbeat_miss;
        stream_message.m_error_any = __oe_error_any;
        stream_message.m_error_level_over_temperature_system = __oe_error_level_over_temperature_system;
        stream_message.m_error_level_config_consistency = __oe_error_level_config_consistency;
        stream_message.m_last_node_missed = __oe_last_node_missed;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_global_fsm_errors(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 24: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_levitation_config stream_message;
        stream_message.m_target_airgap = __oe_target_airgap;
        stream_message.m_airgap_transition_duration = __oe_airgap_transition_duration;
        stream_message.m_airgap_transition_mode = __oe_airgap_transition_mode;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_levitation_config(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
        default:
          canzero_exit_critical();
          break;
        }
        break;
      }
      case HEARTBEAT_JOB_TAG: {
        scheduler_reschedule(time + heartbeat_interval);
        canzero_exit_critical();
        canzero_frame heartbeat_frame;
        canzero_message_heartbeat_can0 heartbeat_can0;
        heartbeat_can0.m_node_id = node_id_input_board;
        heartbeat_can0.m_unregister = 0;
        heartbeat_can0.m_ticks_next = 14;
        canzero_serialize_canzero_message_heartbeat_can0(&heartbeat_can0, &heartbeat_frame);
        canzero_can0_send(&heartbeat_frame);
        canzero_message_heartbeat_can1 heartbeat_can1;
        heartbeat_can1.m_node_id = node_id_input_board;
        heartbeat_can1.m_unregister = 0;
        heartbeat_can1.m_ticks_next = 14;
        canzero_serialize_canzero_message_heartbeat_can1(&heartbeat_can1, &heartbeat_frame);
        canzero_can1_send(&heartbeat_frame);
        break;
      }
      case HEARTBEAT_WDG_JOB_TAG: {
        scheduler_reschedule(time + heartbeat_wdg_tick_duration);
        canzero_exit_critical();
        for (unsigned int i = 0; i < node_id_count; ++i) {
          heartbeat_wdg_job.job.wdg_job.can0_static_tick_countdowns[i] 
            -= heartbeat_wdg_job.job.wdg_job.can0_static_wdg_armed[i];
          heartbeat_wdg_job.job.wdg_job.can1_static_tick_countdowns[i] 
            -= heartbeat_wdg_job.job.wdg_job.can1_static_wdg_armed[i];
        }
        for (unsigned int i = 0; i < MAX_DYN_HEARTBEATS; ++i) {
          heartbeat_wdg_job.job.wdg_job.can0_dynamic_tick_countdowns[i] 
            -= heartbeat_wdg_job.job.wdg_job.can0_dynamic_wdg_armed[i];
          heartbeat_wdg_job.job.wdg_job.can1_dynamic_tick_countdowns[i] 
            -= heartbeat_wdg_job.job.wdg_job.can1_dynamic_wdg_armed[i];
        }
        for (unsigned int i = 0; i < node_id_count; ++i) {
          if (heartbeat_wdg_job.job.wdg_job.can0_static_tick_countdowns[i] <= 0) {
            canzero_can0_wdg_timeout(i);
          }
          if (heartbeat_wdg_job.job.wdg_job.can1_static_tick_countdowns[i] <= 0) {
            canzero_can1_wdg_timeout(i);
          }
        }
        for (unsigned int i = 0; i < MAX_DYN_HEARTBEATS; ++i) {
          if (heartbeat_wdg_job.job.wdg_job.can0_dynamic_tick_countdowns[i] <= 0) {
            canzero_can0_wdg_timeout(node_id_count + i);
          }
          if (heartbeat_wdg_job.job.wdg_job.can1_dynamic_tick_countdowns[i] <= 0) {
            canzero_can1_wdg_timeout(node_id_count + i);
          }
        }
        break;
      }
      case GET_RESP_FRAGMENTATION_JOB_TAG: {
        get_resp_fragmentation_job *fragmentation_job = &job->job.get_fragmentation_job;
        canzero_message_get_resp fragmentation_response;
        fragmentation_response.m_header.m_sof = 0;
        fragmentation_response.m_header.m_toggle = fragmentation_job->offset % 2;
        fragmentation_response.m_header.m_od_index = fragmentation_job->od_index;
        fragmentation_response.m_header.m_client_id = fragmentation_job->client_id;
        fragmentation_response.m_header.m_server_id = 0x3;
        fragmentation_response.m_data = fragmentation_job->buffer[fragmentation_job->offset];
        fragmentation_job->offset += 1;
        if (fragmentation_job->offset == fragmentation_job->size) {
          fragmentation_response.m_header.m_eof = 1;
          scheduler_unschedule();
        } else {
          fragmentation_response.m_header.m_eof = 0;
          scheduler_reschedule(time + get_resp_fragmentation_interval);
        }
        canzero_exit_critical();
        canzero_frame fragmentation_frame;
        canzero_serialize_canzero_message_get_resp(&fragmentation_response, &fragmentation_frame);
        canzero_can0_send(&fragmentation_frame);
        break;
      }
      default: {
        canzero_exit_critical();
        break;
      }
    }
  }
}

static uint32_t scheduler_next_job_timeout() {
  return scheduler.heap[0]->climax;
}

static uint32_t DMAMEM __oe_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_build_time_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_velocity_pid_rx_fragmentation_buffer[6];
static uint32_t DMAMEM __oe_acceleration_calibration_variance_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_acceleration_calibration_offset_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_acceleration_calibration_target_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_motor_driver_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_guidance_board_front_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_guidance_board_back_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_levitation_board1_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_levitation_board2_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_levitation_board3_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_power_board12_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_power_board24_config_hash_rx_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_led_board_config_hash_rx_fragmentation_buffer[2];
static PROGMEM void canzero_handle_get_req(canzero_frame* frame) {
  canzero_message_get_req msg;
  canzero_deserialize_canzero_message_get_req(frame, &msg);
  if (msg.m_header.m_server_id != node_id_input_board) {
    return;
  }
  canzero_message_get_resp resp{};
  switch (msg.m_header.m_od_index) {
  case 0: {
    {
      uint64_t masked = (__oe_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_config_hash_rx_fragmentation_buffer, 2, 0, msg.m_header.m_client_id);
    break;
  }
  case 1: {
    __oe_build_time_rx_fragmentation_buffer[0] = (__oe_build_time.m_year & (0xFFFFFFFF >> (32 - 16)));
    __oe_build_time_rx_fragmentation_buffer[0] |= ((__oe_build_time.m_month & (0xFFFFFFFF >> (32 - 8))) << 16);
    __oe_build_time_rx_fragmentation_buffer[0] |= ((__oe_build_time.m_day & (0xFFFFFFFF >> (32 - 8))) << 24);
    __oe_build_time_rx_fragmentation_buffer[1] = (__oe_build_time.m_hour & (0xFFFFFFFF >> (32 - 8)));
    __oe_build_time_rx_fragmentation_buffer[1] |= ((__oe_build_time.m_min & (0xFFFFFFFF >> (32 - 8))) << 8);
    __oe_build_time_rx_fragmentation_buffer[1] |= ((__oe_build_time.m_sec & (0xFFFFFFFF >> (32 - 8))) << 16);

    resp.m_data = __oe_build_time_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_build_time_rx_fragmentation_buffer, 2, 1, msg.m_header.m_client_id);
    break;
  }
  case 2: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_command) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 3: {
    resp.m_data |= min_u32((__oe_target_acceleration - (-50)) / 0.000000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 4: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_ignore_45v) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 5: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_global_state) & (0xFF >> (8 - 5)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 6: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_global_command) & (0xFF >> (8 - 4)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 7: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_system_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 8: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_pod_grounded) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 9: {
    resp.m_data |= min_u32((__oe_system_power_consumption - (0)) / 0.15259021896696423, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 10: {
    resp.m_data |= min_u32((__oe_communication_power_consumption - (0)) / 0.007629510948348211, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 11: {
    resp.m_data |= min_u32((__oe_track_length - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 12: {
    resp.m_data |= min_u32((__oe_brake_margin - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 13: {
    resp.m_data |= min_u32((__oe_emergency_brake_margin - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 14: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_assert_45V_system_online) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 15: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 16: {
    resp.m_data |= min_u32((__oe_loop_frequency - (0)) / 0.00000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 17: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 18: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 19: {
    resp.m_data |= ((uint32_t)(__oe_last_node_missed & (0xFF >> (8 - 8)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 20: {
    resp.m_data |= min_u32((__oe_acceleration_target_velocity - (0)) / 0.0000000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 21: {
    {
      uint64_t masked = (min_u64((__oe_velocity_pid.m_Kp - ((double)0)) / (double)0.0000000000000005421010862427522, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_velocity_pid_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_velocity_pid_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }    {
      uint64_t masked = (min_u64((__oe_velocity_pid.m_Ki - ((double)0)) / (double)0.0000000000000005421010862427522, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_velocity_pid_rx_fragmentation_buffer[2] = ((uint32_t*)&masked)[0];
      __oe_velocity_pid_rx_fragmentation_buffer[3] = ((uint32_t*)&masked)[1];
    }    {
      uint64_t masked = (min_u64((__oe_velocity_pid.m_Kd - ((double)0)) / (double)0.0000000000000005421010862427522, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_velocity_pid_rx_fragmentation_buffer[4] = ((uint32_t*)&masked)[0];
      __oe_velocity_pid_rx_fragmentation_buffer[5] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_velocity_pid_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_velocity_pid_rx_fragmentation_buffer, 6, 21, msg.m_header.m_client_id);
    break;
  }
  case 22: {
    resp.m_data |= min_u32((__oe_position - (-10)) / 0.0007629510948348211, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 23: {
    resp.m_data |= min_u32((__oe_velocity - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 24: {
    resp.m_data |= min_u32((__oe_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 25: {
    resp.m_data |= ((uint32_t)(((uint16_t)__oe_linear_encoder_count) & (0xFFFF >> (16 - 16)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 26: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_absolute_position_known) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 27: {
    resp.m_data |= min_u32((__oe_absolute_position_offset - (-10)) / 0.0006103608758678569, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 28: {
    resp.m_data |= min_u32((__oe_raw_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 29: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 30: {
    {
      uint64_t masked = (min_u64((__oe_acceleration_calibration_variance - ((double)-1)) / (double)0.00000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_acceleration_calibration_variance_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_acceleration_calibration_variance_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_acceleration_calibration_variance_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_variance_rx_fragmentation_buffer, 2, 30, msg.m_header.m_client_id);
    break;
  }
  case 31: {
    {
      uint64_t masked = (min_u64((__oe_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_acceleration_calibration_offset_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_acceleration_calibration_offset_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_acceleration_calibration_offset_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_offset_rx_fragmentation_buffer, 2, 31, msg.m_header.m_client_id);
    break;
  }
  case 32: {
    {
      uint64_t masked = (min_u64((__oe_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_acceleration_calibration_target_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_acceleration_calibration_target_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_acceleration_calibration_target_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_target_rx_fragmentation_buffer, 2, 32, msg.m_header.m_client_id);
    break;
  }
  case 33: {
    resp.m_data |= min_u32((__oe_raw_lateral_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 34: {
    resp.m_data |= min_u32((__oe_lateral_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 35: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_lateral_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 36: {
    {
      uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_variance - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer, 2, 36, msg.m_header.m_client_id);
    break;
  }
  case 37: {
    {
      uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer, 2, 37, msg.m_header.m_client_id);
    break;
  }
  case 38: {
    {
      uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer, 2, 38, msg.m_header.m_client_id);
    break;
  }
  case 39: {
    resp.m_data |= min_u32((__oe_raw_vertical_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 40: {
    resp.m_data |= min_u32((__oe_vertical_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 41: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_vertical_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 42: {
    {
      uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_variance - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer, 2, 42, msg.m_header.m_client_id);
    break;
  }
  case 43: {
    {
      uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer, 2, 43, msg.m_header.m_client_id);
    break;
  }
  case 44: {
    {
      uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer, 2, 44, msg.m_header.m_client_id);
    break;
  }
  case 45: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_calibration_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 46: {
    resp.m_data |= min_u32((__oe_bat24_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 47: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_bat24_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 48: {
    resp.m_data |= min_u32((__oe_bat24_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 49: {
    resp.m_data |= min_u32((__oe_bat24_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 50: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 51: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 52: {
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[6] = (__oe_error_level_config_bat24_under_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_under_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_under_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer, 7, 52, msg.m_header.m_client_id);
    break;
  }
  case 53: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 54: {
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[6] = (__oe_error_level_config_bat24_over_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer, 7, 54, msg.m_header.m_client_id);
    break;
  }
  case 55: {
    resp.m_data |= min_u32((__oe_bat24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 56: {
    resp.m_data |= min_u32((__oe_bat24_current_calibration_offset - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 57: {
    resp.m_data |= min_u32((__oe_bat24_current_calibration_target - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 58: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_bat24_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 59: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 60: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 61: {
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_over_current.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_over_current.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_over_current.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[6] = (__oe_error_level_config_bat24_over_current.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_current.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_current.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_current_rx_fragmentation_buffer, 7, 61, msg.m_header.m_client_id);
    break;
  }
  case 62: {
    resp.m_data |= min_u32((__oe_supercap_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 63: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_supercap_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 64: {
    resp.m_data |= min_u32((__oe_supercap_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 65: {
    resp.m_data |= min_u32((__oe_supercap_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 66: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_supercap_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 67: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 68: {
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[6] = (__oe_error_level_config_supercap_under_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_under_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_under_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer, 7, 68, msg.m_header.m_client_id);
    break;
  }
  case 69: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 70: {
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[6] = (__oe_error_level_config_supercap_over_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_over_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_over_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer, 7, 70, msg.m_header.m_client_id);
    break;
  }
  case 71: {
    resp.m_data |= min_u32((__oe_link24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 72: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_link24_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 73: {
    resp.m_data |= min_u32((__oe_link24_current_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 74: {
    resp.m_data |= min_u32((__oe_link24_current_calibration_target - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 75: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_link24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 76: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 77: {
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link24_over_current.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link24_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link24_over_current.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link24_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link24_over_current.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link24_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[6] = (__oe_error_level_config_link24_over_current.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link24_over_current.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link24_over_current.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_current_rx_fragmentation_buffer, 7, 77, msg.m_header.m_client_id);
    break;
  }
  case 78: {
    resp.m_data |= min_u32((__oe_link45_voltage - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 79: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_link45_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 80: {
    resp.m_data |= min_u32((__oe_link45_voltage_calibration_offset - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 81: {
    resp.m_data |= min_u32((__oe_link45_voltage_calibration_target - (0)) / 0.00000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 82: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 83: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 84: {
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link45_under_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link45_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link45_under_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link45_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link45_under_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link45_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[6] = (__oe_error_level_config_link45_under_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_under_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_under_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer, 7, 84, msg.m_header.m_client_id);
    break;
  }
  case 85: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 86: {
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link45_over_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link45_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link45_over_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link45_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link45_over_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link45_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[6] = (__oe_error_level_config_link45_over_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer, 7, 86, msg.m_header.m_client_id);
    break;
  }
  case 87: {
    resp.m_data |= min_u32((__oe_link45_current - (-1000)) / 0.0000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 88: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_link45_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 89: {
    resp.m_data |= min_u32((__oe_link45_current_calibration_offset - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 90: {
    resp.m_data |= min_u32((__oe_link45_current_calibration_target - (-1000)) / 0.0000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 91: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 92: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 93: {
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link45_over_current.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link45_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link45_over_current.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link45_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link45_over_current.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link45_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[6] = (__oe_error_level_config_link45_over_current.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_current.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_current.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_current_rx_fragmentation_buffer, 7, 93, msg.m_header.m_client_id);
    break;
  }
  case 94: {
    resp.m_data |= min_u32((__oe_mcu_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 95: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 96: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 97: {
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_mcu_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_mcu_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_mcu_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_mcu_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_mcu_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_mcu_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[6] = (__oe_error_level_config_mcu_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_mcu_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_mcu_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_mcu_temperature_rx_fragmentation_buffer, 7, 97, msg.m_header.m_client_id);
    break;
  }
  case 98: {
    resp.m_data |= min_u32((__oe_bat24_cell_temperature_1 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 99: {
    resp.m_data |= min_u32((__oe_bat24_cell_temperature_2 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 100: {
    resp.m_data |= min_u32((__oe_bat24_temperature_max - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 101: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_cell_temperature_1_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 102: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_cell_temperature_2_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 103: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 104: {
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[6] = (__oe_error_level_config_bat24_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_temperature_rx_fragmentation_buffer, 7, 104, msg.m_header.m_client_id);
    break;
  }
  case 105: {
    resp.m_data |= min_u32((__oe_supercap_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 106: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_supercap_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 107: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 108: {
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_supercap_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_supercap_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_supercap_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_supercap_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_supercap_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_supercap_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[6] = (__oe_error_level_config_supercap_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_temperature_rx_fragmentation_buffer, 7, 108, msg.m_header.m_client_id);
    break;
  }
  case 109: {
    resp.m_data |= min_u32((__oe_sac_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 110: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_sac_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 111: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_sac_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 112: {
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[6] = (__oe_error_level_config_sac_ebox_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_sac_ebox_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_sac_ebox_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer, 7, 112, msg.m_header.m_client_id);
    break;
  }
  case 113: {
    resp.m_data |= min_u32((__oe_power_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 114: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_power_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 115: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_power_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 116: {
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[6] = (__oe_error_level_config_power_ebox_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_power_ebox_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_power_ebox_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer, 7, 116, msg.m_header.m_client_id);
    break;
  }
  case 117: {
    resp.m_data |= min_u32((__oe_ambient_temperature_1 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 118: {
    resp.m_data |= min_u32((__oe_ambient_temperature_2 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 119: {
    resp.m_data |= min_u32((__oe_ambient_temperature_3 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 120: {
    resp.m_data |= min_u32((__oe_ambient_temperature_avg - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 121: {
    resp.m_data |= min_u32((__oe_ambient_temperature_max - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 122: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_1_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 123: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_2_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 124: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_3_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 125: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_ambient_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 126: {
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_ambient_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_ambient_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_ambient_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_ambient_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_ambient_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_ambient_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[6] = (__oe_error_level_config_ambient_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_ambient_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[6] |= ((__oe_error_level_config_ambient_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

    resp.m_data = __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_ambient_temperature_rx_fragmentation_buffer, 7, 126, msg.m_header.m_client_id);
    break;
  }
  case 127: {
    resp.m_data |= min_u32((__oe_cooling_flow_rate_begin - (0)) / 0.006103608758678569, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 128: {
    resp.m_data |= min_u32((__oe_cooling_flow_rate_end - (0)) / 0.006103608758678569, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 129: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_flow_rate_low) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 130: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_flow_rate_mismatch) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 131: {
    resp.m_data |= min_u32((__oe_cooling_cycle_temp_begin - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 132: {
    resp.m_data |= min_u32((__oe_cooling_cycle_temp_end - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 133: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_cycle_temp_begin_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 134: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_cycle_temp_end_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 135: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_overtemp) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 136: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_state) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 137: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 138: {
    {
      uint64_t masked = (__oe_motor_driver_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_motor_driver_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_motor_driver_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_motor_driver_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_motor_driver_config_hash_rx_fragmentation_buffer, 2, 138, msg.m_header.m_client_id);
    break;
  }
  case 139: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 140: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 141: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 142: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 143: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_acceleration_calibration_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 144: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_invalid_target_acceleration) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 145: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 146: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_board_temperature1_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 147: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_board_temperature2_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 148: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_board_temperature3_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 149: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 150: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature1_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 151: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature2_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 152: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature3_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 153: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature4_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 154: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 155: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_phase_current_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 156: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 157: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_u1) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 158: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_v1) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 159: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_w1) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 160: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_u2) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 161: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_v2) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 162: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_w2) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 163: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 164: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_board_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 165: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 166: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_lim_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 167: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_phase_current_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 168: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_command) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 169: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_state) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 170: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 171: {
    {
      uint64_t masked = (__oe_guidance_board_front_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_guidance_board_front_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_guidance_board_front_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_guidance_board_front_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_guidance_board_front_config_hash_rx_fragmentation_buffer, 2, 171, msg.m_header.m_client_id);
    break;
  }
  case 172: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 173: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 174: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 175: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 176: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_outer_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 177: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_inner_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 178: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_outer_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 179: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_inner_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 180: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 181: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 182: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 183: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_input_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 184: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 185: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 186: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 187: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 188: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 189: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 190: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 191: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 192: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 193: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 194: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_state) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 195: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 196: {
    {
      uint64_t masked = (__oe_guidance_board_back_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_guidance_board_back_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_guidance_board_back_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_guidance_board_back_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_guidance_board_back_config_hash_rx_fragmentation_buffer, 2, 196, msg.m_header.m_client_id);
    break;
  }
  case 197: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 198: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 199: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 200: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 201: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_outer_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 202: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_inner_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 203: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_outer_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 204: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_inner_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 205: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 206: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 207: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 208: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_input_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 209: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 210: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 211: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 212: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 213: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 214: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 215: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 216: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 217: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 218: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 219: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_command) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 220: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_state) & (0xFF >> (8 - 4)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 221: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 222: {
    {
      uint64_t masked = (__oe_levitation_board1_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_levitation_board1_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_levitation_board1_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_levitation_board1_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_levitation_board1_config_hash_rx_fragmentation_buffer, 2, 222, msg.m_header.m_client_id);
    break;
  }
  case 223: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 224: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 225: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 226: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 227: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 228: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 229: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 230: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 231: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 232: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 233: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 234: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 235: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 236: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 237: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 238: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 239: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 240: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 241: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 242: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_state) & (0xFF >> (8 - 4)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 243: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 244: {
    {
      uint64_t masked = (__oe_levitation_board2_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_levitation_board2_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_levitation_board2_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_levitation_board2_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_levitation_board2_config_hash_rx_fragmentation_buffer, 2, 244, msg.m_header.m_client_id);
    break;
  }
  case 245: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 246: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 247: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 248: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 249: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 250: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 251: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 252: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 253: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 254: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 255: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 256: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 257: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 258: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 259: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 260: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 261: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 262: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 263: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 264: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_state) & (0xFF >> (8 - 4)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 265: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 266: {
    {
      uint64_t masked = (__oe_levitation_board3_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_levitation_board3_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_levitation_board3_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_levitation_board3_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_levitation_board3_config_hash_rx_fragmentation_buffer, 2, 266, msg.m_header.m_client_id);
    break;
  }
  case 267: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 268: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 269: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 270: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 271: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 272: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 273: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 274: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 275: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 276: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 277: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 278: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 279: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 280: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 281: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 282: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 283: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 284: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 285: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 286: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_state) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 287: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_command) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 288: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 289: {
    {
      uint64_t masked = (__oe_power_board12_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_power_board12_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_power_board12_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_power_board12_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_power_board12_config_hash_rx_fragmentation_buffer, 2, 289, msg.m_header.m_client_id);
    break;
  }
  case 290: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 291: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_error_any_short) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 292: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 293: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 294: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_state) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 295: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_command) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 296: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 297: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_cooling_pump_channel_ctrl) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 298: {
    {
      uint64_t masked = (__oe_power_board24_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_power_board24_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_power_board24_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_power_board24_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_power_board24_config_hash_rx_fragmentation_buffer, 2, 298, msg.m_header.m_client_id);
    break;
  }
  case 299: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 300: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_error_any_short) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 301: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 302: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 303: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_state) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 304: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_command) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 305: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 306: {
    {
      uint64_t masked = (__oe_led_board_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_led_board_config_hash_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_led_board_config_hash_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_led_board_config_hash_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_led_board_config_hash_rx_fragmentation_buffer, 2, 306, msg.m_header.m_client_id);
    break;
  }
  case 307: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 308: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 309: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 310: {
    resp.m_data |= min_u32((__oe_gamepad_max_acceleration - (0)) / 0.0000000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 311: {
    resp.m_data |= min_u32((__oe_gamepad_lt2 - (0)) / 0.00392156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 312: {
    resp.m_data |= min_u32((__oe_gamepad_rt2 - (0)) / 0.00392156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 313: {
    resp.m_data |= min_u32((__oe_target_airgap - (0)) / 0.000000003492459655621196, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 314: {
    resp.m_data |= min_u32((__oe_airgap_transition_duration - (0)) / 0.0009155413138017853, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 315: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_airgap_transition_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 316: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 317: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 318: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 319: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 320: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 321: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 322: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 323: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 324: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 325: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 326: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 327: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 328: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 329: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 330: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 331: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_config_consistency) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 332: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_any) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 333: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_over_temperature_system) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  }
  resp.m_header.m_od_index = msg.m_header.m_od_index;
  resp.m_header.m_client_id = msg.m_header.m_client_id;
  resp.m_header.m_server_id = msg.m_header.m_server_id;
  canzero_frame resp_frame;
  canzero_serialize_canzero_message_get_resp(&resp, &resp_frame);
  canzero_can0_send(&resp_frame);
}
static uint32_t DMAMEM config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM build_time_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM build_time_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM velocity_pid_tmp_tx_fragmentation_buffer[6];
static uint32_t DMAMEM velocity_pid_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM acceleration_calibration_variance_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM acceleration_calibration_variance_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM acceleration_calibration_offset_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM acceleration_calibration_offset_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM acceleration_calibration_target_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM acceleration_calibration_target_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM lateral_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM lateral_acceleration_calibration_variance_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM lateral_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM lateral_acceleration_calibration_offset_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM lateral_acceleration_calibration_target_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM lateral_acceleration_calibration_target_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM vertical_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM vertical_acceleration_calibration_variance_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM vertical_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM vertical_acceleration_calibration_offset_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM vertical_acceleration_calibration_target_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM vertical_acceleration_calibration_target_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_bat24_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_supercap_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_supercap_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_link24_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_link45_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_mcu_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_bat24_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_supercap_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_power_ebox_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t DMAMEM error_level_config_ambient_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM motor_driver_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM motor_driver_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM guidance_board_front_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM guidance_board_front_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM guidance_board_back_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM guidance_board_back_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM levitation_board1_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM levitation_board1_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM levitation_board2_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM levitation_board2_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM levitation_board3_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM levitation_board3_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM power_board12_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM power_board12_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM power_board24_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM power_board24_config_hash_tmp_tx_fragmentation_offset = 0;
static uint32_t DMAMEM led_board_config_hash_tmp_tx_fragmentation_buffer[2];
static uint32_t DMAMEM led_board_config_hash_tmp_tx_fragmentation_offset = 0;
static PROGMEM void canzero_handle_set_req(canzero_frame* frame) {
  canzero_message_set_req msg;
  canzero_deserialize_canzero_message_set_req(frame, &msg);
  if (msg.m_header.m_server_id != 3) {
    return;
  }
  canzero_message_set_resp resp{};
  switch (msg.m_header.m_od_index) {
  case 0 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      config_hash_tmp_tx_fragmentation_offset += 1;
      if (config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    config_hash_tmp_tx_fragmentation_buffer[config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t config_hash_tmp;
    config_hash_tmp = (uint64_t)config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_config_hash(config_hash_tmp);
    break;
  }
  case 1 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      build_time_tmp_tx_fragmentation_offset = 0;
    }else {
      build_time_tmp_tx_fragmentation_offset += 1;
      if (build_time_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    build_time_tmp_tx_fragmentation_buffer[build_time_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    date_time build_time_tmp;
    build_time_tmp.m_year = (build_time_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 16)));
    build_time_tmp.m_month = (build_time_tmp_tx_fragmentation_buffer[0] >> 16) & (0xFFFFFFFF >> (32 - 8));
    build_time_tmp.m_day = (build_time_tmp_tx_fragmentation_buffer[0] >> 24) & (0xFFFFFFFF >> (32 - 8));
    build_time_tmp.m_hour = (build_time_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 8)));
    build_time_tmp.m_min = (build_time_tmp_tx_fragmentation_buffer[1] >> 8) & (0xFFFFFFFF >> (32 - 8));
    build_time_tmp.m_sec = (build_time_tmp_tx_fragmentation_buffer[1] >> 16) & (0xFFFFFFFF >> (32 - 8));
    canzero_set_build_time(build_time_tmp);
    break;
  }
  case 2 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    motor_command motor_driver_command_tmp;
    motor_driver_command_tmp = ((motor_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_motor_driver_command(motor_driver_command_tmp);
    break;
  }
  case 3 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float target_acceleration_tmp;
    target_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000023283064370807974 + -50);
    canzero_set_target_acceleration(target_acceleration_tmp);
    break;
  }
  case 4 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t ignore_45v_tmp;
    ignore_45v_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_ignore_45v(ignore_45v_tmp);
    break;
  }
  case 5 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    global_state global_state_tmp;
    global_state_tmp = ((global_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 5))));
    canzero_set_global_state(global_state_tmp);
    break;
  }
  case 6 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    global_command global_command_tmp;
    global_command_tmp = ((global_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 4))));
    canzero_set_global_command(global_command_tmp);
    break;
  }
  case 7 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status system_sdc_status_tmp;
    system_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_system_sdc_status(system_sdc_status_tmp);
    break;
  }
  case 8 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t pod_grounded_tmp;
    pod_grounded_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_pod_grounded(pod_grounded_tmp);
    break;
  }
  case 9 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float system_power_consumption_tmp;
    system_power_consumption_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.15259021896696423 + 0);
    canzero_set_system_power_consumption(system_power_consumption_tmp);
    break;
  }
  case 10 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float communication_power_consumption_tmp;
    communication_power_consumption_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.007629510948348211 + 0);
    canzero_set_communication_power_consumption(communication_power_consumption_tmp);
    break;
  }
  case 11 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float track_length_tmp;
    track_length_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_track_length(track_length_tmp);
    break;
  }
  case 12 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float brake_margin_tmp;
    brake_margin_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_brake_margin(brake_margin_tmp);
    break;
  }
  case 13 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float emergency_brake_margin_tmp;
    emergency_brake_margin_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_emergency_brake_margin(emergency_brake_margin_tmp);
    break;
  }
  case 14 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t assert_45V_system_online_tmp;
    assert_45V_system_online_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_assert_45V_system_online(assert_45V_system_online_tmp);
    break;
  }
  case 15 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status sdc_status_tmp;
    sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_sdc_status(sdc_status_tmp);
    break;
  }
  case 16 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float loop_frequency_tmp;
    loop_frequency_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000023283064370807974 + 0);
    canzero_set_loop_frequency(loop_frequency_tmp);
    break;
  }
  case 17 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag assertion_fault_tmp;
    assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_assertion_fault(assertion_fault_tmp);
    break;
  }
  case 18 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_heartbeat_miss_tmp;
    error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_heartbeat_miss(error_heartbeat_miss_tmp);
    break;
  }
  case 19 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    uint8_t last_node_missed_tmp;
    last_node_missed_tmp = ((uint8_t)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8)))));
    canzero_set_last_node_missed(last_node_missed_tmp);
    break;
  }
  case 20 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float acceleration_target_velocity_tmp;
    acceleration_target_velocity_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.0000000023283064370807974 + 0);
    canzero_set_acceleration_target_velocity(acceleration_target_velocity_tmp);
    break;
  }
  case 21 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      velocity_pid_tmp_tx_fragmentation_offset = 0;
    }else {
      velocity_pid_tmp_tx_fragmentation_offset += 1;
      if (velocity_pid_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    velocity_pid_tmp_tx_fragmentation_buffer[velocity_pid_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    pid_parameters velocity_pid_tmp;
    velocity_pid_tmp.m_Kp = ((uint64_t)velocity_pid_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(velocity_pid_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000005421010862427522 + 0;
    velocity_pid_tmp.m_Ki = ((uint64_t)velocity_pid_tmp_tx_fragmentation_buffer[2] | (((uint64_t)(velocity_pid_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000005421010862427522 + 0;
    velocity_pid_tmp.m_Kd = ((uint64_t)velocity_pid_tmp_tx_fragmentation_buffer[4] | (((uint64_t)(velocity_pid_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000005421010862427522 + 0;
    canzero_set_velocity_pid(velocity_pid_tmp);
    break;
  }
  case 22 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float position_tmp;
    position_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0007629510948348211 + -10);
    canzero_set_position(position_tmp);
    break;
  }
  case 23 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float velocity_tmp;
    velocity_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_velocity(velocity_tmp);
    break;
  }
  case 24 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float acceleration_tmp;
    acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0015259021896696422 + -50);
    canzero_set_acceleration(acceleration_tmp);
    break;
  }
  case 25 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    int16_t linear_encoder_count_tmp;
    linear_encoder_count_tmp = (((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) & (0x1 << (16 - 1))) != 0 ? (int16_t) (((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) | (0xFFFFFFFF << (16 - 1))) : (int16_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16)));
    canzero_set_linear_encoder_count(linear_encoder_count_tmp);
    break;
  }
  case 26 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t absolute_position_known_tmp;
    absolute_position_known_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_absolute_position_known(absolute_position_known_tmp);
    break;
  }
  case 27 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float absolute_position_offset_tmp;
    absolute_position_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0006103608758678569 + -10);
    canzero_set_absolute_position_offset(absolute_position_offset_tmp);
    break;
  }
  case 28 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float raw_acceleration_tmp;
    raw_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0015259021896696422 + -50);
    canzero_set_raw_acceleration(raw_acceleration_tmp);
    break;
  }
  case 29 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_acceleration_out_of_range_tmp;
    error_acceleration_out_of_range_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_acceleration_out_of_range(error_acceleration_out_of_range_tmp);
    break;
  }
  case 30 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      acceleration_calibration_variance_tmp_tx_fragmentation_offset = 0;
    }else {
      acceleration_calibration_variance_tmp_tx_fragmentation_offset += 1;
      if (acceleration_calibration_variance_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    acceleration_calibration_variance_tmp_tx_fragmentation_buffer[acceleration_calibration_variance_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double acceleration_calibration_variance_tmp;
    acceleration_calibration_variance_tmp = ((uint64_t)acceleration_calibration_variance_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(acceleration_calibration_variance_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.00000000000000000010842021724855044 + -1;
    canzero_set_acceleration_calibration_variance(acceleration_calibration_variance_tmp);
    break;
  }
  case 31 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      acceleration_calibration_offset_tmp_tx_fragmentation_offset = 0;
    }else {
      acceleration_calibration_offset_tmp_tx_fragmentation_offset += 1;
      if (acceleration_calibration_offset_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    acceleration_calibration_offset_tmp_tx_fragmentation_buffer[acceleration_calibration_offset_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double acceleration_calibration_offset_tmp;
    acceleration_calibration_offset_tmp = ((uint64_t)acceleration_calibration_offset_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(acceleration_calibration_offset_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_acceleration_calibration_offset(acceleration_calibration_offset_tmp);
    break;
  }
  case 32 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      acceleration_calibration_target_tmp_tx_fragmentation_offset = 0;
    }else {
      acceleration_calibration_target_tmp_tx_fragmentation_offset += 1;
      if (acceleration_calibration_target_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    acceleration_calibration_target_tmp_tx_fragmentation_buffer[acceleration_calibration_target_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double acceleration_calibration_target_tmp;
    acceleration_calibration_target_tmp = ((uint64_t)acceleration_calibration_target_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(acceleration_calibration_target_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_acceleration_calibration_target(acceleration_calibration_target_tmp);
    break;
  }
  case 33 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float raw_lateral_acceleration_tmp;
    raw_lateral_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_raw_lateral_acceleration(raw_lateral_acceleration_tmp);
    break;
  }
  case 34 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float lateral_acceleration_tmp;
    lateral_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_lateral_acceleration(lateral_acceleration_tmp);
    break;
  }
  case 35 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_lateral_acceleration_out_of_range_tmp;
    error_lateral_acceleration_out_of_range_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_lateral_acceleration_out_of_range(error_lateral_acceleration_out_of_range_tmp);
    break;
  }
  case 36 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      lateral_acceleration_calibration_variance_tmp_tx_fragmentation_offset = 0;
    }else {
      lateral_acceleration_calibration_variance_tmp_tx_fragmentation_offset += 1;
      if (lateral_acceleration_calibration_variance_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    lateral_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[lateral_acceleration_calibration_variance_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double lateral_acceleration_calibration_variance_tmp;
    lateral_acceleration_calibration_variance_tmp = ((uint64_t)lateral_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(lateral_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_lateral_acceleration_calibration_variance(lateral_acceleration_calibration_variance_tmp);
    break;
  }
  case 37 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      lateral_acceleration_calibration_offset_tmp_tx_fragmentation_offset = 0;
    }else {
      lateral_acceleration_calibration_offset_tmp_tx_fragmentation_offset += 1;
      if (lateral_acceleration_calibration_offset_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    lateral_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[lateral_acceleration_calibration_offset_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double lateral_acceleration_calibration_offset_tmp;
    lateral_acceleration_calibration_offset_tmp = ((uint64_t)lateral_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(lateral_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_lateral_acceleration_calibration_offset(lateral_acceleration_calibration_offset_tmp);
    break;
  }
  case 38 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      lateral_acceleration_calibration_target_tmp_tx_fragmentation_offset = 0;
    }else {
      lateral_acceleration_calibration_target_tmp_tx_fragmentation_offset += 1;
      if (lateral_acceleration_calibration_target_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    lateral_acceleration_calibration_target_tmp_tx_fragmentation_buffer[lateral_acceleration_calibration_target_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double lateral_acceleration_calibration_target_tmp;
    lateral_acceleration_calibration_target_tmp = ((uint64_t)lateral_acceleration_calibration_target_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(lateral_acceleration_calibration_target_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_lateral_acceleration_calibration_target(lateral_acceleration_calibration_target_tmp);
    break;
  }
  case 39 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float raw_vertical_acceleration_tmp;
    raw_vertical_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0015259021896696422 + -50);
    canzero_set_raw_vertical_acceleration(raw_vertical_acceleration_tmp);
    break;
  }
  case 40 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float vertical_acceleration_tmp;
    vertical_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_vertical_acceleration(vertical_acceleration_tmp);
    break;
  }
  case 41 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_vertical_acceleration_out_of_range_tmp;
    error_vertical_acceleration_out_of_range_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_vertical_acceleration_out_of_range(error_vertical_acceleration_out_of_range_tmp);
    break;
  }
  case 42 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      vertical_acceleration_calibration_variance_tmp_tx_fragmentation_offset = 0;
    }else {
      vertical_acceleration_calibration_variance_tmp_tx_fragmentation_offset += 1;
      if (vertical_acceleration_calibration_variance_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    vertical_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[vertical_acceleration_calibration_variance_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double vertical_acceleration_calibration_variance_tmp;
    vertical_acceleration_calibration_variance_tmp = ((uint64_t)vertical_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(vertical_acceleration_calibration_variance_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_vertical_acceleration_calibration_variance(vertical_acceleration_calibration_variance_tmp);
    break;
  }
  case 43 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      vertical_acceleration_calibration_offset_tmp_tx_fragmentation_offset = 0;
    }else {
      vertical_acceleration_calibration_offset_tmp_tx_fragmentation_offset += 1;
      if (vertical_acceleration_calibration_offset_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    vertical_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[vertical_acceleration_calibration_offset_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double vertical_acceleration_calibration_offset_tmp;
    vertical_acceleration_calibration_offset_tmp = ((uint64_t)vertical_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(vertical_acceleration_calibration_offset_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_vertical_acceleration_calibration_offset(vertical_acceleration_calibration_offset_tmp);
    break;
  }
  case 44 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      vertical_acceleration_calibration_target_tmp_tx_fragmentation_offset = 0;
    }else {
      vertical_acceleration_calibration_target_tmp_tx_fragmentation_offset += 1;
      if (vertical_acceleration_calibration_target_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    vertical_acceleration_calibration_target_tmp_tx_fragmentation_buffer[vertical_acceleration_calibration_target_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    double vertical_acceleration_calibration_target_tmp;
    vertical_acceleration_calibration_target_tmp = ((uint64_t)vertical_acceleration_calibration_target_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(vertical_acceleration_calibration_target_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32)) * 0.0000000000000000010842021724855044 + -10;
    canzero_set_vertical_acceleration_calibration_target(vertical_acceleration_calibration_target_tmp);
    break;
  }
  case 45 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_acceleration_calibration_failed_tmp;
    error_acceleration_calibration_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_acceleration_calibration_failed(error_acceleration_calibration_failed_tmp);
    break;
  }
  case 46 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_voltage_tmp;
    bat24_voltage_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_bat24_voltage(bat24_voltage_tmp);
    break;
  }
  case 47 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode bat24_voltage_calibration_mode_tmp;
    bat24_voltage_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_bat24_voltage_calibration_mode(bat24_voltage_calibration_mode_tmp);
    break;
  }
  case 48 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_voltage_calibration_offset_tmp;
    bat24_voltage_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000004656612874161595 + -10);
    canzero_set_bat24_voltage_calibration_offset(bat24_voltage_calibration_offset_tmp);
    break;
  }
  case 49 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_voltage_calibration_target_tmp;
    bat24_voltage_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_bat24_voltage_calibration_target(bat24_voltage_calibration_target_tmp);
    break;
  }
  case 50 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_voltage_invalid_tmp;
    error_bat24_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_voltage_invalid(error_bat24_voltage_invalid_tmp);
    break;
  }
  case 51 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_under_voltage_tmp;
    error_level_bat24_under_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_under_voltage(error_level_bat24_under_voltage_tmp);
    break;
  }
  case 52 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_under_voltage_tmp;
    error_level_config_bat24_under_voltage_tmp.m_info_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_under_voltage_tmp.m_info_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_under_voltage_tmp.m_warning_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_under_voltage_tmp.m_warning_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_under_voltage_tmp.m_error_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_under_voltage_tmp.m_error_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_under_voltage_tmp.m_ignore_info = ((bool_t)((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_bat24_under_voltage_tmp.m_ignore_warning = ((bool_t)((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_under_voltage_tmp.m_ignore_error = ((bool_t)((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_bat24_under_voltage(error_level_config_bat24_under_voltage_tmp);
    break;
  }
  case 53 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_over_voltage_tmp;
    error_level_bat24_over_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_voltage(error_level_bat24_over_voltage_tmp);
    break;
  }
  case 54 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_over_voltage_tmp;
    error_level_config_bat24_over_voltage_tmp.m_info_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_over_voltage_tmp.m_info_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_voltage_tmp.m_warning_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_over_voltage_tmp.m_warning_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_voltage_tmp.m_error_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_over_voltage_tmp.m_error_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_voltage_tmp.m_ignore_info = ((bool_t)((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_bat24_over_voltage_tmp.m_ignore_warning = ((bool_t)((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_voltage_tmp.m_ignore_error = ((bool_t)((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_bat24_over_voltage(error_level_config_bat24_over_voltage_tmp);
    break;
  }
  case 55 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_current_tmp;
    bat24_current_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current(bat24_current_tmp);
    break;
  }
  case 56 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_current_calibration_offset_tmp;
    bat24_current_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current_calibration_offset(bat24_current_calibration_offset_tmp);
    break;
  }
  case 57 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_current_calibration_target_tmp;
    bat24_current_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current_calibration_target(bat24_current_calibration_target_tmp);
    break;
  }
  case 58 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode bat24_current_calibration_mode_tmp;
    bat24_current_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_bat24_current_calibration_mode(bat24_current_calibration_mode_tmp);
    break;
  }
  case 59 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_current_invalid_tmp;
    error_bat24_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_current_invalid(error_bat24_current_invalid_tmp);
    break;
  }
  case 60 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_over_current_tmp;
    error_level_bat24_over_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_current(error_level_bat24_over_current_tmp);
    break;
  }
  case 61 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_bat24_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_over_current_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[error_level_config_bat24_over_current_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_over_current_tmp;
    error_level_config_bat24_over_current_tmp.m_info_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_over_current_tmp.m_info_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_current_tmp.m_warning_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_over_current_tmp.m_warning_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_current_tmp.m_error_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_over_current_tmp.m_error_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_current_tmp.m_ignore_info = ((bool_t)((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_bat24_over_current_tmp.m_ignore_warning = ((bool_t)((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_current_tmp.m_ignore_error = ((bool_t)((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_bat24_over_current(error_level_config_bat24_over_current_tmp);
    break;
  }
  case 62 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_voltage_tmp;
    supercap_voltage_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_supercap_voltage(supercap_voltage_tmp);
    break;
  }
  case 63 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode supercap_voltage_calibration_mode_tmp;
    supercap_voltage_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_supercap_voltage_calibration_mode(supercap_voltage_calibration_mode_tmp);
    break;
  }
  case 64 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_voltage_calibration_offset_tmp;
    supercap_voltage_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000004656612874161595 + -10);
    canzero_set_supercap_voltage_calibration_offset(supercap_voltage_calibration_offset_tmp);
    break;
  }
  case 65 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_voltage_calibration_target_tmp;
    supercap_voltage_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_supercap_voltage_calibration_target(supercap_voltage_calibration_target_tmp);
    break;
  }
  case 66 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_supercap_voltage_invalid_tmp;
    error_supercap_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_supercap_voltage_invalid(error_supercap_voltage_invalid_tmp);
    break;
  }
  case 67 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_supercap_under_voltage_tmp;
    error_level_supercap_under_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_under_voltage(error_level_supercap_under_voltage_tmp);
    break;
  }
  case 68 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_supercap_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_supercap_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_supercap_under_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_supercap_under_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_supercap_under_voltage_tmp;
    error_level_config_supercap_under_voltage_tmp.m_info_thresh = ((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_under_voltage_tmp.m_info_timeout = ((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_under_voltage_tmp.m_warning_thresh = ((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_under_voltage_tmp.m_warning_timeout = ((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_under_voltage_tmp.m_error_thresh = ((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_under_voltage_tmp.m_error_timeout = ((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_under_voltage_tmp.m_ignore_info = ((bool_t)((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_supercap_under_voltage_tmp.m_ignore_warning = ((bool_t)((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_supercap_under_voltage_tmp.m_ignore_error = ((bool_t)((error_level_config_supercap_under_voltage_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_supercap_under_voltage(error_level_config_supercap_under_voltage_tmp);
    break;
  }
  case 69 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_supercap_over_voltage_tmp;
    error_level_supercap_over_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_over_voltage(error_level_supercap_over_voltage_tmp);
    break;
  }
  case 70 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_supercap_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_supercap_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_supercap_over_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_supercap_over_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_supercap_over_voltage_tmp;
    error_level_config_supercap_over_voltage_tmp.m_info_thresh = ((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_over_voltage_tmp.m_info_timeout = ((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_over_voltage_tmp.m_warning_thresh = ((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_over_voltage_tmp.m_warning_timeout = ((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_over_voltage_tmp.m_error_thresh = ((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_over_voltage_tmp.m_error_timeout = ((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_over_voltage_tmp.m_ignore_info = ((bool_t)((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_supercap_over_voltage_tmp.m_ignore_warning = ((bool_t)((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_supercap_over_voltage_tmp.m_ignore_error = ((bool_t)((error_level_config_supercap_over_voltage_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_supercap_over_voltage(error_level_config_supercap_over_voltage_tmp);
    break;
  }
  case 71 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_current_tmp;
    link24_current_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_link24_current(link24_current_tmp);
    break;
  }
  case 72 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode link24_current_calibration_mode_tmp;
    link24_current_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_link24_current_calibration_mode(link24_current_calibration_mode_tmp);
    break;
  }
  case 73 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_current_calibration_offset_tmp;
    link24_current_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000004656612874161595 + -10);
    canzero_set_link24_current_calibration_offset(link24_current_calibration_offset_tmp);
    break;
  }
  case 74 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_current_calibration_target_tmp;
    link24_current_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_link24_current_calibration_target(link24_current_calibration_target_tmp);
    break;
  }
  case 75 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_link24_current_invalid_tmp;
    error_link24_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_link24_current_invalid(error_link24_current_invalid_tmp);
    break;
  }
  case 76 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link24_over_current_tmp;
    error_level_link24_over_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_over_current(error_level_link24_over_current_tmp);
    break;
  }
  case 77 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_link24_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link24_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link24_over_current_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[error_level_config_link24_over_current_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link24_over_current_tmp;
    error_level_config_link24_over_current_tmp.m_info_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link24_over_current_tmp.m_info_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_current_tmp.m_warning_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link24_over_current_tmp.m_warning_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_current_tmp.m_error_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link24_over_current_tmp.m_error_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_current_tmp.m_ignore_info = ((bool_t)((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_link24_over_current_tmp.m_ignore_warning = ((bool_t)((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_over_current_tmp.m_ignore_error = ((bool_t)((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_link24_over_current(error_level_config_link24_over_current_tmp);
    break;
  }
  case 78 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_voltage_tmp;
    link45_voltage_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100);
    canzero_set_link45_voltage(link45_voltage_tmp);
    break;
  }
  case 79 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode link45_voltage_calibration_mode_tmp;
    link45_voltage_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_link45_voltage_calibration_mode(link45_voltage_calibration_mode_tmp);
    break;
  }
  case 80 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_voltage_calibration_offset_tmp;
    link45_voltage_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100);
    canzero_set_link45_voltage_calibration_offset(link45_voltage_calibration_offset_tmp);
    break;
  }
  case 81 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_voltage_calibration_target_tmp;
    link45_voltage_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000023283064370807974 + 0);
    canzero_set_link45_voltage_calibration_target(link45_voltage_calibration_target_tmp);
    break;
  }
  case 82 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_link45_voltage_invalid_tmp;
    error_link45_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_link45_voltage_invalid(error_link45_voltage_invalid_tmp);
    break;
  }
  case 83 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_under_voltage_tmp;
    error_level_link45_under_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_under_voltage(error_level_link45_under_voltage_tmp);
    break;
  }
  case 84 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_under_voltage_tmp;
    error_level_config_link45_under_voltage_tmp.m_info_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_under_voltage_tmp.m_info_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_under_voltage_tmp.m_warning_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_under_voltage_tmp.m_warning_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_under_voltage_tmp.m_error_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_under_voltage_tmp.m_error_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_under_voltage_tmp.m_ignore_info = ((bool_t)((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_link45_under_voltage_tmp.m_ignore_warning = ((bool_t)((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_under_voltage_tmp.m_ignore_error = ((bool_t)((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_link45_under_voltage(error_level_config_link45_under_voltage_tmp);
    break;
  }
  case 85 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_over_voltage_tmp;
    error_level_link45_over_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_voltage(error_level_link45_over_voltage_tmp);
    break;
  }
  case 86 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_over_voltage_tmp;
    error_level_config_link45_over_voltage_tmp.m_info_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_over_voltage_tmp.m_info_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_voltage_tmp.m_warning_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_over_voltage_tmp.m_warning_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_voltage_tmp.m_error_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_over_voltage_tmp.m_error_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_voltage_tmp.m_ignore_info = ((bool_t)((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_link45_over_voltage_tmp.m_ignore_warning = ((bool_t)((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_voltage_tmp.m_ignore_error = ((bool_t)((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_link45_over_voltage(error_level_config_link45_over_voltage_tmp);
    break;
  }
  case 87 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_current_tmp;
    link45_current_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.0000004656612874161595 + -1000);
    canzero_set_link45_current(link45_current_tmp);
    break;
  }
  case 88 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode link45_current_calibration_mode_tmp;
    link45_current_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_link45_current_calibration_mode(link45_current_calibration_mode_tmp);
    break;
  }
  case 89 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_current_calibration_offset_tmp;
    link45_current_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100);
    canzero_set_link45_current_calibration_offset(link45_current_calibration_offset_tmp);
    break;
  }
  case 90 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_current_calibration_target_tmp;
    link45_current_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.0000004656612874161595 + -1000);
    canzero_set_link45_current_calibration_target(link45_current_calibration_target_tmp);
    break;
  }
  case 91 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_link45_current_invalid_tmp;
    error_link45_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_link45_current_invalid(error_link45_current_invalid_tmp);
    break;
  }
  case 92 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_over_current_tmp;
    error_level_link45_over_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_current(error_level_link45_over_current_tmp);
    break;
  }
  case 93 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_link45_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_over_current_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[error_level_config_link45_over_current_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_over_current_tmp;
    error_level_config_link45_over_current_tmp.m_info_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_over_current_tmp.m_info_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_current_tmp.m_warning_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_over_current_tmp.m_warning_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_current_tmp.m_error_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_link45_over_current_tmp.m_error_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_current_tmp.m_ignore_info = ((bool_t)((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_link45_over_current_tmp.m_ignore_warning = ((bool_t)((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_current_tmp.m_ignore_error = ((bool_t)((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_link45_over_current(error_level_config_link45_over_current_tmp);
    break;
  }
  case 94 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float mcu_temperature_tmp;
    mcu_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_mcu_temperature(mcu_temperature_tmp);
    break;
  }
  case 95 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_mcu_temperature_invalid_tmp;
    error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_mcu_temperature_invalid(error_mcu_temperature_invalid_tmp);
    break;
  }
  case 96 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_mcu_temperature_tmp;
    error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_mcu_temperature(error_level_mcu_temperature_tmp);
    break;
  }
  case 97 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_mcu_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_mcu_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_mcu_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[error_level_config_mcu_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_mcu_temperature_tmp;
    error_level_config_mcu_temperature_tmp.m_info_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_mcu_temperature_tmp.m_info_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_mcu_temperature_tmp.m_warning_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_mcu_temperature_tmp.m_warning_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_mcu_temperature_tmp.m_error_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_mcu_temperature_tmp.m_error_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_mcu_temperature_tmp.m_ignore_info = ((bool_t)((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_mcu_temperature_tmp.m_ignore_warning = ((bool_t)((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_mcu_temperature_tmp.m_ignore_error = ((bool_t)((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_mcu_temperature(error_level_config_mcu_temperature_tmp);
    break;
  }
  case 98 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_cell_temperature_1_tmp;
    bat24_cell_temperature_1_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_bat24_cell_temperature_1(bat24_cell_temperature_1_tmp);
    break;
  }
  case 99 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_cell_temperature_2_tmp;
    bat24_cell_temperature_2_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_bat24_cell_temperature_2(bat24_cell_temperature_2_tmp);
    break;
  }
  case 100 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_temperature_max_tmp;
    bat24_temperature_max_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_bat24_temperature_max(bat24_temperature_max_tmp);
    break;
  }
  case 101 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_cell_temperature_1_invalid_tmp;
    error_bat24_cell_temperature_1_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_cell_temperature_1_invalid(error_bat24_cell_temperature_1_invalid_tmp);
    break;
  }
  case 102 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_cell_temperature_2_invalid_tmp;
    error_bat24_cell_temperature_2_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_cell_temperature_2_invalid(error_bat24_cell_temperature_2_invalid_tmp);
    break;
  }
  case 103 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_temperature_tmp;
    error_level_bat24_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_temperature(error_level_bat24_temperature_tmp);
    break;
  }
  case 104 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_bat24_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[error_level_config_bat24_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_temperature_tmp;
    error_level_config_bat24_temperature_tmp.m_info_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_temperature_tmp.m_info_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_temperature_tmp.m_warning_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_temperature_tmp.m_warning_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_temperature_tmp.m_error_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_bat24_temperature_tmp.m_error_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_temperature_tmp.m_ignore_info = ((bool_t)((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_bat24_temperature_tmp.m_ignore_warning = ((bool_t)((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_temperature_tmp.m_ignore_error = ((bool_t)((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_bat24_temperature(error_level_config_bat24_temperature_tmp);
    break;
  }
  case 105 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_temperature_tmp;
    supercap_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_supercap_temperature(supercap_temperature_tmp);
    break;
  }
  case 106 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_supercap_temperature_invalid_tmp;
    error_supercap_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_supercap_temperature_invalid(error_supercap_temperature_invalid_tmp);
    break;
  }
  case 107 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_supercap_temperature_tmp;
    error_level_supercap_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_temperature(error_level_supercap_temperature_tmp);
    break;
  }
  case 108 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_supercap_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_supercap_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_supercap_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[error_level_config_supercap_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_supercap_temperature_tmp;
    error_level_config_supercap_temperature_tmp.m_info_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_temperature_tmp.m_info_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_temperature_tmp.m_warning_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_temperature_tmp.m_warning_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_temperature_tmp.m_error_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_supercap_temperature_tmp.m_error_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_temperature_tmp.m_ignore_info = ((bool_t)((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_supercap_temperature_tmp.m_ignore_warning = ((bool_t)((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_supercap_temperature_tmp.m_ignore_error = ((bool_t)((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_supercap_temperature(error_level_config_supercap_temperature_tmp);
    break;
  }
  case 109 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float sac_ebox_temperature_tmp;
    sac_ebox_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_sac_ebox_temperature(sac_ebox_temperature_tmp);
    break;
  }
  case 110 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_sac_ebox_temperature_invalid_tmp;
    error_sac_ebox_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_sac_ebox_temperature_invalid(error_sac_ebox_temperature_invalid_tmp);
    break;
  }
  case 111 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_sac_ebox_temperature_tmp;
    error_level_sac_ebox_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_sac_ebox_temperature(error_level_sac_ebox_temperature_tmp);
    break;
  }
  case 112 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_sac_ebox_temperature_tmp;
    error_level_config_sac_ebox_temperature_tmp.m_info_thresh = ((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_sac_ebox_temperature_tmp.m_info_timeout = ((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_sac_ebox_temperature_tmp.m_warning_thresh = ((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_sac_ebox_temperature_tmp.m_warning_timeout = ((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_sac_ebox_temperature_tmp.m_error_thresh = ((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_sac_ebox_temperature_tmp.m_error_timeout = ((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_sac_ebox_temperature_tmp.m_ignore_info = ((bool_t)((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_sac_ebox_temperature_tmp.m_ignore_warning = ((bool_t)((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_sac_ebox_temperature_tmp.m_ignore_error = ((bool_t)((error_level_config_sac_ebox_temperature_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_sac_ebox_temperature(error_level_config_sac_ebox_temperature_tmp);
    break;
  }
  case 113 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float power_ebox_temperature_tmp;
    power_ebox_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_power_ebox_temperature(power_ebox_temperature_tmp);
    break;
  }
  case 114 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_power_ebox_temperature_invalid_tmp;
    error_power_ebox_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_power_ebox_temperature_invalid(error_power_ebox_temperature_invalid_tmp);
    break;
  }
  case 115 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_power_ebox_temperature_tmp;
    error_level_power_ebox_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_power_ebox_temperature(error_level_power_ebox_temperature_tmp);
    break;
  }
  case 116 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_power_ebox_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_power_ebox_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_power_ebox_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[error_level_config_power_ebox_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_power_ebox_temperature_tmp;
    error_level_config_power_ebox_temperature_tmp.m_info_thresh = ((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_power_ebox_temperature_tmp.m_info_timeout = ((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_power_ebox_temperature_tmp.m_warning_thresh = ((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_power_ebox_temperature_tmp.m_warning_timeout = ((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_power_ebox_temperature_tmp.m_error_thresh = ((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_power_ebox_temperature_tmp.m_error_timeout = ((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_power_ebox_temperature_tmp.m_ignore_info = ((bool_t)((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_power_ebox_temperature_tmp.m_ignore_warning = ((bool_t)((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_power_ebox_temperature_tmp.m_ignore_error = ((bool_t)((error_level_config_power_ebox_temperature_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_power_ebox_temperature(error_level_config_power_ebox_temperature_tmp);
    break;
  }
  case 117 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_1_tmp;
    ambient_temperature_1_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_1(ambient_temperature_1_tmp);
    break;
  }
  case 118 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_2_tmp;
    ambient_temperature_2_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_2(ambient_temperature_2_tmp);
    break;
  }
  case 119 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_3_tmp;
    ambient_temperature_3_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_3(ambient_temperature_3_tmp);
    break;
  }
  case 120 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_avg_tmp;
    ambient_temperature_avg_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_avg(ambient_temperature_avg_tmp);
    break;
  }
  case 121 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_max_tmp;
    ambient_temperature_max_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_max(ambient_temperature_max_tmp);
    break;
  }
  case 122 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_ambient_temperature_1_invalid_tmp;
    error_ambient_temperature_1_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_ambient_temperature_1_invalid(error_ambient_temperature_1_invalid_tmp);
    break;
  }
  case 123 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_ambient_temperature_2_invalid_tmp;
    error_ambient_temperature_2_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_ambient_temperature_2_invalid(error_ambient_temperature_2_invalid_tmp);
    break;
  }
  case 124 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_ambient_temperature_3_invalid_tmp;
    error_ambient_temperature_3_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_ambient_temperature_3_invalid(error_ambient_temperature_3_invalid_tmp);
    break;
  }
  case 125 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_ambient_temperature_tmp;
    error_level_ambient_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_ambient_temperature(error_level_ambient_temperature_tmp);
    break;
  }
  case 126 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      error_level_config_ambient_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_ambient_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_ambient_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[error_level_config_ambient_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_ambient_temperature_tmp;
    error_level_config_ambient_temperature_tmp.m_info_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_ambient_temperature_tmp.m_info_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ambient_temperature_tmp.m_warning_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[2] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_ambient_temperature_tmp.m_warning_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[3] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ambient_temperature_tmp.m_error_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[4] & (0xFFFFFFFF >> (32 - 32)))) * 0.0000004656612874161595 + -1000;
    error_level_config_ambient_temperature_tmp.m_error_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[5] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ambient_temperature_tmp.m_ignore_info = ((bool_t)((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[6] & (0xFFFFFFFF >> (32 - 1)))));
    error_level_config_ambient_temperature_tmp.m_ignore_warning = ((bool_t)((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[6] >> 1) & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_ambient_temperature_tmp.m_ignore_error = ((bool_t)((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[6] >> 2) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_level_config_ambient_temperature(error_level_config_ambient_temperature_tmp);
    break;
  }
  case 127 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float cooling_flow_rate_begin_tmp;
    cooling_flow_rate_begin_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.006103608758678569 + 0);
    canzero_set_cooling_flow_rate_begin(cooling_flow_rate_begin_tmp);
    break;
  }
  case 128 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float cooling_flow_rate_end_tmp;
    cooling_flow_rate_end_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.006103608758678569 + 0);
    canzero_set_cooling_flow_rate_end(cooling_flow_rate_end_tmp);
    break;
  }
  case 129 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_cooling_flow_rate_low_tmp;
    error_cooling_flow_rate_low_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_cooling_flow_rate_low(error_cooling_flow_rate_low_tmp);
    break;
  }
  case 130 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_cooling_flow_rate_mismatch_tmp;
    error_cooling_flow_rate_mismatch_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_cooling_flow_rate_mismatch(error_cooling_flow_rate_mismatch_tmp);
    break;
  }
  case 131 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float cooling_cycle_temp_begin_tmp;
    cooling_cycle_temp_begin_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_cooling_cycle_temp_begin(cooling_cycle_temp_begin_tmp);
    break;
  }
  case 132 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float cooling_cycle_temp_end_tmp;
    cooling_cycle_temp_end_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_cooling_cycle_temp_end(cooling_cycle_temp_end_tmp);
    break;
  }
  case 133 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_cooling_cycle_temp_begin_invalid_tmp;
    error_cooling_cycle_temp_begin_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_cooling_cycle_temp_begin_invalid(error_cooling_cycle_temp_begin_invalid_tmp);
    break;
  }
  case 134 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_cooling_cycle_temp_end_invalid_tmp;
    error_cooling_cycle_temp_end_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_cooling_cycle_temp_end_invalid(error_cooling_cycle_temp_end_invalid_tmp);
    break;
  }
  case 135 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_cooling_cycle_overtemp_tmp;
    error_level_cooling_cycle_overtemp_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_cooling_cycle_overtemp(error_level_cooling_cycle_overtemp_tmp);
    break;
  }
  case 136 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    motor_state motor_driver_state_tmp;
    motor_driver_state_tmp = ((motor_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_motor_driver_state(motor_driver_state_tmp);
    break;
  }
  case 137 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status motor_driver_sdc_status_tmp;
    motor_driver_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_sdc_status(motor_driver_sdc_status_tmp);
    break;
  }
  case 138 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      motor_driver_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      motor_driver_config_hash_tmp_tx_fragmentation_offset += 1;
      if (motor_driver_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    motor_driver_config_hash_tmp_tx_fragmentation_buffer[motor_driver_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t motor_driver_config_hash_tmp;
    motor_driver_config_hash_tmp = (uint64_t)motor_driver_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(motor_driver_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_motor_driver_config_hash(motor_driver_config_hash_tmp);
    break;
  }
  case 139 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_assertion_fault_tmp;
    motor_driver_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_assertion_fault(motor_driver_assertion_fault_tmp);
    break;
  }
  case 140 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_arming_failed_tmp;
    motor_driver_error_arming_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_arming_failed(motor_driver_error_arming_failed_tmp);
    break;
  }
  case 141 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_precharge_failed_tmp;
    motor_driver_error_precharge_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_precharge_failed(motor_driver_error_precharge_failed_tmp);
    break;
  }
  case 142 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_acceleration_out_of_range_tmp;
    motor_driver_error_acceleration_out_of_range_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_acceleration_out_of_range(motor_driver_error_acceleration_out_of_range_tmp);
    break;
  }
  case 143 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_acceleration_calibration_failed_tmp;
    motor_driver_error_acceleration_calibration_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_acceleration_calibration_failed(motor_driver_error_acceleration_calibration_failed_tmp);
    break;
  }
  case 144 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_invalid_target_acceleration_tmp;
    motor_driver_error_invalid_target_acceleration_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_invalid_target_acceleration(motor_driver_error_invalid_target_acceleration_tmp);
    break;
  }
  case 145 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_vdc_voltage_invalid_tmp;
    motor_driver_error_vdc_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_vdc_voltage_invalid(motor_driver_error_vdc_voltage_invalid_tmp);
    break;
  }
  case 146 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_board_temperature1_invalid_tmp;
    motor_driver_error_board_temperature1_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_board_temperature1_invalid(motor_driver_error_board_temperature1_invalid_tmp);
    break;
  }
  case 147 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_board_temperature2_invalid_tmp;
    motor_driver_error_board_temperature2_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_board_temperature2_invalid(motor_driver_error_board_temperature2_invalid_tmp);
    break;
  }
  case 148 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_board_temperature3_invalid_tmp;
    motor_driver_error_board_temperature3_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_board_temperature3_invalid(motor_driver_error_board_temperature3_invalid_tmp);
    break;
  }
  case 149 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_mcu_temperature_invalid_tmp;
    motor_driver_error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_mcu_temperature_invalid(motor_driver_error_mcu_temperature_invalid_tmp);
    break;
  }
  case 150 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_lim_temperature1_invalid_tmp;
    motor_driver_error_lim_temperature1_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_lim_temperature1_invalid(motor_driver_error_lim_temperature1_invalid_tmp);
    break;
  }
  case 151 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_lim_temperature2_invalid_tmp;
    motor_driver_error_lim_temperature2_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_lim_temperature2_invalid(motor_driver_error_lim_temperature2_invalid_tmp);
    break;
  }
  case 152 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_lim_temperature3_invalid_tmp;
    motor_driver_error_lim_temperature3_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_lim_temperature3_invalid(motor_driver_error_lim_temperature3_invalid_tmp);
    break;
  }
  case 153 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_lim_temperature4_invalid_tmp;
    motor_driver_error_lim_temperature4_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_lim_temperature4_invalid(motor_driver_error_lim_temperature4_invalid_tmp);
    break;
  }
  case 154 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_heartbeat_miss_tmp;
    motor_driver_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_heartbeat_miss(motor_driver_error_heartbeat_miss_tmp);
    break;
  }
  case 155 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_phase_current_unexpected_tmp;
    motor_driver_error_phase_current_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_phase_current_unexpected(motor_driver_error_phase_current_unexpected_tmp);
    break;
  }
  case 156 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_error_sdc_brake_tmp;
    motor_driver_error_sdc_brake_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_error_sdc_brake(motor_driver_error_sdc_brake_tmp);
    break;
  }
  case 157 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_current_u1_tmp;
    motor_driver_error_level_current_u1_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_current_u1(motor_driver_error_level_current_u1_tmp);
    break;
  }
  case 158 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_current_v1_tmp;
    motor_driver_error_level_current_v1_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_current_v1(motor_driver_error_level_current_v1_tmp);
    break;
  }
  case 159 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_current_w1_tmp;
    motor_driver_error_level_current_w1_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_current_w1(motor_driver_error_level_current_w1_tmp);
    break;
  }
  case 160 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_current_u2_tmp;
    motor_driver_error_level_current_u2_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_current_u2(motor_driver_error_level_current_u2_tmp);
    break;
  }
  case 161 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_current_v2_tmp;
    motor_driver_error_level_current_v2_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_current_v2(motor_driver_error_level_current_v2_tmp);
    break;
  }
  case 162 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_current_w2_tmp;
    motor_driver_error_level_current_w2_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_current_w2(motor_driver_error_level_current_w2_tmp);
    break;
  }
  case 163 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_vdc_voltage_tmp;
    motor_driver_error_level_vdc_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_vdc_voltage(motor_driver_error_level_vdc_voltage_tmp);
    break;
  }
  case 164 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_board_temperature_tmp;
    motor_driver_error_level_board_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_board_temperature(motor_driver_error_level_board_temperature_tmp);
    break;
  }
  case 165 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_mcu_temperature_tmp;
    motor_driver_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_mcu_temperature(motor_driver_error_level_mcu_temperature_tmp);
    break;
  }
  case 166 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level motor_driver_error_level_lim_temperature_tmp;
    motor_driver_error_level_lim_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_motor_driver_error_level_lim_temperature(motor_driver_error_level_lim_temperature_tmp);
    break;
  }
  case 167 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag motor_driver_phase_current_unexpected_tmp;
    motor_driver_phase_current_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_motor_driver_phase_current_unexpected(motor_driver_phase_current_unexpected_tmp);
    break;
  }
  case 168 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    guidance_command guidance_command_tmp;
    guidance_command_tmp = ((guidance_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_guidance_command(guidance_command_tmp);
    break;
  }
  case 169 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    guidance_state guidance_board_front_state_tmp;
    guidance_board_front_state_tmp = ((guidance_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_guidance_board_front_state(guidance_board_front_state_tmp);
    break;
  }
  case 170 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status guidance_board_front_sdc_status_tmp;
    guidance_board_front_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_sdc_status(guidance_board_front_sdc_status_tmp);
    break;
  }
  case 171 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      guidance_board_front_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      guidance_board_front_config_hash_tmp_tx_fragmentation_offset += 1;
      if (guidance_board_front_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    guidance_board_front_config_hash_tmp_tx_fragmentation_buffer[guidance_board_front_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t guidance_board_front_config_hash_tmp;
    guidance_board_front_config_hash_tmp = (uint64_t)guidance_board_front_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(guidance_board_front_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_guidance_board_front_config_hash(guidance_board_front_config_hash_tmp);
    break;
  }
  case 172 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_assertion_fault_tmp;
    guidance_board_front_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_assertion_fault(guidance_board_front_assertion_fault_tmp);
    break;
  }
  case 173 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_arming_failed_tmp;
    guidance_board_front_error_arming_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_arming_failed(guidance_board_front_error_arming_failed_tmp);
    break;
  }
  case 174 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_precharge_failed_tmp;
    guidance_board_front_error_precharge_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_precharge_failed(guidance_board_front_error_precharge_failed_tmp);
    break;
  }
  case 175 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_heartbeat_miss_tmp;
    guidance_board_front_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_heartbeat_miss(guidance_board_front_error_heartbeat_miss_tmp);
    break;
  }
  case 176 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_outer_airgap_left_invalid_tmp;
    guidance_board_front_error_outer_airgap_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_outer_airgap_left_invalid(guidance_board_front_error_outer_airgap_left_invalid_tmp);
    break;
  }
  case 177 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_inner_airgap_left_invalid_tmp;
    guidance_board_front_error_inner_airgap_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_inner_airgap_left_invalid(guidance_board_front_error_inner_airgap_left_invalid_tmp);
    break;
  }
  case 178 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_outer_airgap_right_invalid_tmp;
    guidance_board_front_error_outer_airgap_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_outer_airgap_right_invalid(guidance_board_front_error_outer_airgap_right_invalid_tmp);
    break;
  }
  case 179 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_inner_airgap_right_invalid_tmp;
    guidance_board_front_error_inner_airgap_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_inner_airgap_right_invalid(guidance_board_front_error_inner_airgap_right_invalid_tmp);
    break;
  }
  case 180 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_vdc_voltage_invalid_tmp;
    guidance_board_front_error_vdc_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_vdc_voltage_invalid(guidance_board_front_error_vdc_voltage_invalid_tmp);
    break;
  }
  case 181 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_magnet_current_left_invalid_tmp;
    guidance_board_front_error_magnet_current_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_magnet_current_left_invalid(guidance_board_front_error_magnet_current_left_invalid_tmp);
    break;
  }
  case 182 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_magnet_current_right_invalid_tmp;
    guidance_board_front_error_magnet_current_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_magnet_current_right_invalid(guidance_board_front_error_magnet_current_right_invalid_tmp);
    break;
  }
  case 183 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_input_current_invalid_tmp;
    guidance_board_front_error_input_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_input_current_invalid(guidance_board_front_error_input_current_invalid_tmp);
    break;
  }
  case 184 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_magnet_temperature_left_invalid_tmp;
    guidance_board_front_error_magnet_temperature_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_magnet_temperature_left_invalid(guidance_board_front_error_magnet_temperature_left_invalid_tmp);
    break;
  }
  case 185 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_magnet_temperature_right_invalid_tmp;
    guidance_board_front_error_magnet_temperature_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_magnet_temperature_right_invalid(guidance_board_front_error_magnet_temperature_right_invalid_tmp);
    break;
  }
  case 186 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_mcu_temperature_invalid_tmp;
    guidance_board_front_error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_mcu_temperature_invalid(guidance_board_front_error_mcu_temperature_invalid_tmp);
    break;
  }
  case 187 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_front_error_level_vdc_voltage_tmp;
    guidance_board_front_error_level_vdc_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_front_error_level_vdc_voltage(guidance_board_front_error_level_vdc_voltage_tmp);
    break;
  }
  case 188 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_front_error_level_magnet_current_left_tmp;
    guidance_board_front_error_level_magnet_current_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_front_error_level_magnet_current_left(guidance_board_front_error_level_magnet_current_left_tmp);
    break;
  }
  case 189 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_front_error_level_magnet_current_right_tmp;
    guidance_board_front_error_level_magnet_current_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_front_error_level_magnet_current_right(guidance_board_front_error_level_magnet_current_right_tmp);
    break;
  }
  case 190 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_front_error_level_input_current_tmp;
    guidance_board_front_error_level_input_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_front_error_level_input_current(guidance_board_front_error_level_input_current_tmp);
    break;
  }
  case 191 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_front_error_level_magnet_temperature_left_tmp;
    guidance_board_front_error_level_magnet_temperature_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_front_error_level_magnet_temperature_left(guidance_board_front_error_level_magnet_temperature_left_tmp);
    break;
  }
  case 192 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_front_error_level_magnet_temperature_right_tmp;
    guidance_board_front_error_level_magnet_temperature_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_front_error_level_magnet_temperature_right(guidance_board_front_error_level_magnet_temperature_right_tmp);
    break;
  }
  case 193 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_front_error_level_mcu_temperature_tmp;
    guidance_board_front_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_front_error_level_mcu_temperature(guidance_board_front_error_level_mcu_temperature_tmp);
    break;
  }
  case 194 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    guidance_state guidance_board_back_state_tmp;
    guidance_board_back_state_tmp = ((guidance_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_guidance_board_back_state(guidance_board_back_state_tmp);
    break;
  }
  case 195 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status guidance_board_back_sdc_status_tmp;
    guidance_board_back_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_sdc_status(guidance_board_back_sdc_status_tmp);
    break;
  }
  case 196 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      guidance_board_back_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      guidance_board_back_config_hash_tmp_tx_fragmentation_offset += 1;
      if (guidance_board_back_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    guidance_board_back_config_hash_tmp_tx_fragmentation_buffer[guidance_board_back_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t guidance_board_back_config_hash_tmp;
    guidance_board_back_config_hash_tmp = (uint64_t)guidance_board_back_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(guidance_board_back_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_guidance_board_back_config_hash(guidance_board_back_config_hash_tmp);
    break;
  }
  case 197 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_assertion_fault_tmp;
    guidance_board_back_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_assertion_fault(guidance_board_back_assertion_fault_tmp);
    break;
  }
  case 198 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_arming_failed_tmp;
    guidance_board_back_error_arming_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_arming_failed(guidance_board_back_error_arming_failed_tmp);
    break;
  }
  case 199 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_precharge_failed_tmp;
    guidance_board_back_error_precharge_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_precharge_failed(guidance_board_back_error_precharge_failed_tmp);
    break;
  }
  case 200 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_heartbeat_miss_tmp;
    guidance_board_back_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_heartbeat_miss(guidance_board_back_error_heartbeat_miss_tmp);
    break;
  }
  case 201 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_outer_airgap_left_invalid_tmp;
    guidance_board_back_error_outer_airgap_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_outer_airgap_left_invalid(guidance_board_back_error_outer_airgap_left_invalid_tmp);
    break;
  }
  case 202 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_inner_airgap_left_invalid_tmp;
    guidance_board_back_error_inner_airgap_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_inner_airgap_left_invalid(guidance_board_back_error_inner_airgap_left_invalid_tmp);
    break;
  }
  case 203 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_outer_airgap_right_invalid_tmp;
    guidance_board_back_error_outer_airgap_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_outer_airgap_right_invalid(guidance_board_back_error_outer_airgap_right_invalid_tmp);
    break;
  }
  case 204 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_inner_airgap_right_invalid_tmp;
    guidance_board_back_error_inner_airgap_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_inner_airgap_right_invalid(guidance_board_back_error_inner_airgap_right_invalid_tmp);
    break;
  }
  case 205 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_vdc_voltage_invalid_tmp;
    guidance_board_back_error_vdc_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_vdc_voltage_invalid(guidance_board_back_error_vdc_voltage_invalid_tmp);
    break;
  }
  case 206 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_magnet_current_left_invalid_tmp;
    guidance_board_back_error_magnet_current_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_magnet_current_left_invalid(guidance_board_back_error_magnet_current_left_invalid_tmp);
    break;
  }
  case 207 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_magnet_current_right_invalid_tmp;
    guidance_board_back_error_magnet_current_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_magnet_current_right_invalid(guidance_board_back_error_magnet_current_right_invalid_tmp);
    break;
  }
  case 208 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_input_current_invalid_tmp;
    guidance_board_back_error_input_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_input_current_invalid(guidance_board_back_error_input_current_invalid_tmp);
    break;
  }
  case 209 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_magnet_temperature_left_invalid_tmp;
    guidance_board_back_error_magnet_temperature_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_magnet_temperature_left_invalid(guidance_board_back_error_magnet_temperature_left_invalid_tmp);
    break;
  }
  case 210 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_magnet_temperature_right_invalid_tmp;
    guidance_board_back_error_magnet_temperature_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_magnet_temperature_right_invalid(guidance_board_back_error_magnet_temperature_right_invalid_tmp);
    break;
  }
  case 211 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_mcu_temperature_invalid_tmp;
    guidance_board_back_error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_mcu_temperature_invalid(guidance_board_back_error_mcu_temperature_invalid_tmp);
    break;
  }
  case 212 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_back_error_level_vdc_voltage_tmp;
    guidance_board_back_error_level_vdc_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_back_error_level_vdc_voltage(guidance_board_back_error_level_vdc_voltage_tmp);
    break;
  }
  case 213 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_back_error_level_magnet_current_left_tmp;
    guidance_board_back_error_level_magnet_current_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_back_error_level_magnet_current_left(guidance_board_back_error_level_magnet_current_left_tmp);
    break;
  }
  case 214 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_back_error_level_magnet_current_right_tmp;
    guidance_board_back_error_level_magnet_current_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_back_error_level_magnet_current_right(guidance_board_back_error_level_magnet_current_right_tmp);
    break;
  }
  case 215 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_back_error_level_input_current_tmp;
    guidance_board_back_error_level_input_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_back_error_level_input_current(guidance_board_back_error_level_input_current_tmp);
    break;
  }
  case 216 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_back_error_level_magnet_temperature_left_tmp;
    guidance_board_back_error_level_magnet_temperature_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_back_error_level_magnet_temperature_left(guidance_board_back_error_level_magnet_temperature_left_tmp);
    break;
  }
  case 217 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_back_error_level_magnet_temperature_right_tmp;
    guidance_board_back_error_level_magnet_temperature_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_back_error_level_magnet_temperature_right(guidance_board_back_error_level_magnet_temperature_right_tmp);
    break;
  }
  case 218 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level guidance_board_back_error_level_mcu_temperature_tmp;
    guidance_board_back_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_guidance_board_back_error_level_mcu_temperature(guidance_board_back_error_level_mcu_temperature_tmp);
    break;
  }
  case 219 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    levitation_command levitation_command_tmp;
    levitation_command_tmp = ((levitation_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_levitation_command(levitation_command_tmp);
    break;
  }
  case 220 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    levitation_state levitation_board1_state_tmp;
    levitation_board1_state_tmp = ((levitation_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 4))));
    canzero_set_levitation_board1_state(levitation_board1_state_tmp);
    break;
  }
  case 221 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status levitation_board1_sdc_status_tmp;
    levitation_board1_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_sdc_status(levitation_board1_sdc_status_tmp);
    break;
  }
  case 222 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      levitation_board1_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      levitation_board1_config_hash_tmp_tx_fragmentation_offset += 1;
      if (levitation_board1_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    levitation_board1_config_hash_tmp_tx_fragmentation_buffer[levitation_board1_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t levitation_board1_config_hash_tmp;
    levitation_board1_config_hash_tmp = (uint64_t)levitation_board1_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(levitation_board1_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_levitation_board1_config_hash(levitation_board1_config_hash_tmp);
    break;
  }
  case 223 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_assertion_fault_tmp;
    levitation_board1_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_assertion_fault(levitation_board1_assertion_fault_tmp);
    break;
  }
  case 224 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_airgap_left_invalid_tmp;
    levitation_board1_error_airgap_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_airgap_left_invalid(levitation_board1_error_airgap_left_invalid_tmp);
    break;
  }
  case 225 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_airgap_right_invalid_tmp;
    levitation_board1_error_airgap_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_airgap_right_invalid(levitation_board1_error_airgap_right_invalid_tmp);
    break;
  }
  case 226 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_vdc_voltage_invalid_tmp;
    levitation_board1_error_vdc_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_vdc_voltage_invalid(levitation_board1_error_vdc_voltage_invalid_tmp);
    break;
  }
  case 227 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_magnet_current_left_invalid_tmp;
    levitation_board1_error_magnet_current_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_magnet_current_left_invalid(levitation_board1_error_magnet_current_left_invalid_tmp);
    break;
  }
  case 228 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_magnet_current_right_invalid_tmp;
    levitation_board1_error_magnet_current_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_magnet_current_right_invalid(levitation_board1_error_magnet_current_right_invalid_tmp);
    break;
  }
  case 229 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_magnet_temperature_left_invalid_tmp;
    levitation_board1_error_magnet_temperature_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_magnet_temperature_left_invalid(levitation_board1_error_magnet_temperature_left_invalid_tmp);
    break;
  }
  case 230 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_magnet_temperature_right_invalid_tmp;
    levitation_board1_error_magnet_temperature_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_magnet_temperature_right_invalid(levitation_board1_error_magnet_temperature_right_invalid_tmp);
    break;
  }
  case 231 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_mcu_temperature_invalid_tmp;
    levitation_board1_error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_mcu_temperature_invalid(levitation_board1_error_mcu_temperature_invalid_tmp);
    break;
  }
  case 232 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_arming_failed_tmp;
    levitation_board1_error_arming_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_arming_failed(levitation_board1_error_arming_failed_tmp);
    break;
  }
  case 233 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_precharge_failed_tmp;
    levitation_board1_error_precharge_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_precharge_failed(levitation_board1_error_precharge_failed_tmp);
    break;
  }
  case 234 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_heartbeat_miss_tmp;
    levitation_board1_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_heartbeat_miss(levitation_board1_error_heartbeat_miss_tmp);
    break;
  }
  case 235 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board1_error_level_vdc_voltage_tmp;
    levitation_board1_error_level_vdc_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board1_error_level_vdc_voltage(levitation_board1_error_level_vdc_voltage_tmp);
    break;
  }
  case 236 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board1_error_level_magnet_current_left_tmp;
    levitation_board1_error_level_magnet_current_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board1_error_level_magnet_current_left(levitation_board1_error_level_magnet_current_left_tmp);
    break;
  }
  case 237 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board1_error_level_magnet_current_right_tmp;
    levitation_board1_error_level_magnet_current_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board1_error_level_magnet_current_right(levitation_board1_error_level_magnet_current_right_tmp);
    break;
  }
  case 238 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board1_error_level_input_current_tmp;
    levitation_board1_error_level_input_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board1_error_level_input_current(levitation_board1_error_level_input_current_tmp);
    break;
  }
  case 239 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board1_error_level_magnet_temperature_left_tmp;
    levitation_board1_error_level_magnet_temperature_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board1_error_level_magnet_temperature_left(levitation_board1_error_level_magnet_temperature_left_tmp);
    break;
  }
  case 240 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board1_error_level_magnet_temperature_right_tmp;
    levitation_board1_error_level_magnet_temperature_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board1_error_level_magnet_temperature_right(levitation_board1_error_level_magnet_temperature_right_tmp);
    break;
  }
  case 241 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board1_error_level_mcu_temperature_tmp;
    levitation_board1_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board1_error_level_mcu_temperature(levitation_board1_error_level_mcu_temperature_tmp);
    break;
  }
  case 242 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    levitation_state levitation_board2_state_tmp;
    levitation_board2_state_tmp = ((levitation_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 4))));
    canzero_set_levitation_board2_state(levitation_board2_state_tmp);
    break;
  }
  case 243 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status levitation_board2_sdc_status_tmp;
    levitation_board2_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_sdc_status(levitation_board2_sdc_status_tmp);
    break;
  }
  case 244 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      levitation_board2_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      levitation_board2_config_hash_tmp_tx_fragmentation_offset += 1;
      if (levitation_board2_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    levitation_board2_config_hash_tmp_tx_fragmentation_buffer[levitation_board2_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t levitation_board2_config_hash_tmp;
    levitation_board2_config_hash_tmp = (uint64_t)levitation_board2_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(levitation_board2_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_levitation_board2_config_hash(levitation_board2_config_hash_tmp);
    break;
  }
  case 245 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_assertion_fault_tmp;
    levitation_board2_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_assertion_fault(levitation_board2_assertion_fault_tmp);
    break;
  }
  case 246 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_airgap_left_invalid_tmp;
    levitation_board2_error_airgap_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_airgap_left_invalid(levitation_board2_error_airgap_left_invalid_tmp);
    break;
  }
  case 247 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_airgap_right_invalid_tmp;
    levitation_board2_error_airgap_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_airgap_right_invalid(levitation_board2_error_airgap_right_invalid_tmp);
    break;
  }
  case 248 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_vdc_voltage_invalid_tmp;
    levitation_board2_error_vdc_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_vdc_voltage_invalid(levitation_board2_error_vdc_voltage_invalid_tmp);
    break;
  }
  case 249 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_magnet_current_left_invalid_tmp;
    levitation_board2_error_magnet_current_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_magnet_current_left_invalid(levitation_board2_error_magnet_current_left_invalid_tmp);
    break;
  }
  case 250 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_magnet_current_right_invalid_tmp;
    levitation_board2_error_magnet_current_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_magnet_current_right_invalid(levitation_board2_error_magnet_current_right_invalid_tmp);
    break;
  }
  case 251 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_magnet_temperature_left_invalid_tmp;
    levitation_board2_error_magnet_temperature_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_magnet_temperature_left_invalid(levitation_board2_error_magnet_temperature_left_invalid_tmp);
    break;
  }
  case 252 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_magnet_temperature_right_invalid_tmp;
    levitation_board2_error_magnet_temperature_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_magnet_temperature_right_invalid(levitation_board2_error_magnet_temperature_right_invalid_tmp);
    break;
  }
  case 253 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_mcu_temperature_invalid_tmp;
    levitation_board2_error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_mcu_temperature_invalid(levitation_board2_error_mcu_temperature_invalid_tmp);
    break;
  }
  case 254 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_arming_failed_tmp;
    levitation_board2_error_arming_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_arming_failed(levitation_board2_error_arming_failed_tmp);
    break;
  }
  case 255 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_precharge_failed_tmp;
    levitation_board2_error_precharge_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_precharge_failed(levitation_board2_error_precharge_failed_tmp);
    break;
  }
  case 256 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_heartbeat_miss_tmp;
    levitation_board2_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_heartbeat_miss(levitation_board2_error_heartbeat_miss_tmp);
    break;
  }
  case 257 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board2_error_level_vdc_voltage_tmp;
    levitation_board2_error_level_vdc_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board2_error_level_vdc_voltage(levitation_board2_error_level_vdc_voltage_tmp);
    break;
  }
  case 258 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board2_error_level_magnet_current_left_tmp;
    levitation_board2_error_level_magnet_current_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board2_error_level_magnet_current_left(levitation_board2_error_level_magnet_current_left_tmp);
    break;
  }
  case 259 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board2_error_level_magnet_current_right_tmp;
    levitation_board2_error_level_magnet_current_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board2_error_level_magnet_current_right(levitation_board2_error_level_magnet_current_right_tmp);
    break;
  }
  case 260 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board2_error_level_input_current_tmp;
    levitation_board2_error_level_input_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board2_error_level_input_current(levitation_board2_error_level_input_current_tmp);
    break;
  }
  case 261 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board2_error_level_magnet_temperature_left_tmp;
    levitation_board2_error_level_magnet_temperature_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board2_error_level_magnet_temperature_left(levitation_board2_error_level_magnet_temperature_left_tmp);
    break;
  }
  case 262 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board2_error_level_magnet_temperature_right_tmp;
    levitation_board2_error_level_magnet_temperature_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board2_error_level_magnet_temperature_right(levitation_board2_error_level_magnet_temperature_right_tmp);
    break;
  }
  case 263 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board2_error_level_mcu_temperature_tmp;
    levitation_board2_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board2_error_level_mcu_temperature(levitation_board2_error_level_mcu_temperature_tmp);
    break;
  }
  case 264 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    levitation_state levitation_board3_state_tmp;
    levitation_board3_state_tmp = ((levitation_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 4))));
    canzero_set_levitation_board3_state(levitation_board3_state_tmp);
    break;
  }
  case 265 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status levitation_board3_sdc_status_tmp;
    levitation_board3_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_sdc_status(levitation_board3_sdc_status_tmp);
    break;
  }
  case 266 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      levitation_board3_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      levitation_board3_config_hash_tmp_tx_fragmentation_offset += 1;
      if (levitation_board3_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    levitation_board3_config_hash_tmp_tx_fragmentation_buffer[levitation_board3_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t levitation_board3_config_hash_tmp;
    levitation_board3_config_hash_tmp = (uint64_t)levitation_board3_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(levitation_board3_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_levitation_board3_config_hash(levitation_board3_config_hash_tmp);
    break;
  }
  case 267 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_assertion_fault_tmp;
    levitation_board3_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_assertion_fault(levitation_board3_assertion_fault_tmp);
    break;
  }
  case 268 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_airgap_left_invalid_tmp;
    levitation_board3_error_airgap_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_airgap_left_invalid(levitation_board3_error_airgap_left_invalid_tmp);
    break;
  }
  case 269 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_airgap_right_invalid_tmp;
    levitation_board3_error_airgap_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_airgap_right_invalid(levitation_board3_error_airgap_right_invalid_tmp);
    break;
  }
  case 270 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_vdc_voltage_invalid_tmp;
    levitation_board3_error_vdc_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_vdc_voltage_invalid(levitation_board3_error_vdc_voltage_invalid_tmp);
    break;
  }
  case 271 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_magnet_current_left_invalid_tmp;
    levitation_board3_error_magnet_current_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_magnet_current_left_invalid(levitation_board3_error_magnet_current_left_invalid_tmp);
    break;
  }
  case 272 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_magnet_current_right_invalid_tmp;
    levitation_board3_error_magnet_current_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_magnet_current_right_invalid(levitation_board3_error_magnet_current_right_invalid_tmp);
    break;
  }
  case 273 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_magnet_temperature_left_invalid_tmp;
    levitation_board3_error_magnet_temperature_left_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_magnet_temperature_left_invalid(levitation_board3_error_magnet_temperature_left_invalid_tmp);
    break;
  }
  case 274 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_magnet_temperature_right_invalid_tmp;
    levitation_board3_error_magnet_temperature_right_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_magnet_temperature_right_invalid(levitation_board3_error_magnet_temperature_right_invalid_tmp);
    break;
  }
  case 275 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_mcu_temperature_invalid_tmp;
    levitation_board3_error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_mcu_temperature_invalid(levitation_board3_error_mcu_temperature_invalid_tmp);
    break;
  }
  case 276 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_arming_failed_tmp;
    levitation_board3_error_arming_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_arming_failed(levitation_board3_error_arming_failed_tmp);
    break;
  }
  case 277 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_precharge_failed_tmp;
    levitation_board3_error_precharge_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_precharge_failed(levitation_board3_error_precharge_failed_tmp);
    break;
  }
  case 278 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_heartbeat_miss_tmp;
    levitation_board3_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_heartbeat_miss(levitation_board3_error_heartbeat_miss_tmp);
    break;
  }
  case 279 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board3_error_level_vdc_voltage_tmp;
    levitation_board3_error_level_vdc_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board3_error_level_vdc_voltage(levitation_board3_error_level_vdc_voltage_tmp);
    break;
  }
  case 280 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board3_error_level_magnet_current_left_tmp;
    levitation_board3_error_level_magnet_current_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board3_error_level_magnet_current_left(levitation_board3_error_level_magnet_current_left_tmp);
    break;
  }
  case 281 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board3_error_level_magnet_current_right_tmp;
    levitation_board3_error_level_magnet_current_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board3_error_level_magnet_current_right(levitation_board3_error_level_magnet_current_right_tmp);
    break;
  }
  case 282 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board3_error_level_input_current_tmp;
    levitation_board3_error_level_input_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board3_error_level_input_current(levitation_board3_error_level_input_current_tmp);
    break;
  }
  case 283 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board3_error_level_magnet_temperature_left_tmp;
    levitation_board3_error_level_magnet_temperature_left_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board3_error_level_magnet_temperature_left(levitation_board3_error_level_magnet_temperature_left_tmp);
    break;
  }
  case 284 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board3_error_level_magnet_temperature_right_tmp;
    levitation_board3_error_level_magnet_temperature_right_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board3_error_level_magnet_temperature_right(levitation_board3_error_level_magnet_temperature_right_tmp);
    break;
  }
  case 285 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level levitation_board3_error_level_mcu_temperature_tmp;
    levitation_board3_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_levitation_board3_error_level_mcu_temperature(levitation_board3_error_level_mcu_temperature_tmp);
    break;
  }
  case 286 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    pdu_12v_state power_board12_state_tmp;
    power_board12_state_tmp = ((pdu_12v_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_power_board12_state(power_board12_state_tmp);
    break;
  }
  case 287 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    pdu_12v_command power_board12_command_tmp;
    power_board12_command_tmp = ((pdu_12v_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_power_board12_command(power_board12_command_tmp);
    break;
  }
  case 288 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status power_board12_sdc_status_tmp;
    power_board12_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board12_sdc_status(power_board12_sdc_status_tmp);
    break;
  }
  case 289 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      power_board12_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      power_board12_config_hash_tmp_tx_fragmentation_offset += 1;
      if (power_board12_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    power_board12_config_hash_tmp_tx_fragmentation_buffer[power_board12_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t power_board12_config_hash_tmp;
    power_board12_config_hash_tmp = (uint64_t)power_board12_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(power_board12_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_power_board12_config_hash(power_board12_config_hash_tmp);
    break;
  }
  case 290 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag power_board12_assertion_fault_tmp;
    power_board12_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board12_assertion_fault(power_board12_assertion_fault_tmp);
    break;
  }
  case 291 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag power_board12_error_any_short_tmp;
    power_board12_error_any_short_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board12_error_any_short(power_board12_error_any_short_tmp);
    break;
  }
  case 292 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag power_board12_error_heartbeat_miss_tmp;
    power_board12_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board12_error_heartbeat_miss(power_board12_error_heartbeat_miss_tmp);
    break;
  }
  case 293 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level power_board12_error_level_mcu_temperature_tmp;
    power_board12_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_power_board12_error_level_mcu_temperature(power_board12_error_level_mcu_temperature_tmp);
    break;
  }
  case 294 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    pdu_24v_state power_board24_state_tmp;
    power_board24_state_tmp = ((pdu_24v_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_power_board24_state(power_board24_state_tmp);
    break;
  }
  case 295 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    pdu_24v_command power_board24_command_tmp;
    power_board24_command_tmp = ((pdu_24v_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_power_board24_command(power_board24_command_tmp);
    break;
  }
  case 296 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status power_board24_sdc_status_tmp;
    power_board24_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board24_sdc_status(power_board24_sdc_status_tmp);
    break;
  }
  case 297 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t power_board24_cooling_pump_channel_ctrl_tmp;
    power_board24_cooling_pump_channel_ctrl_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board24_cooling_pump_channel_ctrl(power_board24_cooling_pump_channel_ctrl_tmp);
    break;
  }
  case 298 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      power_board24_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      power_board24_config_hash_tmp_tx_fragmentation_offset += 1;
      if (power_board24_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    power_board24_config_hash_tmp_tx_fragmentation_buffer[power_board24_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t power_board24_config_hash_tmp;
    power_board24_config_hash_tmp = (uint64_t)power_board24_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(power_board24_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_power_board24_config_hash(power_board24_config_hash_tmp);
    break;
  }
  case 299 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag power_board24_assertion_fault_tmp;
    power_board24_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board24_assertion_fault(power_board24_assertion_fault_tmp);
    break;
  }
  case 300 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag power_board24_error_any_short_tmp;
    power_board24_error_any_short_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board24_error_any_short(power_board24_error_any_short_tmp);
    break;
  }
  case 301 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag power_board24_error_heartbeat_miss_tmp;
    power_board24_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_power_board24_error_heartbeat_miss(power_board24_error_heartbeat_miss_tmp);
    break;
  }
  case 302 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level power_board24_error_level_mcu_temperature_tmp;
    power_board24_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_power_board24_error_level_mcu_temperature(power_board24_error_level_mcu_temperature_tmp);
    break;
  }
  case 303 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    led_board_state led_board_state_tmp;
    led_board_state_tmp = ((led_board_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set_led_board_state(led_board_state_tmp);
    break;
  }
  case 304 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    led_board_command led_board_command_tmp;
    led_board_command_tmp = ((led_board_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_led_board_command(led_board_command_tmp);
    break;
  }
  case 305 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status led_board_sdc_status_tmp;
    led_board_sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_led_board_sdc_status(led_board_sdc_status_tmp);
    break;
  }
  case 306 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 0) {
        return; //TODO proper error response frame!
      }
      led_board_config_hash_tmp_tx_fragmentation_offset = 0;
    }else {
      led_board_config_hash_tmp_tx_fragmentation_offset += 1;
      if (led_board_config_hash_tmp_tx_fragmentation_offset >= 2) {
        return;
      }
    }
    led_board_config_hash_tmp_tx_fragmentation_buffer[led_board_config_hash_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    uint64_t led_board_config_hash_tmp;
    led_board_config_hash_tmp = (uint64_t)led_board_config_hash_tmp_tx_fragmentation_buffer[0] | (((uint64_t)(led_board_config_hash_tmp_tx_fragmentation_buffer[1] & (0xFFFFFFFF >> (32 - 32)))) << 32);
    canzero_set_led_board_config_hash(led_board_config_hash_tmp);
    break;
  }
  case 307 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag led_board_assertion_fault_tmp;
    led_board_assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_led_board_assertion_fault(led_board_assertion_fault_tmp);
    break;
  }
  case 308 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag led_board_error_heartbeat_miss_tmp;
    led_board_error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_led_board_error_heartbeat_miss(led_board_error_heartbeat_miss_tmp);
    break;
  }
  case 309 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level led_board_error_level_mcu_temperature_tmp;
    led_board_error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_led_board_error_level_mcu_temperature(led_board_error_level_mcu_temperature_tmp);
    break;
  }
  case 310 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float gamepad_max_acceleration_tmp;
    gamepad_max_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.0000000023283064370807974 + 0);
    canzero_set_gamepad_max_acceleration(gamepad_max_acceleration_tmp);
    break;
  }
  case 311 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float gamepad_lt2_tmp;
    gamepad_lt2_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.00392156862745098 + 0);
    canzero_set_gamepad_lt2(gamepad_lt2_tmp);
    break;
  }
  case 312 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float gamepad_rt2_tmp;
    gamepad_rt2_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.00392156862745098 + 0);
    canzero_set_gamepad_rt2(gamepad_rt2_tmp);
    break;
  }
  case 313 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float target_airgap_tmp;
    target_airgap_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000003492459655621196 + 0);
    canzero_set_target_airgap(target_airgap_tmp);
    break;
  }
  case 314 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float airgap_transition_duration_tmp;
    airgap_transition_duration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0009155413138017853 + 0);
    canzero_set_airgap_transition_duration(airgap_transition_duration_tmp);
    break;
  }
  case 315 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    airgap_transition_mode airgap_transition_mode_tmp;
    airgap_transition_mode_tmp = ((airgap_transition_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_airgap_transition_mode(airgap_transition_mode_tmp);
    break;
  }
  case 316 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_sdc_brake_tmp;
    guidance_board_front_error_sdc_brake_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_sdc_brake(guidance_board_front_error_sdc_brake_tmp);
    break;
  }
  case 317 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_magnet_current_left_unexpected_tmp;
    guidance_board_front_error_magnet_current_left_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_magnet_current_left_unexpected(guidance_board_front_error_magnet_current_left_unexpected_tmp);
    break;
  }
  case 318 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_front_error_magnet_current_right_unexpected_tmp;
    guidance_board_front_error_magnet_current_right_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_front_error_magnet_current_right_unexpected(guidance_board_front_error_magnet_current_right_unexpected_tmp);
    break;
  }
  case 319 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_sdc_brake_tmp;
    guidance_board_back_error_sdc_brake_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_sdc_brake(guidance_board_back_error_sdc_brake_tmp);
    break;
  }
  case 320 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_magnet_current_left_unexpected_tmp;
    guidance_board_back_error_magnet_current_left_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_magnet_current_left_unexpected(guidance_board_back_error_magnet_current_left_unexpected_tmp);
    break;
  }
  case 321 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag guidance_board_back_error_magnet_current_right_unexpected_tmp;
    guidance_board_back_error_magnet_current_right_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_guidance_board_back_error_magnet_current_right_unexpected(guidance_board_back_error_magnet_current_right_unexpected_tmp);
    break;
  }
  case 322 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_sdc_brake_tmp;
    levitation_board1_error_sdc_brake_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_sdc_brake(levitation_board1_error_sdc_brake_tmp);
    break;
  }
  case 323 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_magnet_current_left_unexpected_tmp;
    levitation_board1_error_magnet_current_left_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_magnet_current_left_unexpected(levitation_board1_error_magnet_current_left_unexpected_tmp);
    break;
  }
  case 324 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board1_error_magnet_current_right_unexpected_tmp;
    levitation_board1_error_magnet_current_right_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board1_error_magnet_current_right_unexpected(levitation_board1_error_magnet_current_right_unexpected_tmp);
    break;
  }
  case 325 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_sdc_brake_tmp;
    levitation_board2_error_sdc_brake_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_sdc_brake(levitation_board2_error_sdc_brake_tmp);
    break;
  }
  case 326 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_magnet_current_left_unexpected_tmp;
    levitation_board2_error_magnet_current_left_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_magnet_current_left_unexpected(levitation_board2_error_magnet_current_left_unexpected_tmp);
    break;
  }
  case 327 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board2_error_magnet_current_right_unexpected_tmp;
    levitation_board2_error_magnet_current_right_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board2_error_magnet_current_right_unexpected(levitation_board2_error_magnet_current_right_unexpected_tmp);
    break;
  }
  case 328 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_sdc_brake_tmp;
    levitation_board3_error_sdc_brake_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_sdc_brake(levitation_board3_error_sdc_brake_tmp);
    break;
  }
  case 329 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_magnet_current_left_unexpected_tmp;
    levitation_board3_error_magnet_current_left_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_magnet_current_left_unexpected(levitation_board3_error_magnet_current_left_unexpected_tmp);
    break;
  }
  case 330 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag levitation_board3_error_magnet_current_right_unexpected_tmp;
    levitation_board3_error_magnet_current_right_unexpected_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_levitation_board3_error_magnet_current_right_unexpected(levitation_board3_error_magnet_current_right_unexpected_tmp);
    break;
  }
  case 331 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_config_consistency_tmp;
    error_level_config_consistency_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_config_consistency(error_level_config_consistency_tmp);
    break;
  }
  case 332 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_any_tmp;
    error_any_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_any(error_any_tmp);
    break;
  }
  case 333 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_over_temperature_system_tmp;
    error_level_over_temperature_system_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_over_temperature_system(error_level_over_temperature_system_tmp);
    break;
  }
  default:
    return;
  }
  resp.m_header.m_od_index = msg.m_header.m_od_index;
  resp.m_header.m_client_id = msg.m_header.m_client_id;
  resp.m_header.m_server_id = msg.m_header.m_server_id;
  resp.m_header.m_erno = set_resp_erno_Success;
  canzero_frame resp_frame;
  canzero_serialize_canzero_message_set_resp(&resp, &resp_frame);
  canzero_can1_send(&resp_frame);

}
static void canzero_handle_motor_driver_stream_state(canzero_frame* frame) {
  canzero_message_motor_driver_stream_state msg;
  canzero_deserialize_canzero_message_motor_driver_stream_state(frame, &msg);
  canzero_set_motor_driver_state(msg.m_state);
  canzero_set_motor_driver_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_motor_driver_stream_config_hash(canzero_frame* frame) {
  canzero_message_motor_driver_stream_config_hash msg;
  canzero_deserialize_canzero_message_motor_driver_stream_config_hash(frame, &msg);
  canzero_set_motor_driver_config_hash(msg.m_config_hash);
}
static void canzero_handle_motor_driver_stream_errors(canzero_frame* frame) {
  canzero_message_motor_driver_stream_errors msg;
  canzero_deserialize_canzero_message_motor_driver_stream_errors(frame, &msg);
  canzero_set_motor_driver_assertion_fault(msg.m_assertion_fault);
  canzero_set_motor_driver_error_arming_failed(msg.m_error_arming_failed);
  canzero_set_motor_driver_error_precharge_failed(msg.m_error_precharge_failed);
  canzero_set_motor_driver_error_acceleration_out_of_range(msg.m_error_acceleration_out_of_range);
  canzero_set_motor_driver_error_acceleration_calibration_failed(msg.m_error_acceleration_calibration_failed);
  canzero_set_motor_driver_error_invalid_target_acceleration(msg.m_error_invalid_target_acceleration);
  canzero_set_motor_driver_error_vdc_voltage_invalid(msg.m_error_vdc_voltage_invalid);
  canzero_set_motor_driver_error_board_temperature1_invalid(msg.m_error_board_temperature1_invalid);
  canzero_set_motor_driver_error_board_temperature2_invalid(msg.m_error_board_temperature2_invalid);
  canzero_set_motor_driver_error_board_temperature3_invalid(msg.m_error_board_temperature3_invalid);
  canzero_set_motor_driver_error_mcu_temperature_invalid(msg.m_error_mcu_temperature_invalid);
  canzero_set_motor_driver_error_lim_temperature1_invalid(msg.m_error_lim_temperature1_invalid);
  canzero_set_motor_driver_error_lim_temperature2_invalid(msg.m_error_lim_temperature2_invalid);
  canzero_set_motor_driver_error_lim_temperature3_invalid(msg.m_error_lim_temperature3_invalid);
  canzero_set_motor_driver_error_lim_temperature4_invalid(msg.m_error_lim_temperature4_invalid);
  canzero_set_motor_driver_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_motor_driver_error_phase_current_unexpected(msg.m_error_phase_current_unexpected);
  canzero_set_motor_driver_error_sdc_brake(msg.m_error_sdc_brake);
  canzero_set_motor_driver_error_level_current_u1(msg.m_error_level_current_u1);
  canzero_set_motor_driver_error_level_current_v1(msg.m_error_level_current_v1);
  canzero_set_motor_driver_error_level_current_w1(msg.m_error_level_current_w1);
  canzero_set_motor_driver_error_level_current_u2(msg.m_error_level_current_u2);
  canzero_set_motor_driver_error_level_current_v2(msg.m_error_level_current_v2);
  canzero_set_motor_driver_error_level_current_w2(msg.m_error_level_current_w2);
  canzero_set_motor_driver_error_level_vdc_voltage(msg.m_error_level_vdc_voltage);
  canzero_set_motor_driver_error_level_board_temperature(msg.m_error_level_board_temperature);
  canzero_set_motor_driver_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
  canzero_set_motor_driver_error_level_lim_temperature(msg.m_error_level_lim_temperature);
  canzero_set_motor_driver_phase_current_unexpected(msg.m_phase_current_unexpected);
}
static void canzero_handle_guidance_board_front_stream_state(canzero_frame* frame) {
  canzero_message_guidance_board_front_stream_state msg;
  canzero_deserialize_canzero_message_guidance_board_front_stream_state(frame, &msg);
  canzero_set_guidance_board_front_state(msg.m_state);
  canzero_set_guidance_board_front_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_guidance_board_front_stream_config_hash(canzero_frame* frame) {
  canzero_message_guidance_board_front_stream_config_hash msg;
  canzero_deserialize_canzero_message_guidance_board_front_stream_config_hash(frame, &msg);
  canzero_set_guidance_board_front_config_hash(msg.m_config_hash);
}
static void canzero_handle_guidance_board_front_stream_errors(canzero_frame* frame) {
  canzero_message_guidance_board_front_stream_errors msg;
  canzero_deserialize_canzero_message_guidance_board_front_stream_errors(frame, &msg);
  canzero_set_guidance_board_front_assertion_fault(msg.m_assertion_fault);
  canzero_set_guidance_board_front_error_arming_failed(msg.m_error_arming_failed);
  canzero_set_guidance_board_front_error_precharge_failed(msg.m_error_precharge_failed);
  canzero_set_guidance_board_front_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_guidance_board_front_error_outer_airgap_left_invalid(msg.m_error_outer_airgap_left_invalid);
  canzero_set_guidance_board_front_error_inner_airgap_left_invalid(msg.m_error_inner_airgap_left_invalid);
  canzero_set_guidance_board_front_error_outer_airgap_right_invalid(msg.m_error_outer_airgap_right_invalid);
  canzero_set_guidance_board_front_error_inner_airgap_right_invalid(msg.m_error_inner_airgap_right_invalid);
  canzero_set_guidance_board_front_error_vdc_voltage_invalid(msg.m_error_vdc_voltage_invalid);
  canzero_set_guidance_board_front_error_magnet_current_left_invalid(msg.m_error_magnet_current_left_invalid);
  canzero_set_guidance_board_front_error_magnet_current_right_invalid(msg.m_error_magnet_current_right_invalid);
  canzero_set_guidance_board_front_error_input_current_invalid(msg.m_error_input_current_invalid);
  canzero_set_guidance_board_front_error_magnet_temperature_left_invalid(msg.m_error_magnet_temperature_left_invalid);
  canzero_set_guidance_board_front_error_magnet_temperature_right_invalid(msg.m_error_magnet_temperature_right_invalid);
  canzero_set_guidance_board_front_error_mcu_temperature_invalid(msg.m_error_mcu_temperature_invalid);
  canzero_set_guidance_board_front_error_sdc_brake(msg.m_error_sdc_brake);
  canzero_set_guidance_board_front_error_magnet_current_left_unexpected(msg.m_error_magnet_current_left_unexpected);
  canzero_set_guidance_board_front_error_magnet_current_right_unexpected(msg.m_error_magnet_current_right_unexpected);
  canzero_set_guidance_board_front_error_level_vdc_voltage(msg.m_error_level_vdc_voltage);
  canzero_set_guidance_board_front_error_level_magnet_current_left(msg.m_error_level_magnet_current_left);
  canzero_set_guidance_board_front_error_level_magnet_current_right(msg.m_error_level_magnet_current_right);
  canzero_set_guidance_board_front_error_level_input_current(msg.m_error_level_input_current);
  canzero_set_guidance_board_front_error_level_magnet_temperature_left(msg.m_error_level_magnet_temperature_left);
  canzero_set_guidance_board_front_error_level_magnet_temperature_right(msg.m_error_level_magnet_temperature_right);
  canzero_set_guidance_board_front_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_guidance_board_back_stream_state(canzero_frame* frame) {
  canzero_message_guidance_board_back_stream_state msg;
  canzero_deserialize_canzero_message_guidance_board_back_stream_state(frame, &msg);
  canzero_set_guidance_board_back_state(msg.m_state);
  canzero_set_guidance_board_back_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_guidance_board_back_stream_config_hash(canzero_frame* frame) {
  canzero_message_guidance_board_back_stream_config_hash msg;
  canzero_deserialize_canzero_message_guidance_board_back_stream_config_hash(frame, &msg);
  canzero_set_guidance_board_back_config_hash(msg.m_config_hash);
}
static void canzero_handle_guidance_board_back_stream_errors(canzero_frame* frame) {
  canzero_message_guidance_board_back_stream_errors msg;
  canzero_deserialize_canzero_message_guidance_board_back_stream_errors(frame, &msg);
  canzero_set_guidance_board_back_assertion_fault(msg.m_assertion_fault);
  canzero_set_guidance_board_back_error_arming_failed(msg.m_error_arming_failed);
  canzero_set_guidance_board_back_error_precharge_failed(msg.m_error_precharge_failed);
  canzero_set_guidance_board_back_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_guidance_board_back_error_outer_airgap_left_invalid(msg.m_error_outer_airgap_left_invalid);
  canzero_set_guidance_board_back_error_inner_airgap_left_invalid(msg.m_error_inner_airgap_left_invalid);
  canzero_set_guidance_board_back_error_outer_airgap_right_invalid(msg.m_error_outer_airgap_right_invalid);
  canzero_set_guidance_board_back_error_inner_airgap_right_invalid(msg.m_error_inner_airgap_right_invalid);
  canzero_set_guidance_board_back_error_vdc_voltage_invalid(msg.m_error_vdc_voltage_invalid);
  canzero_set_guidance_board_back_error_magnet_current_left_invalid(msg.m_error_magnet_current_left_invalid);
  canzero_set_guidance_board_back_error_magnet_current_right_invalid(msg.m_error_magnet_current_right_invalid);
  canzero_set_guidance_board_back_error_input_current_invalid(msg.m_error_input_current_invalid);
  canzero_set_guidance_board_back_error_magnet_temperature_left_invalid(msg.m_error_magnet_temperature_left_invalid);
  canzero_set_guidance_board_back_error_magnet_temperature_right_invalid(msg.m_error_magnet_temperature_right_invalid);
  canzero_set_guidance_board_back_error_mcu_temperature_invalid(msg.m_error_mcu_temperature_invalid);
  canzero_set_guidance_board_back_error_sdc_brake(msg.m_error_sdc_brake);
  canzero_set_guidance_board_back_error_magnet_current_left_unexpected(msg.m_error_magnet_current_left_unexpected);
  canzero_set_guidance_board_back_error_magnet_current_right_unexpected(msg.m_error_magnet_current_right_unexpected);
  canzero_set_guidance_board_back_error_level_vdc_voltage(msg.m_error_level_vdc_voltage);
  canzero_set_guidance_board_back_error_level_magnet_current_left(msg.m_error_level_magnet_current_left);
  canzero_set_guidance_board_back_error_level_magnet_current_right(msg.m_error_level_magnet_current_right);
  canzero_set_guidance_board_back_error_level_input_current(msg.m_error_level_input_current);
  canzero_set_guidance_board_back_error_level_magnet_temperature_left(msg.m_error_level_magnet_temperature_left);
  canzero_set_guidance_board_back_error_level_magnet_temperature_right(msg.m_error_level_magnet_temperature_right);
  canzero_set_guidance_board_back_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_levitation_board1_stream_state(canzero_frame* frame) {
  canzero_message_levitation_board1_stream_state msg;
  canzero_deserialize_canzero_message_levitation_board1_stream_state(frame, &msg);
  canzero_set_levitation_board1_state(msg.m_state);
  canzero_set_levitation_board1_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_levitation_board1_stream_config_hash(canzero_frame* frame) {
  canzero_message_levitation_board1_stream_config_hash msg;
  canzero_deserialize_canzero_message_levitation_board1_stream_config_hash(frame, &msg);
  canzero_set_levitation_board1_config_hash(msg.m_config_hash);
}
static void canzero_handle_levitation_board1_stream_errors(canzero_frame* frame) {
  canzero_message_levitation_board1_stream_errors msg;
  canzero_deserialize_canzero_message_levitation_board1_stream_errors(frame, &msg);
  canzero_set_levitation_board1_assertion_fault(msg.m_assertion_fault);
  canzero_set_levitation_board1_error_airgap_left_invalid(msg.m_error_airgap_left_invalid);
  canzero_set_levitation_board1_error_airgap_right_invalid(msg.m_error_airgap_right_invalid);
  canzero_set_levitation_board1_error_vdc_voltage_invalid(msg.m_error_vdc_voltage_invalid);
  canzero_set_levitation_board1_error_magnet_current_left_invalid(msg.m_error_magnet_current_left_invalid);
  canzero_set_levitation_board1_error_magnet_current_right_invalid(msg.m_error_magnet_current_right_invalid);
  canzero_set_levitation_board1_error_magnet_temperature_left_invalid(msg.m_error_magnet_temperature_left_invalid);
  canzero_set_levitation_board1_error_magnet_temperature_right_invalid(msg.m_error_magnet_temperature_right_invalid);
  canzero_set_levitation_board1_error_mcu_temperature_invalid(msg.m_error_mcu_temperature_invalid);
  canzero_set_levitation_board1_error_arming_failed(msg.m_error_arming_failed);
  canzero_set_levitation_board1_error_precharge_failed(msg.m_error_precharge_failed);
  canzero_set_levitation_board1_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_levitation_board1_error_sdc_brake(msg.m_error_sdc_brake);
  canzero_set_levitation_board1_error_magnet_current_left_unexpected(msg.m_error_magnet_current_left_unexpected);
  canzero_set_levitation_board1_error_magnet_current_right_unexpected(msg.m_error_magnet_current_right_unexpected);
  canzero_set_levitation_board1_error_level_vdc_voltage(msg.m_error_level_vdc_voltage);
  canzero_set_levitation_board1_error_level_magnet_current_left(msg.m_error_level_magnet_current_left);
  canzero_set_levitation_board1_error_level_magnet_current_right(msg.m_error_level_magnet_current_right);
  canzero_set_levitation_board1_error_level_input_current(msg.m_error_level_input_current);
  canzero_set_levitation_board1_error_level_magnet_temperature_left(msg.m_error_level_magnet_temperature_left);
  canzero_set_levitation_board1_error_level_magnet_temperature_right(msg.m_error_level_magnet_temperature_right);
  canzero_set_levitation_board1_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_levitation_board2_stream_state(canzero_frame* frame) {
  canzero_message_levitation_board2_stream_state msg;
  canzero_deserialize_canzero_message_levitation_board2_stream_state(frame, &msg);
  canzero_set_levitation_board2_state(msg.m_state);
  canzero_set_levitation_board2_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_levitation_board2_stream_config_hash(canzero_frame* frame) {
  canzero_message_levitation_board2_stream_config_hash msg;
  canzero_deserialize_canzero_message_levitation_board2_stream_config_hash(frame, &msg);
  canzero_set_levitation_board2_config_hash(msg.m_config_hash);
}
static void canzero_handle_levitation_board2_stream_errors(canzero_frame* frame) {
  canzero_message_levitation_board2_stream_errors msg;
  canzero_deserialize_canzero_message_levitation_board2_stream_errors(frame, &msg);
  canzero_set_levitation_board2_assertion_fault(msg.m_assertion_fault);
  canzero_set_levitation_board2_error_airgap_left_invalid(msg.m_error_airgap_left_invalid);
  canzero_set_levitation_board2_error_airgap_right_invalid(msg.m_error_airgap_right_invalid);
  canzero_set_levitation_board2_error_vdc_voltage_invalid(msg.m_error_vdc_voltage_invalid);
  canzero_set_levitation_board2_error_magnet_current_left_invalid(msg.m_error_magnet_current_left_invalid);
  canzero_set_levitation_board2_error_magnet_current_right_invalid(msg.m_error_magnet_current_right_invalid);
  canzero_set_levitation_board2_error_magnet_temperature_left_invalid(msg.m_error_magnet_temperature_left_invalid);
  canzero_set_levitation_board2_error_magnet_temperature_right_invalid(msg.m_error_magnet_temperature_right_invalid);
  canzero_set_levitation_board2_error_mcu_temperature_invalid(msg.m_error_mcu_temperature_invalid);
  canzero_set_levitation_board2_error_arming_failed(msg.m_error_arming_failed);
  canzero_set_levitation_board2_error_precharge_failed(msg.m_error_precharge_failed);
  canzero_set_levitation_board2_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_levitation_board2_error_sdc_brake(msg.m_error_sdc_brake);
  canzero_set_levitation_board2_error_magnet_current_left_unexpected(msg.m_error_magnet_current_left_unexpected);
  canzero_set_levitation_board2_error_magnet_current_right_unexpected(msg.m_error_magnet_current_right_unexpected);
  canzero_set_levitation_board2_error_level_vdc_voltage(msg.m_error_level_vdc_voltage);
  canzero_set_levitation_board2_error_level_magnet_current_left(msg.m_error_level_magnet_current_left);
  canzero_set_levitation_board2_error_level_magnet_current_right(msg.m_error_level_magnet_current_right);
  canzero_set_levitation_board2_error_level_input_current(msg.m_error_level_input_current);
  canzero_set_levitation_board2_error_level_magnet_temperature_left(msg.m_error_level_magnet_temperature_left);
  canzero_set_levitation_board2_error_level_magnet_temperature_right(msg.m_error_level_magnet_temperature_right);
  canzero_set_levitation_board2_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_levitation_board3_stream_state(canzero_frame* frame) {
  canzero_message_levitation_board3_stream_state msg;
  canzero_deserialize_canzero_message_levitation_board3_stream_state(frame, &msg);
  canzero_set_levitation_board3_state(msg.m_state);
  canzero_set_levitation_board3_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_levitation_board3_stream_config_hash(canzero_frame* frame) {
  canzero_message_levitation_board3_stream_config_hash msg;
  canzero_deserialize_canzero_message_levitation_board3_stream_config_hash(frame, &msg);
  canzero_set_levitation_board3_config_hash(msg.m_config_hash);
}
static void canzero_handle_levitation_board3_stream_errors(canzero_frame* frame) {
  canzero_message_levitation_board3_stream_errors msg;
  canzero_deserialize_canzero_message_levitation_board3_stream_errors(frame, &msg);
  canzero_set_levitation_board3_assertion_fault(msg.m_assertion_fault);
  canzero_set_levitation_board3_error_airgap_left_invalid(msg.m_error_airgap_left_invalid);
  canzero_set_levitation_board3_error_airgap_right_invalid(msg.m_error_airgap_right_invalid);
  canzero_set_levitation_board3_error_vdc_voltage_invalid(msg.m_error_vdc_voltage_invalid);
  canzero_set_levitation_board3_error_magnet_current_left_invalid(msg.m_error_magnet_current_left_invalid);
  canzero_set_levitation_board3_error_magnet_current_right_invalid(msg.m_error_magnet_current_right_invalid);
  canzero_set_levitation_board3_error_magnet_temperature_left_invalid(msg.m_error_magnet_temperature_left_invalid);
  canzero_set_levitation_board3_error_magnet_temperature_right_invalid(msg.m_error_magnet_temperature_right_invalid);
  canzero_set_levitation_board3_error_mcu_temperature_invalid(msg.m_error_mcu_temperature_invalid);
  canzero_set_levitation_board3_error_arming_failed(msg.m_error_arming_failed);
  canzero_set_levitation_board3_error_precharge_failed(msg.m_error_precharge_failed);
  canzero_set_levitation_board3_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_levitation_board3_error_sdc_brake(msg.m_error_sdc_brake);
  canzero_set_levitation_board3_error_magnet_current_left_unexpected(msg.m_error_magnet_current_left_unexpected);
  canzero_set_levitation_board3_error_magnet_current_right_unexpected(msg.m_error_magnet_current_right_unexpected);
  canzero_set_levitation_board3_error_level_vdc_voltage(msg.m_error_level_vdc_voltage);
  canzero_set_levitation_board3_error_level_magnet_current_left(msg.m_error_level_magnet_current_left);
  canzero_set_levitation_board3_error_level_magnet_current_right(msg.m_error_level_magnet_current_right);
  canzero_set_levitation_board3_error_level_input_current(msg.m_error_level_input_current);
  canzero_set_levitation_board3_error_level_magnet_temperature_left(msg.m_error_level_magnet_temperature_left);
  canzero_set_levitation_board3_error_level_magnet_temperature_right(msg.m_error_level_magnet_temperature_right);
  canzero_set_levitation_board3_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_power_board12_stream_state(canzero_frame* frame) {
  canzero_message_power_board12_stream_state msg;
  canzero_deserialize_canzero_message_power_board12_stream_state(frame, &msg);
  canzero_set_power_board12_state(msg.m_state);
  canzero_set_power_board12_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_power_board12_stream_config_hash(canzero_frame* frame) {
  canzero_message_power_board12_stream_config_hash msg;
  canzero_deserialize_canzero_message_power_board12_stream_config_hash(frame, &msg);
  canzero_set_power_board12_config_hash(msg.m_config_hash);
}
static void canzero_handle_power_board12_stream_errors(canzero_frame* frame) {
  canzero_message_power_board12_stream_errors msg;
  canzero_deserialize_canzero_message_power_board12_stream_errors(frame, &msg);
  canzero_set_power_board12_assertion_fault(msg.m_assertion_fault);
  canzero_set_power_board12_error_any_short(msg.m_error_any_short);
  canzero_set_power_board12_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_power_board12_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_power_board24_stream_state(canzero_frame* frame) {
  canzero_message_power_board24_stream_state msg;
  canzero_deserialize_canzero_message_power_board24_stream_state(frame, &msg);
  canzero_set_power_board24_state(msg.m_state);
  canzero_set_power_board24_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_power_board24_stream_config_hash(canzero_frame* frame) {
  canzero_message_power_board24_stream_config_hash msg;
  canzero_deserialize_canzero_message_power_board24_stream_config_hash(frame, &msg);
  canzero_set_power_board24_config_hash(msg.m_config_hash);
}
static void canzero_handle_power_board24_stream_errors(canzero_frame* frame) {
  canzero_message_power_board24_stream_errors msg;
  canzero_deserialize_canzero_message_power_board24_stream_errors(frame, &msg);
  canzero_set_power_board24_assertion_fault(msg.m_assertion_fault);
  canzero_set_power_board24_error_any_short(msg.m_error_any_short);
  canzero_set_power_board24_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_power_board24_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_led_board_stream_state(canzero_frame* frame) {
  canzero_message_led_board_stream_state msg;
  canzero_deserialize_canzero_message_led_board_stream_state(frame, &msg);
  canzero_set_led_board_state(msg.m_state);
  canzero_set_led_board_sdc_status(msg.m_sdc_status);
}
static void canzero_handle_led_board_stream_config_hash(canzero_frame* frame) {
  canzero_message_led_board_stream_config_hash msg;
  canzero_deserialize_canzero_message_led_board_stream_config_hash(frame, &msg);
  canzero_set_led_board_config_hash(msg.m_config_hash);
}
static void canzero_handle_led_board_stream_errors(canzero_frame* frame) {
  canzero_message_led_board_stream_errors msg;
  canzero_deserialize_canzero_message_led_board_stream_errors(frame, &msg);
  canzero_set_led_board_assertion_fault(msg.m_assertion_fault);
  canzero_set_led_board_error_heartbeat_miss(msg.m_error_heartbeat_miss);
  canzero_set_led_board_error_level_mcu_temperature(msg.m_error_level_mcu_temperature);
}
static void canzero_handle_gamepad_stream_input(canzero_frame* frame) {
  canzero_message_gamepad_stream_input msg;
  canzero_deserialize_canzero_message_gamepad_stream_input(frame, &msg);
  canzero_set_gamepad_lt2(msg.m_lt2);
  canzero_set_gamepad_rt2(msg.m_rt2);
}
 void canzero_handle_heartbeat_can0(canzero_frame* frame) {
  canzero_message_heartbeat_can0 msg;
  canzero_deserialize_canzero_message_heartbeat_can0(frame, &msg);

  if (msg.m_node_id < node_id_count) {   // static heartbeat
    if (msg.m_unregister != 0) {  // unregister only unregisters this bus
      heartbeat_wdg_job.job.wdg_job.can0_static_wdg_armed[msg.m_node_id] = 0;
    } else { // register registers for all buses
      heartbeat_wdg_job.job.wdg_job.can0_static_wdg_armed[msg.m_node_id] = 1;
      heartbeat_wdg_job.job.wdg_job.can1_static_wdg_armed[msg.m_node_id] = 1;
    }
    if (heartbeat_wdg_job.job.wdg_job.can0_static_tick_countdowns[msg.m_node_id] <= 0 &&
        msg.m_ticks_next > 0) {
      canzero_can0_wdg_recovered(msg.m_node_id);
    }
    heartbeat_wdg_job.job.wdg_job.can0_static_tick_countdowns[msg.m_node_id] = msg.m_ticks_next;
  } else {  // dynamic heartbeat
    if (msg.m_unregister != 0) { // unregister only unregisters this bus
      heartbeat_wdg_job.job.wdg_job.can0_dynamic_wdg_armed[msg.m_node_id - node_id_count] = 0;
    } else { // register registers all buses
      heartbeat_wdg_job.job.wdg_job.can0_dynamic_wdg_armed[msg.m_node_id - node_id_count] = 1;
      heartbeat_wdg_job.job.wdg_job.can1_dynamic_wdg_armed[msg.m_node_id - node_id_count] = 1;
    }
    if (heartbeat_wdg_job.job.wdg_job.can0_dynamic_tick_countdowns[msg.m_node_id - node_id_count] <= 0 
        && msg.m_ticks_next > 0) {
      canzero_can0_wdg_recovered(msg.m_node_id);
    }
    heartbeat_wdg_job.job.wdg_job.can0_dynamic_tick_countdowns[msg.m_node_id - node_id_count]
      = msg.m_ticks_next;
  }
}
 void canzero_handle_heartbeat_can1(canzero_frame* frame) {
  canzero_message_heartbeat_can1 msg;
  canzero_deserialize_canzero_message_heartbeat_can1(frame, &msg);

  if (msg.m_node_id < node_id_count) {   // static heartbeat
    if (msg.m_unregister != 0) {  // unregister only unregisters this bus
      heartbeat_wdg_job.job.wdg_job.can1_static_wdg_armed[msg.m_node_id] = 0;
    } else { // register registers for all buses
      heartbeat_wdg_job.job.wdg_job.can0_static_wdg_armed[msg.m_node_id] = 1;
      heartbeat_wdg_job.job.wdg_job.can1_static_wdg_armed[msg.m_node_id] = 1;
    }
    if (heartbeat_wdg_job.job.wdg_job.can1_static_tick_countdowns[msg.m_node_id] <= 0 &&
        msg.m_ticks_next > 0) {
      canzero_can1_wdg_recovered(msg.m_node_id);
    }
    heartbeat_wdg_job.job.wdg_job.can1_static_tick_countdowns[msg.m_node_id] = msg.m_ticks_next;
  } else {  // dynamic heartbeat
    if (msg.m_unregister != 0) { // unregister only unregisters this bus
      heartbeat_wdg_job.job.wdg_job.can1_dynamic_wdg_armed[msg.m_node_id - node_id_count] = 0;
    } else { // register registers all buses
      heartbeat_wdg_job.job.wdg_job.can0_dynamic_wdg_armed[msg.m_node_id - node_id_count] = 1;
      heartbeat_wdg_job.job.wdg_job.can1_dynamic_wdg_armed[msg.m_node_id - node_id_count] = 1;
    }
    if (heartbeat_wdg_job.job.wdg_job.can1_dynamic_tick_countdowns[msg.m_node_id - node_id_count] <= 0 
        && msg.m_ticks_next > 0) {
      canzero_can1_wdg_recovered(msg.m_node_id);
    }
    heartbeat_wdg_job.job.wdg_job.can1_dynamic_tick_countdowns[msg.m_node_id - node_id_count]
      = msg.m_ticks_next;
  }
}
void canzero_can0_poll() {
  canzero_frame frame;
  while (canzero_can0_recv(&frame)) {
    switch (frame.id) {
      case 0x13E:
        canzero_handle_get_req(&frame);
        break;
      case 0x111:
        canzero_handle_motor_driver_stream_state(&frame);
        break;
      case 0xD1:
        canzero_handle_motor_driver_stream_config_hash(&frame);
        break;
      case 0xF3:
        canzero_handle_guidance_board_front_stream_state(&frame);
        break;
      case 0xD3:
        canzero_handle_guidance_board_front_stream_errors(&frame);
        break;
      case 0x53:
        canzero_handle_guidance_board_back_stream_config_hash(&frame);
        break;
      case 0xD2:
        canzero_handle_levitation_board1_stream_state(&frame);
        break;
      case 0xB2:
        canzero_handle_levitation_board1_stream_errors(&frame);
        break;
      case 0xF2:
        canzero_handle_levitation_board2_stream_config_hash(&frame);
        break;
      case 0xB1:
        canzero_handle_levitation_board3_stream_state(&frame);
        break;
      case 0x91:
        canzero_handle_levitation_board3_stream_errors(&frame);
        break;
      case 0x90:
        canzero_handle_power_board12_stream_state(&frame);
        break;
      case 0x70:
        canzero_handle_power_board12_stream_errors(&frame);
        break;
      case 0xB0:
        canzero_handle_power_board24_stream_config_hash(&frame);
        break;
      case 0x52:
        canzero_handle_led_board_stream_errors(&frame);
        break;
      case 0x5F:
        canzero_handle_gamepad_stream_input(&frame);
        break;
      case 0x16F:
        canzero_handle_heartbeat_can0(&frame);
        break;
    }
  }
}
void canzero_can1_poll() {
  canzero_frame frame;
  while (canzero_can1_recv(&frame)) {
    switch (frame.id) {
      case 0x15E:
        canzero_handle_set_req(&frame);
        break;
      case 0xF1:
        canzero_handle_motor_driver_stream_errors(&frame);
        break;
      case 0xB3:
        canzero_handle_guidance_board_front_stream_config_hash(&frame);
        break;
      case 0x93:
        canzero_handle_guidance_board_back_stream_state(&frame);
        break;
      case 0x73:
        canzero_handle_guidance_board_back_stream_errors(&frame);
        break;
      case 0x92:
        canzero_handle_levitation_board1_stream_config_hash(&frame);
        break;
      case 0x51:
        canzero_handle_levitation_board2_stream_state(&frame);
        break;
      case 0x112:
        canzero_handle_levitation_board2_stream_errors(&frame);
        break;
      case 0x71:
        canzero_handle_levitation_board3_stream_config_hash(&frame);
        break;
      case 0x50:
        canzero_handle_power_board12_stream_config_hash(&frame);
        break;
      case 0xF0:
        canzero_handle_power_board24_stream_state(&frame);
        break;
      case 0xD0:
        canzero_handle_power_board24_stream_errors(&frame);
        break;
      case 0x72:
        canzero_handle_led_board_stream_state(&frame);
        break;
      case 0x113:
        canzero_handle_led_board_stream_config_hash(&frame);
        break;
      case 0x16E:
        canzero_handle_heartbeat_can1(&frame);
        break;
    }
  }
}
uint32_t canzero_update_continue(uint32_t time){
  schedule_jobs(time);
  return scheduler_next_job_timeout();
}
#define COMPUTE_BUILD_YEAR \
    ( (__DATE__[ 7] - '0') * 1000 + \
        (__DATE__[ 8] - '0') *  100 + \
        (__DATE__[ 9] - '0') *   10 + \
        (__DATE__[10] - '0') \
    )
#define COMPUTE_BUILD_DAY \
    ( \
        ((__DATE__[4] >= '0') ? (__DATE__[4] - '0') * 10 : 0) + \
        (__DATE__[5] - '0') \
    )
#define BUILD_MONTH_IS_JAN (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_FEB (__DATE__[0] == 'F')
#define BUILD_MONTH_IS_MAR (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r')
#define BUILD_MONTH_IS_APR (__DATE__[0] == 'A' && __DATE__[1] == 'p')
#define BUILD_MONTH_IS_MAY (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y')
#define BUILD_MONTH_IS_JUN (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_JUL (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l')
#define BUILD_MONTH_IS_AUG (__DATE__[0] == 'A' && __DATE__[1] == 'u')
#define BUILD_MONTH_IS_SEP (__DATE__[0] == 'S')
#define BUILD_MONTH_IS_OCT (__DATE__[0] == 'O')
#define BUILD_MONTH_IS_NOV (__DATE__[0] == 'N')
#define BUILD_MONTH_IS_DEC (__DATE__[0] == 'D')
#define COMPUTE_BUILD_MONTH \
    ( \
        (BUILD_MONTH_IS_JAN) ?  1 : \
        (BUILD_MONTH_IS_FEB) ?  2 : \
        (BUILD_MONTH_IS_MAR) ?  3 : \
        (BUILD_MONTH_IS_APR) ?  4 : \
        (BUILD_MONTH_IS_MAY) ?  5 : \
        (BUILD_MONTH_IS_JUN) ?  6 : \
        (BUILD_MONTH_IS_JUL) ?  7 : \
        (BUILD_MONTH_IS_AUG) ?  8 : \
        (BUILD_MONTH_IS_SEP) ?  9 : \
        (BUILD_MONTH_IS_OCT) ? 10 : \
        (BUILD_MONTH_IS_NOV) ? 11 : \
        (BUILD_MONTH_IS_DEC) ? 12 : \
        /* error default */  99 \
    )
#define COMPUTE_BUILD_HOUR ((__TIME__[0] - '0') * 10 + __TIME__[1] - '0')
#define COMPUTE_BUILD_MIN  ((__TIME__[3] - '0') * 10 + __TIME__[4] - '0')
#define COMPUTE_BUILD_SEC  ((__TIME__[6] - '0') * 10 + __TIME__[7] - '0')
#define BUILD_DATE_IS_BAD (__DATE__[0] == '?')
#define BUILD_YEAR  ((BUILD_DATE_IS_BAD) ? 99 : COMPUTE_BUILD_YEAR)
#define BUILD_MONTH ((BUILD_DATE_IS_BAD) ? 99 : COMPUTE_BUILD_MONTH)
#define BUILD_DAY   ((BUILD_DATE_IS_BAD) ? 99 : COMPUTE_BUILD_DAY)
#define BUILD_TIME_IS_BAD (__TIME__[0] == '?')
#define BUILD_HOUR  ((BUILD_TIME_IS_BAD) ? 99 :  COMPUTE_BUILD_HOUR)
#define BUILD_MIN   ((BUILD_TIME_IS_BAD) ? 99 :  COMPUTE_BUILD_MIN)
#define BUILD_SEC   ((BUILD_TIME_IS_BAD) ? 99 :  COMPUTE_BUILD_SEC)
void canzero_init() {
  __oe_config_hash = 1439478898903526003ull;
  __oe_build_time = {
    .m_year = BUILD_YEAR,
    .m_month = BUILD_MONTH,
    .m_day = BUILD_DAY,
    .m_hour = BUILD_HOUR,
    .m_min = BUILD_MIN,
    .m_sec = BUILD_SEC
  };
  canzero_can0_setup(1000000, NULL, 0);
  canzero_can1_setup(1000000, NULL, 0);

  job_pool_allocator_init();
  scheduler.size = 0;
  schedule_heartbeat_job();
  schedule_heartbeat_wdg_job();
  schedule_motor_command_interval_job();
  schedule_debug_settings_interval_job();
  schedule_position_estimation_interval_job();
  schedule_linear_encoder_interval_job();
  schedule_accelerations_interval_job();
  schedule_bat24_interval_job();
  schedule_link24_interval_job();
  schedule_link45_interval_job();
  schedule_mics_temperatures_interval_job();
  schedule_bat_temperatures_interval_job();
  schedule_cooling_cycle_interval_job();
  schedule_ambient_temperatures_interval_job();
  schedule_power_consumption_interval_job();
  schedule_errors_interval_job();
  schedule_errors2_interval_job();
  schedule_errors3_interval_job();
  schedule_config_hash_interval_job();
  schedule_state_interval_job();
  schedule_guidance_command_interval_job();
  schedule_levitation_command_interval_job();
  schedule_levitation_conifg_interval_job();
  schedule_pdu_12v_command_interval_job();
  schedule_pdu_24v_command_interval_job();
  schedule_global_fsm_errors_interval_job();
  schedule_levitation_config_interval_job();

}
void canzero_set_config_hash(uint64_t value) {
  extern uint64_t __oe_config_hash;
  if (__oe_config_hash != value) {
    __oe_config_hash = value;
    if (config_hash_interval_job.climax > config_hash_interval_job.job.stream_job.last_schedule + 0) {
      config_hash_interval_job.climax = config_hash_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&config_hash_interval_job);
    }
  }
}
void canzero_set_motor_driver_command(motor_command value) {
  extern motor_command __oe_motor_driver_command;
  if (__oe_motor_driver_command != value) {
    __oe_motor_driver_command = value;
    if (motor_command_interval_job.climax > motor_command_interval_job.job.stream_job.last_schedule + 1) {
      motor_command_interval_job.climax = motor_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&motor_command_interval_job);
    }
  }
}
void canzero_set_target_acceleration(float value) {
  extern float __oe_target_acceleration;
  if (__oe_target_acceleration != value) {
    __oe_target_acceleration = value;
    if (motor_command_interval_job.climax > motor_command_interval_job.job.stream_job.last_schedule + 1) {
      motor_command_interval_job.climax = motor_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&motor_command_interval_job);
    }
  }
}
void canzero_set_ignore_45v(bool_t value) {
  extern bool_t __oe_ignore_45v;
  if (__oe_ignore_45v != value) {
    __oe_ignore_45v = value;
    if (debug_settings_interval_job.climax > debug_settings_interval_job.job.stream_job.last_schedule + 1) {
      debug_settings_interval_job.climax = debug_settings_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&debug_settings_interval_job);
    }
  }
}
void canzero_set_global_state(global_state value) {
  extern global_state __oe_global_state;
  if (__oe_global_state != value) {
    __oe_global_state = value;
    if (state_interval_job.climax > state_interval_job.job.stream_job.last_schedule + 1) {
      state_interval_job.climax = state_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&state_interval_job);
    }
  }
}
void canzero_set_global_command(global_command value) {
  extern global_command __oe_global_command;
  if (__oe_global_command != value) {
    __oe_global_command = value;
    if (state_interval_job.climax > state_interval_job.job.stream_job.last_schedule + 1) {
      state_interval_job.climax = state_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&state_interval_job);
    }
  }
}
void canzero_set_system_sdc_status(sdc_status value) {
  extern sdc_status __oe_system_sdc_status;
  if (__oe_system_sdc_status != value) {
    __oe_system_sdc_status = value;
    if (state_interval_job.climax > state_interval_job.job.stream_job.last_schedule + 1) {
      state_interval_job.climax = state_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&state_interval_job);
    }
  }
}
void canzero_set_pod_grounded(bool_t value) {
  extern bool_t __oe_pod_grounded;
  if (__oe_pod_grounded != value) {
    __oe_pod_grounded = value;
    if (motor_command_interval_job.climax > motor_command_interval_job.job.stream_job.last_schedule + 1) {
      motor_command_interval_job.climax = motor_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&motor_command_interval_job);
    }
  }
}
void canzero_set_assertion_fault(error_flag value) {
  extern error_flag __oe_assertion_fault;
  if (__oe_assertion_fault != value) {
    __oe_assertion_fault = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_heartbeat_miss(error_flag value) {
  extern error_flag __oe_error_heartbeat_miss;
  if (__oe_error_heartbeat_miss != value) {
    __oe_error_heartbeat_miss = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
    if (global_fsm_errors_interval_job.climax > global_fsm_errors_interval_job.job.stream_job.last_schedule + 0) {
      global_fsm_errors_interval_job.climax = global_fsm_errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&global_fsm_errors_interval_job);
    }
  }
}
void canzero_set_last_node_missed(uint8_t value) {
  extern uint8_t __oe_last_node_missed;
  if (__oe_last_node_missed != value) {
    __oe_last_node_missed = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
    if (global_fsm_errors_interval_job.climax > global_fsm_errors_interval_job.job.stream_job.last_schedule + 0) {
      global_fsm_errors_interval_job.climax = global_fsm_errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&global_fsm_errors_interval_job);
    }
  }
}
void canzero_set_linear_encoder_count(int16_t value) {
  extern int16_t __oe_linear_encoder_count;
  if (__oe_linear_encoder_count != value) {
    __oe_linear_encoder_count = value;
    if (linear_encoder_interval_job.climax > linear_encoder_interval_job.job.stream_job.last_schedule + 50) {
      linear_encoder_interval_job.climax = linear_encoder_interval_job.job.stream_job.last_schedule + 50;
      scheduler_promote_job(&linear_encoder_interval_job);
    }
  }
}
void canzero_set_absolute_position_known(bool_t value) {
  extern bool_t __oe_absolute_position_known;
  if (__oe_absolute_position_known != value) {
    __oe_absolute_position_known = value;
    if (linear_encoder_interval_job.climax > linear_encoder_interval_job.job.stream_job.last_schedule + 50) {
      linear_encoder_interval_job.climax = linear_encoder_interval_job.job.stream_job.last_schedule + 50;
      scheduler_promote_job(&linear_encoder_interval_job);
    }
  }
}
void canzero_set_absolute_position_offset(float value) {
  extern float __oe_absolute_position_offset;
  if (__oe_absolute_position_offset != value) {
    __oe_absolute_position_offset = value;
    if (linear_encoder_interval_job.climax > linear_encoder_interval_job.job.stream_job.last_schedule + 50) {
      linear_encoder_interval_job.climax = linear_encoder_interval_job.job.stream_job.last_schedule + 50;
      scheduler_promote_job(&linear_encoder_interval_job);
    }
  }
}
void canzero_set_error_acceleration_out_of_range(error_flag value) {
  extern error_flag __oe_error_acceleration_out_of_range;
  if (__oe_error_acceleration_out_of_range != value) {
    __oe_error_acceleration_out_of_range = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_lateral_acceleration_out_of_range(error_flag value) {
  extern error_flag __oe_error_lateral_acceleration_out_of_range;
  if (__oe_error_lateral_acceleration_out_of_range != value) {
    __oe_error_lateral_acceleration_out_of_range = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_vertical_acceleration_out_of_range(error_flag value) {
  extern error_flag __oe_error_vertical_acceleration_out_of_range;
  if (__oe_error_vertical_acceleration_out_of_range != value) {
    __oe_error_vertical_acceleration_out_of_range = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_acceleration_calibration_failed(error_flag value) {
  extern error_flag __oe_error_acceleration_calibration_failed;
  if (__oe_error_acceleration_calibration_failed != value) {
    __oe_error_acceleration_calibration_failed = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_bat24_voltage_invalid(error_flag value) {
  extern error_flag __oe_error_bat24_voltage_invalid;
  if (__oe_error_bat24_voltage_invalid != value) {
    __oe_error_bat24_voltage_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_under_voltage(error_level value) {
  extern error_level __oe_error_level_bat24_under_voltage;
  if (__oe_error_level_bat24_under_voltage != value) {
    __oe_error_level_bat24_under_voltage = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_over_voltage(error_level value) {
  extern error_level __oe_error_level_bat24_over_voltage;
  if (__oe_error_level_bat24_over_voltage != value) {
    __oe_error_level_bat24_over_voltage = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_bat24_current_invalid(error_flag value) {
  extern error_flag __oe_error_bat24_current_invalid;
  if (__oe_error_bat24_current_invalid != value) {
    __oe_error_bat24_current_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_over_current(error_level value) {
  extern error_level __oe_error_level_bat24_over_current;
  if (__oe_error_level_bat24_over_current != value) {
    __oe_error_level_bat24_over_current = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_supercap_voltage_invalid(error_flag value) {
  extern error_flag __oe_error_supercap_voltage_invalid;
  if (__oe_error_supercap_voltage_invalid != value) {
    __oe_error_supercap_voltage_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_supercap_under_voltage(error_level value) {
  extern error_level __oe_error_level_supercap_under_voltage;
  if (__oe_error_level_supercap_under_voltage != value) {
    __oe_error_level_supercap_under_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_supercap_over_voltage(error_level value) {
  extern error_level __oe_error_level_supercap_over_voltage;
  if (__oe_error_level_supercap_over_voltage != value) {
    __oe_error_level_supercap_over_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_link24_current_invalid(error_flag value) {
  extern error_flag __oe_error_link24_current_invalid;
  if (__oe_error_link24_current_invalid != value) {
    __oe_error_link24_current_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link24_over_current(error_level value) {
  extern error_level __oe_error_level_link24_over_current;
  if (__oe_error_level_link24_over_current != value) {
    __oe_error_level_link24_over_current = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_link45_voltage_invalid(error_flag value) {
  extern error_flag __oe_error_link45_voltage_invalid;
  if (__oe_error_link45_voltage_invalid != value) {
    __oe_error_link45_voltage_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_under_voltage(error_level value) {
  extern error_level __oe_error_level_link45_under_voltage;
  if (__oe_error_level_link45_under_voltage != value) {
    __oe_error_level_link45_under_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_voltage(error_level value) {
  extern error_level __oe_error_level_link45_over_voltage;
  if (__oe_error_level_link45_over_voltage != value) {
    __oe_error_level_link45_over_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_link45_current_invalid(error_flag value) {
  extern error_flag __oe_error_link45_current_invalid;
  if (__oe_error_link45_current_invalid != value) {
    __oe_error_link45_current_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_current(error_level value) {
  extern error_level __oe_error_level_link45_over_current;
  if (__oe_error_level_link45_over_current != value) {
    __oe_error_level_link45_over_current = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_mcu_temperature_invalid(error_flag value) {
  extern error_flag __oe_error_mcu_temperature_invalid;
  if (__oe_error_mcu_temperature_invalid != value) {
    __oe_error_mcu_temperature_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_mcu_temperature(error_level value) {
  extern error_level __oe_error_level_mcu_temperature;
  if (__oe_error_level_mcu_temperature != value) {
    __oe_error_level_mcu_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_bat24_cell_temperature_1_invalid(error_flag value) {
  extern error_flag __oe_error_bat24_cell_temperature_1_invalid;
  if (__oe_error_bat24_cell_temperature_1_invalid != value) {
    __oe_error_bat24_cell_temperature_1_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_bat24_cell_temperature_2_invalid(error_flag value) {
  extern error_flag __oe_error_bat24_cell_temperature_2_invalid;
  if (__oe_error_bat24_cell_temperature_2_invalid != value) {
    __oe_error_bat24_cell_temperature_2_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_temperature(error_level value) {
  extern error_level __oe_error_level_bat24_temperature;
  if (__oe_error_level_bat24_temperature != value) {
    __oe_error_level_bat24_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_supercap_temperature_invalid(error_flag value) {
  extern error_flag __oe_error_supercap_temperature_invalid;
  if (__oe_error_supercap_temperature_invalid != value) {
    __oe_error_supercap_temperature_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_supercap_temperature(error_level value) {
  extern error_level __oe_error_level_supercap_temperature;
  if (__oe_error_level_supercap_temperature != value) {
    __oe_error_level_supercap_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_sac_ebox_temperature_invalid(error_flag value) {
  extern error_flag __oe_error_sac_ebox_temperature_invalid;
  if (__oe_error_sac_ebox_temperature_invalid != value) {
    __oe_error_sac_ebox_temperature_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_sac_ebox_temperature(error_level value) {
  extern error_level __oe_error_level_sac_ebox_temperature;
  if (__oe_error_level_sac_ebox_temperature != value) {
    __oe_error_level_sac_ebox_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_power_ebox_temperature_invalid(error_flag value) {
  extern error_flag __oe_error_power_ebox_temperature_invalid;
  if (__oe_error_power_ebox_temperature_invalid != value) {
    __oe_error_power_ebox_temperature_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_power_ebox_temperature(error_level value) {
  extern error_level __oe_error_level_power_ebox_temperature;
  if (__oe_error_level_power_ebox_temperature != value) {
    __oe_error_level_power_ebox_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_ambient_temperature_1_invalid(error_flag value) {
  extern error_flag __oe_error_ambient_temperature_1_invalid;
  if (__oe_error_ambient_temperature_1_invalid != value) {
    __oe_error_ambient_temperature_1_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_ambient_temperature_2_invalid(error_flag value) {
  extern error_flag __oe_error_ambient_temperature_2_invalid;
  if (__oe_error_ambient_temperature_2_invalid != value) {
    __oe_error_ambient_temperature_2_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_ambient_temperature_3_invalid(error_flag value) {
  extern error_flag __oe_error_ambient_temperature_3_invalid;
  if (__oe_error_ambient_temperature_3_invalid != value) {
    __oe_error_ambient_temperature_3_invalid = value;
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_ambient_temperature(error_level value) {
  extern error_level __oe_error_level_ambient_temperature;
  if (__oe_error_level_ambient_temperature != value) {
    __oe_error_level_ambient_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 1) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_cooling_flow_rate_low(error_flag value) {
  extern error_flag __oe_error_cooling_flow_rate_low;
  if (__oe_error_cooling_flow_rate_low != value) {
    __oe_error_cooling_flow_rate_low = value;
    if (errors3_interval_job.climax > errors3_interval_job.job.stream_job.last_schedule + 1) {
      errors3_interval_job.climax = errors3_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors3_interval_job);
    }
  }
}
void canzero_set_error_cooling_flow_rate_mismatch(error_flag value) {
  extern error_flag __oe_error_cooling_flow_rate_mismatch;
  if (__oe_error_cooling_flow_rate_mismatch != value) {
    __oe_error_cooling_flow_rate_mismatch = value;
    if (errors3_interval_job.climax > errors3_interval_job.job.stream_job.last_schedule + 1) {
      errors3_interval_job.climax = errors3_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors3_interval_job);
    }
  }
}
void canzero_set_error_cooling_cycle_temp_begin_invalid(error_flag value) {
  extern error_flag __oe_error_cooling_cycle_temp_begin_invalid;
  if (__oe_error_cooling_cycle_temp_begin_invalid != value) {
    __oe_error_cooling_cycle_temp_begin_invalid = value;
    if (errors3_interval_job.climax > errors3_interval_job.job.stream_job.last_schedule + 1) {
      errors3_interval_job.climax = errors3_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors3_interval_job);
    }
  }
}
void canzero_set_error_cooling_cycle_temp_end_invalid(error_flag value) {
  extern error_flag __oe_error_cooling_cycle_temp_end_invalid;
  if (__oe_error_cooling_cycle_temp_end_invalid != value) {
    __oe_error_cooling_cycle_temp_end_invalid = value;
    if (errors3_interval_job.climax > errors3_interval_job.job.stream_job.last_schedule + 1) {
      errors3_interval_job.climax = errors3_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors3_interval_job);
    }
  }
}
void canzero_set_error_level_cooling_cycle_overtemp(error_level value) {
  extern error_level __oe_error_level_cooling_cycle_overtemp;
  if (__oe_error_level_cooling_cycle_overtemp != value) {
    __oe_error_level_cooling_cycle_overtemp = value;
    if (errors3_interval_job.climax > errors3_interval_job.job.stream_job.last_schedule + 1) {
      errors3_interval_job.climax = errors3_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&errors3_interval_job);
    }
  }
}
void canzero_set_guidance_command(guidance_command value) {
  extern guidance_command __oe_guidance_command;
  if (__oe_guidance_command != value) {
    __oe_guidance_command = value;
    if (guidance_command_interval_job.climax > guidance_command_interval_job.job.stream_job.last_schedule + 1) {
      guidance_command_interval_job.climax = guidance_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&guidance_command_interval_job);
    }
  }
}
void canzero_set_levitation_command(levitation_command value) {
  extern levitation_command __oe_levitation_command;
  if (__oe_levitation_command != value) {
    __oe_levitation_command = value;
    if (levitation_command_interval_job.climax > levitation_command_interval_job.job.stream_job.last_schedule + 1) {
      levitation_command_interval_job.climax = levitation_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&levitation_command_interval_job);
    }
  }
}
void canzero_set_power_board12_command(pdu_12v_command value) {
  extern pdu_12v_command __oe_power_board12_command;
  if (__oe_power_board12_command != value) {
    __oe_power_board12_command = value;
    if (pdu_12v_command_interval_job.climax > pdu_12v_command_interval_job.job.stream_job.last_schedule + 1) {
      pdu_12v_command_interval_job.climax = pdu_12v_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&pdu_12v_command_interval_job);
    }
  }
}
void canzero_set_power_board24_command(pdu_24v_command value) {
  extern pdu_24v_command __oe_power_board24_command;
  if (__oe_power_board24_command != value) {
    __oe_power_board24_command = value;
    if (pdu_24v_command_interval_job.climax > pdu_24v_command_interval_job.job.stream_job.last_schedule + 1) {
      pdu_24v_command_interval_job.climax = pdu_24v_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&pdu_24v_command_interval_job);
    }
  }
}
void canzero_set_power_board24_cooling_pump_channel_ctrl(bool_t value) {
  extern bool_t __oe_power_board24_cooling_pump_channel_ctrl;
  if (__oe_power_board24_cooling_pump_channel_ctrl != value) {
    __oe_power_board24_cooling_pump_channel_ctrl = value;
    if (pdu_24v_command_interval_job.climax > pdu_24v_command_interval_job.job.stream_job.last_schedule + 1) {
      pdu_24v_command_interval_job.climax = pdu_24v_command_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&pdu_24v_command_interval_job);
    }
  }
}
void canzero_set_target_airgap(float value) {
  extern float __oe_target_airgap;
  if (__oe_target_airgap != value) {
    __oe_target_airgap = value;
    if (levitation_conifg_interval_job.climax > levitation_conifg_interval_job.job.stream_job.last_schedule + 1) {
      levitation_conifg_interval_job.climax = levitation_conifg_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&levitation_conifg_interval_job);
    }
    if (levitation_config_interval_job.climax > levitation_config_interval_job.job.stream_job.last_schedule + 50) {
      levitation_config_interval_job.climax = levitation_config_interval_job.job.stream_job.last_schedule + 50;
      scheduler_promote_job(&levitation_config_interval_job);
    }
  }
}
void canzero_set_airgap_transition_duration(float value) {
  extern float __oe_airgap_transition_duration;
  if (__oe_airgap_transition_duration != value) {
    __oe_airgap_transition_duration = value;
    if (levitation_conifg_interval_job.climax > levitation_conifg_interval_job.job.stream_job.last_schedule + 1) {
      levitation_conifg_interval_job.climax = levitation_conifg_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&levitation_conifg_interval_job);
    }
    if (levitation_config_interval_job.climax > levitation_config_interval_job.job.stream_job.last_schedule + 50) {
      levitation_config_interval_job.climax = levitation_config_interval_job.job.stream_job.last_schedule + 50;
      scheduler_promote_job(&levitation_config_interval_job);
    }
  }
}
void canzero_set_airgap_transition_mode(airgap_transition_mode value) {
  extern airgap_transition_mode __oe_airgap_transition_mode;
  if (__oe_airgap_transition_mode != value) {
    __oe_airgap_transition_mode = value;
    if (levitation_conifg_interval_job.climax > levitation_conifg_interval_job.job.stream_job.last_schedule + 1) {
      levitation_conifg_interval_job.climax = levitation_conifg_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&levitation_conifg_interval_job);
    }
    if (levitation_config_interval_job.climax > levitation_config_interval_job.job.stream_job.last_schedule + 50) {
      levitation_config_interval_job.climax = levitation_config_interval_job.job.stream_job.last_schedule + 50;
      scheduler_promote_job(&levitation_config_interval_job);
    }
  }
}
void canzero_set_error_level_config_consistency(error_level value) {
  extern error_level __oe_error_level_config_consistency;
  if (__oe_error_level_config_consistency != value) {
    __oe_error_level_config_consistency = value;
    if (global_fsm_errors_interval_job.climax > global_fsm_errors_interval_job.job.stream_job.last_schedule + 0) {
      global_fsm_errors_interval_job.climax = global_fsm_errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&global_fsm_errors_interval_job);
    }
  }
}
void canzero_set_error_any(error_level value) {
  extern error_level __oe_error_any;
  if (__oe_error_any != value) {
    __oe_error_any = value;
    if (global_fsm_errors_interval_job.climax > global_fsm_errors_interval_job.job.stream_job.last_schedule + 0) {
      global_fsm_errors_interval_job.climax = global_fsm_errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&global_fsm_errors_interval_job);
    }
  }
}
void canzero_set_error_level_over_temperature_system(error_level value) {
  extern error_level __oe_error_level_over_temperature_system;
  if (__oe_error_level_over_temperature_system != value) {
    __oe_error_level_over_temperature_system = value;
    if (global_fsm_errors_interval_job.climax > global_fsm_errors_interval_job.job.stream_job.last_schedule + 0) {
      global_fsm_errors_interval_job.climax = global_fsm_errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&global_fsm_errors_interval_job);
    }
  }
}
static uint32_t DMAMEM __oe_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_build_time_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_velocity_pid_send_fragmentation_buffer[6];
static uint32_t DMAMEM __oe_acceleration_calibration_variance_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_acceleration_calibration_offset_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_acceleration_calibration_target_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_lateral_acceleration_calibration_variance_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_lateral_acceleration_calibration_offset_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_lateral_acceleration_calibration_target_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_vertical_acceleration_calibration_variance_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_vertical_acceleration_calibration_offset_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_vertical_acceleration_calibration_target_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link24_over_current_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_link45_over_current_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[7];
static uint32_t DMAMEM __oe_motor_driver_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_guidance_board_front_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_guidance_board_back_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_levitation_board1_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_levitation_board2_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_levitation_board3_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_power_board12_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_power_board24_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_led_board_config_hash_send_fragmentation_buffer[2];
void canzero_send_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 0;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_config_hash_send_fragmentation_buffer, 2, 0, 255);

}
void canzero_send_build_time() {
  canzero_message_get_resp msg;
  __oe_build_time_send_fragmentation_buffer[0] = (__oe_build_time.m_year & (0xFFFFFFFF >> (32 - 16)));
  __oe_build_time_send_fragmentation_buffer[0] |= ((__oe_build_time.m_month & (0xFFFFFFFF >> (32 - 8))) << 16);
  __oe_build_time_send_fragmentation_buffer[0] |= ((__oe_build_time.m_day & (0xFFFFFFFF >> (32 - 8))) << 24);
  __oe_build_time_send_fragmentation_buffer[1] = (__oe_build_time.m_hour & (0xFFFFFFFF >> (32 - 8)));
  __oe_build_time_send_fragmentation_buffer[1] |= ((__oe_build_time.m_min & (0xFFFFFFFF >> (32 - 8))) << 8);
  __oe_build_time_send_fragmentation_buffer[1] |= ((__oe_build_time.m_sec & (0xFFFFFFFF >> (32 - 8))) << 16);

  msg.m_data = __oe_build_time_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 1;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_build_time_send_fragmentation_buffer, 2, 1, 255);

}
void canzero_send_motor_driver_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_command) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 2;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_target_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_target_acceleration - (-50)) / 0.000000023283064370807974, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 3;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_ignore_45v() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_ignore_45v) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 4;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_global_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_global_state) & (0xFF >> (8 - 5)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 5;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_global_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_global_command) & (0xFF >> (8 - 4)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 6;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_system_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_system_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 7;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_pod_grounded() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_pod_grounded) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 8;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_system_power_consumption() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_system_power_consumption - (0)) / 0.15259021896696423, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 9;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_communication_power_consumption() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_communication_power_consumption - (0)) / 0.007629510948348211, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 10;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_track_length() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_track_length - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 11;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_brake_margin() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_brake_margin - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 12;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_emergency_brake_margin() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_emergency_brake_margin - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 13;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_assert_45V_system_online() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_assert_45V_system_online) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 14;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 15;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_loop_frequency() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_loop_frequency - (0)) / 0.00000023283064370807974, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 16;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 17;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 18;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_last_node_missed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(__oe_last_node_missed & (0xFF >> (8 - 8)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 19;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_acceleration_target_velocity() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_acceleration_target_velocity - (0)) / 0.0000000023283064370807974, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 20;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_velocity_pid() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_velocity_pid.m_Kp - ((double)0)) / (double)0.0000000000000005421010862427522, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_velocity_pid_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_velocity_pid_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }  {
    uint64_t masked = (min_u64((__oe_velocity_pid.m_Ki - ((double)0)) / (double)0.0000000000000005421010862427522, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_velocity_pid_send_fragmentation_buffer[2] = ((uint32_t*)&masked)[0];
    __oe_velocity_pid_send_fragmentation_buffer[3] = ((uint32_t*)&masked)[1];
  }  {
    uint64_t masked = (min_u64((__oe_velocity_pid.m_Kd - ((double)0)) / (double)0.0000000000000005421010862427522, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_velocity_pid_send_fragmentation_buffer[4] = ((uint32_t*)&masked)[0];
    __oe_velocity_pid_send_fragmentation_buffer[5] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_velocity_pid_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 21;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_velocity_pid_send_fragmentation_buffer, 6, 21, 255);

}
void canzero_send_position() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_position - (-10)) / 0.0007629510948348211, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 22;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_velocity() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_velocity - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 23;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 24;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_linear_encoder_count() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint16_t)__oe_linear_encoder_count) & (0xFFFF >> (16 - 16)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 25;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_absolute_position_known() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_absolute_position_known) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 26;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_absolute_position_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_absolute_position_offset - (-10)) / 0.0006103608758678569, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 27;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_raw_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_raw_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 28;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_acceleration_out_of_range() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 29;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_acceleration_calibration_variance() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_acceleration_calibration_variance - ((double)-1)) / (double)0.00000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_acceleration_calibration_variance_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_acceleration_calibration_variance_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_acceleration_calibration_variance_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 30;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_variance_send_fragmentation_buffer, 2, 30, 255);

}
void canzero_send_acceleration_calibration_offset() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_acceleration_calibration_offset_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_acceleration_calibration_offset_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_acceleration_calibration_offset_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 31;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_offset_send_fragmentation_buffer, 2, 31, 255);

}
void canzero_send_acceleration_calibration_target() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_acceleration_calibration_target_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_acceleration_calibration_target_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_acceleration_calibration_target_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 32;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_target_send_fragmentation_buffer, 2, 32, 255);

}
void canzero_send_raw_lateral_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_raw_lateral_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 33;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_lateral_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_lateral_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 34;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_lateral_acceleration_out_of_range() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_lateral_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 35;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_lateral_acceleration_calibration_variance() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_variance - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_lateral_acceleration_calibration_variance_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_lateral_acceleration_calibration_variance_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_lateral_acceleration_calibration_variance_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 36;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_variance_send_fragmentation_buffer, 2, 36, 255);

}
void canzero_send_lateral_acceleration_calibration_offset() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_lateral_acceleration_calibration_offset_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_lateral_acceleration_calibration_offset_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_lateral_acceleration_calibration_offset_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 37;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_offset_send_fragmentation_buffer, 2, 37, 255);

}
void canzero_send_lateral_acceleration_calibration_target() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_lateral_acceleration_calibration_target_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_lateral_acceleration_calibration_target_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_lateral_acceleration_calibration_target_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 38;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_target_send_fragmentation_buffer, 2, 38, 255);

}
void canzero_send_raw_vertical_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_raw_vertical_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 39;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_vertical_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_vertical_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 40;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_vertical_acceleration_out_of_range() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_vertical_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 41;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_vertical_acceleration_calibration_variance() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_variance - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_vertical_acceleration_calibration_variance_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_vertical_acceleration_calibration_variance_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_vertical_acceleration_calibration_variance_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 42;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_variance_send_fragmentation_buffer, 2, 42, 255);

}
void canzero_send_vertical_acceleration_calibration_offset() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_vertical_acceleration_calibration_offset_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_vertical_acceleration_calibration_offset_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_vertical_acceleration_calibration_offset_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 43;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_offset_send_fragmentation_buffer, 2, 43, 255);

}
void canzero_send_vertical_acceleration_calibration_target() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_vertical_acceleration_calibration_target_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_vertical_acceleration_calibration_target_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_vertical_acceleration_calibration_target_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 44;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_target_send_fragmentation_buffer, 2, 44, 255);

}
void canzero_send_error_acceleration_calibration_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_calibration_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 45;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 46;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_voltage_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_bat24_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 47;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_voltage_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 48;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_voltage_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 49;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_bat24_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 50;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_bat24_under_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_under_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 51;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_bat24_under_voltage() {
  canzero_message_get_resp msg;
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[6] = (__oe_error_level_config_bat24_under_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_under_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_under_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 52;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer, 7, 52, 255);

}
void canzero_send_error_level_bat24_over_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 53;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_bat24_over_voltage() {
  canzero_message_get_resp msg;
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[6] = (__oe_error_level_config_bat24_over_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 54;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer, 7, 54, 255);

}
void canzero_send_bat24_current() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 55;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_current_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_current_calibration_offset - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 56;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_current_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_current_calibration_target - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 57;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_current_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_bat24_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 58;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_bat24_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 59;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_bat24_over_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 60;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_bat24_over_current() {
  canzero_message_get_resp msg;
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_over_current.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_over_current.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_over_current.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[6] = (__oe_error_level_config_bat24_over_current.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_current.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_over_current.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_bat24_over_current_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 61;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_current_send_fragmentation_buffer, 7, 61, 255);

}
void canzero_send_supercap_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 62;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_supercap_voltage_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_supercap_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 63;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_supercap_voltage_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 64;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_supercap_voltage_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 65;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_supercap_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_supercap_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 66;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_supercap_under_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_under_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 67;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_supercap_under_voltage() {
  canzero_message_get_resp msg;
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_supercap_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[6] = (__oe_error_level_config_supercap_under_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_under_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_under_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 68;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer, 7, 68, 255);

}
void canzero_send_error_level_supercap_over_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_over_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 69;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_supercap_over_voltage() {
  canzero_message_get_resp msg;
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_supercap_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[6] = (__oe_error_level_config_supercap_over_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_over_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_over_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 70;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer, 7, 70, 255);

}
void canzero_send_link24_current() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 71;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link24_current_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_link24_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 72;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link24_current_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link24_current_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 73;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link24_current_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link24_current_calibration_target - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 74;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_link24_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_link24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 75;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_link24_over_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_over_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 76;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_link24_over_current() {
  canzero_message_get_resp msg;
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link24_over_current.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link24_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link24_over_current.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link24_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link24_over_current.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link24_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[6] = (__oe_error_level_config_link24_over_current.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link24_over_current.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_link24_over_current_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link24_over_current.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_link24_over_current_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 77;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_current_send_fragmentation_buffer, 7, 77, 255);

}
void canzero_send_link45_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_voltage - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 78;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link45_voltage_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_link45_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 79;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link45_voltage_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_voltage_calibration_offset - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 80;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link45_voltage_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_voltage_calibration_target - (0)) / 0.00000023283064370807974, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 81;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_link45_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 82;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_link45_under_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_under_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 83;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_link45_under_voltage() {
  canzero_message_get_resp msg;
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link45_under_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link45_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link45_under_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link45_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link45_under_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link45_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[6] = (__oe_error_level_config_link45_under_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_under_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_under_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_link45_under_voltage_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 84;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_under_voltage_send_fragmentation_buffer, 7, 84, 255);

}
void canzero_send_error_level_link45_over_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 85;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_link45_over_voltage() {
  canzero_message_get_resp msg;
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link45_over_voltage.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link45_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link45_over_voltage.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link45_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link45_over_voltage.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link45_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[6] = (__oe_error_level_config_link45_over_voltage.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_voltage.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_voltage.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_link45_over_voltage_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 86;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_voltage_send_fragmentation_buffer, 7, 86, 255);

}
void canzero_send_link45_current() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_current - (-1000)) / 0.0000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 87;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link45_current_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_link45_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 88;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link45_current_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_current_calibration_offset - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 89;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_link45_current_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_current_calibration_target - (-1000)) / 0.0000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 90;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_link45_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_current_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 91;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_link45_over_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 92;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_link45_over_current() {
  canzero_message_get_resp msg;
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_link45_over_current.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_link45_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_link45_over_current.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_link45_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_link45_over_current.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_link45_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[6] = (__oe_error_level_config_link45_over_current.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_current.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_link45_over_current_send_fragmentation_buffer[6] |= ((__oe_error_level_config_link45_over_current.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_link45_over_current_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 93;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_current_send_fragmentation_buffer, 7, 93, 255);

}
void canzero_send_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_mcu_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 94;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 95;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 96;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_mcu_temperature() {
  canzero_message_get_resp msg;
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_mcu_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_mcu_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_mcu_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_mcu_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_mcu_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_mcu_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[6] = (__oe_error_level_config_mcu_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_mcu_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_mcu_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_mcu_temperature_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 97;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_mcu_temperature_send_fragmentation_buffer, 7, 97, 255);

}
void canzero_send_bat24_cell_temperature_1() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_cell_temperature_1 - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 98;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_cell_temperature_2() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_cell_temperature_2 - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 99;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_bat24_temperature_max() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_temperature_max - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 100;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_bat24_cell_temperature_1_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_cell_temperature_1_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 101;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_bat24_cell_temperature_2_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_cell_temperature_2_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 102;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_bat24_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 103;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_bat24_temperature() {
  canzero_message_get_resp msg;
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_bat24_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_bat24_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_bat24_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_bat24_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_bat24_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_bat24_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[6] = (__oe_error_level_config_bat24_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_bat24_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_bat24_temperature_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 104;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_temperature_send_fragmentation_buffer, 7, 104, 255);

}
void canzero_send_supercap_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 105;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_supercap_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_supercap_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 106;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_supercap_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 107;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_supercap_temperature() {
  canzero_message_get_resp msg;
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_supercap_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_supercap_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_supercap_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_supercap_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_supercap_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_supercap_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[6] = (__oe_error_level_config_supercap_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_supercap_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_supercap_temperature_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 108;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_temperature_send_fragmentation_buffer, 7, 108, 255);

}
void canzero_send_sac_ebox_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_sac_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 109;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_sac_ebox_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_sac_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 110;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_sac_ebox_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_sac_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 111;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_sac_ebox_temperature() {
  canzero_message_get_resp msg;
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_sac_ebox_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[6] = (__oe_error_level_config_sac_ebox_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_sac_ebox_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_sac_ebox_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 112;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer, 7, 112, 255);

}
void canzero_send_power_ebox_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_power_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 113;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_power_ebox_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_power_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 114;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_power_ebox_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_power_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 115;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_power_ebox_temperature() {
  canzero_message_get_resp msg;
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_power_ebox_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[6] = (__oe_error_level_config_power_ebox_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_power_ebox_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_power_ebox_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 116;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer, 7, 116, 255);

}
void canzero_send_ambient_temperature_1() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_ambient_temperature_1 - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 117;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_ambient_temperature_2() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_ambient_temperature_2 - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 118;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_ambient_temperature_3() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_ambient_temperature_3 - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 119;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_ambient_temperature_avg() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_ambient_temperature_avg - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 120;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_ambient_temperature_max() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_ambient_temperature_max - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 121;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_ambient_temperature_1_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_1_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 122;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_ambient_temperature_2_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_2_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 123;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_ambient_temperature_3_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_3_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 124;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_ambient_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_ambient_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 125;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_ambient_temperature() {
  canzero_message_get_resp msg;
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[0] = (min_u32((__oe_error_level_config_ambient_temperature.m_info_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[1] = (min_u32((__oe_error_level_config_ambient_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[2] = (min_u32((__oe_error_level_config_ambient_temperature.m_warning_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[3] = (min_u32((__oe_error_level_config_ambient_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[4] = (min_u32((__oe_error_level_config_ambient_temperature.m_error_thresh - ((float)-1000)) / (float)0.0000004656612874161595, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[5] = (min_u32((__oe_error_level_config_ambient_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784, 0xFFFFFFFFul) & (0xFFFFFFFF >> (32 - 32)));
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[6] = (__oe_error_level_config_ambient_temperature.m_ignore_info & (0xFFFFFFFF >> (32 - 1)));
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_ambient_temperature.m_ignore_warning & (0xFFFFFFFF >> (32 - 1))) << 1);
  __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[6] |= ((__oe_error_level_config_ambient_temperature.m_ignore_error & (0xFFFFFFFF >> (32 - 1))) << 2);

  msg.m_data = __oe_error_level_config_ambient_temperature_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 126;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_ambient_temperature_send_fragmentation_buffer, 7, 126, 255);

}
void canzero_send_cooling_flow_rate_begin() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_cooling_flow_rate_begin - (0)) / 0.006103608758678569, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 127;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_cooling_flow_rate_end() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_cooling_flow_rate_end - (0)) / 0.006103608758678569, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 128;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_cooling_flow_rate_low() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_flow_rate_low) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 129;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_cooling_flow_rate_mismatch() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_flow_rate_mismatch) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 130;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_cooling_cycle_temp_begin() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_cooling_cycle_temp_begin - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 131;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_cooling_cycle_temp_end() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_cooling_cycle_temp_end - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 132;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_cooling_cycle_temp_begin_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_cycle_temp_begin_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 133;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_cooling_cycle_temp_end_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_cooling_cycle_temp_end_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 134;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_cooling_cycle_overtemp() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_overtemp) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 135;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_state) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 136;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 137;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_motor_driver_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_motor_driver_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_motor_driver_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_motor_driver_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 138;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_motor_driver_config_hash_send_fragmentation_buffer, 2, 138, 255);

}
void canzero_send_motor_driver_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 139;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_arming_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 140;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_precharge_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 141;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_acceleration_out_of_range() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 142;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_acceleration_calibration_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_acceleration_calibration_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 143;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_invalid_target_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_invalid_target_acceleration) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 144;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_vdc_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 145;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_board_temperature1_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_board_temperature1_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 146;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_board_temperature2_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_board_temperature2_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 147;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_board_temperature3_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_board_temperature3_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 148;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 149;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_lim_temperature1_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature1_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 150;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_lim_temperature2_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature2_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 151;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_lim_temperature3_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature3_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 152;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_lim_temperature4_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_lim_temperature4_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 153;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 154;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_phase_current_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_phase_current_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 155;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_sdc_brake() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 156;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_current_u1() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_u1) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 157;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_current_v1() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_v1) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 158;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_current_w1() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_w1) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 159;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_current_u2() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_u2) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 160;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_current_v2() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_v2) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 161;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_current_w2() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_current_w2) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 162;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_vdc_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 163;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_board_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_board_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 164;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 165;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_error_level_lim_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_error_level_lim_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 166;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_motor_driver_phase_current_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_motor_driver_phase_current_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 167;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_command) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 168;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_state) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 169;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 170;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_guidance_board_front_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_guidance_board_front_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_guidance_board_front_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_guidance_board_front_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 171;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_guidance_board_front_config_hash_send_fragmentation_buffer, 2, 171, 255);

}
void canzero_send_guidance_board_front_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 172;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_arming_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 173;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_precharge_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 174;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 175;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_outer_airgap_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_outer_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 176;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_inner_airgap_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_inner_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 177;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_outer_airgap_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_outer_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 178;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_inner_airgap_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_inner_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 179;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_vdc_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 180;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_magnet_current_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 181;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_magnet_current_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 182;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_input_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_input_current_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 183;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_magnet_temperature_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 184;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_magnet_temperature_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 185;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 186;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_level_vdc_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 187;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_level_magnet_current_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 188;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_level_magnet_current_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 189;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_level_input_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 190;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_level_magnet_temperature_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 191;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_level_magnet_temperature_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 192;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 193;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_state) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 194;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 195;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_guidance_board_back_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_guidance_board_back_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_guidance_board_back_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_guidance_board_back_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 196;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_guidance_board_back_config_hash_send_fragmentation_buffer, 2, 196, 255);

}
void canzero_send_guidance_board_back_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 197;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_arming_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 198;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_precharge_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 199;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 200;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_outer_airgap_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_outer_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 201;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_inner_airgap_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_inner_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 202;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_outer_airgap_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_outer_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 203;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_inner_airgap_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_inner_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 204;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_vdc_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 205;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_magnet_current_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 206;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_magnet_current_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 207;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_input_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_input_current_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 208;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_magnet_temperature_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 209;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_magnet_temperature_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 210;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 211;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_level_vdc_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 212;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_level_magnet_current_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 213;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_level_magnet_current_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 214;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_level_input_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 215;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_level_magnet_temperature_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 216;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_level_magnet_temperature_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 217;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 218;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_command) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 219;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_state) & (0xFF >> (8 - 4)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 220;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 221;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_levitation_board1_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_levitation_board1_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_levitation_board1_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_levitation_board1_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 222;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_levitation_board1_config_hash_send_fragmentation_buffer, 2, 222, 255);

}
void canzero_send_levitation_board1_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 223;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_airgap_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 224;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_airgap_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 225;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_vdc_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 226;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_magnet_current_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 227;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_magnet_current_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 228;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_magnet_temperature_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 229;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_magnet_temperature_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 230;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 231;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_arming_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 232;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_precharge_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 233;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 234;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_level_vdc_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 235;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_level_magnet_current_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 236;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_level_magnet_current_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 237;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_level_input_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 238;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_level_magnet_temperature_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 239;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_level_magnet_temperature_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 240;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 241;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_state) & (0xFF >> (8 - 4)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 242;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 243;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_levitation_board2_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_levitation_board2_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_levitation_board2_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_levitation_board2_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 244;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_levitation_board2_config_hash_send_fragmentation_buffer, 2, 244, 255);

}
void canzero_send_levitation_board2_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 245;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_airgap_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 246;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_airgap_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 247;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_vdc_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 248;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_magnet_current_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 249;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_magnet_current_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 250;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_magnet_temperature_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 251;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_magnet_temperature_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 252;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 253;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_arming_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 254;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_precharge_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 255;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 256;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_level_vdc_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 257;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_level_magnet_current_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 258;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_level_magnet_current_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 259;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_level_input_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 260;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_level_magnet_temperature_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 261;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_level_magnet_temperature_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 262;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 263;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_state) & (0xFF >> (8 - 4)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 264;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 265;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_levitation_board3_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_levitation_board3_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_levitation_board3_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_levitation_board3_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 266;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_levitation_board3_config_hash_send_fragmentation_buffer, 2, 266, 255);

}
void canzero_send_levitation_board3_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 267;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_airgap_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_airgap_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 268;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_airgap_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_airgap_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 269;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_vdc_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_vdc_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 270;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_magnet_current_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 271;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_magnet_current_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 272;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_magnet_temperature_left_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_temperature_left_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 273;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_magnet_temperature_right_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_temperature_right_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 274;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 275;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_arming_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_arming_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 276;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_precharge_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_precharge_failed) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 277;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 278;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_level_vdc_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_vdc_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 279;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_level_magnet_current_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_current_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 280;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_level_magnet_current_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_current_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 281;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_level_input_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_input_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 282;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_level_magnet_temperature_left() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_temperature_left) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 283;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_level_magnet_temperature_right() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_magnet_temperature_right) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 284;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 285;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board12_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_state) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 286;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board12_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_command) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 287;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board12_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 288;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board12_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_power_board12_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_power_board12_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_power_board12_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_power_board12_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 289;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_power_board12_config_hash_send_fragmentation_buffer, 2, 289, 255);

}
void canzero_send_power_board12_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 290;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board12_error_any_short() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_error_any_short) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 291;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board12_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 292;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board12_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board12_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 293;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_state) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 294;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_command) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 295;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 296;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_cooling_pump_channel_ctrl() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_cooling_pump_channel_ctrl) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 297;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_power_board24_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_power_board24_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_power_board24_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_power_board24_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 298;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_power_board24_config_hash_send_fragmentation_buffer, 2, 298, 255);

}
void canzero_send_power_board24_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 299;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_error_any_short() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_error_any_short) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 300;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 301;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_power_board24_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_power_board24_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 302;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_led_board_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_state) & (0xFF >> (8 - 3)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 303;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_led_board_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_command) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 304;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_led_board_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_sdc_status) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 305;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_led_board_config_hash() {
  canzero_message_get_resp msg;
  {
    uint64_t masked = (__oe_led_board_config_hash & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
    __oe_led_board_config_hash_send_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
    __oe_led_board_config_hash_send_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
  }
  msg.m_data = __oe_led_board_config_hash_send_fragmentation_buffer[0];
  msg.m_header.m_eof = 0;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 306;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_led_board_config_hash_send_fragmentation_buffer, 2, 306, 255);

}
void canzero_send_led_board_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 307;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_led_board_error_heartbeat_miss() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 308;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_led_board_error_level_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_led_board_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 309;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_gamepad_max_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_gamepad_max_acceleration - (0)) / 0.0000000023283064370807974, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 310;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_gamepad_lt2() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_gamepad_lt2 - (0)) / 0.00392156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 311;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_gamepad_rt2() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_gamepad_rt2 - (0)) / 0.00392156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 312;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_target_airgap() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_target_airgap - (0)) / 0.000000003492459655621196, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 313;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_airgap_transition_duration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_airgap_transition_duration - (0)) / 0.0009155413138017853, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 314;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_airgap_transition_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_airgap_transition_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 315;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_sdc_brake() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 316;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_magnet_current_left_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 317;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_front_error_magnet_current_right_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_front_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 318;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_sdc_brake() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 319;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_magnet_current_left_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 320;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_guidance_board_back_error_magnet_current_right_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_guidance_board_back_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 321;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_sdc_brake() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 322;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_magnet_current_left_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 323;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board1_error_magnet_current_right_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board1_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 324;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_sdc_brake() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 325;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_magnet_current_left_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 326;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board2_error_magnet_current_right_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board2_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 327;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_sdc_brake() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_sdc_brake) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 328;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_magnet_current_left_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_left_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 329;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_levitation_board3_error_magnet_current_right_unexpected() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_levitation_board3_error_magnet_current_right_unexpected) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 330;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_config_consistency() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_config_consistency) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 331;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_any() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_any) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 332;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_over_temperature_system() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_over_temperature_system) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 333;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
