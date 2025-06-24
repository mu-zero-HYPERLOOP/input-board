#include "canzero/canzero.h"
#include "control/velocity.h"
#include "fsm/error_handling.h"
#include "fsm/states.h"
#include "fsm/invariants.h"
#include "fsm/sdc.h"
#include "fsm/subsystems.h"
#include <array>

constexpr std::array<guidance_state, 2>
  ALLOWED_GUIDANCE_STATES = {guidance_state_CONTROL, guidance_state_READY};

constexpr Duration MIN_STATE_TIME = 1_s;

constexpr Duration STATE_TIMEOUT = 5_s;


// Invariants: 
// - guidance is in [control, ready]
// - levitation is in control
// - motor is in ready
// - input board is running
// - pdus are running
// - sdc is closed
// Exit condition:
// - Guidance is stopped
global_state fsm::states::stop_guidance(global_command cmd, Duration time_since_last_transition) {
  using namespace fsm::invariant;

  const pdu_24v_state pdu24_state = canzero_get_power_board24_state();
  const pdu_12v_state pdu12_state = canzero_get_power_board12_state();

  const guidance_state g1_state = canzero_get_guidance_board_front_state();
  const guidance_state g2_state = canzero_get_guidance_board_back_state();

  const levitation_state l1_state = canzero_get_levitation_board1_state();
  const levitation_state l2_state = canzero_get_levitation_board2_state();
  const levitation_state l3_state = canzero_get_levitation_board3_state();

  const motor_state motor_state = canzero_get_motor_driver_state();

  if (global_command_RESTART == cmd){
    return global_state_RESTARTING;
  }

  // ================= TRANSITIONS =================
  if (global_command_SHUTDOWN == cmd){
    return global_state_SHUTDOWN;
  }

  if (global_command_EMERGENCY == cmd){
    return global_state_DISARMING45;
  }
  
  // Invariant: guidance
  if ((!contains(ALLOWED_GUIDANCE_STATES, g1_state)
      || !contains(ALLOWED_GUIDANCE_STATES, g2_state)) && !DISABLE_GUIDANCE_SUBSYSTEM){
    return error_handling::invariant_broken();
  }

  // Invariant: levitation 
  if ((levitation_state_CONTROL != l1_state
      || levitation_state_CONTROL != l2_state
      || levitation_state_CONTROL != l3_state) && !DISABLE_LEVITATION_SUBSYSTEM){
    return error_handling::invariant_broken();
  }

  // Invariant: motor
  if (motor_state_READY != motor_state && !DISABLE_MOTOR_SUBSYSTEM){
    return error_handling::invariant_broken();
  }

  // Invariant: pdus
  if ((pdu_12v_state_CHANNELS_ON != pdu12_state
      || pdu_24v_state_CHANNELS_ON != pdu24_state) && !DISABLE_POWER_SUBSYSTEM){
    return error_handling::invariant_broken();
  }

  // Invariant: sdc
  if (sdc::status() == sdc_status_OPEN){
    return error_handling::invariant_broken();
  }

  // Pod commands
  if (global_command_STOP_45 == cmd){
    return global_state_DISARMING45;
  }

  if (time_since_last_transition > STATE_TIMEOUT){
    canzero_set_global_command(global_command_NONE);
    return global_state_DISARMING45;
  }

  if (((guidance_state_READY == g1_state
      && guidance_state_READY == g2_state) || DISABLE_GUIDANCE_SUBSYSTEM)
      && time_since_last_transition > MIN_STATE_TIME){
    return global_state_STOP_LEVITATION;
  }

  // =================== OUTPUTS ===================
  canzero_set_guidance_command(guidance_command_STOP);
  canzero_set_levitation_command(levitation_command_NONE);
  canzero_set_motor_driver_command(motor_command_NONE);
  canzero_set_pod_grounded(bool_t_FALSE);
  canzero_set_power_board12_command(pdu_12v_command_NONE);
  canzero_set_power_board24_command(pdu_24v_command_NONE);
  canzero_set_assert_45V_system_online(bool_t_TRUE);
  control::velocity::disable();

  return global_state_STOP_GUIDANCE;
}
