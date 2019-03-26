#pragma once
#include "string.hpp"

template<typename T, typename State> class DigitDP {
protected:
  String num;
  State curr;
  State prev;

  virtual void step(int) = 0;
  virtual T result() = 0;

public:
  DigitDP(String num) : num(num) {}
  
  template<typename S> DigitDP(S num) : num(num) {}
  
  T solve() {
    for (char c : num) {
      prev = curr;
      step(c - '0');
    }
    return result();
  }
};
