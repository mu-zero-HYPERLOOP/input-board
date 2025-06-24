#include "canzero/canzero.h"
#include "control/velocity.h"
#include "fsm/error_handling.h"
#include "fsm/invariants.h"
#include "fsm/sdc.h"
#include "fsm/states.h"
#include "fsm/subsystems.h"
#include <array>

// Note: start is allowed, because we can access this state from start directly
// skipping the "stable" states completely! especially important for safe error
// handling!
constexpr std::array<levitation_state, 4> ALLOWED_LEVITATION_STATES = {
    levitation_state_CONTROL, levitation_state_STOP, levitation_state_READY,
    levitation_state_START};

constexpr Duration STATE_TIMEOUT = 10_s;

// Invariants:
// - guidance is ready
// - levitation is in [control, stop, ready]
// - motor is ready
// - input board is running
// - pdus are running
// - sdc is closed.
// Exit condition:
// - all systems in ready.
global_state fsm::states::stop_levitation(global_command cmd,
                                          Duration time_since_last_transition) {
  using namespace fsm::invariant;

  const pdu_24v_state pdu24_state = canzero_get_power_board24_state();
  const pdu_12v_state pdu12_state = canzero_get_power_board12_state();

  const guidance_state g1_state = canzero_get_guidance_board_front_state();
  const guidance_state g2_state = canzero_get_guidance_board_back_state();

  const levitation_state l1_state = canzero_get_levitation_board1_state();
  const levitation_state l2_state = canzero_get_levitation_board2_state();
  const levitation_state l3_state = canzero_get_levitation_board3_state();

  const motor_state motor_state = canzero_get_motor_driver_state();

  if (global_command_RESTART == cmd) {
    return global_state_RESTARTING;
  }

  // ================== TRANSITIONS ==============
  if (global_command_SHUTDOWN == cmd) {
    return global_state_SHUTDOWN;
  }

  if (global_command_EMERGENCY == cmd) {
    return global_state_DISARMING45;
  }

  // Invariant: guidance
  if ((guidance_state_READY != g1_state || guidance_state_READY != g2_state) &&
      !DISABLE_GUIDANCE_SUBSYSTEM) {
    return error_handling::invariant_broken();
  }

  // Invariant: levitation
  if ((!contains(ALLOWED_LEVITATION_STATES, l1_state) ||
       !contains(ALLOWED_LEVITATION_STATES, l2_state) ||
       !contains(ALLOWED_LEVITATION_STATES, l3_state)) &&
      !DISABLE_LEVITATION_SUBSYSTEM) {
    return error_handling::invariant_broken();
  }

  // Invariant: motor
  if (motor_state_READY != motor_state && !DISABLE_MOTOR_SUBSYSTEM) {
    return global_state_DISARMING45;
  }

  // Invariant: pdus
  if ((pdu_12v_state_CHANNELS_ON != pdu12_state ||
       pdu_24v_state_CHANNELS_ON != pdu24_state) &&
      !DISABLE_POWER_SUBSYSTEM) {
    return error_handling::invariant_broken();
  }

  // Invariant: sdc
  if (sdc::status() == sdc_status_OPEN) {
    return error_handling::invariant_broken();
  }

  if (time_since_last_transition > STATE_TIMEOUT) {
    canzero_set_global_command(global_command_NONE);
    return global_state_DISARMING45;
  }

  // Pod command
  if (global_command_STOP_45 == cmd) {
    return global_state_DISARMING45;
  }

  // Exit condition
  if ((levitation_state_READY == l1_state &&
       levitation_state_READY == l2_state &&
       levitation_state_READY == l3_state) ||
      DISABLE_LEVITATION_SUBSYSTEM) {
    return global_state_READY;
  }

  // ==================== OUTPUTS ================
  canzero_set_guidance_command(guidance_command_NONE);
  canzero_set_levitation_command(levitation_command_STOP);
  canzero_set_motor_driver_command(motor_command_NONE);
  canzero_set_pod_grounded(bool_t_FALSE);
  canzero_set_power_board12_command(pdu_12v_command_NONE);
  canzero_set_power_board24_command(pdu_24v_command_NONE);
  canzero_set_assert_45V_system_online(bool_t_TRUE);
  control::velocity::disable();

  return global_state_STOP_LEVITATION;
}
