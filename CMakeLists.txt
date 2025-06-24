######################################################################
# @author      : karl (karlsasssie@gmail.com)
# @file        : CMakeLists
# @created     : Friday Apr 07, 2023 15:39:05 CEST
######################################################################

cmake_minimum_required(VERSION 3.5)
project(input_board CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
  mock/can.cpp
  mock/input_board.cpp
  mock/print.cpp
  src/main.cpp
  src/canzero/canzero.cpp
  src/sensors/accelerometer.cpp
  src/sensors/ambient_temperature.cpp
  src/sensors/bat24_current.cpp
  src/sensors/bat24_temperature.cpp
  src/sensors/bat24_voltage.cpp
  src/sensors/ebox_temperature.cpp
  src/sensors/linear_encoder.cpp
  src/sensors/link24_current.cpp
  src/sensors/supercap_voltage.cpp
  src/sensors/link45_current.cpp
  src/sensors/link45_voltage.cpp
  src/sensors/mcu_temperature.cpp
  src/sensors/supercap_temperature.cpp
  src/state_estimation/state_estimation.cpp
  src/state_estimation/ekf.cpp
  src/error_handling.cpp
  src/handle_heartbeat.cpp
  
  src/fsm/states/acceleration.cpp
  src/fsm/states/arming45.cpp
  src/fsm/states/calibrating.cpp
  src/fsm/states/controller.cpp
  src/fsm/states/cruising.cpp
  src/fsm/states/deceleration.cpp
  src/fsm/states/disarming45.cpp
  src/fsm/states/guidance_stable.cpp
  src/fsm/states/idle.cpp
  src/fsm/states/init.cpp
  src/fsm/states/levitation_stable.cpp
  src/fsm/states/precharge.cpp
  src/fsm/states/ready.cpp
  src/fsm/states/restarting.cpp
  src/fsm/states/shutdown.cpp
  src/fsm/states/start_guidance.cpp
  src/fsm/states/start_levitation.cpp
  src/fsm/states/stop_levitation.cpp
  src/fsm/states/stop_guidance.cpp
  src/fsm/error_handling.cpp
  src/fsm/fsm.cpp
  src/fsm/sdc.cpp

  src/control/velocity.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src/ mock/)

