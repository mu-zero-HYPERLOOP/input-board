#pragma once

#include "canzero/canzero.h"
namespace fsm::error_handling {

global_command approve(global_command cmd);

global_state invariant_broken();

global_state invariant_broken_idle();

} // namespace fsm::error_handling
