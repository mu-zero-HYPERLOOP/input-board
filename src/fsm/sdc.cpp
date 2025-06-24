#include "fsm/sdc.h"
#include "canzero/canzero.h"
#include "subsystems.h"

sdc_status sdc::status() {

  if (canzero_get_sdc_status() == sdc_status_OPEN && !DISABLE_INPUT_SUBSYSTEM) {
    return sdc_status_OPEN;
  }

  if ((canzero_get_power_board12_sdc_status() == sdc_status_OPEN ||
       canzero_get_power_board24_sdc_status() == sdc_status_OPEN) &&
      !DISABLE_POWER_SUBSYSTEM) {
    return sdc_status_OPEN;
  }

  if ((canzero_get_guidance_board_front_sdc_status() == sdc_status_OPEN ||
       canzero_get_guidance_board_back_sdc_status() == sdc_status_OPEN) &&
      !DISABLE_GUIDANCE_SUBSYSTEM) {
    return sdc_status_OPEN;
  }

  if ((canzero_get_levitation_board1_sdc_status() == sdc_status_OPEN ||
       canzero_get_levitation_board2_sdc_status() == sdc_status_OPEN ||
       canzero_get_levitation_board3_sdc_status() == sdc_status_OPEN) &&
      !DISABLE_LEVITATION_SUBSYSTEM) {
    return sdc_status_OPEN;
  }

  if (canzero_get_motor_driver_sdc_status() == sdc_status_OPEN &&
      !DISABLE_MOTOR_SUBSYSTEM) {
    return sdc_status_OPEN;
  }

  if (DISABLE_GUIDANCE_SUBSYSTEM && DISABLE_LEVITATION_SUBSYSTEM &&
      DISABLE_MOTOR_SUBSYSTEM && DISABLE_INPUT_SUBSYSTEM &&
      DISABLE_POWER_SUBSYSTEM) {
    switch (canzero_get_global_state()) {
    case global_state_INIT:
    case global_state_IDLE:
    case global_state_DISARMING45:
    case global_state_SHUTDOWN:
    case global_state_RESTARTING:
    case global_state_CALIBRATING:
      return sdc_status_OPEN;
    case global_state_ARMING45:
    case global_state_PRECHARGE:
    case global_state_READY:
    case global_state_START_LEVITATION:
    case global_state_LEVITATION_STABLE:
    case global_state_START_GUIDANCE:
    case global_state_GUIDANCE_STABLE:
    case global_state_ACCELERATION:
    case global_state_CONTROLLER:
    case global_state_CRUISING:
    case global_state_DECELERATION:
    case global_state_STOP_LEVITATION:
    case global_state_STOP_GUIDANCE:
      return sdc_status_CLOSED;
    }
  }

  return sdc_status_CLOSED;
}
