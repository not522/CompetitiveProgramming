#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  int am = max(a);
  rsort(b);
  int res = ceil(h, am);
  for (int i = 0; i < n; ++i) {
    h -= b[i];
    if (h <= 0) {
      chmin(res, i + 1);
      break;
    }
    chmin(res, ceil(h, am) + i + 1);
  }
  cout << res << endl;
}
