#pragma once
#include "container/bit_iterator.hpp"

class Subset {
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
      if (val == 0) n = 0;
      else val = (val - 1) & n;
    }

    operator int() const {
      return val;
    }

    bool in(int i) const {
      return val.in(i);
    }
  };
  
  Iterator i, n;

public:
  Subset(int n) : i(n, n), n(0, 0) {}

  Iterator& begin() {
    return i;
  }

  Iterator& end() {
    return n;
  }
};
