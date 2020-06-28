#include "math/prime.hpp"

int main() {
  Prime prime(100003);
  int x(in);
  for (int i = x;; ++i) {
    if (prime.isPrime(i)) {
      cout << i << endl;
      break;
    }
  }
}
