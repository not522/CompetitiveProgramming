#pragma once
#include <queue>

template<typename T> class PriorityQueue : public std::priority_queue<T> {
public:
  PriorityQueue() : std::priority_queue<T>() {}

  PriorityQueue(const std::initializer_list<T>& s) : std::priority_queue<T>(s) {}

  T top() {
    T res = std::priority_queue<T>::top();
    this->pop();
    return res;
  }

  T peek() const {
    return std::priority_queue<T>::top();
  }
};
