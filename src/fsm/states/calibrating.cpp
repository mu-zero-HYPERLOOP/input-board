#include "canzero/canzero.h"
#include "fsm/states.h"
#include "fsm/subsystems.h"

// NOTE this is a bad hack!
// constexpr Duration START_CALIBRATION = 1_s;

// THIS STATE IS CURRENT NOT ACCESSIBLE (DISABLED)
global_state fsm::states::calibrating(global_command cmd,
                                   Duration time_since_last_transition) {

  if (global_command_RESTART == cmd){
    return global_state_RESTARTING;
  }

  if (DISABLE_INPUT_SUBSYSTEM){
    return global_state_IDLE;
  }

  canzero_set_assert_45V_system_online(bool_t_FALSE);

  canzero_set_pod_grounded(bool_t_TRUE);

  return global_state_IDLE;
}
