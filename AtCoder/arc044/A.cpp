#include "math/prime.hpp"

int main() {
  int n;
  cin >> n;
  Prime prime;
  cout << (n != 1 && (prime.isPrime(n) || prime.primeFactor(n)[0] > 5) ? "Prime" : "Not Prime") << endl;
}
