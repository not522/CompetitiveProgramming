#pragma once
#include "template.hpp"

class DoublePointer {
private:
  int n;

protected:
  int front, back;

  virtual bool valid(int) = 0;
  virtual void pop(int) = 0;
  virtual void push(int) = 0;
  
public:
  DoublePointer(int n) : n(n) {}

  void solve() {
    for (front = 0, back = 0; front < n;) {
      if (back < n && valid(back)) {
        push(back);
        ++back;
      } else {
        if (front < back) pop(front);
        else ++back;
        ++front;
      }
    }
  }
};
