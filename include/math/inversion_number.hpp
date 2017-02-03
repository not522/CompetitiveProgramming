#pragma once
#include "template.hpp"

template<typename T> long long inversion_number(const vector<T>& v) {
  function<long long(vector<T>&)> f = [&](vector<T>& v){
    if (v.size() <= 1u) return 0;
    int n = v.size();
    vector<int> a(v.begin(), v.begin() + n / 2);
    vector<int> b(v.begin() + n / 2, v.end());
    int count = f(a) + f(b);
    for (int i = 0, j = 0, k = 0; i < n; ++i) {
      if (k == (int)b.size()) {
        v[i] = a[j++];
      } else if (j == (int)a.size()) {
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
  auto vv = v;
  return f(vv);
}
