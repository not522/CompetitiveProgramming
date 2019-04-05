#include "template.hpp"

int main() {
  int64_t n(in), h(in), a(in), b(in), c(in), d(in), e(in), res = inf<int64_t>();
  for (int i = 0; i <= n; ++i) {
    auto k = max<int64_t>(0, n - i - (h + i * b + (n - i) * d - 1) / (d + e));
    chmin(res, i * a + k * c);
  }
  cout << res << endl;
}
