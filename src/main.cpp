/**
 * @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

#include "canzero/canzero.h"
#include "firmware/input_board.h"

int main() {

  canzero_init();

  canzero_set_state(input_board_state_INIT);

  while(true) {

    canzero_set_state(input_board_state_RUNNING);


    canzero_can0_poll();
    canzero_can1_poll();
    canzero_update_continue(canzero_get_time());

  }

}
