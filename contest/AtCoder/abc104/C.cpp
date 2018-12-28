#include "container/power_set.hpp"
#include "math/basic.hpp"

int main() {
  int d, g, r = numeric_limits<int>::max();
  cin >> d >> g;
  vector<int> p(d), c(d);
  for (int i = 0; i < d; ++i) cin >> p[i] >> c[i];
  for (auto bit : PowerSet(d)) {
    int a = 0, k = 0;
    for (int i : bit) {
      a += p[i];
      k += 100 * (i + 1) * p[i] + c[i];
    }
    if (g <= k) {
      chmin(r, a);
      continue;
    }
    for (int i = d - 1; k < g; --i) {
      if (bit.in(i)) continue;
      int b = ceil(g - k, 100 * (i + 1));
      if (b > p[i]) break;
      chmin(r, a + b);
      break;
    }
  }
  cout << r << endl;
}
