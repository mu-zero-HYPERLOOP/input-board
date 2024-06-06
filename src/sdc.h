#pragma once
#include "canzero/canzero.h"
#include "firmware/input_board.h"


namespace sdc {

static inline void begin(){
  canzero_set_sdc_status(sdc_status_OPEN);
  input_board::set_sdc(false);
}

static inline void open(){
  canzero_set_sdc_status(sdc_status_OPEN);
  input_board::set_sdc(false);
}

static inline void close(){
  canzero_set_sdc_status(sdc_status_CLOSED);
  input_board::set_sdc(true);
}

}
