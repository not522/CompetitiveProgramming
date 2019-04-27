#include "container/union_find.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n + m);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int l;
      cin >> l;
      uf.unite(i, n + l - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (uf.equal(0, i)) continue;
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}
