/**
 * @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

#include "firmware/input_board.h"

int main() {
  Voltage x = InputBoard::read_ain_mux1();
}
