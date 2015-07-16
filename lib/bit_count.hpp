#pragma once
#include "template.hpp"

int countBit(int n) {
  return __builtin_popcount(n);
}

int countBit(unsigned int n) {
  return __builtin_popcount(n);
}

int countBit(long long n) {
  return __builtin_popcountll(n);
}

int countBit(unsigned long long n) {
  return __builtin_popcountll(n);
}
