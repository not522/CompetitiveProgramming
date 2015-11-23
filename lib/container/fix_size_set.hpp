#pragma once
#include "container/bit_iterator.hpp"

class FixSizeSet {
private:
  struct Iterator {
  private:
    BitIterator val, n;

  public:
    Iterator(int val, int n) : val(val), n(n) {}

    Iterator operator*() {
      return *this;
    }

    bool operator!=(const Iterator& itr) const {
      return n != itr.n;
    }

    void operator++() {
      int x = val & -val, y = val + x;
      val = ((val & ~y) / x / 2) | y;
      if (val >= (1 << n)) n = 0;
    }

    operator int() const {
      return val;
    }

    bool in(int i) const {
      return val.in(i);
    }

    BitIterator::Iterator& begin() {
      return val.begin();
    }

    BitIterator::Iterator& end() {
      return val.end();
    }
  };
  
  Iterator i, n;

public:
  FixSizeSet(int n, int k) : i((1 << k) - 1, n), n(0, 0) {}

  Iterator& begin() {
    return i;
  }

  Iterator& end() {
    return n;
  }
};
