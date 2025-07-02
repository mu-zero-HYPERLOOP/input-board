#pragma once

enum ain_pin {
  ain_ntc_mux = 18,
  ain_mux = 14,
  ain_15 = 15,
  ain_16 = 16,
  ain_17 = 17,
  ain_iso_19 = 19,
  ain_iso_20 = 20,
  ain_iso_21 = 21,
};

// first byte is the pin second byte is mux_sel
enum mux_pin {
  mux_ntc_0 = ain_ntc_mux | (0 << 8),
  mux_ntc_1 = ain_ntc_mux| (1 << 8),
  mux_ntc_2 = ain_ntc_mux | (2 << 8),
  mux_ntc_3 = ain_ntc_mux | (3 << 8),
  mux_ntc_4 = ain_ntc_mux | (4 << 8),
  mux_ntc_5 = ain_ntc_mux | (5 << 8),
  mux_ntc_6 = ain_ntc_mux | (6 << 8),
  mux_ntc_7 = ain_ntc_mux | (7 << 8),
  mux_ain_0 = ain_mux | (0 << 8),
  mux_ain_1 = ain_mux | (1 << 8),
  mux_ain_2 = ain_mux | (2 << 8),
  mux_ain_3 = ain_mux | (3 << 8),
  mux_ain_4 = ain_mux | (4 << 8),
  mux_ain_5 = ain_mux | (5 << 8),
  mux_ain_6 = ain_mux | (6 << 8),
  mux_ain_7 = ain_mux | (7 << 8),

  MUX_PIN_SHR = 0, // shift left
  MUX_PIN_MASK = 0xFF,
  MUX_SEL_SHR = 8, // shift left
  MUX_SEL_MASK  = 0xFF << 8,
};


enum din_pin {
  din_2 = 2,
  din_3 = 3,
  din_4 = 4,
  din_5 = 5,
  din_6 = 6,
  din_hack = 7,
  din_COUNT,
};

enum ctrl_pin {
  accel_cs = 10,
  sdc_ctrl = 32,
  mux_sel0 = 38,
  mux_sel1 = 37,
  mux_sel2 = 36
};

