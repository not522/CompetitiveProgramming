#include "vector.hpp"

int w0;
vector<int> a[4];

int64_t solve(int k, int w) {
  if (k == 4) return 0;
  int64_t res = solve(k + 1, w), r = 0;
  for (int i = 0; i < int(a[k].size()); ++i) {
    w -= w0 + k;
    if (w < 0) break;
    r += a[k][i];
    chmax(res, r + solve(k + 1, w));
  }
  return res;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> w(n), v(n);
  for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
  w0 = w[0];
  for (int i = 0; i < n; ++i) a[w[i] - w0].emplace_back(v[i]);
  for (int i = 0; i < 4; ++i) rsort(a[i]);
  cout << solve(0, x) << endl;
}
