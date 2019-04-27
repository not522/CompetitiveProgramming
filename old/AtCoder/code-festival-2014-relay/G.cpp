#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  cin >> a;
  if (accumulate(a) < m) {
    cout << -1 << endl;
    return 0;
  }
  constexpr int INF = numeric_limits<int>::max() / 2;
  vector<int> dp1(m + max(a), INF);
  dp1[0] = 0;
  auto dp2 = dp1;
  for (int i : a) {
    for (int j = 0; j < m; ++j) chmin(dp2[j + i], dp1[j] + 1);
    dp1 = dp2;
  }
  for (int i = m; ; ++i) if (dp1[i] != INF) {
    cout << i << endl;
    break;
  }
}
