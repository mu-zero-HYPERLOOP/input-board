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
input_board_state DMAMEM __oe_state;
sdc_status DMAMEM __oe_sdc_status;
float DMAMEM __oe_position;
float DMAMEM __oe_velocity;
float DMAMEM __oe_acceleration;
error_flag DMAMEM __oe_assertion_fault;
error_flag DMAMEM __oe_error_acceleration_out_of_range;
error_flag DMAMEM __oe_error_lateral_acceleration_out_of_range;
error_flag DMAMEM __oe_error_vertical_acceleration_out_of_range;
error_flag DMAMEM __oe_error_acceleration_calibration_failed;
error_flag DMAMEM __oe_error_bat24_voltage_invalid;
error_flag DMAMEM __oe_error_bat24_current_invalid;
error_flag DMAMEM __oe_error_supercap_voltage_invalid;
error_flag DMAMEM __oe_error_link24_current_invalid;
error_flag DMAMEM __oe_error_link45_voltage_invalid;
error_flag DMAMEM __oe_error_link45_current_invalid;
error_flag DMAMEM __oe_error_mcu_temperature_invalid;
error_flag DMAMEM __oe_error_sac_ebox_temperature_invalid;
error_flag DMAMEM __oe_error_power_ebox_temperature_invalid;
error_flag DMAMEM __oe_error_bat24_cell_temperature_1_invalid;
error_flag DMAMEM __oe_error_bat24_cell_temperature_2_invalid;
error_flag DMAMEM __oe_error_supercap_temperature_invalid;
error_flag DMAMEM __oe_error_ambient_temperature_1_invalid;
error_flag DMAMEM __oe_error_ambient_temperature_2_invalid;
error_flag DMAMEM __oe_error_ambient_temperature_3_invalid;
error_flag DMAMEM __oe_error_heartbeat_miss;
error_level DMAMEM __oe_error_level_bat24_under_voltage;
error_level DMAMEM __oe_error_level_bat24_over_voltage;
error_level DMAMEM __oe_error_level_bat24_over_current;
error_level DMAMEM __oe_error_level_supercap_under_voltage;
error_level DMAMEM __oe_error_level_supercap_over_voltage;
error_level DMAMEM __oe_error_level_link24_over_current;
error_level DMAMEM __oe_error_level_link45_under_voltage;
error_level DMAMEM __oe_error_level_link45_over_voltage;
error_level DMAMEM __oe_error_level_link45_over_current;
error_level DMAMEM __oe_error_level_mcu_temperature;
error_level DMAMEM __oe_error_level_bat24_temperature;
error_level DMAMEM __oe_error_level_supercap_temperature;
error_level DMAMEM __oe_error_level_sac_ebox_temperature;
error_level DMAMEM __oe_error_level_power_ebox_temperature;
error_level DMAMEM __oe_error_level_ambient_temperature;
input_board_command DMAMEM __oe_command;
float DMAMEM __oe_target_acceleration;
bool_t DMAMEM __oe_pod_grounded;
bool_t DMAMEM __oe_assert_45V_system_online;
int16_t DMAMEM __oe_linear_encoder_count;
float DMAMEM __oe_raw_acceleration;
double DMAMEM __oe_acceleration_calibration_variance;
double DMAMEM __oe_acceleration_calibration_offset;
double DMAMEM __oe_acceleration_calibration_target;
float DMAMEM __oe_raw_lateral_acceleration;
float DMAMEM __oe_lateral_acceleration;
double DMAMEM __oe_lateral_acceleration_calibration_variance;
double DMAMEM __oe_lateral_acceleration_calibration_offset;
double DMAMEM __oe_lateral_acceleration_calibration_target;
float DMAMEM __oe_raw_vertical_acceleration;
float DMAMEM __oe_vertical_acceleration;
double DMAMEM __oe_vertical_acceleration_calibration_variance;
double DMAMEM __oe_vertical_acceleration_calibration_offset;
double DMAMEM __oe_vertical_acceleration_calibration_target;
float DMAMEM __oe_track_length;
float DMAMEM __oe_bat24_voltage;
calibration_mode DMAMEM __oe_bat24_voltage_calibration_mode;
float DMAMEM __oe_bat24_voltage_calibration_offset;
float DMAMEM __oe_bat24_voltage_calibration_target;
error_level_config DMAMEM __oe_error_level_config_bat24_under_voltage;
error_level_config DMAMEM __oe_error_level_config_bat24_over_voltage;
float DMAMEM __oe_bat24_current;
float DMAMEM __oe_bat24_current_calibration_offset;
float DMAMEM __oe_bat24_current_calibration_target;
calibration_mode DMAMEM __oe_bat24_current_calibration_mode;
error_level_config DMAMEM __oe_error_level_config_bat24_over_current;
float DMAMEM __oe_supercap_voltage;
calibration_mode DMAMEM __oe_supercap_voltage_calibration_mode;
float DMAMEM __oe_supercap_voltage_calibration_offset;
float DMAMEM __oe_supercap_voltage_calibration_target;
error_level_config DMAMEM __oe_error_level_config_supercap_under_voltage;
error_level_config DMAMEM __oe_error_level_config_supercap_over_voltage;
float DMAMEM __oe_link24_current;
calibration_mode DMAMEM __oe_link24_current_calibration_mode;
float DMAMEM __oe_link24_current_calibration_offset;
float DMAMEM __oe_link24_current_calibration_target;
error_level_config DMAMEM __oe_error_level_config_link24_over_current;
float DMAMEM __oe_link45_voltage;
calibration_mode DMAMEM __oe_link45_voltage_calibration_mode;
float DMAMEM __oe_link45_voltage_calibration_offset;
float DMAMEM __oe_link45_voltage_calibration_target;
error_level_config DMAMEM __oe_error_level_config_link45_under_voltage;
error_level_config DMAMEM __oe_error_level_config_link45_over_voltage;
float DMAMEM __oe_link45_current;
calibration_mode DMAMEM __oe_link45_current_calibration_mode;
float DMAMEM __oe_link45_current_calibration_offset;
float DMAMEM __oe_link45_current_calibration_target;
error_level_config DMAMEM __oe_error_level_config_link45_over_current;
float DMAMEM __oe_mcu_temperature;
error_level_config DMAMEM __oe_error_level_config_mcu_temperature;
float DMAMEM __oe_bat24_cell_temperature_1;
float DMAMEM __oe_bat24_cell_temperature_2;
float DMAMEM __oe_bat24_temperature_max;
error_level_config DMAMEM __oe_error_level_config_bat24_temperature;
float DMAMEM __oe_supercap_temperature;
error_level_config DMAMEM __oe_error_level_config_supercap_temperature;
float DMAMEM __oe_sac_ebox_temperature;
error_level_config DMAMEM __oe_error_level_config_sac_ebox_temperature;
float DMAMEM __oe_power_ebox_temperature;
error_level_config DMAMEM __oe_error_level_config_power_ebox_temperature;
float DMAMEM __oe_ambient_temperature_1;
float DMAMEM __oe_ambient_temperature_2;
float DMAMEM __oe_ambient_temperature_3;
float DMAMEM __oe_ambient_temperature_avg;
float DMAMEM __oe_ambient_temperature_max;
error_level_config DMAMEM __oe_error_level_config_ambient_temperature;
float DMAMEM __oe_cooling_cycle_flow_rate;
float DMAMEM __oe_loop_frequency;
uint8_t DMAMEM __oe_last_node_missed;
bool_t DMAMEM __oe_ignore_45v;
motor_command DMAMEM __oe__motor_command;
float DMAMEM __oe_system_power_consumption;
float DMAMEM __oe_communication_power_consumption;
static void canzero_serialize_canzero_message_get_resp(canzero_message_get_resp* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x1BD;
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
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x1DD;
  frame->dlc = 4;
  ((uint32_t*)data)[0] = (uint16_t)(msg->m_header.m_od_index & (0xFFFF >> (16 - 13)));
  ((uint32_t*)data)[0] |= msg->m_header.m_client_id << 13;
  ((uint32_t*)data)[0] |= msg->m_header.m_server_id << 21;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_header.m_erno & (0xFF >> (8 - 1))) << 29;
}
static void canzero_serialize_canzero_message_input_board_stream_state(canzero_message_input_board_stream_state* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x177;
  frame->dlc = 1;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_state & (0xFF >> (8 - 2)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_sdc_status & (0xFF >> (8 - 1))) << 2;
}
static void canzero_serialize_canzero_message_input_board_stream_position_estimation(canzero_message_input_board_stream_position_estimation* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x157;
  frame->dlc = 6;
  uint32_t position_0 = ((msg->m_position - -10) / 0.0007629510948348211) + 0.5f;
  if (position_0 > 0xFFFF) {
    position_0 = 0xFFFF;
  }
  ((uint32_t*)data)[0] = position_0;
  uint32_t velocity_16 = ((msg->m_velocity - -10) / 0.00030518043793392844) + 0.5f;
  if (velocity_16 > 0xFFFF) {
    velocity_16 = 0xFFFF;
  }
  ((uint32_t*)data)[0] |= velocity_16 << 16;
  uint32_t acceleration_32 = ((msg->m_acceleration - -50) / 0.0015259021896696422) + 0.5f;
  if (acceleration_32 > 0xFFFF) {
    acceleration_32 = 0xFFFF;
  }
  ((uint32_t*)data)[1] = acceleration_32;
}
static void canzero_serialize_canzero_message_input_board_stream_config_hash(canzero_message_input_board_stream_config_hash* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x117;
  frame->dlc = 8;
  ((uint64_t*)data)[0] = msg->m_config_hash;
}
static void canzero_serialize_canzero_message_input_board_stream_errors(canzero_message_input_board_stream_errors* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x52;
  frame->dlc = 4;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_assertion_fault & (0xFF >> (8 - 1)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_acceleration_out_of_range & (0xFF >> (8 - 1))) << 1;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_lateral_acceleration_out_of_range & (0xFF >> (8 - 1))) << 2;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_vertical_acceleration_out_of_range & (0xFF >> (8 - 1))) << 3;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_acceleration_calibration_failed & (0xFF >> (8 - 1))) << 4;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_voltage_invalid & (0xFF >> (8 - 1))) << 5;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_current_invalid & (0xFF >> (8 - 1))) << 6;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_supercap_voltage_invalid & (0xFF >> (8 - 1))) << 7;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_link24_current_invalid & (0xFF >> (8 - 1))) << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_link45_voltage_invalid & (0xFF >> (8 - 1))) << 9;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_link45_current_invalid & (0xFF >> (8 - 1))) << 10;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_mcu_temperature_invalid & (0xFF >> (8 - 1))) << 11;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_sac_ebox_temperature_invalid & (0xFF >> (8 - 1))) << 12;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_power_ebox_temperature_invalid & (0xFF >> (8 - 1))) << 13;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_cell_temperature_1_invalid & (0xFF >> (8 - 1))) << 14;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_bat24_cell_temperature_2_invalid & (0xFF >> (8 - 1))) << 15;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_supercap_temperature_invalid & (0xFF >> (8 - 1))) << 16;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_ambient_temperature_1_invalid & (0xFF >> (8 - 1))) << 17;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_ambient_temperature_2_invalid & (0xFF >> (8 - 1))) << 18;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_ambient_temperature_3_invalid & (0xFF >> (8 - 1))) << 19;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_heartbeat_miss & (0xFF >> (8 - 1))) << 20;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_under_voltage & (0xFF >> (8 - 2))) << 21;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_over_voltage & (0xFF >> (8 - 2))) << 23;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_over_current & (0xFF >> (8 - 2))) << 25;
}
static void canzero_serialize_canzero_message_input_board_stream_errors2(canzero_message_input_board_stream_errors2* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x137;
  frame->dlc = 4;
  ((uint32_t*)data)[0] = (uint8_t)(msg->m_error_level_supercap_under_voltage & (0xFF >> (8 - 2)));
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_supercap_over_voltage & (0xFF >> (8 - 2))) << 2;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link24_over_current & (0xFF >> (8 - 2))) << 4;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_under_voltage & (0xFF >> (8 - 2))) << 6;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_over_voltage & (0xFF >> (8 - 2))) << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_link45_over_current & (0xFF >> (8 - 2))) << 10;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_mcu_temperature & (0xFF >> (8 - 2))) << 12;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_bat24_temperature & (0xFF >> (8 - 2))) << 14;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_supercap_temperature & (0xFF >> (8 - 2))) << 16;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_sac_ebox_temperature & (0xFF >> (8 - 2))) << 18;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_power_ebox_temperature & (0xFF >> (8 - 2))) << 20;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_error_level_ambient_temperature & (0xFF >> (8 - 2))) << 22;
  ((uint32_t*)data)[0] |= msg->m_last_node_missed << 24;
}
static void canzero_serialize_canzero_message_input_board_stream_linear_encoder(canzero_message_input_board_stream_linear_encoder* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x7C;
  frame->dlc = 2;
  ((uint32_t*)data)[0] = msg->m_linear_encoder_count;
}
static void canzero_serialize_canzero_message_input_board_stream_accelerations(canzero_message_input_board_stream_accelerations* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x15D;
  frame->dlc = 6;
  uint32_t raw_acceleration_0 = ((msg->m_raw_acceleration - -50) / 0.0015259021896696422) + 0.5f;
  if (raw_acceleration_0 > 0xFFFF) {
    raw_acceleration_0 = 0xFFFF;
  }
  ((uint32_t*)data)[0] = raw_acceleration_0;
  uint32_t lateral_acceleration_16 = ((msg->m_lateral_acceleration - -10) / 0.00030518043793392844) + 0.5f;
  if (lateral_acceleration_16 > 0xFFFF) {
    lateral_acceleration_16 = 0xFFFF;
  }
  ((uint32_t*)data)[0] |= lateral_acceleration_16 << 16;
  uint32_t vertical_acceleration_32 = ((msg->m_vertical_acceleration - -10) / 0.00030518043793392844) + 0.5f;
  if (vertical_acceleration_32 > 0xFFFF) {
    vertical_acceleration_32 = 0xFFFF;
  }
  ((uint32_t*)data)[1] = vertical_acceleration_32;
}
static void canzero_serialize_canzero_message_input_board_stream_bat24(canzero_message_input_board_stream_bat24* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x19D;
  frame->dlc = 8;
  uint32_t bat24_voltage_0 = ((msg->m_bat24_voltage - 0) / 0.000000011641532185403987) + 0.5f;
  if (bat24_voltage_0 > 0xFFFFFFFF) {
    bat24_voltage_0 = 0xFFFFFFFF;
  }
  ((uint32_t*)data)[0] = bat24_voltage_0;
  uint32_t bat24_current_32 = ((msg->m_bat24_current - -30) / 0.000000013969838622484784) + 0.5f;
  if (bat24_current_32 > 0xFFFFFFFF) {
    bat24_current_32 = 0xFFFFFFFF;
  }
  ((uint32_t*)data)[1] = bat24_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_link24(canzero_message_input_board_stream_link24* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x9C;
  frame->dlc = 8;
  uint32_t supercap_voltage_0 = ((msg->m_supercap_voltage - 0) / 0.000000011641532185403987) + 0.5f;
  if (supercap_voltage_0 > 0xFFFFFFFF) {
    supercap_voltage_0 = 0xFFFFFFFF;
  }
  ((uint32_t*)data)[0] = supercap_voltage_0;
  uint32_t link24_current_32 = ((msg->m_link24_current - -30) / 0.000000013969838622484784) + 0.5f;
  if (link24_current_32 > 0xFFFFFFFF) {
    link24_current_32 = 0xFFFFFFFF;
  }
  ((uint32_t*)data)[1] = link24_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_link45(canzero_message_input_board_stream_link45* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xBC;
  frame->dlc = 8;
  uint32_t link45_voltage_0 = ((msg->m_link45_voltage - -100) / 0.00000004656612874161595) + 0.5f;
  if (link45_voltage_0 > 0xFFFFFFFF) {
    link45_voltage_0 = 0xFFFFFFFF;
  }
  ((uint32_t*)data)[0] = link45_voltage_0;
  uint32_t link45_current_32 = ((msg->m_link45_current - -1000) / 0.0000004656612874161595) + 0.5f;
  if (link45_current_32 > 0xFFFFFFFF) {
    link45_current_32 = 0xFFFFFFFF;
  }
  ((uint32_t*)data)[1] = link45_current_32;
}
static void canzero_serialize_canzero_message_input_board_stream_mics_temperatures(canzero_message_input_board_stream_mics_temperatures* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xDC;
  frame->dlc = 4;
  uint32_t mcu_temperature_0 = ((msg->m_mcu_temperature - -1) / 0.592156862745098) + 0.5f;
  if (mcu_temperature_0 > 0xFF) {
    mcu_temperature_0 = 0xFF;
  }
  ((uint32_t*)data)[0] = mcu_temperature_0;
  uint32_t supercap_temperature_8 = ((msg->m_supercap_temperature - -1) / 0.592156862745098) + 0.5f;
  if (supercap_temperature_8 > 0xFF) {
    supercap_temperature_8 = 0xFF;
  }
  ((uint32_t*)data)[0] |= supercap_temperature_8 << 8;
  uint32_t sac_ebox_temperature_16 = ((msg->m_sac_ebox_temperature - -1) / 0.592156862745098) + 0.5f;
  if (sac_ebox_temperature_16 > 0xFF) {
    sac_ebox_temperature_16 = 0xFF;
  }
  ((uint32_t*)data)[0] |= sac_ebox_temperature_16 << 16;
  uint32_t power_ebox_temperature_24 = ((msg->m_power_ebox_temperature - -1) / 0.592156862745098) + 0.5f;
  if (power_ebox_temperature_24 > 0xFF) {
    power_ebox_temperature_24 = 0xFF;
  }
  ((uint32_t*)data)[0] |= power_ebox_temperature_24 << 24;
}
static void canzero_serialize_canzero_message_input_board_stream_bat_temperatures(canzero_message_input_board_stream_bat_temperatures* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x5C;
  frame->dlc = 3;
  uint32_t bat24_cell_temperature_1_0 = ((msg->m_bat24_cell_temperature_1 - -1) / 0.592156862745098) + 0.5f;
  if (bat24_cell_temperature_1_0 > 0xFF) {
    bat24_cell_temperature_1_0 = 0xFF;
  }
  ((uint32_t*)data)[0] = bat24_cell_temperature_1_0;
  uint32_t bat24_cell_temperature_2_8 = ((msg->m_bat24_cell_temperature_2 - -1) / 0.592156862745098) + 0.5f;
  if (bat24_cell_temperature_2_8 > 0xFF) {
    bat24_cell_temperature_2_8 = 0xFF;
  }
  ((uint32_t*)data)[0] |= bat24_cell_temperature_2_8 << 8;
  uint32_t bat24_temperature_max_16 = ((msg->m_bat24_temperature_max - -1) / 0.592156862745098) + 0.5f;
  if (bat24_temperature_max_16 > 0xFF) {
    bat24_temperature_max_16 = 0xFF;
  }
  ((uint32_t*)data)[0] |= bat24_temperature_max_16 << 16;
}
static void canzero_serialize_canzero_message_input_board_stream_ambient_temperatures(canzero_message_input_board_stream_ambient_temperatures* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x17D;
  frame->dlc = 6;
  uint32_t ambient_temperature_1_0 = ((msg->m_ambient_temperature_1 - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_1_0 > 0xFF) {
    ambient_temperature_1_0 = 0xFF;
  }
  ((uint32_t*)data)[0] = ambient_temperature_1_0;
  uint32_t ambient_temperature_2_8 = ((msg->m_ambient_temperature_2 - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_2_8 > 0xFF) {
    ambient_temperature_2_8 = 0xFF;
  }
  ((uint32_t*)data)[0] |= ambient_temperature_2_8 << 8;
  uint32_t ambient_temperature_3_16 = ((msg->m_ambient_temperature_3 - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_3_16 > 0xFF) {
    ambient_temperature_3_16 = 0xFF;
  }
  ((uint32_t*)data)[0] |= ambient_temperature_3_16 << 16;
  uint32_t ambient_temperature_max_24 = ((msg->m_ambient_temperature_max - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_max_24 > 0xFF) {
    ambient_temperature_max_24 = 0xFF;
  }
  ((uint32_t*)data)[0] |= ambient_temperature_max_24 << 24;
  uint32_t ambient_temperature_avg_32 = ((msg->m_ambient_temperature_avg - -1) / 0.592156862745098) + 0.5f;
  if (ambient_temperature_avg_32 > 0xFF) {
    ambient_temperature_avg_32 = 0xFF;
  }
  ((uint32_t*)data)[1] = ambient_temperature_avg_32;
  uint32_t supercap_temperature_40 = ((msg->m_supercap_temperature - -1) / 0.592156862745098) + 0.5f;
  if (supercap_temperature_40 > 0xFF) {
    supercap_temperature_40 = 0xFF;
  }
  ((uint32_t*)data)[1] |= supercap_temperature_40 << 8;
}
static void canzero_serialize_canzero_message_input_board_stream_power_consumption(canzero_message_input_board_stream_power_consumption* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0xFC;
  frame->dlc = 4;
  uint32_t system_power_consumption_0 = ((msg->m_system_power_consumption - 0) / 0.15259021896696423) + 0.5f;
  if (system_power_consumption_0 > 0xFFFF) {
    system_power_consumption_0 = 0xFFFF;
  }
  ((uint32_t*)data)[0] = system_power_consumption_0;
  uint32_t communication_power_consumption_16 = ((msg->m_communication_power_consumption - 0) / 0.007629510948348211) + 0.5f;
  if (communication_power_consumption_16 > 0xFFFF) {
    communication_power_consumption_16 = 0xFFFF;
  }
  ((uint32_t*)data)[0] |= communication_power_consumption_16 << 16;
}
static void canzero_serialize_canzero_message_heartbeat_can0(canzero_message_heartbeat_can0* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x1F4;
  frame->dlc = 2;
  ((uint32_t*)data)[0] = msg->m_node_id;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_unregister & (0xFF >> (8 - 1))) << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_ticks_next & (0xFF >> (8 - 7))) << 9;
}
static void canzero_serialize_canzero_message_heartbeat_can1(canzero_message_heartbeat_can1* msg, canzero_frame* frame) {
  uint8_t* data = frame->data;
  for(uint8_t i = 0; i < 8; ++i){
    data[i] = 0;
  }
  frame->id = 0x1F3;
  frame->dlc = 2;
  ((uint32_t*)data)[0] = msg->m_node_id;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_unregister & (0xFF >> (8 - 1))) << 8;
  ((uint32_t*)data)[0] |= (uint8_t)(msg->m_ticks_next & (0xFF >> (8 - 7))) << 9;
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
static void canzero_deserialize_canzero_message_mother_board_stream_motor_command(canzero_frame* frame, canzero_message_mother_board_stream_motor_command* msg) {
  uint8_t* data = frame->data;
  msg->m_target_acceleration = (((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 32))) * 0.000000023283064370807974 + -50;
  msg->m_motor_driver_command = (motor_command)(((uint32_t*)data)[1] & (0xFFFFFFFF >> (32 - 3)));
  msg->m_pod_grounded = (bool_t)((((uint32_t*)data)[1] >> 3) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_mother_board_stream_input_board_command(canzero_frame* frame, canzero_message_mother_board_stream_input_board_command* msg) {
  uint8_t* data = frame->data;
  msg->m_input_board_command = (input_board_command)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
  msg->m_input_board_assert_45V_online = (bool_t)((((uint32_t*)data)[0] >> 1) & (0xFFFFFFFF >> (32 - 1)));
}
static void canzero_deserialize_canzero_message_mother_board_stream_debug_settings(canzero_frame* frame, canzero_message_mother_board_stream_debug_settings* msg) {
  uint8_t* data = frame->data;
  msg->m_ignore_45v = (bool_t)(((uint32_t*)data)[0] & (0xFFFFFFFF >> (32 - 1)));
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

#define SCHEDULER_HEAP_SIZE 80
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
static const uint32_t get_resp_fragmentation_interval = 10;
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
static const uint32_t heartbeat_interval = 100;
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

static job_t state_interval_job;
static const uint32_t state_interval = 1;
static void schedule_state_interval_job(){
  uint32_t time = canzero_get_time();
  state_interval_job.climax = time + state_interval;
  state_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  state_interval_job.job.stream_job.stream_id = 0;
  state_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&state_interval_job);
}
static job_t position_estimation_interval_job;
static const uint32_t position_estimation_interval = 10;
static void schedule_position_estimation_interval_job(){
  uint32_t time = canzero_get_time();
  position_estimation_interval_job.climax = time + position_estimation_interval;
  position_estimation_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  position_estimation_interval_job.job.stream_job.stream_id = 1;
  position_estimation_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&position_estimation_interval_job);
}
static job_t config_hash_interval_job;
static const uint32_t config_hash_interval = 0;
static void schedule_config_hash_interval_job(){
  uint32_t time = canzero_get_time();
  config_hash_interval_job.climax = time + config_hash_interval;
  config_hash_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  config_hash_interval_job.job.stream_job.stream_id = 2;
  config_hash_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&config_hash_interval_job);
}
static job_t errors_interval_job;
static const uint32_t errors_interval = 0;
static void schedule_errors_interval_job(){
  uint32_t time = canzero_get_time();
  errors_interval_job.climax = time + errors_interval;
  errors_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  errors_interval_job.job.stream_job.stream_id = 3;
  errors_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&errors_interval_job);
}
static job_t errors2_interval_job;
static const uint32_t errors2_interval = 0;
static void schedule_errors2_interval_job(){
  uint32_t time = canzero_get_time();
  errors2_interval_job.climax = time + errors2_interval;
  errors2_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  errors2_interval_job.job.stream_job.stream_id = 4;
  errors2_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&errors2_interval_job);
}
static job_t linear_encoder_interval_job;
static const uint32_t linear_encoder_interval = 50;
static void schedule_linear_encoder_interval_job(){
  uint32_t time = canzero_get_time();
  linear_encoder_interval_job.climax = time + linear_encoder_interval;
  linear_encoder_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  linear_encoder_interval_job.job.stream_job.stream_id = 5;
  linear_encoder_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&linear_encoder_interval_job);
}
static job_t accelerations_interval_job;
static const uint32_t accelerations_interval = 50;
static void schedule_accelerations_interval_job(){
  uint32_t time = canzero_get_time();
  accelerations_interval_job.climax = time + accelerations_interval;
  accelerations_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  accelerations_interval_job.job.stream_job.stream_id = 6;
  accelerations_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&accelerations_interval_job);
}
static job_t bat24_interval_job;
static const uint32_t bat24_interval = 100;
static void schedule_bat24_interval_job(){
  uint32_t time = canzero_get_time();
  bat24_interval_job.climax = time + bat24_interval;
  bat24_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  bat24_interval_job.job.stream_job.stream_id = 7;
  bat24_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&bat24_interval_job);
}
static job_t link24_interval_job;
static const uint32_t link24_interval = 100;
static void schedule_link24_interval_job(){
  uint32_t time = canzero_get_time();
  link24_interval_job.climax = time + link24_interval;
  link24_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  link24_interval_job.job.stream_job.stream_id = 8;
  link24_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&link24_interval_job);
}
static job_t link45_interval_job;
static const uint32_t link45_interval = 100;
static void schedule_link45_interval_job(){
  uint32_t time = canzero_get_time();
  link45_interval_job.climax = time + link45_interval;
  link45_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  link45_interval_job.job.stream_job.stream_id = 9;
  link45_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&link45_interval_job);
}
static job_t mics_temperatures_interval_job;
static const uint32_t mics_temperatures_interval = 500;
static void schedule_mics_temperatures_interval_job(){
  uint32_t time = canzero_get_time();
  mics_temperatures_interval_job.climax = time + mics_temperatures_interval;
  mics_temperatures_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  mics_temperatures_interval_job.job.stream_job.stream_id = 10;
  mics_temperatures_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&mics_temperatures_interval_job);
}
static job_t bat_temperatures_interval_job;
static const uint32_t bat_temperatures_interval = 500;
static void schedule_bat_temperatures_interval_job(){
  uint32_t time = canzero_get_time();
  bat_temperatures_interval_job.climax = time + bat_temperatures_interval;
  bat_temperatures_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  bat_temperatures_interval_job.job.stream_job.stream_id = 11;
  bat_temperatures_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&bat_temperatures_interval_job);
}
static job_t ambient_temperatures_interval_job;
static const uint32_t ambient_temperatures_interval = 500;
static void schedule_ambient_temperatures_interval_job(){
  uint32_t time = canzero_get_time();
  ambient_temperatures_interval_job.climax = time + ambient_temperatures_interval;
  ambient_temperatures_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  ambient_temperatures_interval_job.job.stream_job.stream_id = 12;
  ambient_temperatures_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&ambient_temperatures_interval_job);
}
static job_t power_consumption_interval_job;
static const uint32_t power_consumption_interval = 500;
static void schedule_power_consumption_interval_job(){
  uint32_t time = canzero_get_time();
  power_consumption_interval_job.climax = time + power_consumption_interval;
  power_consumption_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  power_consumption_interval_job.job.stream_job.stream_id = 13;
  power_consumption_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&power_consumption_interval_job);
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
        canzero_message_input_board_stream_state stream_message;
        stream_message.m_state = __oe_state;
        stream_message.m_sdc_status = __oe_sdc_status;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_state(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 1: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 10);
        canzero_exit_critical();
        canzero_message_input_board_stream_position_estimation stream_message;
        stream_message.m_position = __oe_position;
        stream_message.m_velocity = __oe_velocity;
        stream_message.m_acceleration = __oe_acceleration;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_position_estimation(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 2: {
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
      case 3: {
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
      case 4: {
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
        canzero_can1_send(&stream_frame);
        break;
      }
      case 5: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_linear_encoder stream_message;
        stream_message.m_linear_encoder_count = __oe_linear_encoder_count;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_linear_encoder(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 6: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 50);
        canzero_exit_critical();
        canzero_message_input_board_stream_accelerations stream_message;
        stream_message.m_raw_acceleration = __oe_raw_acceleration;
        stream_message.m_lateral_acceleration = __oe_lateral_acceleration;
        stream_message.m_vertical_acceleration = __oe_vertical_acceleration;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_accelerations(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 7: {
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
      case 8: {
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
      case 9: {
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
      case 10: {
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
      case 11: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_bat_temperatures stream_message;
        stream_message.m_bat24_cell_temperature_1 = __oe_bat24_cell_temperature_1;
        stream_message.m_bat24_cell_temperature_2 = __oe_bat24_cell_temperature_2;
        stream_message.m_bat24_temperature_max = __oe_bat24_temperature_max;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_bat_temperatures(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 12: {
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
      case 13: {
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
        heartbeat_can0.m_ticks_next = 20;
        canzero_serialize_canzero_message_heartbeat_can0(&heartbeat_can0, &heartbeat_frame);
        canzero_can0_send(&heartbeat_frame);
        canzero_message_heartbeat_can1 heartbeat_can1;
        heartbeat_can1.m_node_id = node_id_input_board;
        heartbeat_can1.m_unregister = 0;
        heartbeat_can1.m_ticks_next = 20;
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
        fragmentation_response.m_header.m_server_id = 0x8;
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
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_state) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 3: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 4: {
    resp.m_data |= min_u32((__oe_position - (-10)) / 0.0007629510948348211, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 5: {
    resp.m_data |= min_u32((__oe_velocity - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 6: {
    resp.m_data |= min_u32((__oe_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 7: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 8: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 9: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_lateral_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 10: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_vertical_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 11: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_calibration_failed) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 12: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 13: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 14: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_supercap_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 15: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_link24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 16: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 17: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_current_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 18: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 19: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_sac_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 20: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_power_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 21: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_cell_temperature_1_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 22: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_cell_temperature_2_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 23: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_supercap_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 24: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_1_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 25: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_2_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 26: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_ambient_temperature_3_invalid) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 27: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_heartbeat_miss) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 28: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 29: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 30: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 31: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 32: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 33: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 34: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 35: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 36: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 37: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 38: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 39: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 40: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_sac_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 41: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_power_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 42: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_ambient_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 43: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_command) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 44: {
    resp.m_data |= min_u32((__oe_target_acceleration - (-50)) / 0.000000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 45: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_pod_grounded) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 46: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_assert_45V_system_online) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 47: {
    resp.m_data |= ((uint32_t)(((uint16_t)__oe_linear_encoder_count) & (0xFFFF >> (16 - 16)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 48: {
    resp.m_data |= min_u32((__oe_raw_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 49: {
    {
      uint64_t masked = (min_u64((__oe_acceleration_calibration_variance - ((double)-1)) / (double)0.00000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_acceleration_calibration_variance_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_acceleration_calibration_variance_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_acceleration_calibration_variance_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_variance_rx_fragmentation_buffer, 2, 49, msg.m_header.m_client_id);
    break;
  }
  case 50: {
    {
      uint64_t masked = (min_u64((__oe_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_acceleration_calibration_offset_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_acceleration_calibration_offset_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_acceleration_calibration_offset_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_offset_rx_fragmentation_buffer, 2, 50, msg.m_header.m_client_id);
    break;
  }
  case 51: {
    {
      uint64_t masked = (min_u64((__oe_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_acceleration_calibration_target_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_acceleration_calibration_target_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_acceleration_calibration_target_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_target_rx_fragmentation_buffer, 2, 51, msg.m_header.m_client_id);
    break;
  }
  case 52: {
    resp.m_data |= min_u32((__oe_raw_lateral_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 53: {
    resp.m_data |= min_u32((__oe_lateral_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 54: {
    {
      uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_variance - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_variance_rx_fragmentation_buffer, 2, 54, msg.m_header.m_client_id);
    break;
  }
  case 55: {
    {
      uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_offset_rx_fragmentation_buffer, 2, 55, msg.m_header.m_client_id);
    break;
  }
  case 56: {
    {
      uint64_t masked = (min_u64((__oe_lateral_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_target_rx_fragmentation_buffer, 2, 56, msg.m_header.m_client_id);
    break;
  }
  case 57: {
    resp.m_data |= min_u32((__oe_raw_vertical_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 58: {
    resp.m_data |= min_u32((__oe_vertical_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 59: {
    {
      uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_variance - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_variance_rx_fragmentation_buffer, 2, 59, msg.m_header.m_client_id);
    break;
  }
  case 60: {
    {
      uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_offset - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_offset_rx_fragmentation_buffer, 2, 60, msg.m_header.m_client_id);
    break;
  }
  case 61: {
    {
      uint64_t masked = (min_u64((__oe_vertical_acceleration_calibration_target - ((double)-10)) / (double)0.0000000000000000010842021724855044, 0xFFFFFFFFFFFFFFFFull) & (0xFFFFFFFFFFFFFFFF >> (64 - 64)));
      __oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer[0] = ((uint32_t*)&masked)[0];
      __oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer[1] = ((uint32_t*)&masked)[1];
    }
    resp.m_data = __oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_target_rx_fragmentation_buffer, 2, 61, msg.m_header.m_client_id);
    break;
  }
  case 62: {
    resp.m_data |= min_u32((__oe_track_length - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 63: {
    resp.m_data |= min_u32((__oe_bat24_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 64: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_bat24_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 65: {
    resp.m_data |= min_u32((__oe_bat24_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 66: {
    resp.m_data |= min_u32((__oe_bat24_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 67: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer, 7, 67, msg.m_header.m_client_id);
    break;
  }
  case 68: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer, 7, 68, msg.m_header.m_client_id);
    break;
  }
  case 69: {
    resp.m_data |= min_u32((__oe_bat24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 70: {
    resp.m_data |= min_u32((__oe_bat24_current_calibration_offset - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 71: {
    resp.m_data |= min_u32((__oe_bat24_current_calibration_target - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 72: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_bat24_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 73: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_current_rx_fragmentation_buffer, 7, 73, msg.m_header.m_client_id);
    break;
  }
  case 74: {
    resp.m_data |= min_u32((__oe_supercap_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 75: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_supercap_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 76: {
    resp.m_data |= min_u32((__oe_supercap_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 77: {
    resp.m_data |= min_u32((__oe_supercap_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 78: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_under_voltage_rx_fragmentation_buffer, 7, 78, msg.m_header.m_client_id);
    break;
  }
  case 79: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_over_voltage_rx_fragmentation_buffer, 7, 79, msg.m_header.m_client_id);
    break;
  }
  case 80: {
    resp.m_data |= min_u32((__oe_link24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 81: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_link24_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 82: {
    resp.m_data |= min_u32((__oe_link24_current_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 83: {
    resp.m_data |= min_u32((__oe_link24_current_calibration_target - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 84: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_current_rx_fragmentation_buffer, 7, 84, msg.m_header.m_client_id);
    break;
  }
  case 85: {
    resp.m_data |= min_u32((__oe_link45_voltage - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 86: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_link45_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 87: {
    resp.m_data |= min_u32((__oe_link45_voltage_calibration_offset - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 88: {
    resp.m_data |= min_u32((__oe_link45_voltage_calibration_target - (0)) / 0.00000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 89: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer, 7, 89, msg.m_header.m_client_id);
    break;
  }
  case 90: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer, 7, 90, msg.m_header.m_client_id);
    break;
  }
  case 91: {
    resp.m_data |= min_u32((__oe_link45_current - (-1000)) / 0.0000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 92: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_link45_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 93: {
    resp.m_data |= min_u32((__oe_link45_current_calibration_offset - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 94: {
    resp.m_data |= min_u32((__oe_link45_current_calibration_target - (-1000)) / 0.0000004656612874161595, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 95: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_current_rx_fragmentation_buffer, 7, 95, msg.m_header.m_client_id);
    break;
  }
  case 96: {
    resp.m_data |= min_u32((__oe_mcu_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_temperature_rx_fragmentation_buffer, 7, 101, msg.m_header.m_client_id);
    break;
  }
  case 102: {
    resp.m_data |= min_u32((__oe_supercap_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 103: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_temperature_rx_fragmentation_buffer, 7, 103, msg.m_header.m_client_id);
    break;
  }
  case 104: {
    resp.m_data |= min_u32((__oe_sac_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 105: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_sac_ebox_temperature_rx_fragmentation_buffer, 7, 105, msg.m_header.m_client_id);
    break;
  }
  case 106: {
    resp.m_data |= min_u32((__oe_power_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 107: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_power_ebox_temperature_rx_fragmentation_buffer, 7, 107, msg.m_header.m_client_id);
    break;
  }
  case 108: {
    resp.m_data |= min_u32((__oe_ambient_temperature_1 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 109: {
    resp.m_data |= min_u32((__oe_ambient_temperature_2 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 110: {
    resp.m_data |= min_u32((__oe_ambient_temperature_3 - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 111: {
    resp.m_data |= min_u32((__oe_ambient_temperature_avg - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 112: {
    resp.m_data |= min_u32((__oe_ambient_temperature_max - (-1)) / 0.592156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 113: {
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
    schedule_get_resp_fragmentation_job(__oe_error_level_config_ambient_temperature_rx_fragmentation_buffer, 7, 113, msg.m_header.m_client_id);
    break;
  }
  case 114: {
    resp.m_data |= min_u32((__oe_cooling_cycle_flow_rate - (0)) / 0.00392156862745098, 0xFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 115: {
    resp.m_data |= min_u32((__oe_loop_frequency - (0)) / 0.00000023283064370807974, 0xFFFFFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 116: {
    resp.m_data |= ((uint32_t)(__oe_last_node_missed & (0xFF >> (8 - 8)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 117: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_ignore_45v) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 118: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe__motor_command) & (0xFF >> (8 - 3)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 119: {
    resp.m_data |= min_u32((__oe_system_power_consumption - (0)) / 0.15259021896696423, 0xFFFF) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 120: {
    resp.m_data |= min_u32((__oe_communication_power_consumption - (0)) / 0.007629510948348211, 0xFFFF) << 0;
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
static PROGMEM void canzero_handle_set_req(canzero_frame* frame) {
  canzero_message_set_req msg;
  canzero_deserialize_canzero_message_set_req(frame, &msg);
  if (msg.m_header.m_server_id != 8) {
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
    input_board_state state_tmp;
    state_tmp = ((input_board_state)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_state(state_tmp);
    break;
  }
  case 3 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status sdc_status_tmp;
    sdc_status_tmp = ((sdc_status)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_sdc_status(sdc_status_tmp);
    break;
  }
  case 4 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float position_tmp;
    position_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0007629510948348211 + -10);
    canzero_set_position(position_tmp);
    break;
  }
  case 5 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float velocity_tmp;
    velocity_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_velocity(velocity_tmp);
    break;
  }
  case 6 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float acceleration_tmp;
    acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0015259021896696422 + -50);
    canzero_set_acceleration(acceleration_tmp);
    break;
  }
  case 7 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag assertion_fault_tmp;
    assertion_fault_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_assertion_fault(assertion_fault_tmp);
    break;
  }
  case 8 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_acceleration_out_of_range_tmp;
    error_acceleration_out_of_range_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_acceleration_out_of_range(error_acceleration_out_of_range_tmp);
    break;
  }
  case 9 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_lateral_acceleration_out_of_range_tmp;
    error_lateral_acceleration_out_of_range_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_lateral_acceleration_out_of_range(error_lateral_acceleration_out_of_range_tmp);
    break;
  }
  case 10 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_vertical_acceleration_out_of_range_tmp;
    error_vertical_acceleration_out_of_range_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_vertical_acceleration_out_of_range(error_vertical_acceleration_out_of_range_tmp);
    break;
  }
  case 11 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_acceleration_calibration_failed_tmp;
    error_acceleration_calibration_failed_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_acceleration_calibration_failed(error_acceleration_calibration_failed_tmp);
    break;
  }
  case 12 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_voltage_invalid_tmp;
    error_bat24_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_voltage_invalid(error_bat24_voltage_invalid_tmp);
    break;
  }
  case 13 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_current_invalid_tmp;
    error_bat24_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_current_invalid(error_bat24_current_invalid_tmp);
    break;
  }
  case 14 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_supercap_voltage_invalid_tmp;
    error_supercap_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_supercap_voltage_invalid(error_supercap_voltage_invalid_tmp);
    break;
  }
  case 15 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_link24_current_invalid_tmp;
    error_link24_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_link24_current_invalid(error_link24_current_invalid_tmp);
    break;
  }
  case 16 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_link45_voltage_invalid_tmp;
    error_link45_voltage_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_link45_voltage_invalid(error_link45_voltage_invalid_tmp);
    break;
  }
  case 17 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_link45_current_invalid_tmp;
    error_link45_current_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_link45_current_invalid(error_link45_current_invalid_tmp);
    break;
  }
  case 18 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_mcu_temperature_invalid_tmp;
    error_mcu_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_mcu_temperature_invalid(error_mcu_temperature_invalid_tmp);
    break;
  }
  case 19 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_sac_ebox_temperature_invalid_tmp;
    error_sac_ebox_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_sac_ebox_temperature_invalid(error_sac_ebox_temperature_invalid_tmp);
    break;
  }
  case 20 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_power_ebox_temperature_invalid_tmp;
    error_power_ebox_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_power_ebox_temperature_invalid(error_power_ebox_temperature_invalid_tmp);
    break;
  }
  case 21 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_cell_temperature_1_invalid_tmp;
    error_bat24_cell_temperature_1_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_cell_temperature_1_invalid(error_bat24_cell_temperature_1_invalid_tmp);
    break;
  }
  case 22 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_bat24_cell_temperature_2_invalid_tmp;
    error_bat24_cell_temperature_2_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_bat24_cell_temperature_2_invalid(error_bat24_cell_temperature_2_invalid_tmp);
    break;
  }
  case 23 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_supercap_temperature_invalid_tmp;
    error_supercap_temperature_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_supercap_temperature_invalid(error_supercap_temperature_invalid_tmp);
    break;
  }
  case 24 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_ambient_temperature_1_invalid_tmp;
    error_ambient_temperature_1_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_ambient_temperature_1_invalid(error_ambient_temperature_1_invalid_tmp);
    break;
  }
  case 25 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_ambient_temperature_2_invalid_tmp;
    error_ambient_temperature_2_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_ambient_temperature_2_invalid(error_ambient_temperature_2_invalid_tmp);
    break;
  }
  case 26 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_ambient_temperature_3_invalid_tmp;
    error_ambient_temperature_3_invalid_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_ambient_temperature_3_invalid(error_ambient_temperature_3_invalid_tmp);
    break;
  }
  case 27 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag error_heartbeat_miss_tmp;
    error_heartbeat_miss_tmp = ((error_flag)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_error_heartbeat_miss(error_heartbeat_miss_tmp);
    break;
  }
  case 28 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_under_voltage_tmp;
    error_level_bat24_under_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_under_voltage(error_level_bat24_under_voltage_tmp);
    break;
  }
  case 29 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_over_voltage_tmp;
    error_level_bat24_over_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_voltage(error_level_bat24_over_voltage_tmp);
    break;
  }
  case 30 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_over_current_tmp;
    error_level_bat24_over_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_current(error_level_bat24_over_current_tmp);
    break;
  }
  case 31 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_supercap_under_voltage_tmp;
    error_level_supercap_under_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_under_voltage(error_level_supercap_under_voltage_tmp);
    break;
  }
  case 32 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_supercap_over_voltage_tmp;
    error_level_supercap_over_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_over_voltage(error_level_supercap_over_voltage_tmp);
    break;
  }
  case 33 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link24_over_current_tmp;
    error_level_link24_over_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_over_current(error_level_link24_over_current_tmp);
    break;
  }
  case 34 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_under_voltage_tmp;
    error_level_link45_under_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_under_voltage(error_level_link45_under_voltage_tmp);
    break;
  }
  case 35 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_over_voltage_tmp;
    error_level_link45_over_voltage_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_voltage(error_level_link45_over_voltage_tmp);
    break;
  }
  case 36 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_over_current_tmp;
    error_level_link45_over_current_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_current(error_level_link45_over_current_tmp);
    break;
  }
  case 37 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_mcu_temperature_tmp;
    error_level_mcu_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_mcu_temperature(error_level_mcu_temperature_tmp);
    break;
  }
  case 38 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_temperature_tmp;
    error_level_bat24_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_temperature(error_level_bat24_temperature_tmp);
    break;
  }
  case 39 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_supercap_temperature_tmp;
    error_level_supercap_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_temperature(error_level_supercap_temperature_tmp);
    break;
  }
  case 40 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_sac_ebox_temperature_tmp;
    error_level_sac_ebox_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_sac_ebox_temperature(error_level_sac_ebox_temperature_tmp);
    break;
  }
  case 41 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_power_ebox_temperature_tmp;
    error_level_power_ebox_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_power_ebox_temperature(error_level_power_ebox_temperature_tmp);
    break;
  }
  case 42 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_ambient_temperature_tmp;
    error_level_ambient_temperature_tmp = ((error_level)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_ambient_temperature(error_level_ambient_temperature_tmp);
    break;
  }
  case 43 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    input_board_command command_tmp;
    command_tmp = ((input_board_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_command(command_tmp);
    break;
  }
  case 44 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float target_acceleration_tmp;
    target_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000023283064370807974 + -50);
    canzero_set_target_acceleration(target_acceleration_tmp);
    break;
  }
  case 45 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t pod_grounded_tmp;
    pod_grounded_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_pod_grounded(pod_grounded_tmp);
    break;
  }
  case 46 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t assert_45V_system_online_tmp;
    assert_45V_system_online_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_assert_45V_system_online(assert_45V_system_online_tmp);
    break;
  }
  case 47 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    int16_t linear_encoder_count_tmp;
    linear_encoder_count_tmp = (((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) & (0x1 << (16 - 1))) != 0 ? (int16_t) (((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) | (0xFFFFFFFF << (16 - 1))) : (int16_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16)));
    canzero_set_linear_encoder_count(linear_encoder_count_tmp);
    break;
  }
  case 48 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float raw_acceleration_tmp;
    raw_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0015259021896696422 + -50);
    canzero_set_raw_acceleration(raw_acceleration_tmp);
    break;
  }
  case 49 : {
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
  case 50 : {
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
  case 51 : {
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
  case 52 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float raw_lateral_acceleration_tmp;
    raw_lateral_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_raw_lateral_acceleration(raw_lateral_acceleration_tmp);
    break;
  }
  case 53 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float lateral_acceleration_tmp;
    lateral_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_lateral_acceleration(lateral_acceleration_tmp);
    break;
  }
  case 54 : {
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
  case 55 : {
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
  case 56 : {
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
  case 57 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float raw_vertical_acceleration_tmp;
    raw_vertical_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.0015259021896696422 + -50);
    canzero_set_raw_vertical_acceleration(raw_vertical_acceleration_tmp);
    break;
  }
  case 58 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float vertical_acceleration_tmp;
    vertical_acceleration_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_vertical_acceleration(vertical_acceleration_tmp);
    break;
  }
  case 59 : {
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
  case 60 : {
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
  case 61 : {
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
  case 62 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float track_length_tmp;
    track_length_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_track_length(track_length_tmp);
    break;
  }
  case 63 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_voltage_tmp;
    bat24_voltage_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_bat24_voltage(bat24_voltage_tmp);
    break;
  }
  case 64 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode bat24_voltage_calibration_mode_tmp;
    bat24_voltage_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_bat24_voltage_calibration_mode(bat24_voltage_calibration_mode_tmp);
    break;
  }
  case 65 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_voltage_calibration_offset_tmp;
    bat24_voltage_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000004656612874161595 + -10);
    canzero_set_bat24_voltage_calibration_offset(bat24_voltage_calibration_offset_tmp);
    break;
  }
  case 66 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_voltage_calibration_target_tmp;
    bat24_voltage_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_bat24_voltage_calibration_target(bat24_voltage_calibration_target_tmp);
    break;
  }
  case 67 : {
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
  case 68 : {
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
  case 69 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_current_tmp;
    bat24_current_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current(bat24_current_tmp);
    break;
  }
  case 70 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_current_calibration_offset_tmp;
    bat24_current_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current_calibration_offset(bat24_current_calibration_offset_tmp);
    break;
  }
  case 71 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_current_calibration_target_tmp;
    bat24_current_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current_calibration_target(bat24_current_calibration_target_tmp);
    break;
  }
  case 72 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode bat24_current_calibration_mode_tmp;
    bat24_current_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_bat24_current_calibration_mode(bat24_current_calibration_mode_tmp);
    break;
  }
  case 73 : {
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
  case 74 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_voltage_tmp;
    supercap_voltage_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_supercap_voltage(supercap_voltage_tmp);
    break;
  }
  case 75 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode supercap_voltage_calibration_mode_tmp;
    supercap_voltage_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_supercap_voltage_calibration_mode(supercap_voltage_calibration_mode_tmp);
    break;
  }
  case 76 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_voltage_calibration_offset_tmp;
    supercap_voltage_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000004656612874161595 + -10);
    canzero_set_supercap_voltage_calibration_offset(supercap_voltage_calibration_offset_tmp);
    break;
  }
  case 77 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_voltage_calibration_target_tmp;
    supercap_voltage_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_supercap_voltage_calibration_target(supercap_voltage_calibration_target_tmp);
    break;
  }
  case 78 : {
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
  case 79 : {
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
  case 80 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_current_tmp;
    link24_current_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_link24_current(link24_current_tmp);
    break;
  }
  case 81 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode link24_current_calibration_mode_tmp;
    link24_current_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_link24_current_calibration_mode(link24_current_calibration_mode_tmp);
    break;
  }
  case 82 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_current_calibration_offset_tmp;
    link24_current_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000004656612874161595 + -10);
    canzero_set_link24_current_calibration_offset(link24_current_calibration_offset_tmp);
    break;
  }
  case 83 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_current_calibration_target_tmp;
    link24_current_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_link24_current_calibration_target(link24_current_calibration_target_tmp);
    break;
  }
  case 84 : {
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
  case 85 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_voltage_tmp;
    link45_voltage_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100);
    canzero_set_link45_voltage(link45_voltage_tmp);
    break;
  }
  case 86 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode link45_voltage_calibration_mode_tmp;
    link45_voltage_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_link45_voltage_calibration_mode(link45_voltage_calibration_mode_tmp);
    break;
  }
  case 87 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_voltage_calibration_offset_tmp;
    link45_voltage_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100);
    canzero_set_link45_voltage_calibration_offset(link45_voltage_calibration_offset_tmp);
    break;
  }
  case 88 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_voltage_calibration_target_tmp;
    link45_voltage_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000023283064370807974 + 0);
    canzero_set_link45_voltage_calibration_target(link45_voltage_calibration_target_tmp);
    break;
  }
  case 89 : {
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
  case 90 : {
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
  case 91 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_current_tmp;
    link45_current_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.0000004656612874161595 + -1000);
    canzero_set_link45_current(link45_current_tmp);
    break;
  }
  case 92 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    calibration_mode link45_current_calibration_mode_tmp;
    link45_current_calibration_mode_tmp = ((calibration_mode)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_link45_current_calibration_mode(link45_current_calibration_mode_tmp);
    break;
  }
  case 93 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_current_calibration_offset_tmp;
    link45_current_calibration_offset_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100);
    canzero_set_link45_current_calibration_offset(link45_current_calibration_offset_tmp);
    break;
  }
  case 94 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_current_calibration_target_tmp;
    link45_current_calibration_target_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.0000004656612874161595 + -1000);
    canzero_set_link45_current_calibration_target(link45_current_calibration_target_tmp);
    break;
  }
  case 95 : {
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
  case 96 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float mcu_temperature_tmp;
    mcu_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_mcu_temperature(mcu_temperature_tmp);
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
  case 102 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_temperature_tmp;
    supercap_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_supercap_temperature(supercap_temperature_tmp);
    break;
  }
  case 103 : {
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
  case 104 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float sac_ebox_temperature_tmp;
    sac_ebox_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_sac_ebox_temperature(sac_ebox_temperature_tmp);
    break;
  }
  case 105 : {
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
  case 106 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float power_ebox_temperature_tmp;
    power_ebox_temperature_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_power_ebox_temperature(power_ebox_temperature_tmp);
    break;
  }
  case 107 : {
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
  case 108 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_1_tmp;
    ambient_temperature_1_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_1(ambient_temperature_1_tmp);
    break;
  }
  case 109 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_2_tmp;
    ambient_temperature_2_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_2(ambient_temperature_2_tmp);
    break;
  }
  case 110 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_3_tmp;
    ambient_temperature_3_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_3(ambient_temperature_3_tmp);
    break;
  }
  case 111 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_avg_tmp;
    ambient_temperature_avg_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_avg(ambient_temperature_avg_tmp);
    break;
  }
  case 112 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_max_tmp;
    ambient_temperature_max_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature_max(ambient_temperature_max_tmp);
    break;
  }
  case 113 : {
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
  case 114 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float cooling_cycle_flow_rate_tmp;
    cooling_cycle_flow_rate_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8))) * 0.00392156862745098 + 0);
    canzero_set_cooling_cycle_flow_rate(cooling_cycle_flow_rate_tmp);
    break;
  }
  case 115 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float loop_frequency_tmp;
    loop_frequency_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 32))) * 0.00000023283064370807974 + 0);
    canzero_set_loop_frequency(loop_frequency_tmp);
    break;
  }
  case 116 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    uint8_t last_node_missed_tmp;
    last_node_missed_tmp = ((uint8_t)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 8)))));
    canzero_set_last_node_missed(last_node_missed_tmp);
    break;
  }
  case 117 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t ignore_45v_tmp;
    ignore_45v_tmp = ((bool_t)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_ignore_45v(ignore_45v_tmp);
    break;
  }
  case 118 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    motor_command _motor_command_tmp;
    _motor_command_tmp = ((motor_command)((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 3))));
    canzero_set__motor_command(_motor_command_tmp);
    break;
  }
  case 119 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float system_power_consumption_tmp;
    system_power_consumption_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.15259021896696423 + 0);
    canzero_set_system_power_consumption(system_power_consumption_tmp);
    break;
  }
  case 120 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float communication_power_consumption_tmp;
    communication_power_consumption_tmp = (float)(((msg.m_data >> 0) & (0xFFFFFFFF >> (32 - 16))) * 0.007629510948348211 + 0);
    canzero_set_communication_power_consumption(communication_power_consumption_tmp);
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
static void canzero_handle_mother_board_stream_motor_command(canzero_frame* frame) {
  canzero_message_mother_board_stream_motor_command msg;
  canzero_deserialize_canzero_message_mother_board_stream_motor_command(frame, &msg);
  canzero_set_target_acceleration(msg.m_target_acceleration);
  canzero_set__motor_command(msg.m_motor_driver_command);
  canzero_set_pod_grounded(msg.m_pod_grounded);
}
static void canzero_handle_mother_board_stream_input_board_command(canzero_frame* frame) {
  canzero_message_mother_board_stream_input_board_command msg;
  canzero_deserialize_canzero_message_mother_board_stream_input_board_command(frame, &msg);
  canzero_set_command(msg.m_input_board_command);
  canzero_set_assert_45V_system_online(msg.m_input_board_assert_45V_online);
}
static void canzero_handle_mother_board_stream_debug_settings(canzero_frame* frame) {
  canzero_message_mother_board_stream_debug_settings msg;
  canzero_deserialize_canzero_message_mother_board_stream_debug_settings(frame, &msg);
  canzero_set_ignore_45v(msg.m_ignore_45v);
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
      case 0x1BE:
        canzero_handle_get_req(&frame);
        break;
      case 0x4E:
        canzero_handle_mother_board_stream_input_board_command(&frame);
        break;
      case 0x51:
        canzero_handle_mother_board_stream_debug_settings(&frame);
        break;
      case 0x1F4:
        canzero_handle_heartbeat_can0(&frame);
        break;
    }
  }
}
void canzero_can1_poll() {
  canzero_frame frame;
  while (canzero_can1_recv(&frame)) {
    switch (frame.id) {
      case 0x1DE:
        canzero_handle_set_req(&frame);
        break;
      case 0x4C:
        canzero_handle_mother_board_stream_motor_command(&frame);
        break;
      case 0x1F3:
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
  __oe_config_hash = 15293460524362237552ull;
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
  schedule_state_interval_job();
  schedule_position_estimation_interval_job();
  schedule_config_hash_interval_job();
  schedule_errors_interval_job();
  schedule_errors2_interval_job();
  schedule_linear_encoder_interval_job();
  schedule_accelerations_interval_job();
  schedule_bat24_interval_job();
  schedule_link24_interval_job();
  schedule_link45_interval_job();
  schedule_mics_temperatures_interval_job();
  schedule_bat_temperatures_interval_job();
  schedule_ambient_temperatures_interval_job();
  schedule_power_consumption_interval_job();

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
void canzero_set_state(input_board_state value) {
  extern input_board_state __oe_state;
  if (__oe_state != value) {
    __oe_state = value;
    if (state_interval_job.climax > state_interval_job.job.stream_job.last_schedule + 1) {
      state_interval_job.climax = state_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&state_interval_job);
    }
  }
}
void canzero_set_sdc_status(sdc_status value) {
  extern sdc_status __oe_sdc_status;
  if (__oe_sdc_status != value) {
    __oe_sdc_status = value;
    if (state_interval_job.climax > state_interval_job.job.stream_job.last_schedule + 1) {
      state_interval_job.climax = state_interval_job.job.stream_job.last_schedule + 1;
      scheduler_promote_job(&state_interval_job);
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
void canzero_set_error_heartbeat_miss(error_flag value) {
  extern error_flag __oe_error_heartbeat_miss;
  if (__oe_error_heartbeat_miss != value) {
    __oe_error_heartbeat_miss = value;
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
void canzero_set_error_level_supercap_under_voltage(error_level value) {
  extern error_level __oe_error_level_supercap_under_voltage;
  if (__oe_error_level_supercap_under_voltage != value) {
    __oe_error_level_supercap_under_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_supercap_over_voltage(error_level value) {
  extern error_level __oe_error_level_supercap_over_voltage;
  if (__oe_error_level_supercap_over_voltage != value) {
    __oe_error_level_supercap_over_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_link24_over_current(error_level value) {
  extern error_level __oe_error_level_link24_over_current;
  if (__oe_error_level_link24_over_current != value) {
    __oe_error_level_link24_over_current = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_link45_under_voltage(error_level value) {
  extern error_level __oe_error_level_link45_under_voltage;
  if (__oe_error_level_link45_under_voltage != value) {
    __oe_error_level_link45_under_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_voltage(error_level value) {
  extern error_level __oe_error_level_link45_over_voltage;
  if (__oe_error_level_link45_over_voltage != value) {
    __oe_error_level_link45_over_voltage = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_current(error_level value) {
  extern error_level __oe_error_level_link45_over_current;
  if (__oe_error_level_link45_over_current != value) {
    __oe_error_level_link45_over_current = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_mcu_temperature(error_level value) {
  extern error_level __oe_error_level_mcu_temperature;
  if (__oe_error_level_mcu_temperature != value) {
    __oe_error_level_mcu_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_temperature(error_level value) {
  extern error_level __oe_error_level_bat24_temperature;
  if (__oe_error_level_bat24_temperature != value) {
    __oe_error_level_bat24_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_supercap_temperature(error_level value) {
  extern error_level __oe_error_level_supercap_temperature;
  if (__oe_error_level_supercap_temperature != value) {
    __oe_error_level_supercap_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_sac_ebox_temperature(error_level value) {
  extern error_level __oe_error_level_sac_ebox_temperature;
  if (__oe_error_level_sac_ebox_temperature != value) {
    __oe_error_level_sac_ebox_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_power_ebox_temperature(error_level value) {
  extern error_level __oe_error_level_power_ebox_temperature;
  if (__oe_error_level_power_ebox_temperature != value) {
    __oe_error_level_power_ebox_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
void canzero_set_error_level_ambient_temperature(error_level value) {
  extern error_level __oe_error_level_ambient_temperature;
  if (__oe_error_level_ambient_temperature != value) {
    __oe_error_level_ambient_temperature = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
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
void canzero_set_last_node_missed(uint8_t value) {
  extern uint8_t __oe_last_node_missed;
  if (__oe_last_node_missed != value) {
    __oe_last_node_missed = value;
    if (errors2_interval_job.climax > errors2_interval_job.job.stream_job.last_schedule + 0) {
      errors2_interval_job.climax = errors2_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors2_interval_job);
    }
  }
}
static uint32_t DMAMEM __oe_config_hash_send_fragmentation_buffer[2];
static uint32_t DMAMEM __oe_build_time_send_fragmentation_buffer[2];
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
void canzero_send_state() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_state) & (0xFF >> (8 - 2)))) << 0;
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
void canzero_send_sdc_status() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_sdc_status) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_position() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_position - (-10)) / 0.0007629510948348211, 0xFFFF) << 0;
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
void canzero_send_velocity() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_velocity - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
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
void canzero_send_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
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
void canzero_send_assertion_fault() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_acceleration_out_of_range() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_lateral_acceleration_out_of_range() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_lateral_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_vertical_acceleration_out_of_range() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_vertical_acceleration_out_of_range) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_acceleration_calibration_failed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_acceleration_calibration_failed) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_bat24_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_bat24_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_supercap_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_supercap_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_link24_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_link24_current_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_link45_voltage_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_voltage_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_link45_current_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_link45_current_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_mcu_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_mcu_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_sac_ebox_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_sac_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_power_ebox_temperature_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_power_ebox_temperature_invalid) & (0xFF >> (8 - 1)))) << 0;
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
void canzero_send_error_bat24_cell_temperature_1_invalid() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_bat24_cell_temperature_1_invalid) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 21;
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
  msg.m_header.m_od_index = 22;
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
  msg.m_header.m_od_index = 23;
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
  msg.m_header.m_od_index = 24;
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
  msg.m_header.m_od_index = 25;
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
  msg.m_header.m_od_index = 26;
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
  msg.m_header.m_od_index = 27;
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
  msg.m_header.m_od_index = 28;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_bat24_over_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
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
void canzero_send_error_level_bat24_over_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 30;
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
  msg.m_header.m_od_index = 31;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_supercap_over_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_over_voltage) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 32;
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
  msg.m_header.m_od_index = 33;
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
  msg.m_header.m_od_index = 34;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_error_level_link45_over_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_voltage) & (0xFF >> (8 - 2)))) << 0;
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
void canzero_send_error_level_link45_over_current() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_current) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 36;
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
  msg.m_header.m_od_index = 37;
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
  msg.m_header.m_od_index = 38;
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
  msg.m_header.m_od_index = 39;
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
  msg.m_header.m_od_index = 40;
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
  msg.m_header.m_od_index = 41;
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
  msg.m_header.m_od_index = 42;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_command) & (0xFF >> (8 - 1)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 43;
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
  msg.m_header.m_od_index = 44;
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
  msg.m_header.m_od_index = 45;
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
  msg.m_header.m_od_index = 46;
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
  msg.m_header.m_od_index = 47;
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
  msg.m_header.m_od_index = 48;
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
  msg.m_header.m_od_index = 49;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_variance_send_fragmentation_buffer, 2, 49, 255);

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
  msg.m_header.m_od_index = 50;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_offset_send_fragmentation_buffer, 2, 50, 255);

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
  msg.m_header.m_od_index = 51;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_acceleration_calibration_target_send_fragmentation_buffer, 2, 51, 255);

}
void canzero_send_raw_lateral_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_raw_lateral_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 52;
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
  msg.m_header.m_od_index = 53;
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
  msg.m_header.m_od_index = 54;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_variance_send_fragmentation_buffer, 2, 54, 255);

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
  msg.m_header.m_od_index = 55;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_offset_send_fragmentation_buffer, 2, 55, 255);

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
  msg.m_header.m_od_index = 56;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_lateral_acceleration_calibration_target_send_fragmentation_buffer, 2, 56, 255);

}
void canzero_send_raw_vertical_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_raw_vertical_acceleration - (-50)) / 0.0015259021896696422, 0xFFFF) << 0;
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
void canzero_send_vertical_acceleration() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_vertical_acceleration - (-10)) / 0.00030518043793392844, 0xFFFF) << 0;
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
  msg.m_header.m_od_index = 59;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_variance_send_fragmentation_buffer, 2, 59, 255);

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
  msg.m_header.m_od_index = 60;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_offset_send_fragmentation_buffer, 2, 60, 255);

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
  msg.m_header.m_od_index = 61;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_vertical_acceleration_calibration_target_send_fragmentation_buffer, 2, 61, 255);

}
void canzero_send_track_length() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_track_length - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
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
void canzero_send_bat24_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
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
void canzero_send_bat24_voltage_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_bat24_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
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
void canzero_send_bat24_voltage_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
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
void canzero_send_bat24_voltage_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
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
  msg.m_header.m_od_index = 67;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_under_voltage_send_fragmentation_buffer, 7, 67, 255);

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
  msg.m_header.m_od_index = 68;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_voltage_send_fragmentation_buffer, 7, 68, 255);

}
void canzero_send_bat24_current() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
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
void canzero_send_bat24_current_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_bat24_current_calibration_offset - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 70;
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
  msg.m_header.m_od_index = 71;
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
  msg.m_header.m_od_index = 72;
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
  msg.m_header.m_od_index = 73;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_current_send_fragmentation_buffer, 7, 73, 255);

}
void canzero_send_supercap_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_voltage - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
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
void canzero_send_supercap_voltage_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_supercap_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
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
void canzero_send_supercap_voltage_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_voltage_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
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
void canzero_send_supercap_voltage_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_voltage_calibration_target - (0)) / 0.000000011641532185403987, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 77;
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
  msg.m_header.m_od_index = 78;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_under_voltage_send_fragmentation_buffer, 7, 78, 255);

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
  msg.m_header.m_od_index = 79;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_over_voltage_send_fragmentation_buffer, 7, 79, 255);

}
void canzero_send_link24_current() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link24_current - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
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
void canzero_send_link24_current_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_link24_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
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
void canzero_send_link24_current_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link24_current_calibration_offset - (-10)) / 0.000000004656612874161595, 0xFFFFFFFF) << 0;
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
void canzero_send_link24_current_calibration_target() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link24_current_calibration_target - (-30)) / 0.000000013969838622484784, 0xFFFFFFFF) << 0;
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
  msg.m_header.m_od_index = 84;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_current_send_fragmentation_buffer, 7, 84, 255);

}
void canzero_send_link45_voltage() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_voltage - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
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
void canzero_send_link45_voltage_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_link45_voltage_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 86;
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
  msg.m_header.m_od_index = 87;
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
  msg.m_header.m_od_index = 88;
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
  msg.m_header.m_od_index = 89;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_under_voltage_send_fragmentation_buffer, 7, 89, 255);

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
  msg.m_header.m_od_index = 90;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_voltage_send_fragmentation_buffer, 7, 90, 255);

}
void canzero_send_link45_current() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_current - (-1000)) / 0.0000004656612874161595, 0xFFFFFFFF) << 0;
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
void canzero_send_link45_current_calibration_mode() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe_link45_current_calibration_mode) & (0xFF >> (8 - 2)))) << 0;
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
void canzero_send_link45_current_calibration_offset() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_link45_current_calibration_offset - (-100)) / 0.00000004656612874161595, 0xFFFFFFFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 93;
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
  msg.m_header.m_od_index = 94;
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
  msg.m_header.m_od_index = 95;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_current_send_fragmentation_buffer, 7, 95, 255);

}
void canzero_send_mcu_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_mcu_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
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
  msg.m_header.m_od_index = 101;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_temperature_send_fragmentation_buffer, 7, 101, 255);

}
void canzero_send_supercap_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_supercap_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
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
  msg.m_header.m_od_index = 103;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_temperature_send_fragmentation_buffer, 7, 103, 255);

}
void canzero_send_sac_ebox_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_sac_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 104;
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
  msg.m_header.m_od_index = 105;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_sac_ebox_temperature_send_fragmentation_buffer, 7, 105, 255);

}
void canzero_send_power_ebox_temperature() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_power_ebox_temperature - (-1)) / 0.592156862745098, 0xFF) << 0;
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
  msg.m_header.m_od_index = 107;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_power_ebox_temperature_send_fragmentation_buffer, 7, 107, 255);

}
void canzero_send_ambient_temperature_1() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_ambient_temperature_1 - (-1)) / 0.592156862745098, 0xFF) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 108;
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
  msg.m_header.m_od_index = 109;
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
  msg.m_header.m_od_index = 110;
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
  msg.m_header.m_od_index = 111;
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
  msg.m_header.m_od_index = 112;
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
  msg.m_header.m_od_index = 113;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
  schedule_get_resp_fragmentation_job(__oe_error_level_config_ambient_temperature_send_fragmentation_buffer, 7, 113, 255);

}
void canzero_send_cooling_cycle_flow_rate() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_cooling_cycle_flow_rate - (0)) / 0.00392156862745098, 0xFF) << 0;
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
void canzero_send_loop_frequency() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_loop_frequency - (0)) / 0.00000023283064370807974, 0xFFFFFFFF) << 0;
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
void canzero_send_last_node_missed() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(__oe_last_node_missed & (0xFF >> (8 - 8)))) << 0;
  msg.m_header.m_eof = 1;
  msg.m_header.m_sof = 1;
  msg.m_header.m_toggle = 0;
  msg.m_header.m_od_index = 116;
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
  msg.m_header.m_od_index = 117;
  msg.m_header.m_client_id = 255;
  msg.m_header.m_server_id = node_id_input_board;
  canzero_frame sender_frame;
  canzero_serialize_canzero_message_get_resp(&msg, &sender_frame);
  canzero_can0_send(&sender_frame);
}
void canzero_send__motor_command() {
  canzero_message_get_resp msg;
  msg.m_data |= ((uint32_t)(((uint8_t)__oe__motor_command) & (0xFF >> (8 - 3)))) << 0;
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
void canzero_send_system_power_consumption() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_system_power_consumption - (0)) / 0.15259021896696423, 0xFFFF) << 0;
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
void canzero_send_communication_power_consumption() {
  canzero_message_get_resp msg;
  msg.m_data |= min_u32((__oe_communication_power_consumption - (0)) / 0.007629510948348211, 0xFFFF) << 0;
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
