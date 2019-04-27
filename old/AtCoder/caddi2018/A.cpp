#include "math/prime.hpp"

int main() {
  int64_t n, p, res = 1;
  cin >> n >> p;
  for (int64_t q : prime_factor(p)) {
    int c = 0;
    while (p % q == 0) {
      p /= q;
      ++c;
    }
    for (int i = 0; i < c / n; ++i) res *= q;
  }
  cout << res << endl;
}
