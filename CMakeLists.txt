######################################################################
# @author      : karl (karlsasssie@gmail.com)
# @file        : CMakeLists
# @created     : Friday Apr 07, 2023 15:39:05 CEST
######################################################################

cmake_minimum_required(VERSION 2.8)
project(input_board CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
  mock/can.cpp
  mock/input_board.cpp
  src/main.cpp
  src/canzero/canzero.cpp
  src/sensors/accelerometer.cpp
  src/sensors/ambient_temperature.cpp
  src/sensors/bat24_current.cpp
  src/sensors/bat24_temperature.cpp
  src/sensors/bat24_voltage.cpp
  src/sensors/buck_temperature.cpp
  src/sensors/cooling_pressure.cpp
  src/sensors/cooling_temperature.cpp
  src/sensors/ebox_temperature.cpp
  src/sensors/linear_encoder.cpp
  src/sensors/link24_current.cpp
  src/sensors/link24_voltage.cpp
  src/sensors/link45_current.cpp
  src/sensors/link45_voltage.cpp
  src/sensors/mass_flow_rate.cpp
  src/sensors/mcu_temperature.cpp
  src/sensors/supercap_temperature.cpp
  src/state_estimation.cpp
  src/state_estimation/ekf.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src/ mock/)

