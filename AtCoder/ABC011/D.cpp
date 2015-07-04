#include "math/combination_probability.hpp"

int main() {
  int n, d, x, y;
  cin >> n >> d >> x >> y;
  x = abs(x);
  y = abs(y);
  if (x % d || y % d) {
    cout << 0 << endl;
    return 0;
  }
  x /= d;
  y /= d;
  CombinationProbability combinationProbability(1001);
  double res = 0;
  for (int i = 0; i <= n; ++i) {
    int j = n - i;
    if (i < x || (i - x) % 2) continue;
    if (j < y || (j - y) % 2) continue;
    res += combinationProbability.combination(n, i) * combinationProbability.combination(i, (i + x) / 2) * combinationProbability.combination(j, (j + y) / 2);
  }
  cout << fixed << setprecision(15) << res << endl;
}
