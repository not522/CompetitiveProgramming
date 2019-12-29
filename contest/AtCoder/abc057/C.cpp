#include "math.hpp"

int main() {
  int64_t n(in), r = inf<int64_t>();
  for (int64_t a = 1; a * a <= n; ++a) {
    if (n % a == 0) {
      chmin(r, int64_t(log10(n / a)) + 1);
    }
  }
  cout << r << endl;
}
