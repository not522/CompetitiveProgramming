#include "template.hpp"

int main() {
  int64_t n(in), res = 0;
  for (int64_t i = 1; i <= n; ++i) {
    res += (n / i + 1) * (n / i) / 2 * i;
  }
  cout << res << endl;
}
