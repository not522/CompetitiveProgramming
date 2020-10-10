#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> a(n, in), b(n, in), c(n, in);
  int64_t low = -1e18, high = 1e18;
  while (high - low > 1) {
    int64_t mid = (low + high) / 2;
    int64_t dp = a.back() + c.back();
    for (int i = n - 2; i >= 0; --i) {
      if (b[i + 1] + dp >= mid) {
        dp = max(dp, c[i]);
      }
      dp += a[i];
    }
    if (dp + b[0] >= mid) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << low << endl;
}
