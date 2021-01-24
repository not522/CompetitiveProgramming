#pragma once
#include "vector.hpp"

template <typename T> int64_t inversionNumber(Vector<T> v) {
  std::function<int64_t(Vector<T> &)> f = [&](Vector<T> &v) -> int64_t {
    if (v.size() <= 1) {
      return 0;
    }
    int n = v.size();
    auto a = v.subvector(0, n / 2);
    auto b = v.subvector(n / 2);
    int64_t count = f(a) + f(b);
    for (int i = 0, j = 0, k = 0; i < n; ++i) {
      if (k == b.size()) {
        v[i] = a[j++];
      } else if (j == a.size()) {
        v[i] = b[k++];
      } else if (a[j] <= b[k]) {
        v[i] = a[j++];
      } else {
        v[i] = b[k++];
        count += n / 2 - j;
      }
    }
    return count;
  };
  return f(v);
}
