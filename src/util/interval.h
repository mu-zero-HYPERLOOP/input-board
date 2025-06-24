#pragma once

#include "util/timestamp.h"
class Interval {
public:
  explicit Interval(Time period) : m_period(period), m_last(Timestamp::now()) {}
  explicit Interval(Frequency frequency)
      : m_period(1.0f / frequency), m_last(Timestamp::now()) {}

  inline void reset() { m_last = Timestamp::now(); }

  inline bool next() {
    const auto now = Timestamp::now();
    if (now - m_last > m_period) {
      m_last = m_last + m_period;
      return true;
    } else {
      return false;
    }
  }

  inline Frequency frequency() const {
    return 1.0f / static_cast<Time>(m_period);
  }


  inline Time period() const {
    return static_cast<Time>(m_period);
  }

private:
  Duration m_period;
  Timestamp m_last;
};
