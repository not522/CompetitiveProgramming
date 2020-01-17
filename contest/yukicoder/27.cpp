#include "dp/unbounded_knapsack.hpp"

int main() {
  Vector<int> v(4, in);
  v.sort();
  if (v.back() <= 3) {
    cout << 4 << endl;
    return 0;
  }
  Vector<int> a(3), b(3, -1);
  int res = inf<int>();
  for (a[0] = 1; a[0] <= v.back(); ++a[0]) {
    for (a[1] = a[0] + 1; a[1] <= v.back(); ++a[1]) {
      for (a[2] = a[1] + 1; a[2] <= v.back(); ++a[2]) {
        int r = 0;
        for (const auto &u : v) {
          int k = unboundedKnapsack<int, int, true>(u, a, b);
          if (k == -inf<int>()) {
            r = inf<int>();
          } else {
            r -= k;
          }
        }
        chmin(res, r);
      }
    }
  }
  cout << res << endl;
}
