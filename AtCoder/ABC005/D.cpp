#include "cumulative_sum.hpp"

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(n));
  for (auto& i : d) for (int& j : i) cin >> j;
  CumulativeSum2D<vector<vector<int>>> cumulativeSum2D(d);
  vector<int> res(n * n + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = i + 1; k <= n; ++k) {
        for (int l = j + 1; l <= n; ++l) {
          int area = (k - i) * (l - j);
          res[area] = max(res[area], cumulativeSum2D.sum(i, j, k, l));
        }
      }
    }
  }
  for (int i = 0; i < n * n; ++i) res[i + 1] = max(res[i], res[i + 1]);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int p;
    cin >> p;
    cout << res[p] << endl;
  }
}
