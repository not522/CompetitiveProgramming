#pragma once
#include "template.hpp"

class BinarySearch {
private:
  long long lower, upper;

protected:
  virtual bool valid(long long n) = 0;

public:
  BinarySearch(long long lower, long long upper) : lower(lower), upper(upper) {}

  long long solve() {
    while (lower + 1 < upper) {
      long long mid = (lower + upper) / 2;
      if (valid(mid)) lower = mid;
      else upper = mid;
    }
    return lower;
  }
};
