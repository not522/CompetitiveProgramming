#include "container/union_find.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    uf.unite(a, b);
  }
  cout << uf.size() - 1 << endl;
}
