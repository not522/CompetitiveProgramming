#include "template.hpp"

int main() {
  int n, d, k;
  cin >> n >> d >> k;
  vector<int> l(d), r(d);
  for (int i = 0; i < d; ++i) cin >> l[i] >> r[i];
  for (int i = 0; i < k; ++i) {
    int s, t;
    cin >> s >> t;
    int ll = s, rr = s;
    for (int i = 0; i < d; ++i) {
      if (r[i] < ll || rr < l[i]) continue;
      ll = min(ll, l[i]);
      rr = max(rr, r[i]);
      if (ll <= t && t <= rr) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
