#pragma once
#include "template.hpp"

template<typename T> int least_bit(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_ffs(n) - 1;
  if (sizeof(T) == 8) return __builtin_ffsll(n) - 1;
}

template<typename T> int most_bit(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return n ? 31 - __builtin_clz(n) : -1;
  if (sizeof(T) == 8) return n ? 63 - __builtin_clzll(n) : -1;
}

template<typename T> int count_bit(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_popcount(n);
  if (sizeof(T) == 8) return __builtin_popcountll(n);
}
