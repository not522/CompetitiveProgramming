#include "template.hpp"

int main() {
  int n, m, res = numeric_limits<int>::max();
  cin >> n >> m;
  vector<int> f(m);
  for (int& i : f) cin >> i;
  sort(f.begin(), f.end());
  for (int i = 0; i <= m - n; ++i) res = min(res, f[i + n - 1] - f[i]);
  cout << res << endl;
}
