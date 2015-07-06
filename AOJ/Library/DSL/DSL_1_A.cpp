#include "container/union_find.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) uf.unite(x, y);
    else cout << (uf.equal(x, y) ? 1 : 0) << endl;
  }
}
