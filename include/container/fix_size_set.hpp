#pragma once
#include "container/bitset64.hpp"
#include "vector.hpp"

Vector<Bitset64> fixSizeSet(int n, int k) {
  if (k == 0) {
    return Vector<Bitset64>{0};
  }
  Vector<Bitset64> res;
  auto mx = 1ull << n, full = (1ull << k) - 1;
  for (uint64_t comb = (1ull << k) - 1; comb < mx;) {
    res.emplace_back(comb);
    comb += comb & -comb;
    comb += full >> count_bit(comb);
  }
  return res;
}
