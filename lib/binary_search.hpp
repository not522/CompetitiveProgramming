#pragma once
#include "template.hpp"

template<typename Function> long long binarySearch(Function function, long long include, long long exclude) {
  while (abs(exclude - include) > 1) {
    long long middle = (include + exclude) / 2;
    if (function(middle)) include = middle;
    else exclude = middle;
  }
  return include;
}
