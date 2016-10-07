#include "math/count_divisor.hpp"

int main() {
  int n;
  double p, res = 0;
  cin >> n >> p;
  auto c = count_divisor(n);
  for (int i = 2; i <= n; ++i) res += pow(1 - p, c[i] - 2);
  cout << res << endl;
}
