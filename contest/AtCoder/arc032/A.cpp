#include "math/prime.hpp"

int main() {
  int n;
  cin >> n;
  Prime prime;
  cout << (prime.isPrime(n * (n + 1) / 2) ? "WANWAN" : "BOWWOW") << endl;
}
