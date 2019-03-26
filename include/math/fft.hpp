#pragma once
#include <complex>

#include "bit_operation.hpp"
#include "vector.hpp"
#include "math/basic.hpp"

void fft(Vector<std::complex<long double>> &a, int n, int dir) {
  long double theta = dir * 2 * pi() / n;
  for (int m = n; m > 1; m /= 2) {
    int mh = m / 2;
    for (int i = 0; i < mh; i++) {
      auto w = exp(i * theta * std::complex<long double>(0, 1));
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        auto x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
    }
    theta *= 2;
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n / 2; k > (i ^= k); k /= 2);
    if (j < i) swap(a[i], a[j]);
  }
}

template<typename T> Vector<T> convolution(const Vector<T> &aa, const Vector<T> &bb){
  Vector<std::complex<long double>> a(begin(aa), end(aa)), b(begin(bb), end(bb));
  int n = 2 << most_bit(a.size() + b.size());
  a.resize(n);
  b.resize(n);
  fft(a, n, 1);
  fft(b, n, 1);
  for (int i = 0; i < n; ++i) a[i] *= b[i];
  fft(a, n, -1);
  Vector<T> res(n);
  for (int i = 0; i < n; ++i) res[i] = round(real(a[i]) / n);
  return res;
}
