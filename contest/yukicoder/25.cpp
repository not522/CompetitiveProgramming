#include "math.hpp"
#include "math/prime.hpp"

int main() {
  int64_t n(in), m(in);
  auto g = gcd(n, m);
  n /= g;
  m /= g;
  int two = 0, five = 0;
  while (m % 2 == 0) {
    ++two;
    m /= 2;
  }
  while (m % 5 == 0) {
    ++five;
    m /= 5;
  }
  if (m > 1) {
    cout << -1 << endl;
    return 0;
  }
  while (n % 10 == 0) {
    n /= 10;
  }
  n %= 10;
  for (int i = 0; i < two - five; ++i) {
    n = n * 5 % 10;
  }
  for (int i = 0; i < five - two; ++i) {
    n = n * 2 % 10;
  }
  cout << n << endl;
}
