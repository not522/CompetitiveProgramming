#pragma once
#include "bit_operation.hpp"

class BitIterator : public iterator<input_iterator_tag, int> {
public:

  class Iterator : public iterator<input_iterator_tag, int> {
  private:
    int val, bit;

  public:
    Iterator(int val, int bit) : val(val), bit(bit) {}

    Iterator operator*() {
      return *this;
    }

    bool operator!=(const Iterator& itr) const {
      return val != itr.val;
    }

    void operator++() {
      val = least_bit(bit & (-1 << (val + 1)));
    }

    operator int() {
      return val;
    }
  };
  
  Iterator i, n;
  int bit;

  BitIterator(int n) : i(least_bit(n), n), n(-1, n), bit(n) {}

  bool operator!=(const BitIterator& itr) const {
    return i != itr.i;
  }

  void operator++() {
    *this = BitIterator(bit + 1);
  }

  operator int() const {
    return bit;
  }

  bool in(int i) const {
    return bit & (1 << i);
  }

  Iterator& begin() {
    return i;
  }

  Iterator& end() {
    return n;
  }
};
