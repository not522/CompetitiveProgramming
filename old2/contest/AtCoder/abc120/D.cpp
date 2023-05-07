#include "container/union_find.hpp"

int main() {
  int64_t n(in), m(in), r = n * (n - 1) / 2;
  Vector<int> a(m), b(m);
  read(a, b);
  a.reverse();
  b.reverse();
  a -= 1;
  b -= 1;
  UnionFind uf(n);
  Vector<int64_t> res;
  for (int i = 0; i < m; ++i) {
    res.emplace_back(r);
    if (!uf.equal(a[i], b[i])) {
      r -= int64_t(uf.size(a[i])) * uf.size(b[i]);
      uf.unite(a[i], b[i]);
    }
  }
  res.reverse().output();
}
