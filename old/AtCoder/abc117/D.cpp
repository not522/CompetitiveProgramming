#include "template.hpp"

int main() {
  int64_t n, k, res = 0, s = 0;
  cin >> n >> k;
  vector<int64_t> a(n);
  cin >> a;
  for (auto i : a) res += k ^ i;
  for (int64_t i = 1; i <= k; i *= 2) {
    int64_t r = 0, c = 0;
    for (auto j : a) r += ((j ^ k) & -2 * i) + (j & i);
    if (k & i) chmax(res, r + s);
    for (auto j : a) {
      if (j & i) ++c;
    }
    s += max(c, n - c) * i;
  }
  cout << res << endl;
}
