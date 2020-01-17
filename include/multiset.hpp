#pragma once
#include "container.hpp"

#include <set>

template <typename T> class Multiset : public Container<std::multiset<T>> {
public:
  Multiset() : Container<std::multiset<T>>() {}

  template <typename Itr>
  Multiset(Itr first, Itr last) : Container<std::multiset<T>>(first, last) {}

  Multiset(const std::initializer_list<T> &s)
      : Container<std::multiset<T>>(s) {}

  void erase(const T &a) { std::multiset<T>::erase(std::multiset<T>::find(a)); }

  template <typename S> Multiset<T> &operator&=(const S &a) {
    Multiset<T> r;
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
};
