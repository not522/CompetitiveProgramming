#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<int64_t> w(n, in), l(m), v(m);
  read(l, v);
  if (w.max() > v.min()) {
    cout << -1 << endl;
    return 0;
  }
  Vector<int> perm(n);
  for (int i = 0; i < n; ++i) {
    perm[i] = i;
  }
  Vector<int64_t> mem(1 << n);
  for (int i = 1; i < (1 << n); ++i) {
    int64_t ww = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        ww += w[j];
      }
    }
    for (int j = 0; j < m; ++j) {
      if (v[j] < ww) {
        chmax(mem[i], l[j]);
      }
    }
  }
  int64_t res = inf<int64_t>();
  do {
    Vector<int64_t> t(n);
    for (int i = 1; i < n; ++i) {
      int bit = 1 << perm[i];
      for (int j = i - 1; j >= 0; --j) {
        bit |= 1 << perm[j];
        chmax(t[perm[i]], t[perm[j]] + mem[bit]);
      }
    }
    chmin(res, t[perm.back()]);
  } while (perm.next_permutation());
  cout << res << endl;
}
