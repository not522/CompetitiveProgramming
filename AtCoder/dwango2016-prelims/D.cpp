#include "cumulative_sum_2D.hpp"
#include "vector.hpp"

long long solve(const vector<vector<long long>>& b) {
  int h = b.size(), w = b[0].size();
  CumulativeSum2D<long long> sum(b);
  long long res = -1e18;
  vector<long long> dp1(w + 1, -1e18), dp2(w + 1, -1e18);
  for (int i = 0; i < h; ++i) for (int j = i + 1; j <= h; ++j) {
    vector<long long> d1(w + 1), d2(w + 1);
    for (int k = 0; k < w; ++k) {
      long long a = sum.sum(i, k, j, k + 1);
      dp1[k] = max(dp1[k], d1[k + 1] = max(d1[k] + a, a));
    }
    for (int k = w - 1; k >= 0; --k) {
      long long a = sum.sum(i, k, j, k + 1);
      dp2[k] = max(dp2[k], d2[k] = max(d2[k + 1] + a, a));
    }
  }
  for (int i = 0; i < w; ++i) for (int j = 0; j < i; ++j) for (int k = i; k < w; ++k) res = max(res, dp1[j] + dp2[k]);
  return res;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<long long>> b(h, vector<long long>(w)), c(w, vector<long long>(h));
  cin >> b;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) c[j][i] = b[i][j];
  cout << max(solve(b), solve(c)) << endl;
}
