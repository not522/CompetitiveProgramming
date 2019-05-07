#pragma once
#include "template.hpp"

#include <queue>

template <typename T> class Queue : public std::queue<T> {
public:
  Queue() : std::queue<T>() {}

  Queue(const std::initializer_list<T> &q) : std::queue<T>(q) {}

  T front() {
    T res = std::queue<T>::front();
    std::queue<T>::pop();
    return res;
  }

  T peek() const { return std::queue<T>::top(); }

  void pop() const { assert(false); }
};
