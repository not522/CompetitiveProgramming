#pragma once
#include "template.hpp"

class DoublePointer {
private:
  int n;

protected:
  virtual bool valid(int, int) = 0;
  virtual void popFront(int, int) = 0;
  virtual void pushBack(int, int) = 0;
  
public:
  DoublePointer(int n) : n(n) {}

  void solve() {
    int front = 0;
    for (int i = 0; i < n; ++i) {
      while (!valid(front, i)) {
        popFront(front, i);
        ++front;
      }
      pushBack(front, i);
    }
  }
};
