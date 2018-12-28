#include "cumulative_sum_2D.hpp"
#include "vector.hpp"

int64_t solve(const vector<vector<int64_t>>& b) {
  int h = b.size(), w = b[0].size();
  CumulativeSum2D<int64_t> sum(b);
  int64_t res = -1e18;
  vector<int64_t> dp1(w + 1, -1e18), dp2(w + 1, -1e18);
  for (int i = 0; i < h; ++i) for (int j = i + 1; j <= h; ++j) {
    vector<int64_t> d1(w + 1), d2(w + 1);
    for (int k = 0; k < w; ++k) chmax(dp1[k], d1[k + 1] = max(d1[k], int64_t(0)) + sum.sum(i, k, j, k + 1));
    for (int k = w - 1; k >= 0; --k) chmax(dp2[k], d2[k] = max(d2[k + 1], int64_t(0)) + sum.sum(i, k, j, k + 1));
  }
  for (int i = 0; i < w; ++i) for (int j = 0; j < i; ++j) for (int k = i; k < w; ++k) chmax(res, dp1[j] + dp2[k]);
  return res;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int64_t>> b(h, vector<int64_t>(w)), c(w, vector<int64_t>(h));
  cin >> b;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) c[j][i] = b[i][j];
  cout << max(solve(b), solve(c)) << endl;
}
