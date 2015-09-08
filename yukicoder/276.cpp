#include "math/basic.hpp"

int main() {
  long long n;
  cin >> n;
  cout << gcd(n * (n + 1) / 2, n) << endl;
}
