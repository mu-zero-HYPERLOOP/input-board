#pragma once
#include "core_pins.h"
#include "firmware/pinout.h"
#include "util/metrics.h"
#include <SparkFunADXL313.h>
#include <cassert>
#include <numeric>
#include <random>

class Accelerometer {
public:
  static void begin() {
    Serial.printf("Hello, world\n");
    assert(m_adxl.beginSPI(ACCEL_CS));
    m_adxl.setRange(ADXL313_RANGE_2_G);
    m_adxl.setFullResBit(true);
    m_adxl.setFifoMode(ADXL313_FIFO_MODE_FIFO);
    m_adxl.setAxisOffset(0, 0, 0);
    m_adxl.setRate(3200); // lowest possible data rate!
    m_adxl.clearFifo();
    m_adxl.measureModeOn();
  }

  static void calibrate() {
    delay(1000);
    float x_error = 0.0f;
    float y_error = 0.0f;
    float z_error = 0.0f;
    m_adxl.setAxisOffset(0, 0, 0);
    m_adxl.clearFifo();
    while (!m_adxl.dataReady()) { // clear fifo completely
    }
    m_adxl.readAccel();

    for (unsigned int i = 0; i < CALIBRATION_ROUNDS; ++i) {
      /* Serial.printf("Accelerometer Calibration round %u\n", i); */
      std::array<int16_t, CALIBRATION_SAMPLES> x_samples, y_samples, z_samples;
      for (int i = 0; i < CALIBRATION_SAMPLES; ++i) {
        while (!m_adxl.dataReady()) {
        }
        m_adxl.readAccel();
        x_samples[i] = m_adxl.x;
        y_samples[i] = m_adxl.y;
        z_samples[i] = m_adxl.z;
        delay(1);
      }

      float x_average = std::accumulate(x_samples.begin(), x_samples.end(), 0) /
                        static_cast<float>(CALIBRATION_SAMPLES);
      float y_average = std::accumulate(y_samples.begin(), y_samples.end(), 0) /
                        static_cast<float>(CALIBRATION_SAMPLES);
      float z_average = std::accumulate(z_samples.begin(), z_samples.end(), 0) /
                        static_cast<float>(CALIBRATION_SAMPLES);

      float x_mean = x_average / RESOLUTION;
      float y_mean = y_average / RESOLUTION;
      float z_mean = z_average / RESOLUTION;

      float x_round_error = (EXPECTED_X / G) - x_mean;
      float y_round_error = (EXPECTED_Y / G) - y_mean;
      float z_round_error = (EXPECTED_Z / G) - z_mean;

      constexpr double LSBpG = 3.9e-3;

      x_error += std::round(x_round_error / LSBpG) * LSBpG;
      y_error += std::round(y_round_error / LSBpG) * LSBpG;
      z_error += std::round(z_round_error / LSBpG) * LSBpG;
      Serial.printf("x-error : %f (%f) [%i]\n", x_error, x_round_error, (int)std::round(x_round_error / LSBpG));
      Serial.printf("y-error : %f (%f) [%i]\n", y_error, y_round_error, (int)std::round(y_round_error / LSBpG));
      Serial.printf("z-error : %f (%f) [%i]\n", z_error, z_round_error, (int)std::round(z_round_error / LSBpG));
      m_adxl.setAxisOffset(std::round(x_error / LSBpG),
                           std::round(y_error / LSBpG),
                           std::round(z_error / LSBpG));

      m_adxl.clearFifo();
      while (!m_adxl.dataReady()) { // clear
      }
      m_adxl.readAccel();
    }
  }

  static std::tuple<std::normal_distribution<float>,
                    std::normal_distribution<float>,
                    std::normal_distribution<float>>
  estimate_distribution() {
    std::array<float, ESTIMATION_SAMPLES> x_samples, y_samples, z_samples;
    for (int i = 0; i < ESTIMATION_SAMPLES; ++i) {
      while (!m_adxl.dataReady()) {
      }
      m_adxl.readAccel();
      x_samples[i] = (m_adxl.x / RESOLUTION) * static_cast<float>(G);
      y_samples[i] = (m_adxl.y / RESOLUTION) * static_cast<float>(G);
      z_samples[i] = (m_adxl.z / RESOLUTION) * static_cast<float>(G);
      delay(10);
    }

    float x_mean = std::accumulate(x_samples.begin(), x_samples.end(), 0.0f) /
                   static_cast<float>(ESTIMATION_SAMPLES);
    float y_mean = std::accumulate(y_samples.begin(), y_samples.end(), 0.0f) /
                   static_cast<float>(ESTIMATION_SAMPLES);
    float z_mean = std::accumulate(z_samples.begin(), z_samples.end(), 0.0f) /
                   static_cast<float>(ESTIMATION_SAMPLES);

    double x_variance = 0;
    double y_variance = 0;
    double z_variance = 0;
    for (unsigned int i = 0; i < ESTIMATION_SAMPLES; ++i) {
      x_variance += std::pow(x_samples[i] - x_mean, 2);
      y_variance += std::pow(y_samples[i] - y_mean, 2);
      z_variance += std::pow(z_samples[i] - z_mean, 2);
    }
    x_variance /= ESTIMATION_SAMPLES;
    y_variance /= ESTIMATION_SAMPLES;
    z_variance /= ESTIMATION_SAMPLES;

    Serial.printf("N_x(%f,%f)\n", x_mean, std::sqrt(x_variance));
    Serial.printf("N_y(%f,%f)\n", y_mean, std::sqrt(y_variance));
    Serial.printf("N_z(%f,%f)\n", z_mean, std::sqrt(z_variance));

    return {std::normal_distribution{x_mean, (float)x_variance},
            std::normal_distribution{y_mean, (float)y_variance},
            std::normal_distribution{z_mean, (float)z_variance}};
  }

  static inline bool read() {
    if (m_adxl.dataReady()) {
      m_adxl.readAccel();
      m_x = (m_adxl.x / RESOLUTION) * G;
      m_y = (m_adxl.y / RESOLUTION) * G;
      m_z = (m_adxl.z / RESOLUTION) * G;
      return true;
    } else {
      return false;
    }
  }

  static inline auto x() -> Acceleration { return m_x; }
  static inline auto y() -> Acceleration { return m_y; }
  static inline auto z() -> Acceleration { return m_z; }

private:
  static constexpr size_t CALIBRATION_SAMPLES = 3200;
  static constexpr size_t CALIBRATION_ROUNDS = 2;
  static constexpr size_t ESTIMATION_SAMPLES = 100;
  static constexpr float RESOLUTION = 1024;
  static constexpr Acceleration G = Acceleration(9.80665f);
  static constexpr Acceleration EXPECTED_X = 0_mps2;
  static constexpr Acceleration EXPECTED_Y = 0_mps2;
  static constexpr Acceleration EXPECTED_Z = G;

  Accelerometer() = delete;
  static Acceleration m_x;
  static Acceleration m_y;
  static Acceleration m_z;
  static ADXL313 m_adxl;
};
