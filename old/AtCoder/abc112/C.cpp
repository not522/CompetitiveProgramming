#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> h[i];
  for (int i = 0; i < n; ++i) {
    if (h[i]) {
      swap(x[0], x[i]);
      swap(y[0], y[i]);
      swap(h[0], h[i]);
      break;
    }
  }
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      int H = h[0] + abs(x[0] - i) + abs(y[0] - j);
      bool ok = true;
      for (int k = 1; k < n; ++k) {
        if (max(H - abs(x[k] - i) - abs(y[k] - j), 0) != h[k]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << i << " " << j << " " << H << endl;
        return 0;
      }
    }
  }
}
