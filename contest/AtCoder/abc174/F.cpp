#include "container/bit.hpp"

int main() {
  int n(in), q(in);
  Vector<int> c(n, in), l(q), r(q), t(n, -1), ans(q);
  read(l, r);
  --c;
  --l;
  Vector<Tuple<int, int, int>> s;
  for (int i = 0; i < q; ++i) {
    s.emplace_back(r[i], l[i], i);
  }
  s.sort();
  BIT<int> bit(n);
  int k = 0;
  for (auto [q, p, i] : s) {
    for (; k < n && k < q; ++k) {
      bit.add(k, 1);
      if (t[c[k]] != -1) {
        bit.add(t[c[k]], -1);
      }
      t[c[k]] = k;
    }
    ans[i] = bit.sum(p, q);
  }
  ans.output();
}
