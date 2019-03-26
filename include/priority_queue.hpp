#pragma once
#include "container.hpp"

#include <queue>

template<typename T, bool less> class Comp {
public:
  bool operator()(const T& a, const T& b) const {
    return less ? a < b : !(a < b);
  }
};

template<typename T, bool less = true> class PriorityQueue : public Container<std::priority_queue<T, std::vector<T>, Comp<T, less>>> {
private:
  using Queue = Container<std::priority_queue<T, std::vector<T>, Comp<T, less>>>;

public:
  PriorityQueue() : Queue() {}

  PriorityQueue(const std::initializer_list<T>& s) : Queue(s) {}

  T top() {
    T res = Queue::top();
    this->pop();
    return res;
  }

  T peek() const {
    return Queue::top();
  }
};
