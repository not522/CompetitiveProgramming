#pragma once
#include "template.hpp"

template<typename T> inline T gcd(T a, T b) {
  return __gcd(a, b);
}

template<typename T> inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template<typename T> inline T floor(T a, T b) {
  return floor(a / b) * b <= a ? floor(a / b) : floor(a / b) - 1;
}

template<typename T> inline T ceil(T a, T b) {
  return floor(a + b - 1, b);
}

template<typename T> inline T round(T a, T b) {
  return floor(a + b / 2);
}

template<typename T> inline T mod(T a, T b) {
  return a - floor(a, b) * b;
}

template<typename T> inline T factorial(T n) {
  return n <= 1 ? 1 : factorial(n - 1) * n;
}

template<typename T> inline T square(T n) {
  return n * n;
}

template<typename T> inline T cube(T n) {
  return n * n * n;
}

template<typename T> inline T norm(T x1, T y1, T x2, T y2) {
  return square(x1 - x2) + square(y1 - y2);
}

inline long long sqrt(long long n) {
  return sqrt((long double)n);
}
