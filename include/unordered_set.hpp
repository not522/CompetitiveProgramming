#pragma once
#include "container.hpp"

#include <unordered_set>

template <typename T>
class UnorderedSet : public Container<std::unordered_set<T>> {
public:
  UnorderedSet() : Container<std::unordered_set<T>>() {}

  template <typename Itr>
  UnorderedSet(Itr first, Itr last)
      : Container<std::unordered_set<T>>(first, last) {}

  UnorderedSet(const std::initializer_list<T> &s)
      : Container<std::unordered_set<T>>(s) {}

  template <typename S> UnorderedSet<T> &operator&=(const S &a) {
    UnorderedSet<T> r;
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

  int count(const T &a) const { return std::unordered_set<T>::count(a); }

  int contains(const T &a) const { return count(a) > 0; }
};
