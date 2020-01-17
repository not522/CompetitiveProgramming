#pragma once
#include "container.hpp"

#include <set>

template <typename T> class Set : public Container<std::set<T>> {
public:
  Set() : Container<std::set<T>>() {}

  template <typename Itr>
  Set(Itr first, Itr last) : Container<std::set<T>>(first, last) {}

  Set(const std::initializer_list<T> &s) : Container<std::set<T>>(s) {}

  template <typename S> Set<T> &operator&=(const S &a) {
    Set<T> r;
    if (this->size() < a.size()) {
      for (const auto &i : *this) {
        if (a.in(i)) {
          r.emplace(i);
        }
      }
    } else {
      for (const auto &i : a) {
        if (this->in(i)) {
          r.emplace(i);
        }
      }
    }
    *this = r;
    return *this;
  }

  int count(const T &a) const { return std::set<T>::count(a); }

  int contains(const T &a) const { return count(a) > 0; }
};
