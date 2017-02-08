#include "template.hpp"

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> r(n), c(n);
  for (int i = 0; i < n; ++i) cin >> r[i] >> c[i];
  int64_t res = int64_t(2) * h * w - h - w;
  for (int i = 0; i < n; ++i) {
    res -= 4;
    if (r[i] == 1) ++res;
    if (r[i] == h) ++res;
    if (c[i] == 1) ++res;
    if (c[i] == w) ++res;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (abs(r[i] - r[j]) + abs(c[i] - c[j]) == 1) ++res;
    }
  }
  cout << res << endl;
}
