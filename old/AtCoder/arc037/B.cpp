#include "container/union_find.hpp"

int main() {
  int n, m, res = 0;
  cin >> n >> m;
  vector<int> u(m), v(m), c(n);
  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    --u[i], --v[i];
    uf.unite(u[i], v[i]);
  }
  for (int i : u) ++c[uf.find(i)];
  for (int i = 0; i < n; ++i) if (uf.size(i) == c[i] + 1) ++res;
  cout << res << endl;
}
