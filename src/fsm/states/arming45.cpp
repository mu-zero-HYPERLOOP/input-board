#include "canzero/canzero.h"
#include "control/velocity.h"
#include "fsm/error_handling.h"
#include "fsm/invariants.h"
#include "fsm/sdc.h"
#include "fsm/states.h"
#include "fsm/subsystems.h"
#include "print.h"
#include <array>

constexpr std::array<guidance_state, 2> ALLOWED_GUIDANCE_STATES = {
    guidance_state_IDLE, guidance_state_ARMING45};

constexpr std::array<levitation_state, 2> ALLOWED_LEVITATION_STATES = {
    levitation_state_IDLE, levitation_state_ARMING45};

constexpr std::array<motor_state, 2> ALLOWED_MOTOR_STATES = {
    motor_state_IDLE, motor_state_ARMING45};

constexpr Duration STATE_TIMEOUT = 2_s;

// Invariant:
// - guidance is [idle, arming45]
// - levitation is [idle, arming45]
// - motor is [idle, arming45]
// - input board is running
// - all PDU 12V channels are on
// - PDU 24V is in [idle, channels_on]
// Exit condition:
// - The SDC is closed.
// - PDU 24V is in state channels_on
global_state fsm::states::arming45(global_command cmd,
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

  // Invariant: guidance state
  if ((!contains(ALLOWED_GUIDANCE_STATES, g1_state) ||
       !contains(ALLOWED_GUIDANCE_STATES, g2_state)) &&
      !DISABLE_GUIDANCE_SUBSYSTEM) {
    debugPrintf("GUIDANCE INVARIANT BROKEN\n");
    return fsm::error_handling::invariant_broken();
  }

  // Invariant: levitation state
  if ((!contains(ALLOWED_LEVITATION_STATES, l1_state) ||
       !contains(ALLOWED_LEVITATION_STATES, l2_state) ||
       !contains(ALLOWED_LEVITATION_STATES, l3_state)) &&
      !DISABLE_LEVITATION_SUBSYSTEM) {
    debugPrintf("LEVI INVARIANT Broken\n");
    return fsm::error_handling::invariant_broken();
  }

  // Invariant: motor state
  if (!contains(ALLOWED_MOTOR_STATES, motor_state) &&
      !DISABLE_MOTOR_SUBSYSTEM) {
    debugPrintf("Motor Invariant Broken\n");
    return fsm::error_handling::invariant_broken();
  }

  // Invariant: PDUs
  if ((pdu_12v_state_CHANNELS_ON != pdu12_state ||
       pdu_24v_state_CHANNELS_ON != pdu24_state) &&
      !DISABLE_POWER_SUBSYSTEM) {
    debugPrintf("PDU Invariant Broken\n");
    return fsm::error_handling::invariant_broken();
  }

  // ============== TRANSITIONS ==============
  if (global_command_SHUTDOWN == cmd) {
    return global_state_SHUTDOWN;
  }

  if (global_command_EMERGENCY == cmd) {
    return global_state_DISARMING45;
  }

  if (global_command_STOP_45 == cmd || global_command_ABORT == cmd) {
    debugPrintf("ARMING Aborted\n");
    return global_state_DISARMING45;
  }

  if (time_since_last_transition > STATE_TIMEOUT) {
    debugPrintf("ARMING timeout\n");
    return fsm::error_handling::invariant_broken();
  }

  // Transition into precharge iff.
  // - input board is running
  // - all pdu channels are on
  // - guidance is in arming45
  // - levitation is in arming45
  // - motor is in arming45
  // - SDC IS CLOSED!!!
  if (((pdu_12v_state_CHANNELS_ON == pdu12_state &&
        pdu_24v_state_CHANNELS_ON == pdu24_state) ||
       DISABLE_POWER_SUBSYSTEM) &&

      ((guidance_state_ARMING45 == g1_state &&
        guidance_state_ARMING45 == g2_state) ||
       DISABLE_GUIDANCE_SUBSYSTEM) &&

      ((levitation_state_ARMING45 == l1_state &&
        levitation_state_ARMING45 == l2_state &&
        levitation_state_ARMING45 == l3_state) ||
       DISABLE_LEVITATION_SUBSYSTEM) &&

      (motor_state_ARMING45 == motor_state || DISABLE_MOTOR_SUBSYSTEM) &&

      sdc::status() == sdc_status_CLOSED

      && time_since_last_transition > 1000_ms) {
    return global_state_PRECHARGE;
  }

  // =========== OUTPUT ===========
  canzero_set_guidance_command(guidance_command_ARM45);
  canzero_set_levitation_command(levitation_command_ARM45);
  canzero_set_motor_driver_command(motor_command_ARM45);
  canzero_set_pod_grounded(bool_t_TRUE);
  canzero_set_power_board12_command(pdu_12v_command_NONE);
  canzero_set_power_board24_command(pdu_24v_command_NONE);
  canzero_set_assert_45V_system_online(
      time_since_last_transition > 500_ms ? bool_t_TRUE : bool_t_FALSE);
  control::velocity::disable();

  return global_state_ARMING45;
}
