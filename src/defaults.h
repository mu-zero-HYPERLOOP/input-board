#pragma once

#include "canzero/canzero.h"

static inline void can_defaults() {
  canzero_set_error_level_config_consistency(error_level_OK);
  canzero_set_power_board12_command(pdu_12v_command_START);

  canzero_set_global_state(global_state_CALIBRATING);
  canzero_set_global_command(global_command_NONE);
  canzero_set_assert_45V_system_online(bool_t_FALSE);
  canzero_set_sdc_status(sdc_status_OPEN);

  canzero_set_position(0);
  canzero_set_velocity(0);
  canzero_set_acceleration(0);
  canzero_set_absolute_position_known(bool_t_FALSE);
  canzero_set_absolute_position_offset(0);

  canzero_set_assertion_fault(error_flag_OK);

  canzero_set_last_node_missed(255);
  canzero_set_error_heartbeat_miss(error_flag_OK);
  canzero_set_error_bat24_current_invalid(error_flag_OK);
  canzero_set_error_bat24_voltage_invalid(error_flag_OK);
  canzero_set_error_link24_current_invalid(error_flag_OK);
  canzero_set_error_supercap_voltage_invalid(error_flag_OK);
  canzero_set_error_link45_current_invalid(error_flag_OK);
  canzero_set_error_link45_voltage_invalid(error_flag_OK);
  canzero_set_error_mcu_temperature_invalid(error_flag_OK);
  canzero_set_error_acceleration_out_of_range(error_flag_OK);
  canzero_set_error_supercap_temperature_invalid(error_flag_OK);
  canzero_set_error_acceleration_calibration_failed(error_flag_OK);
  canzero_set_error_lateral_acceleration_out_of_range(error_flag_OK);
  canzero_set_error_vertical_acceleration_out_of_range(error_flag_OK);

  canzero_set_error_ambient_temperature_1_invalid(error_flag_OK);
  canzero_set_error_ambient_temperature_2_invalid(error_flag_OK);
  canzero_set_error_ambient_temperature_3_invalid(error_flag_OK);

  canzero_set_error_guidance_front_magnet_temperature_left_invalid(
      error_flag_OK);
  canzero_set_error_guidance_front_magnet_temperature_right_invalid(
      error_flag_OK);
  canzero_set_error_guidance_back_magnet_temperature_left_invalid(
      error_flag_OK);
  canzero_set_error_guidance_back_magnet_temperature_right_invalid(
      error_flag_OK);

  canzero_set_error_level_guidance_front_magnet_temperature_left(
      error_level_OK);
  canzero_set_error_level_guidance_front_magnet_temperature_right(
      error_level_OK);
  canzero_set_error_level_guidance_back_magnet_temperature_left(error_level_OK);
  canzero_set_error_level_guidance_back_magnet_temperature_right(
      error_level_OK);

  canzero_set_error_levitation_front_magnet_temperature_left_invalid(
      error_flag_OK);
  canzero_set_error_levitation_front_magnet_temperature_right_invalid(
      error_flag_OK);
  canzero_set_error_levitation_middle_magnet_temperature_left_invalid(
      error_flag_OK);
  canzero_set_error_levitation_middle_magnet_temperature_right_invalid(
      error_flag_OK);
  canzero_set_error_levitation_back_magnet_temperature_left_invalid(
      error_flag_OK);
  canzero_set_error_levitation_back_magnet_temperature_right_invalid(
      error_flag_OK);

  canzero_set_error_level_levitation_front_magnet_temperature_left(
      error_level_OK);
  canzero_set_error_level_levitation_front_magnet_temperature_right(
      error_level_OK);
  canzero_set_error_level_levitation_middle_magnet_temperature_left(
      error_level_OK);
  canzero_set_error_level_levitation_middle_magnet_temperature_right(
      error_level_OK);
  canzero_set_error_level_levitation_back_magnet_temperature_left(
      error_level_OK);
  canzero_set_error_level_levitation_back_magnet_temperature_right(
      error_level_OK);

  canzero_set_error_level_mcu_temperature(error_level_OK);
  canzero_set_error_level_bat24_temperature(error_level_OK);
  canzero_set_error_level_bat24_over_current(error_level_OK);
  canzero_set_error_level_bat24_over_voltage(error_level_OK);
  canzero_set_error_level_bat24_under_voltage(error_level_OK);
  canzero_set_error_level_supercap_over_voltage(error_level_OK);
  canzero_set_error_level_link24_over_current(error_level_OK);
  canzero_set_error_level_link45_over_current(error_level_OK);
  canzero_set_error_level_link45_over_voltage(error_level_OK);
  canzero_set_error_level_ambient_temperature(error_level_OK);
  canzero_set_error_level_link45_under_voltage(error_level_OK);
  canzero_set_error_level_supercap_under_voltage(error_level_OK);
  canzero_set_error_level_supercap_temperature(error_level_OK);

  canzero_set_error_cooling_cycle_temp_begin_invalid(error_flag_OK);
  canzero_set_error_cooling_cycle_temp_end_invalid(error_flag_OK);

  canzero_set_error_cooling_flow_rate_low(error_flag_OK);
  canzero_set_error_cooling_flow_rate_mismatch(error_flag_OK);

  canzero_set_ignore_45v(bool_t_FALSE);

  canzero_set_system_power_consumption(0);
  canzero_set_communication_power_consumption(0);

  canzero_set_error_level_ambient_temperature(error_level_OK);
  canzero_set_error_ambient_temperature_1_invalid(error_flag_OK);
  canzero_set_error_ambient_temperature_2_invalid(error_flag_OK);
  canzero_set_error_ambient_temperature_3_invalid(error_flag_OK);

  canzero_set_ambient_temperature_avg(0);
  canzero_set_ambient_temperature_max(0);

  canzero_set_ambient_temperature_1(0);
  canzero_set_ambient_temperature_2(0);
  canzero_set_ambient_temperature_3(0);

  canzero_set_error_supercap_temperature_invalid(error_flag_OK);
  canzero_set_error_level_supercap_temperature(error_level_OK);
  canzero_set_supercap_temperature(0);

  canzero_set_sac_ebox_temperature(0);
  canzero_set_power_ebox_temperature(0);
  canzero_set_error_power_ebox_temperature_invalid(error_flag_OK);
  canzero_set_error_sac_ebox_temperature_invalid(error_flag_OK);
  canzero_set_error_level_power_ebox_temperature(error_level_OK);
  canzero_set_error_level_power_ebox_temperature(error_level_OK);

  canzero_set_guidance_board_back_error_level_magnet_temperature_left(error_level_OK);
  canzero_set_guidance_board_front_error_level_magnet_temperature_left(error_level_OK);
  canzero_set_guidance_back_magnet_temperature_left(0);
  canzero_set_guidance_back_magnet_temperature_right(0);
  canzero_set_guidance_front_magnet_temperature_left(0);
  canzero_set_guidance_front_magnet_temperature_right(0);

  canzero_set_error_guidance_back_magnet_temperature_left_invalid(error_flag_OK);
  canzero_set_error_guidance_back_magnet_temperature_right_invalid(error_flag_OK);
  canzero_set_error_guidance_front_magnet_temperature_left_invalid(error_flag_OK);
  canzero_set_error_guidance_front_magnet_temperature_right_invalid(error_flag_OK);
}
