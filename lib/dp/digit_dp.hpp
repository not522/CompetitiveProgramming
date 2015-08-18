#pragma once
#include "template.hpp"

template<typename T, typename State> class DigitDP {
protected:
  string num;
  State curr;
  State prev;

  virtual void init(State&) = 0;
  virtual void step(T) = 0;
  virtual T result(State&) = 0;

public:
  DigitDP(string num) : num(num) {}
  
  DigitDP(T num) : num(to_string(num)) {}
  
  T solve() {
    for (char c : num) {
      prev = curr;
      init(curr);
      step(c - '0');
    }
    return result(curr);
  }
};
