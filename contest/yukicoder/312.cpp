#include "vector.hpp"
#include "math/prime.hpp"

int main() {
  int64_t n;
  cin >> n;
  Prime prime;
  auto d = prime.divisor(n);
  cout << d[lower_bound(d, 3ll)] << endl;
}
