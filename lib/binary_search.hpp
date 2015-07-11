#pragma once
#include "template.hpp"

class BinarySearch {
private:
  long long include, exclude;

protected:
  virtual bool valid(long long n) = 0;

public:
  BinarySearch(long long include, long long exclude) : include(include), exclude(exclude) {}

  long long solve() {
    while (abs(exclude - include) > 1) {
      long long mid = (include + exclude) / 2;
      if (valid(mid)) include = mid;
      else exclude = mid;
    }
    return include;
  }
};
