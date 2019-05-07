#pragma once
#include "math.hpp"

template <typename Function>
long double goldenSectionSearch(Function function, long double lower,
                                long double upper) {
  const long double r = (sqrt(5.l) - 1) / 2;
  long double middle1 = upper - r * (upper - lower);
  long double middle2 = lower + r * (upper - lower);
  for (int i = 0; i < 200; ++i) {
    if (function(middle1) < function(middle2)) {
      upper = middle2;
      middle2 = middle1;
      middle1 = upper - r * (upper - lower);
    } else {
      lower = middle1;
      middle1 = middle2;
      middle2 = lower + r * (upper - lower);
    }
  }
  return lower;
}
