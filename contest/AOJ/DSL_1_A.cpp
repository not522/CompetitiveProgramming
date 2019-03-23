#include "container/union_find.hpp"

int main() {
  set_bool_name("1", "0");
  int n(in), q(in);
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int com(in), x(in), y(in);
    if (com == 0) {
      uf.unite(x, y);
    } else {
      cout << uf.equal(x, y) << endl;
    }
  }
}
