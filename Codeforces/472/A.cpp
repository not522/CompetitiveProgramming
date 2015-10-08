#include "math/prime.hpp"

int main() {
  Prime prime(1000000);
  int n;
  cin >> n;
  for (int i = 4; ; ++i) {
    if (!prime.isPrime(i) && !prime.isPrime(n - i)) {
      cout << i << " " << n - i << endl;
      return 0;
    }
  }
}
