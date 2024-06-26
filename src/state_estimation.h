#pragma once
#include "sensors/linear_encoder.h"
#include "util/metrics.h"
#include "util/timestamp.h"

namespace state_estimation {

constexpr Distance STRIPE_STRIDE = 2_cm;

void begin();

void calibrate();

void linear_encoder_update(
    const sensors::linear_encoder::LinearEncoderEventTag& tag,
    const Timestamp& timestamp);
void acceleration_update(const Acceleration &acc, const Timestamp &timestamp);

void target_acceleration_update(const Acceleration& acc, const Timestamp& timestamp);

int push_acceleration_event(const Acceleration& acc, const Timestamp& timestamp);
int push_position_event(const sensors::linear_encoder::LinearEncoderEvent& event);

void update();
} // namespace state_estimation
