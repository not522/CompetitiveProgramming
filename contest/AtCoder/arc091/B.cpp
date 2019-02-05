#include "template.hpp"

int main() {
  int64_t n, k, res = 0;
  cin >> n >> k;
  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }
  for (int b = k + 1; b <= n; ++b) {
    res += n / b * (b - k) + max(n % b - k + 1, int64_t(0));
  }
  cout << res << endl;
}
