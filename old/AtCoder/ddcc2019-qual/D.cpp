#include "math/garner.hpp"

int main() {
  vector<int> a(30), b(30);
  for (int i = 2; i <= 29; ++i) cin >> a[i];
  for (int i = 2; i <= 29; ++i) b[i] = a[i] % (i - 1);
  vector<int64_t> x{b[3], b[4], b[6], b[8], b[12], b[14], b[18], b[20], b[24]};
  vector<int64_t> y{2, 3, 5, 7, 11, 13, 17, 19, 23};
  auto k = int64_t(garner(x, y));
  for (int64_t i = k; i <= 1000000000000; i += 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23) {
    for (int j = 2; j <= 29; ++j) {
      int r = 0;
      for (auto n = i; n; n /= j) r += n % j;
      if (r != a[j]) goto next;
    }
    cout << i << endl;
    return 0;
 next:;
  }
  cout << "invalid" << endl;
}
