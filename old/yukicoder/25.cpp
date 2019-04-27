#include "math/basic.hpp"

int main() {
  int64_t n, m;
  cin >> n >> m;
  auto g = gcd(n, m);
  n /= g;
  m /= g;
  while (n % 10 == 0) n /= 10;
  n %= 10;
  while (m != 1) {
    n *= 10;
    g = gcd(n, m);
    if (g == 1) {
      cout << -1 << endl;
      return 0;
    }
    n /= g;
    m /= g;
    n %= 10;
  }
  cout << n << endl;
}
