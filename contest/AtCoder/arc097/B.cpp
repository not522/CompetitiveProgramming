#include "container/union_find.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  cin >> p;
  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    uf.unite(x - 1, y - 1);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (uf.equal(i, p[i] - 1)) ++res;
  }
  cout << res << endl;
}
