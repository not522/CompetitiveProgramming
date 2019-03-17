#pragma once
#include <queue>

template<typename T> class Queue : public std::queue<T> {
public:
  Queue() : std::queue<T>() {}

  Queue(const std::initializer_list<T>& s) : std::queue<T>(s) {}

  T front() {
    T res = std::queue<T>::front();
    this->pop();
    return res;
  }

  T peek() const {
    return std::queue<T>::top();
  }
};
