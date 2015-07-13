#include "template.hpp"

int main() {
  long long n, h, a, b, c, d, e;
  cin >> n >> h >> a >> b >> c >> d >> e;
  long long res = numeric_limits<long long>::max();
  for (int i = 0; i <= n; ++i) {
    res = min(res, i * a + max(0ll, n - i - (h + i * b + (n - i) * d - 1) / (d + e)) * c);
  }
  cout << res << endl;
}
