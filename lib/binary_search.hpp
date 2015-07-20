#pragma once
#include "template.hpp"

long long binarySearch(function<bool(long long)> func, long long include, long long exclude) {
  while (abs(exclude - include) > 1) {
    long long middle = (include + exclude) / 2;
    if (func(middle)) include = middle;
    else exclude = middle;
  }
  return include;
}
