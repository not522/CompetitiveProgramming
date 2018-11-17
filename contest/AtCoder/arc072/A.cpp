#include "minmax.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int64_t res = numeric_limits<int64_t>::max();
  for (int t = 0; t < 2; ++t) {
    int64_t r = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      if (t != i % 2) s *= -1;
      if (s <= 0) {
        r += 1 - s;
        s = 1;
      }
      if (t != i % 2) s *= -1;
    }
    chmin(res, r);
  }
  cout << res << endl;
}
