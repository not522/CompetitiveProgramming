#include "math/prime.hpp"

int main() {
  Prime prime(1000000);
  array<int, 1000000> sum;
  sum[0] = 0;
  for (int i = 1; i < 1000000; ++i) sum[i] = sum[i - 1] + prime.isPrime(i);
  int n;
  while (cin >> n) cout << sum[n] << endl;
}
