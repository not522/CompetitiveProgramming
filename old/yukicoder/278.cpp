#include "math/prime.hpp"

int main() {
  int64_t n;
  cin >> n;
  int64_t x = n % 2 ? n : n / 2, res = 0;
  Prime prime;
  for (auto& i : prime.divisor(x)) res += i;
  cout << res << endl;
}
