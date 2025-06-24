#pragma once

#include "util/timestamp.h"
#include "canzero/canzero.h"


namespace fsm::states {

global_state init(global_command cmd, Duration time_since_last_transition);

global_state idle(global_command cmd, Duration time_since_last_transition);

global_state arming45(global_command cmd, Duration time_since_last_transition);

global_state precharge(global_command cmd, Duration time_since_last_transition);

global_state disarming45(global_command cmd, Duration time_since_last_transition);

global_state ready(global_command cmd, Duration time_since_last_transition);

global_state start_levitation(global_command cmd, Duration time_since_last_transition);

global_state levitation_stable(global_command cmd, Duration time_since_last_transition);

global_state start_guidance(global_command cmd, Duration time_since_last_transition);

global_state guidance_stable(global_command cmd, Duration time_since_last_transition);

global_state acceleration(global_command cmd, Duration time_since_last_transition);

global_state deceleration(global_command cmd, Duration time_since_last_transition);

global_state cruising(global_command cmd, Duration time_since_last_transition);

global_state stop_levitation(global_command cmd, Duration time_since_last_transition);

global_state stop_guidance(global_command cmd, Duration time_since_last_transition);

global_state controller(global_command cmd, Duration time_since_last_transition);

global_state shutdown(global_command cmd, Duration time_since_last_transition);

global_state restarting(global_command cmd, Duration time_since_last_transition);

global_state calibrating(global_command cmd, Duration time_since_last_transition);


}
