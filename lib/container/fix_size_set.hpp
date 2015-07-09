#pragma once
#include "template.hpp"

class FixSizeSet {
private:
  struct Iterator {
    int val, n;

    Iterator(int val, int n) : val(val), n(n) {}

    Iterator operator*() {
      return *this;
    }

    bool operator!=(Iterator& itr) {
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

    bool in(int i) {
      return val & (1 << i);
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
