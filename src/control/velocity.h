#pragma once

#include "util/metrics.h"
namespace control::velocity {

void begin();


/// Sets the target acceleration
void target_velocity(const Velocity& velocity);

/// Enables the control
void enable();

/// Disables the control setting target acceleration to zero.
void disable();

void update();

}
