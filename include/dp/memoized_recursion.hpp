#pragma once
#include "map.hpp"
#include "tuple.hpp"
#include "vector.hpp"

template<typename T, typename... Args> class MemoizedRecursion {
protected:
  Map<Tuple<Args...>, T> mem;

  bool used(Args... args) {
    return mem.contains(makeTuple(args...));
  }

  T memo(Args... args) {
    return mem[makeTuple(args...)];
  }

  void push(T t, Args... args) {
    mem[makeTuple(args...)] = t;
  }

  virtual T eval(Args... args) = 0;

public:
  T solve(Args... args) {
    if (used(args...)) return memo(args...);
    T t = eval(args...);
    push(t, args...);
    return t;
  }
};
