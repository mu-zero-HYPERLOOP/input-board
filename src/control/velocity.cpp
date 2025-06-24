#include "control/velocity.h"
#include "canzero/canzero.h"
#include "util/interval.h"
#include "util/metrics.h"
#include "util/trapazoidal_integral.h"
#include <algorithm>

static bool enabled;

static Velocity target_v;

static TrapazoidalIntegral integral(0.0f);
static Interval control_interval(100_Hz);
static float prev_error;

constexpr Acceleration MAX_ACCEL = 1_mps2;

void control::velocity::begin() {
  enabled = false;

  canzero_set_velocity_pid(pid_parameters{
      .m_Kp = 1.0f,
      .m_Ki = 0.1f,
      .m_Kd = 0.0f,
  });
}

void control::velocity::target_velocity(const Velocity &velocity) {
  target_v = velocity;
}

void control::velocity::enable() { enabled = true; }
void control::velocity::disable() {
  enabled = false;
  integral.reset(0.0f);
  prev_error = 0.0f;
}

void control::velocity::update() {
  if (enabled) {
    if (control_interval.next()) {
      const pid_parameters pid = canzero_get_velocity_pid();
      const Velocity v = Velocity(canzero_get_velocity());
      // PID
      const float error = static_cast<float>(target_v - v);
      integral.integrate(error, control_interval.period());
      const float deriviate =
          (prev_error - error) / static_cast<float>(control_interval.period());

      const float control_output =
          error * pid.m_Kp + integral.get() * pid.m_Ki + deriviate * pid.m_Kd;

      prev_error = error;

      const Acceleration target_acceleration = Acceleration(
          std::clamp(control_output, -static_cast<float>(MAX_ACCEL),
                     static_cast<float>(MAX_ACCEL)));
      canzero_set_target_acceleration(static_cast<float>(target_acceleration));
    }
  } else {
    canzero_set_target_acceleration(0);
  }
}
