#pragma once
#include "template.hpp"

template<typename T, typename... Args> class MemoizedRecursion {
protected:
  virtual bool used(Args...) = 0;
  virtual T memo(Args...) = 0;
  virtual void push(T, Args...) = 0;
  virtual T eval(Args...) = 0;
  
public:
  T solve(Args... args) {
    if (used(args...)) return memo(args...);
    T v = eval(args...);
    push(v, args...);
    return v;
  }
};
