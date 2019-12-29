#pragma once
#include "container/bitset64.hpp"
#include "vector.hpp"

Vector<Bitset64> powerSet(int n) {
  Vector<Bitset64> res;
  auto mx = 1ull << n;
  for (uint64_t i = 0; i < mx; ++i) {
    res.emplace_back(i);
  }
  return res;
}
