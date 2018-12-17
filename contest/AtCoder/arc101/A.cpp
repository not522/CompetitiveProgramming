#include "minmax.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> x(n);
  cin >> x;
  int64_t res = numeric_limits<int64_t>::max();
  for (int i = 0; i + k <= n; ++i) {
    if (x[i] > 0) {
      chmin(res, x[i + k - 1]);
    } else if (x[i + k - 1] < 0) {
      chmin(res, -x[i]);
    } else {
      chmin(res, 2 * abs(x[i]) + abs(x[i + k - 1]));
      chmin(res, abs(x[i]) + 2 * abs(x[i + k - 1]));
    }
  }
  cout << res << endl;
}
