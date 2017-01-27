#include "math/mint.hpp"
#include "math/prime.hpp"

int main() {
  int n;
  cin >> n;
  Mint res = 1;
  Prime prime;
  for (auto p : prime.primes(n)) {
    int k = 0, m = n;
    while (m /= p) k += m;
    res *= k + 1;
  }
  cout << res << endl;
}
