#pragma once
#include "template.hpp"

unsigned int xrand() {
  static unsigned int x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  unsigned int t = x ^ x << 11; x = y; y = z; z = w;
  return w = w ^ w >> 19 ^ t ^ t >> 8;
}

double whiteNoise(double sigma) {
  constexpr double PI = acos(-1);
  return sqrt(-2 * log(xrand() / UINT_MAX)) * cos(2 * PI * xrand() / UINT_MAX) * sigma;
}
