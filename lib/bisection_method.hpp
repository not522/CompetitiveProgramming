#pragma once
#include "template.hpp"

template<typename Function> long double bisectionMethod(Function function, long double lower, long double upper) {
  for (int i = 0; i < 200; ++i) {
    long double middle = (lower + upper) / 2;
    (function(middle) <= 0 ? lower : upper) = middle;
  }
  return lower;
}
