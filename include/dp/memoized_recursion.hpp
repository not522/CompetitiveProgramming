#pragma once
#include "map.hpp"
#include "tuple.hpp"
#include "vector.hpp"

template<typename... Args> class MemoizedRecursion {};

template<typename T> class MemoizedRecursion<T> {
protected:
  Vector<bool> use;
  Vector<T> mem;

  bool used(unsigned v) {
    if (v >= use.size()) {
      use.resize(v + 1, false);
      mem.resize(v + 1);
    }
    return use[v];
  }

  T memo(int v) {
    return mem[v];
  }

  void push(T t, int v) {
    use[v] = true;
    mem[v] = t;
  }

  virtual T eval(int v) = 0;

public:
  T solve(int v) {
    if (used(v)) return memo(v);
    T t = eval(v);
    push(t, v);
    return t;
  }
};

template<typename T, typename... Args> class MemoizedRecursion<T, Args...> {
protected:
  Map<Tuple<Args...>, T> mem;

  bool used(Args... args) {
    return mem.count(makeTuple(args...));
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
