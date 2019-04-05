#include "math/combination_probability.hpp"

int main() {
  int n(in), d(in), x(in), y(in);
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
    if (x <= i && (i - x) % 2 == 0 && y <= j && (j - y) % 2 == 0) {
      res += combinationProbability.combination(n, i) *
             combinationProbability.combination(i, (i + x) / 2) *
             combinationProbability.combination(j, (j + y) / 2);
    }
  }
  cout << res << endl;
}
