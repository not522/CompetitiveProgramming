#pragma once
#include "container.hpp"

#include <queue>

template<typename T> class Queue : public Container<std::queue<T>> {
public:
  Queue() : Container<std::queue<T>>() {}

  Queue(const std::initializer_list<T>& q) : Container<std::queue<T>>(q) {}

  T front() {
    T res = std::queue<T>::front();
    this->pop();
    return res;
  }

  T peek() const {
    return std::queue<T>::top();
  }
};
