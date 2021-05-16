#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  int64_t res = 0;
  Vector<int64_t> x{a[0]}, y{0}, z{0};
  for (int i = 2; i < n; i += 2) {
    x.emplace_back(x.back() + a[i]);
  }
  for (int i = 1; i < n; i += 2) {
    y.emplace_back(y.back() + a[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      z.emplace_back(x[i / 2] - y[i / 2]);
    } else {
      z.emplace_back(x[i / 2] - y[i / 2 + 1]);
    }
  }
  z.sort();
  for (int i = 0; i <= n;) {
    int j = i;
    for (; j + 1 <= n && z[i] == z[j + 1]; ++j) {
    }
    res += int64_t(j - i) * int64_t(j - i + 1) / 2;
    i = j + 1;
  }
  cout << res << endl;
}
