#include "template.hpp"

int main() {
  long long n, res = 0;
  cin >> n;
  for (long long t = 1; t <= n; t *= 10) res += n / t / 10 * t + min(t, max(0ll, n % (t * 10) - t + 1));
  cout << res << endl;
}
