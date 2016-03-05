#include "cumulative_sum_1D.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> r(n), h(n);
  for (int i = 0; i < n; ++i) {cin >> r[i] >> h[i]; --h[i];}
  vector<int> c(100001);
  for (int i = 0; i < n; ++i) ++c[r[i]];
  CumulativeSum1D<int> sum(c);
  vector<vector<int>> cnt(100001, vector<int>(3));
  for (int i = 0; i < n; ++i) ++cnt[r[i]][h[i]];
  for (int i = 0; i < n; ++i) {
    int win = sum.sum(0, r[i]);
    win += cnt[r[i]][(h[i] + 1) % 3];
    int draw = cnt[r[i]][h[i]] - 1;
    cout << win << " " << n - 1 - win - draw << " " << draw << endl;
  }
}
