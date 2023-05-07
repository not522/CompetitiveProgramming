#include "container/union_find.hpp"
#include "math/mint.hpp"

int main() {
  Mint::setMod(998244353);
  int n(in), k(in);
  auto a = Vector<int>::makeVector(in, n, n);
  UnionFind uf1(n), uf2(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      bool ok = true;
      for (int t = 0; t < n; ++t) {
        if (a[i][t] + a[j][t] > k) {
          ok = false;
          break;
        }
      }
      if (ok) {
        uf1.unite(i, j);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      bool ok = true;
      for (int t = 0; t < n; ++t) {
        if (a[t][i] + a[t][j] > k) {
          ok = false;
          break;
        }
      }
      if (ok) {
        uf2.unite(i, j);
      }
    }
  }
  Vector<Mint> x(n + 1);
  x[0] = 1;
  for (int i = 1; i <= n; ++i) {
    x[i] = x[i - 1] * i;
  }
  Mint p = 1, q = 1;
  for (auto group : uf1.groups()) {
    p *= x[group.size()];
  }
  for (auto group : uf2.groups()) {
    q *= x[group.size()];
  }
  cout << p * q << endl;
}
