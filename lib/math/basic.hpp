#include "template.hpp"

template<typename T> inline T gcd(T a, T b) {
  return __gcd(a, b);
}

template<typename T> inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template<typename T> inline T floor(T a, T b) {
  return a - a % b;
}

template<typename T> inline T ceil(T a, T b) {
  return floor(a + b - 1, b);
}

template<typename T> inline T round(T a, T b) {
  return floor(a + b / 2);
}
