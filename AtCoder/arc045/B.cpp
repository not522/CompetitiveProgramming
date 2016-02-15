#include "cumulative_sum_1D.hpp"
#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m), t(m), res;
  for (int i = 0; i < m; ++i) cin >> s[i] >> t[i];
  CumulativeSum1D<int, true> sum1(n), sum2(n);
  for (int i = 0; i < m; ++i) sum1.add(s[i] - 1, t[i], 1);
  for (int i = 0; i < n; ++i) if (sum1.value(i) == 1) sum2.add(i, 1);
  for (int i = 0; i < m; ++i) if (sum2.sum(s[i] - 1, t[i]) == 0) res.emplace_back(i + 1);
  cout << res.size() << endl;
  cout << res;
}
