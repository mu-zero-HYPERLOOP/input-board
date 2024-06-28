#pragma once

#include <cstddef>
#include "print.h"
#include <array>
#include <iterator>
#include <optional>

template<typename Type, size_t CAP> struct StaticVec {
private:
  union Element{
    uint8_t _mem;
    Type m_value;
    Element() : _mem(0) {}
  };

public:
  Element m_buffer[CAP];
  size_t m_size;

  int push(Type value) {
    if (m_size >= CAP) { return 0; }
    m_buffer[m_size++].m_value = value;
    return 1;
  }

  void clear() {
    m_size = 0;
  }

  Type* begin() {
    return &m_buffer->m_value;
  }

  Type* end() {
    return &(m_buffer + m_size)->m_value;
  }
};
