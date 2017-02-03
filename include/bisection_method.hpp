#pragma once
#include "template.hpp"

long double bisectionMethod(function<long double(long double)> func, long double lower = 0, long double upper = 1) {
  while ((func(lower) <= 0) == (func(upper) <= 0)) {
    lower -= upper - lower;
    upper += upper - lower;
  }
  if (func(lower) > 0) swap(lower, upper);
  for (int i = 0; i < 200; ++i) {
    long double middle = (lower + upper) / 2;
    (func(middle) <= 0 ? lower : upper) = middle;
  }
  return lower;
}
