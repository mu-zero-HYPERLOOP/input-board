#pragma once
#include "util/metrics.h"

class Accelerometer {
  public:
    static void begin(){
    }
    
    static inline Acceleration readAccel() {
      return 0_mps2;
    }

  private:
    Accelerometer() = delete;
};
