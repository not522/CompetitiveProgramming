#include "vector.hpp"

int main() {
  int h(in), w(in);
  Vector<int64_t> a(h - 1, in), b(w, in), c(h, in), d(w - 1, in);
  int64_t res = 0;
  for (int i = 0; i < h - 1; ++i) {
    res += a[i] + b[0];
  }
  for (int i = 0; i < w - 1; ++i) {
    res += c[0] + d[i];
  }
  res += a.accumulate() * (w - 1) + b.subvector(1).accumulate() * (h - 1);
  auto diff = d - b.subvector(1);
  auto ac = c.subvector(1) - a;
  ac.rsort();
  diff.sort();
  int64_t k = 0;
  auto diff_sum = diff.partial_sum();
  for (int64_t aa : ac) {
    while (k < w - 1 && diff[k] + aa < 0) {
      ++k;
    }
    if (k) {
      res += k * aa + diff_sum[k - 1];
    }
  }
  cout << res << endl;
}
