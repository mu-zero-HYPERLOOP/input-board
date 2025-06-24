#include "canzero/canzero.h"
#include "control/velocity.h"
#include "fsm/error_handling.h"
#include "fsm/states.h"
#include "fsm/sdc.h"
#include "fsm/subsystems.h"
#include "print.h"

// Invariants:
// - All system in idle!
// - SDC open
global_state fsm::states::idle(global_command cmd,
                               Duration time_since_last_transition) {

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

  if (global_command_SHUTDOWN == cmd){
    return global_state_SHUTDOWN;
  }

  // Invariant: guidance
  if ((guidance_state_IDLE != g1_state || guidance_state_IDLE != g2_state) &&
      !DISABLE_GUIDANCE_SUBSYSTEM) {
    debugPrintf("GUIDANCE Invariant Broken\n");
    return fsm::error_handling::invariant_broken_idle();
  }

  // Invariant: levitation
  if ((levitation_state_IDLE != l1_state || levitation_state_IDLE != l2_state ||
       levitation_state_IDLE != l3_state) &&
      !DISABLE_LEVITATION_SUBSYSTEM) {
    debugPrintf("LEVITATION Invariant broken: %d, %d, %d\n", l1_state, l2_state, l3_state);
    return fsm::error_handling::invariant_broken_idle();
  }
  // Invariant: motor
  if (motor_state_IDLE != motor_state && !DISABLE_MOTOR_SUBSYSTEM) {
    debugPrintf("Motor Invariant Broken\n");
    return fsm::error_handling::invariant_broken_idle();
  }

  // Invariant: PDUs
  if ((pdu_12v_state_CHANNELS_ON != pdu12_state || pdu_24v_state_CHANNELS_ON != pdu24_state) &&
      !DISABLE_POWER_SUBSYSTEM) {
    debugPrintf("Pdu Invariant Broken\n");
    return fsm::error_handling::invariant_broken_idle();
  }

  // Invariant: SDC
  if (sdc::status() != sdc_status_OPEN) {
    debugPrintf("SDC Invariant broken\n");
    return fsm::error_handling::invariant_broken_idle();
  }

  // ================ TRANSITIONS ==================
  if (global_command_START_45 == cmd) {
    return global_state_ARMING45;
  }

  // ================== OUTPUT =====================
  canzero_set_guidance_command(guidance_command_NONE);
  canzero_set_levitation_command(levitation_command_NONE);
  canzero_set_motor_driver_command(motor_command_NONE);
  canzero_set_pod_grounded(bool_t_TRUE);
  canzero_set_power_board12_command(pdu_12v_command_NONE);
  canzero_set_power_board24_command(pdu_24v_command_NONE);
  canzero_set_assert_45V_system_online(bool_t_FALSE);
  control::velocity::disable();

  return global_state_IDLE;
}
