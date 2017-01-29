#include "container/union_find.hpp"
#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  vector<tuple<long long, long long>> p(n);
  for (auto& i : p) cin >> get<0>(i) >> get<1>(i);
  vector<tuple<long long, int, int>> dis;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dis.emplace_back(make_tuple(norm(get<0>(p[i]), get<1>(p[i]), get<0>(p[j]), get<1>(p[j])), i, j));
    }
  }
  sort(dis.begin(), dis.end());
  UnionFind uf(n);
  for (const auto& d : dis) {
    uf.unite(get<1>(d), get<2>(d));
    if (uf.equal(0, n - 1)) {
      cout << ceil((int64_t)sqrt(get<0>(d) - 1) + 1, (int64_t)10) * 10 << endl;
      return 0;
    }
  }
}
