#include "math/prime.hpp"

int main() {
  long long x;
  cin >> x;
  Prime prime;
  auto d = prime.primeFactor(x);
  for (auto i : d) while (x % (i * i) == 0) x /= i * i;
  cout << x << endl;
}
