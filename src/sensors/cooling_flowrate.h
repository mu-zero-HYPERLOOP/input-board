
#include "firmware/pinout.h"
namespace sensors::cooling_flowrate {

constexpr din_pin FLOW_RATE_BEGIN_PIN = din_6;
constexpr din_pin FLOW_RATE_END_PIN = din_hack;

const unsigned long rpmTable[] = {
  0, 35, 80, 100, 127, 156, 188, 215, 255, 290, 320, 350, 380, 420, 485, 515, 560, 580,
  605, 630, 660, 675, 695, 720, 745, 775, 810, 840, 860, 885, 915, 940, 955, 975, 1005,
  1035, 1075, 1100, 1130, 1160, 1190, 1220, 1260, 1290, 1320, 1350, 1380, 1410, 1440
};

const unsigned long lphTable[] = {
  0, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155,
  160, 165, 170, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240,
  245, 250, 255, 260, 265, 270, 275, 280, 285, 290, 295, 300, 305, 310
};

const int tableSize = sizeof(rpmTable) / sizeof(rpmTable[0]);

void begin();

void update();


}
