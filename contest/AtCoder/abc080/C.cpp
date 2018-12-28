#include "container/power_set.hpp"

int main() {
  int n, res = numeric_limits<int>::min();
  cin >> n;
  vector<int> f(n);
  vector<vector<int>> p(n, vector<int>(11));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      int b;
      cin >> b;
      f[i] |= b << j;
    }
  }
  cin >> p;
  for (auto i : PowerSet(10)) {
    if (i == 0) continue;
    int r = 0;
    for (int j = 0; j < n; ++j) r += p[j][count_bit(i & f[j])];
    chmax(res, r);
  }
  cout << res << endl;
}
