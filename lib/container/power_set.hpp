#pragma once
#include "template.hpp"

class PowerSet {
private:
  struct Iterator {
    int val;

    Iterator(int val) : val(val) {}

    Iterator operator*() {
      return *this;
    }

    bool operator!=(Iterator& itr) {
      return val != itr.val;
    }

    void operator++() {
      ++val;
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
  PowerSet(int n) : i(0), n(1 << n) {}

  Iterator& begin() {
    return i;
  }

  Iterator& end() {
    return n;
  }
};
