#pragma once
#include "template.hpp"

template<typename T> int least_bit(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_ffs(n) - 1;
  if (sizeof(T) == 8) return __builtin_ffsll(n) - 1;
}

// n must be greater than 0.
template<typename T> int least_bit_fast(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_ctz(n);
  if (sizeof(T) == 8) return __builtin_ctzll(n);
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

template<typename T> int bit_parity(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_parity(n);
  if (sizeof(T) == 8) return __builtin_parityll(n);
}
