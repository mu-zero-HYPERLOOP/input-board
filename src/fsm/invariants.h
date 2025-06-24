#pragma once

#include <algorithm>
#include <array>
#include <cstddef>

namespace fsm::invariant {

template <typename T, size_t N>
bool contains(const std::array<T, N> &range, const T &value) {
  return std::any_of(range.begin(), range.end(),
                     [&](T x) { return x == value; });
}

} // namespace fsm::invariant
