#pragma once
#include "bitwise.hpp"

class Bitset : public Bitwise<Bitset> {
private:
  int arraySize(int n) {
    return (n + 63) / 64;
  }

  void resize(int n) {
    val.resize(arraySize(n));
  }
  
public:
  vector<unsigned long long> val;

  class reference {
  private:
    friend class Bitset;
    vector<unsigned long long>::iterator val;
    int pos;
    reference(vector<unsigned long long>::iterator val, int pos) : val(val), pos(pos) {}
    
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
  
  Bitset(int n) : val(arraySize(n), 0) {}

  reference operator[](int n) {
    return reference(val.begin() + n / 64, n % 64);
  }

  Bitset operator&=(const Bitset& b) {
    if (val.size() < b.val.size()) val.resize(b.val.size());
    for (int i = 0; i < (int)val.size(); ++i) {
      if (i < (int)b.val.size()) val[i] &= b.val[i];
    }
    return *this;
  }

  Bitset operator|=(const Bitset& b) {
    if (val.size() < b.val.size()) val.resize(b.val.size());
    for (int i = 0; i < (int)val.size(); ++i) {
      if (i < (int)b.val.size()) val[i] |= b.val[i];
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
    return accumulate(val.begin(), val.end(), 0, [](int a, unsigned long long b){return a + __builtin_popcountll(b);});
  }

  bool parity() {
    return accumulate(val.begin(), val.end(), 0, [](int a, unsigned long long b){return a ^ __builtin_parityll(b);});
  }
};
