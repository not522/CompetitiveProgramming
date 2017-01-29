#include "math/prime.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  Prime prime;
  auto d = prime.divisor(n);
  cout << d[d.size() - 2] << endl;
}
