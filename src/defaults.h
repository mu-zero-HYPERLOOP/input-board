#pragma once

#include "canzero/canzero.h"

static void can_defaults() {
  canzero_set_state(input_board_state_INIT);
  canzero_set_command(input_board_command_NONE);
  canzero_set_assert_45V_system_online(bool_t_FALSE);
  canzero_set_sdc_status(sdc_status_OPEN);
  canzero_set_assert_45V_system_online(bool_t_FALSE);
  canzero_set_assertion_fault(error_flag_OK);
}
