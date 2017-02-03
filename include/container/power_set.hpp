#pragma once
#include "container/bit_iterator.hpp"

class PowerSet {
private:
  class Iterator : public iterator<input_iterator_tag, int> {
  private:
    BitIterator val;

  public:
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
  PowerSet(int n) : i(0), n(1 << n) {}

  Iterator& begin() {
    return i;
  }

  Iterator& end() {
    return n;
  }
};
