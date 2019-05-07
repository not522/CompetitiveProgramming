#pragma once
#include "template.hpp"

template <typename T> auto identity(const T &m) -> decltype(T::identity(0)) {
  return T::identity(m.size());
}

template <typename T> auto identity(const T &m) -> decltype(T::identity()) {
  (void)m;
  return T::identity();
}

template <typename T> T pow(const T &m, int64_t n) {
  if (n == 0) {
    return identity<T>(m);
  } else if (n < 0) {
    return identity<T>(m) / pow(m, -n);
  }
  T mm = pow(m, n / 2);
  mm *= mm;
  if (n % 2) {
    mm *= m;
  }
  return mm;
}
