#include "math/prime.hpp"

int main() {
  int64_t n, l, res = 0;
  cin >> n >> l;
  Prime prime(l + 1);
  for (int i = 2; i <= l; ++i) {
    if (prime.isPrime(i)) res += max(l - i * (n - 1) + 1, (int64_t)0);
  }
  cout << res << endl;
}
