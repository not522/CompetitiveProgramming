#pragma once
#include "bitwise.hpp"
#include "bit_operation.hpp"

class Bitset : public Bitwise<Bitset> {
private:
  int arraySize(int n) const {
    return (n + 63) / 64;
  }

  void resize(int n) {
    val.resize(arraySize(n) + 1);
  }

public:
  vector<unsigned int64_t> val;

  class reference {
  private:
    friend class Bitset;
    vector<unsigned int64_t>::iterator val;
    int pos;
    reference(vector<unsigned int64_t>::iterator val, int pos) : val(val), pos(pos) {}

  public:
    reference operator=(const reference& r) {
      if ((bool)r) *val |= 1ull << pos;
      else *val &= ~(1ull << pos);
      return *this;
    }

    reference operator=(const bool b) {
      if (b) *val |= 1ull << pos;
      else *val &= ~(1ull << pos);
      return *this;
    }

    operator bool() const {
      return *val >> pos & 1;
    }
  };

  Bitset() {}

  Bitset(int n) : val(arraySize(n), 0) {}

  reference operator[](int n) {
    if (arraySize(n) >= (int)val.size()) resize(n);
    return reference(val.begin() + n / 64, n % 64);
  }

  bool operator[](int n) const {
    if (arraySize(n) >= (int)val.size()) return false;
    return val[n / 64] >> n % 64 & 1;
  }

  Bitset operator&=(const Bitset& b) {
    if (val.size() < b.val.size()) val.resize(b.val.size());
    for (size_t i = 0; i < val.size(); ++i) {
      if (i < b.val.size()) val[i] &= b.val[i];
    }
    return *this;
  }

  Bitset operator|=(const Bitset& b) {
    if (val.size() < b.val.size()) val.resize(b.val.size());
    for (size_t i = 0; i < val.size(); ++i) {
      if (i < b.val.size()) val[i] |= b.val[i];
    }
    return *this;
  }

  Bitset operator^=(const Bitset& b) {
    if (val.size() < b.val.size()) val.resize(b.val.size());
    for (size_t i = 0; i < val.size(); ++i) {
      if (i < b.val.size()) val[i] ^= b.val[i];
    }
    return *this;
  }

  int count() {
    return accumulate(val.begin(), val.end(), 0, [](int a, uint64_t b){return a + count_bit(b);});
  }

  bool parity() {
    return accumulate(val.begin(), val.end(), 0, [](int a, uint64_t b){return a ^ __builtin_parityll(b);});
  }

  int size() const {
    return val.size() * 64;
  }
};
