#pragma once
#include "bit_operation.hpp"
#include "bitwise.hpp"
#include "vector.hpp"

class Bitset : public Vector<uint64_t>, public Bitwise<Bitset> {
private:
  int arraySize(int n) const { return (n + 63) / 64; }

public:
  class reference {
  private:
    friend class Bitset;
    Vector<uint64_t>::iterator val;
    int pos;
    reference(std::vector<uint64_t>::iterator val, int pos)
        : val(val), pos(pos) {}

  public:
    reference &operator=(const reference &r) {
      if (static_cast<bool>(r)) {
        *val |= 1ull << pos;
      } else {
        *val &= ~(1ull << pos);
      }
      return *this;
    }

    reference &operator=(const bool b) {
      if (b) {
        *val |= 1ull << pos;
      } else {
        *val &= ~(1ull << pos);
      }
      return *this;
    }

    operator bool() const { return *val >> pos & 1; }
  };

  Bitset() {}

  Bitset(int n) : Vector<uint64_t>(arraySize(n)) {}

  Bitset(const Vector<uint64_t> &v) : Vector<uint64_t>(v) {}

  reference operator[](int n) {
    if (arraySize(n) >= int(Vector<uint64_t>::size())) {
      resize(n);
    }
    return reference(this->Vector<uint64_t>::begin() + n / 64, n % 64);
  }

  bool operator[](int n) const {
    if (arraySize(n) >= int(Vector<uint64_t>::size())) {
      return false;
    }
    return get(n) >> (n % 64) & 1;
  }

  uint64_t &get(int n) { return Vector<uint64_t>::operator[](n / 64); }

  uint64_t get(int n) const { return Vector<uint64_t>::operator[](n / 64); }

  Bitset &operator&=(const Bitset &b) {
    if (size() < b.size()) {
      resize(b.size());
    }
    for (int i = 0; i < size() && i < b.size(); i += 64) {
      get(i) &= b.get(i);
    }
    return *this;
  }

  Bitset &operator|=(const Bitset &b) {
    if (size() < b.size()) {
      resize(b.size());
    }
    for (int i = 0; i < size() && i < b.size(); i += 64) {
      get(i) |= b.get(i);
    }
    return *this;
  }

  Bitset &operator^=(const Bitset &b) {
    if (size() < b.size()) {
      resize(b.size());
    }
    for (int i = 0; i < size() && i < b.size(); i += 64) {
      get(i) ^= b.get(i);
    }
    return *this;
  }

  int count() {
    return this->accumulate(0,
                            [](int a, uint64_t b) { return a + count_bit(b); });
  }

  bool parity() {
    return this->accumulate(
        0, [](int a, uint64_t b) { return a ^ __builtin_parityll(b); });
  }

  int size() const { return Vector<uint64_t>::size() * 64; }

  void resize(int n) { Vector<uint64_t>::resize(arraySize(n) + 1); }

  class Iterator {
  private:
    int itr;
    const Bitset &bitset;

  public:
    Iterator(int itr, const Bitset &bitset) : itr(itr), bitset(bitset) {}

    int operator*() { return itr; }

    bool operator!=(const Iterator &itr) const { return this->itr != itr.itr; }

    void operator++() {
      if (bitset.get(itr) >> (itr % 64 + 1)) {
        itr += least_bit_fast(bitset.get(itr) >> (itr % 64 + 1)) + 1;
      } else {
        for (int i = itr / 64 * 64 + 64; i < bitset.size(); i += 64) {
          if (bitset.get(i)) {
            itr = i + least_bit_fast(bitset.get(i));
            return;
          }
        }
        itr = bitset.size();
      }
    }
  };

  Iterator begin() {
    for (int i = 0; i < size(); i += 64) {
      if (get(i)) {
        return Iterator(i + least_bit_fast(get(i)), *this);
      }
    }
    return Iterator(size(), *this);
  }

  Iterator end() { return Iterator(size(), *this); }
};

Bitset make_bitset(uint64_t n) { return Vector<uint64_t>(1, n); }
