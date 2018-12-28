#include "vector.hpp"
#include "container/fix_size_set.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m), c(m);
  vector<vector<int>> v(m);
  cin >> a;
  for (int i = 0; i < m; ++i) {
    cin >> b[i] >> c[i];
    v[i].resize(c[i]);
    cin >> v[i];
  }
  int res = 0;
  for (auto i : FixSizeSet(n, 9)) {
    int r = 0;
    for (int j : i) r += a[j];
    for (int j = 0; j < m; ++j) {
      int cnt = 0;
      for (int k : v[j]) if (i.in(k - 1)) ++cnt;
      if (cnt >= 3) r += b[j];
    }
    chmax(res, r);
  }
  cout << res << endl;
}
