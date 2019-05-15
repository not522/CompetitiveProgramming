#pragma once
#include "container.hpp"

#include <deque>

template <typename T> class Deque : public Container<std::deque<T>> {
public:
  Deque() : std::deque<T>() {}

  Deque(const std::initializer_list<T> &q) : std::deque<T>(q) {}

  Deque(int n, Input &in) : Container<std::deque<T>>(n, in) {}
};
