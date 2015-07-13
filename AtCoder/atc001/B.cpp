#include "container/union_find.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int p, a, b;
    cin >> p >> a >> b;
    if (p == 0) uf.unite(a, b);
    else cout << (uf.equal(a, b) ? "Yes" : "No") << endl;
  }
}
