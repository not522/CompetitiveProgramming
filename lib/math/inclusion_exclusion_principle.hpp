#pragma once
#include "bit_operation.hpp"

template<typename T, typename Function, typename S> inline S inclusionExclusionPrinciple(const T& v, Function f, S s) {
  for (int i = 0; i < (1 << v.size()); ++i) {
    T u;
    for (int j = i; j; j &= j - 1) u.emplace_back(v[least_bit(j)]);
    s += (__builtin_parity(i) ? - 1 : 1) * f(u);
  }
  return s;
}
