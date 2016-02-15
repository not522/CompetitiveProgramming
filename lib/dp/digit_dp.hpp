#pragma once
#include "template.hpp"

template<typename T, typename State> class DigitDP {
protected:
  string num;
  State curr;
  State prev;

  virtual void step(int) = 0;
  virtual T result() = 0;

public:
  DigitDP(string num) : num(num) {}
  
  template<typename S> DigitDP(S num) : num(to_string(num)) {}
  
  T solve() {
    for (char c : num) {
      prev = curr;
      step(c - '0');
    }
    return result();
  }
};
