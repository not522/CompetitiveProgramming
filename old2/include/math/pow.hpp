#pragma once
#include "template.hpp"

template <typename T> struct is_integral;

template <> struct is_integral<int> { using value_type = int; };

template <> struct is_integral<long> { using value_type = long; };

template <> struct is_integral<long long> { using value_type = long long; };

template <> struct is_integral<unsigned> { using value_type = unsigned; };

template <> struct is_integral<unsigned long> {
  using value_type = unsigned long;
};

template <> struct is_integral<unsigned long long> {
  using value_type = unsigned long long;
};

template <typename T> typename is_integral<T>::value_type identity(const T &m) {
  (void)m;
  return T(1);
}

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
