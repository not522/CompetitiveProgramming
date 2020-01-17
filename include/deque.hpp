#pragma once
#include "container.hpp"

#include <deque>

template <typename T> class Deque : public Container<std::deque<T>> {
public:
  Deque() : Container<std::deque<T>>() {}

  template <typename Itr>
  Deque(Itr first, Itr last) : Container<std::deque<T>>(first, last) {}

  Deque(const std::initializer_list<T> &q) : Container<std::deque<T>>(q) {}

  Deque(int n, Input &in) : Container<std::deque<T>>(n, in) {}
};
