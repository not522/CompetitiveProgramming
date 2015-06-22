#include "template.hpp"

template<typename T> T gcd(T a, T b) {
  return __gcd(a, b);
}

template<typename T> T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
