#pragma once
#include "bit_operation.hpp"

template<typename T> T gcd(T t) {return t;}

template<typename T, typename... S> T gcd(T a, S... s) {
  auto b = gcd(s...);
  if (a == 0 || b == 0) return max(a, b);
  int fa = least_bit_fast(a);
  int fb = least_bit_fast(b);
  a >>= fa;
  b >>= fb;
  while (a != b) {
    auto& c = a > b ? a : b;
    c >>= least_bit_fast(c = abs(a - b));
  }
  return a << min(fa, fb);
}

template<typename T> T lcm(T t) {return t;}

template<typename T, typename... S> T lcm(T t, S... s) {
  T l = lcm(s...);
  return t / gcd(t, l) * l;
}

template<typename T> T floor(T a, T b) {
  return a / b * b <= a ? a / b : a / b - 1;
}

template<> float floor(float a, float b) {
  return floor(a / b) * b <= a ? floor(a / b) : floor(a / b) - 1;
}

template<> double floor(double a, double b) {
  return floor(a / b) * b <= a ? floor(a / b) : floor(a / b) - 1;
}

template<> long double floor(long double a, long double b) {
  return floor(a / b) * b <= a ? floor(a / b) : floor(a / b) - 1;
}

template<typename T> T ceil(T a, T b) {
  return floor(a + b - 1, b);
}

template<typename T> T round(T a, T b) {
  return floor(a + b / 2, b);
}

template<typename T> T mod(T a, T b) {
  return a - floor(a, b) * b;
}

template<typename T> T factorial(T n) {
  return n <= 1 ? 1 : factorial(n - 1) * n;
}

template<typename T> T square(T n) {
  return n * n;
}

template<typename T> T cube(T n) {
  return n * n * n;
}

template<typename T> T norm(T x1, T y1, T x2, T y2) {
  return square(x1 - x2) + square(y1 - y2);
}

long long sqrt(long long n) {
  return sqrt((long double)n);
}
