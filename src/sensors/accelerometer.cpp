#include "sensors/accelerometer.h"
#include "canzero/canzero.h"
#include "firmware/input_board.h"
#include "state_estimation.h"
#include "util/metrics.h"
#include <cassert>
#include <cmath>

static void on_value(const Acceleration &x, const Acceleration &y,
                     const Acceleration &z) {
  Timestamp now = Timestamp::now();
  Acceleration acc = x + Acceleration(canzero_get_acceleration_calibration_offset());
  Acceleration lateral = z + Acceleration(canzero_get_lateral_acceleration_calibration_offset());
  Acceleration vertical = y + Acceleration(canzero_get_vertical_acceleration_calibration_offset());
  canzero_set_raw_acceleration(static_cast<float>(acc));
  canzero_set_raw_lateral_acceleration(static_cast<float>(lateral));
  canzero_set_raw_vertical_acceleration(static_cast<float>(vertical));
  state_estimation::acceleration_update(acc, now);
  //TODO update state estimation!
}

void sensors::accelerometer::begin() {
  assert(input_board::register_periodic_accelerometer_reading(MEAS_FREQUENCY,
        input_board::AccelerometerRange::ACCEL_RANGE_1G,
                                                              on_value));
}

void sensors::accelerometer::calibrate() {
  Acceleration x_sum = 0_mps2;
  Acceleration y_sum = 0_mps2;
  Acceleration z_sum = 0_mps2;

  constexpr size_t MEAN_ESTIMATION_IT = 1000;
  for (unsigned int i = 0; i < MEAN_ESTIMATION_IT; ++i) {
    const auto &[x, y, z] = input_board::sync_read_acceleration();
    x_sum += x;
    y_sum += y;
    z_sum += z;
  }
  Acceleration x_average = x_sum / MEAN_ESTIMATION_IT;
  Acceleration x_expected = Acceleration(canzero_get_acceleration_calibration_target());
  Acceleration x_offset = x_expected - x_average;
  canzero_set_acceleration_calibration_offset(static_cast<float>(x_offset));

  Acceleration z_average = y_sum / MEAN_ESTIMATION_IT;
  Acceleration z_expected = Acceleration(canzero_get_lateral_acceleration_calibration_target());
  Acceleration z_offset = z_expected - z_average;
  canzero_set_acceleration_calibration_offset(static_cast<float>(z_offset));

  Acceleration y_average = z_sum / MEAN_ESTIMATION_IT;
  Acceleration y_expected = Acceleration(canzero_get_vertical_acceleration_calibration_target());
  Acceleration y_offset = y_expected - y_average;
  canzero_set_vertical_acceleration_calibration_offset(static_cast<float>(y_offset));

  constexpr size_t VARIANCE_ESTIMATION_IT = 1000;
  float x_var = 0;
  float y_var = 0;
  float z_var = 0;
  for (unsigned int i = 0; i < VARIANCE_ESTIMATION_IT; ++i) {
    const auto &[x, y, z] = input_board::sync_read_acceleration();
    x_var += std::pow(static_cast<float>((x - x_average)),2);
    y_var += std::pow(static_cast<float>((y - y_average)),2);
    z_var += std::pow(static_cast<float>((z - z_average)),2);
  }
  x_var /= VARIANCE_ESTIMATION_IT - 1;
  y_var /= VARIANCE_ESTIMATION_IT - 1;
  z_var /= VARIANCE_ESTIMATION_IT - 1;
  x_var = std::sqrt(x_var);
  y_var = std::sqrt(y_var);
  z_var = std::sqrt(z_var);
  canzero_set_acceleration_calibration_variance(x_var);
  canzero_set_lateral_acceleration_calibration_variance(z_var);
  canzero_set_vertical_acceleration_calibration_variance(y_var);
}

void sensors::accelerometer::update() {

}
