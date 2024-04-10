/**
 * @author      : kistenklaus (karlsasssie@gmail.com)
 * @file        : main
 * @created     : Dienstag Apr 09, 2024 14:48:23 CEST
 */

#include "firmware/firmware.h"

int main() {

  while (true) {

    auto ain_mux1 = InputBoard::read_ain_mux1();
    auto ain_mux2 = InputBoard::read_ain_mux2();
    auto ain_mux3 = InputBoard::read_ain_mux3();
    auto ain_mux4 = InputBoard::read_ain_mux4();
    auto ain_mux5 = InputBoard::read_ain_mux5();
    auto ain_mux6 = InputBoard::read_ain_mux6();
    auto ain_mux7 = InputBoard::read_ain_mux7();
    auto ain_mux8 = InputBoard::read_ain_mux8();

    auto ntc1 = InputBoard::read_ntc1();
    auto ntc2 = InputBoard::read_ntc2();
    auto ntc3 = InputBoard::read_ntc3();
    auto ntc4 = InputBoard::read_ntc4();
    auto ntc5 = InputBoard::read_ntc5();
    auto ntc6 = InputBoard::read_ntc6();
    auto ntc7 = InputBoard::read_ntc7();
    auto ntc8 = InputBoard::read_ntc8();
  }
}
