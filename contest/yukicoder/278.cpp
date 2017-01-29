#include "math/prime.hpp"

int main() {
  long long n;
  cin >> n;
  long long x = n % 2 ? n : n / 2, res = 0;
  Prime prime;
  for (auto& i : prime.divisor(x)) res += i;
  cout << res << endl;
}
