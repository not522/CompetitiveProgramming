#include "template.hpp"

int main() {
  int64_t n, res = 0;
  cin >> n;
  for (int64_t t = 1; t <= n; t *= 10) res += n / t / 10 * t + min(t, max(int64_t(0), n % (t * 10) - t + 1));
  cout << res << endl;
}
