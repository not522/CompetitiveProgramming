#pragma once
#include "template.hpp"

class DoublePointer {
protected:
  const int n;

  int front, back;

  virtual bool valid() = 0;
  virtual void pop() = 0;
  virtual void push() = 0;
  virtual void result() = 0;

public:
  DoublePointer(int n) : n(n) {}

  void solve() {
    for (front = 0, back = 0; front < n;) {
      if (back < n && valid()) {
        push();
        ++back;
      } else {
        if (front < back) pop();
        else ++back;
        ++front;
      }
      result();
    }
  }
};
