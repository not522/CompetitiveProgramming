#include "math/prime.hpp"

int main() {
  int64_t n(in), l(in), res = 0;
  Prime prime(l + 1);
  for (int i = 2; i <= l; ++i) {
    if (prime.isPrime(i)) {
      res += max(l - i * (n - 1) + 1, int64_t(0));
    }
  }
  cout << res << endl;
}
