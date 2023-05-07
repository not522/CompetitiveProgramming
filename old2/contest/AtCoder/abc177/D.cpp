#include "container/union_find.hpp"

int main() {
  int n(in), m(in);
  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int a(in), b(in);
    uf.unite(a - 1, b - 1);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    chmax(res, uf.size(i));
  }
  cout << res << endl;
}
