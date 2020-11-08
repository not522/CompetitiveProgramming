#include "container/power_set.hpp"

int main() {
  int n(in), m(in), x(in);
  Vector<int> c;
  Vector<Vector<int>> a;
  for (int i = 0; i < n; ++i) {
    c.emplace_back(in);
    a.emplace_back(m, in);
  }
  int res = inf<int>();
  for (auto bit : powerSet(n)) {
    Vector<int> s(m);
    int cost = 0;
    for (int i : bit) {
      cost += c[i];
      for (int j = 0; j < m; ++j) {
        s[j] += a[i][j];
      }
    }
    if (s.all_of([&](int k) { return k >= x; })) {
      chmin(res, cost);
    }
  }
  if (res == inf<int>()) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}
