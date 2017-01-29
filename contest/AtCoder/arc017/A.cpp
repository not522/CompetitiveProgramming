#include "math/prime.hpp"

int main() {
  int n;
  cin >> n;
  Prime prime;
  cout << (prime.isPrime(n) ? "YES" : "NO") << endl;
}
