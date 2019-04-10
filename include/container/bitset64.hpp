#pragma once
#include "bit_operation.hpp"

class Bitset64 {
public:
  class Iterator {
  public:
    int val;
    uint64_t bit;

    Iterator(uint64_t bit) : val(least_bit(bit)), bit(bit) {}

    Iterator(int val, uint64_t bit) : val(val), bit(bit) {}

    int operator*() {return val;}

    bool operator!=(const Iterator& itr) const {return val != itr.val;}

    void operator++() {val = least_bit(bit & -(2 << val));}
  };

  uint64_t n;

  Bitset64(uint64_t n) : n(n) {}

  Iterator begin() { return Iterator(n); }

  Iterator end() { return Iterator(-1, n); }

  bool contains(int a) const { return n & (1ull << a); }

  operator int64_t() const { return n; }
};
