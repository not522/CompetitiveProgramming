#include "math/prime.hpp"

int main() {
  int64_t n, mn = numeric_limits<int64_t>::max();
  cin >> n;
  Prime prime;
  for (auto i : prime.divisor(n)) {
    for (auto j : prime.divisor(i)) {
      chmin(mn, n / i + i / j + j - 3);
    }
  }
  cout << mn << " " << n - 1 << endl;
}
