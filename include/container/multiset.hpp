#pragma once
#include "arithmetic.hpp"

#include <set>

template <typename T>
class MultiSet : public std::multiset<T>, public Multiplication<MultiSet<T>> {
public:
  MultiSet &operator*=(const MultiSet &m) {
    MultiSet a = *this, b = m, res;
    if (a.size() > b.size()) {
      swap(a, b);
    }
    for (auto &i : a) {
      auto itr = b.find(i);
      if (itr == b.end()) {
        continue;
      }
      b.erase(itr);
      res.insert(i);
    }
    return *this = res;
  }
};
