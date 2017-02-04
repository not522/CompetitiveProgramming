#include "template.hpp"

int main() {
  int64_t n, h, a, b, c, d, e;
  cin >> n >> h >> a >> b >> c >> d >> e;
  int64_t res = numeric_limits<int64_t>::max();
  for (int i = 0; i <= n; ++i) {
    res = min(res, i * a + max(int64_t(0), n - i - (h + i * b + (n - i) * d - 1) / (d + e)) * c);
  }
  cout << res << endl;
}
