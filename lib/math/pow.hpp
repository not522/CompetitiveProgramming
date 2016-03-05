#pragma once
#include "template.hpp"

template<typename T> T pow(const T& m, long long n) {
  if (n == 0) {
    return m.identity();
  } else if (n < 0) {
    return m.identity() / pow(m, -n);
  }
  T mm = pow(m, n / 2);
  mm *= mm;
  if (n % 2) mm *= m;
  return mm;
}
