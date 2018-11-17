#pragma once
#include "bit_operation.hpp"

template<typename T = double> constexpr T pi() {return acos(T(-1));}

template<typename T> T gcd(T t) {return abs(t);}

template<typename T, typename... S> T gcd(T a, S... s) {
  a = abs(a);
  auto b = gcd(s...);
  if (a == 0 || b == 0) return max(a, b);
  int fa = least_bit_fast(a);
  int fb = least_bit_fast(b);
  a >>= fa;
  b >>= fb;
  while (a != b) {
    auto& c = a > b ? a : b;
    c = abs(a - b);
    c >>= least_bit_fast(c);
  }
  return a << min(fa, fb);
}

template<typename T> T gcd(const vector<T>& v) {
  T g = abs(v[0]);
  for (int i = 1; i < int(v.size()); ++i) g = gcd(g, v[i]);
  return g;
}

template<typename T> T lcm(T t) {return abs(t);}

template<typename T, typename... S> T lcm(T t, S... s) {
  T l = lcm(s...);
  return abs(t) / gcd(t, l) * l;
}

template<typename T> T lcm(const vector<T>& v) {
  T l = abs(v[0]);
  for (int i = 1; i < int(v.size()); ++i) l = lcm(l, v[i]);
  return l;
}

template<typename T> T floor(T a, T b) {
  auto d = div(a, b);
  return d.quot - (d.rem && (a < 0) != (b < 0) ? 1 : 0);
}

template<typename T> T ceil(T a, T b) {
  auto d = div(a, b);
  return d.quot + (d.rem && (a > 0) == (b > 0) ? 1 : 0);
}

template<typename T> T round(T a, T b) {return floor(a + b / 2, b);}

template<typename T> T mod(T a, T b) {
  T c = a % b;
  return c < 0 ? c + abs(b) : c;
}

template<typename T> T factorial(T n) {return n <= 1 ? 1 : factorial(n - 1) * n;}

template<typename T> vector<T> factorial_vector(int n) {
  vector<T> v(n + 1, 1);
  for (int i = 1; i <= n; ++i) v[i] = v[i - 1] * i;
  return v;
}

template<typename T> T square(T n) {return n * n;}

template<typename T> T cube(T n) {return n * n * n;}

template<typename T> T norm(T x1, T y1, T x2, T y2) {return square(x1 - x2) + square(y1 - y2);}

template<typename T> bool isSquare(T n) {return square(T(sqrt(n))) == n;}

template<typename T> T clamp(T v, T l, T u) {return v < l ? l : v > u ? u : v;}
