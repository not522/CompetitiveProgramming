#pragma once
#include "container.hpp"

template<typename T> class Set : public Container<set<T>> {
public:
  Set() : Container<set<T>>() {}

  template<typename S> Set<T> operator&=(const S& a) {
    Set<T> r;
    if (this->size() < a.size()) {
      for (const auto& i : *this) {
        if (a.in(i)) r.emplace(i);
      }
    } else {
      for (const auto& i : a) {
        if (this->in(i)) r.emplace(i);
      }
    }
    *this = r;
    return *this;
  }
};
