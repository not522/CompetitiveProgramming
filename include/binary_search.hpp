#pragma once
#include "template.hpp"

int64_t binarySearch(function<bool(int64_t)> func, int64_t include, int64_t exclude) {
  while (abs(exclude - include) > 1) {
    int64_t middle = (include + exclude) / 2;
    (func(middle) ? include : exclude) = middle;
  }
  return include;
}
