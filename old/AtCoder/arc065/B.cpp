#include "container/union_find.hpp"

int main() {
  int n, k[2];
  cin >> n >> k[0] >> k[1];
  vector<UnionFind> uf(2, UnionFind(n));
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < k[t]; ++i) {
      int p, q;
      cin >> p >> q;
      uf[t].unite(p - 1, q - 1);
    }
  }
  vector<vector<int>> gr[2];
  for (int i = 0; i < 2; ++i) gr[i] = uf[i].groups();
  vector<vector<int>> a(2, vector<int>(n));
  for (int t = 0; t < 2; ++t) {
    for (const auto& g : gr[t]) for (int i : g) a[t][i] = g[0];
  }
  map<pair<int, int>, int> m;
  for (int i = 0; i < n; ++i) ++m[make_pair(a[0][i], a[1][i])];
  for (int i = 0; i < n; ++i) {
    cout << m[make_pair(a[0][i], a[1][i])] << (i != n - 1 ? ' ' : '\n');
  }
}
