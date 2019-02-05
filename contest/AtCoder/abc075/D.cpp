#include "template.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  auto a = x, b = y;
  sort(a);
  sort(b);
  int64_t res = numeric_limits<int64_t>::max();
  for (int x1 = 0; x1 < n; ++x1) {
    for (int x2 = x1 + 1; x2 < n; ++x2) {
      for (int y1 = 0; y1 < n; ++y1) {
        for (int y2 = y1 + 1; y2 < n; ++y2) {
          int c = 0;
          for (int i = 0; i < n; ++i) {
            if (a[x1] <= x[i] && x[i] <= a[x2] && b[y1] <= y[i] && y[i] <= b[y2]) ++c;
          }
          if (c >= k) chmin(res, (a[x2] - a[x1]) * (b[y2] - b[y1]));
        }
      }
    }
  }
  cout << res << endl;
}
