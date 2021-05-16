#include "template.hpp"

int main() {
  int64_t n(in), res = n;
  for (int64_t b = 0; (1ll << b) <= n; ++b) {
    int64_t k = 1ll << b;
    auto a = n / k;
    auto c = n - a * k;
    chmin(res, a + b + c);
  }
  cout << res << endl;
}
