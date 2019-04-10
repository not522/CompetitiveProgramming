#include "vector.hpp"

int main() {
  int n(in), d(in), k(in);
  (void)n;
  Vector<int> l(d), r(d);
  read(l, r);
  for (int i = 0; i < k; ++i) {
    int s(in), t(in);
    int ll = s, rr = s;
    for (int i = 0; i < d; ++i) {
      if (r[i] < ll || rr < l[i]) {
        continue;
      }
      chmin(ll, l[i]);
      chmax(rr, r[i]);
      if (ll <= t && t <= rr) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
