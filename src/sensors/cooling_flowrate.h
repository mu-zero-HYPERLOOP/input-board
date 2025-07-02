
#include "firmware/pinout.h"
namespace sensors::cooling_flowrate {

constexpr din_pin FLOW_RATE_BEGIN_PIN = din_6;
constexpr din_pin FLOW_RATE_END_PIN = din_hack;

void begin();

void update();


}
