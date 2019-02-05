#include "math/prime.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << m << endl;
    return 0;
  }
  Prime prime;
  auto d = prime.divisor(m);
  int64_t res = 1;
  for (auto i : d) {
    if (m / i >= n) chmax(res, i);
  }
  cout << res << endl;
}
