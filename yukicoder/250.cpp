#include "math/combination.hpp"

int main() {
  int q;
  cin >> q;
  Combination<long long> comb;
  for (int i = 0; i < q; ++i) {
    long long d, x, t;
    cin >> d >> x >> t;
    if (t == 0) {
      cout << "ZETUBOU" << endl;
      continue;
    }
    double sum = 0, limit = log(t);
    for (int i = 1; i <= d + x - 1; ++i) sum += log(i);
    for (int i = 1; i <= x; ++i) sum -= log(i);
    for (int i = 1; i <= d - 1; ++i) sum -= log(i);
    if (sum > limit + 1) {
      cout << "ZETUBOU" << endl;
      continue;
    }
    long long s = comb.combination(d + x - 1, x);
    cout << (s <= t ? "AC" : "ZETUBOU") << endl;
  }
}