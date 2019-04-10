#pragma once
#include "template.hpp"

#include <stack>
#include <vector>

template<typename T> class Stack : public std::stack<T, std::vector<T>> {
public:
  Stack() : std::stack<T, std::vector<T>>() {}

  Stack(const std::initializer_list<T>& s) : std::stack<T, std::vector<T>>(s) {}

  T top() {
    T res = std::stack<T, std::vector<T>>::top();
    this->pop();
    return res;
  }

  T peek() const {
    return std::stack<T, std::vector<T>>::top();
  }
};
