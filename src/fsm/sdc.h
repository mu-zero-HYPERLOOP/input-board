#pragma once

#include "canzero/canzero.h"

namespace sdc{


sdc_status status();
  
inline void update_sdc_status() {
  canzero_set_system_sdc_status(
      (canzero_get_motor_driver_sdc_status() == sdc_status_OPEN ||
      canzero_get_guidance_board_front_sdc_status() == sdc_status_OPEN||
      canzero_get_guidance_board_back_sdc_status() == sdc_status_OPEN ||
      canzero_get_levitation_board1_sdc_status() == sdc_status_OPEN ||
      canzero_get_levitation_board2_sdc_status() == sdc_status_OPEN ||
      canzero_get_levitation_board3_sdc_status() == sdc_status_OPEN ||
      canzero_get_sdc_status() == sdc_status_OPEN ||
      canzero_get_power_board12_sdc_status() == sdc_status_OPEN ||
      canzero_get_power_board24_sdc_status() == sdc_status_OPEN) ? sdc_status_OPEN : sdc_status_CLOSED
      );
}

}
