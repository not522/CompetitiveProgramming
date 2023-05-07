#include "container/union_find.hpp"

int main() {
  setBoolName("1", "0");
  int n(in), q(in);
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int t(in), u(in), v(in);
    if (t == 0) {
      uf.unite(u, v);
    } else {
      cout << uf.equal(u, v) << endl;
    }
  }
}
