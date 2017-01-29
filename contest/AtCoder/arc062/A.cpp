#include "math/basic.hpp"

int main() {
  int64_t n, x = -1, y = -1, t, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t >> a;
    if (i == 0) {
      x = t;
      y = a;
    } else {
      auto k = max(ceil(x, t), ceil(y, a));
      x = k * t;
      y = k * a;
    }
  }
  cout << x + y << endl;
}
