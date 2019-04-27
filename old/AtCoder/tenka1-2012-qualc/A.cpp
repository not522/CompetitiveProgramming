#include "math/prime.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  Prime prime(n);
  for (int i = 0; i < n; ++i) if (prime.isPrime(i)) ++res;
  cout << res << endl;
}
