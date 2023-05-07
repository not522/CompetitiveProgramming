#include "math/prime.hpp"

int main() {
  Prime prime;
  int64_t n(in), res = inf<int64_t>();
  for (auto d : prime.divisor(n)) {
    chmin(res, d + n / d - 2);
  }
  cout << res << endl;
}
