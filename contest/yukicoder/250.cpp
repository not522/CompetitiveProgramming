#include "math/combination.hpp"

int main() {
  setBoolName("AC", "ZETUBOU");
  int q(in);
  Combination<int64_t> comb;
  for (int i = 0; i < q; ++i) {
    int64_t d(in), x(in), t(in);
    if (t == 0) {
      cout << false << endl;
      continue;
    }
    double sum = 0, limit = log(t);
    for (int i = 1; i <= d + x - 1; ++i) {
      sum += log(i);
    }
    for (int i = 1; i <= x; ++i) {
      sum -= log(i);
    }
    for (int i = 1; i <= d - 1; ++i) {
      sum -= log(i);
    }
    if (sum > limit + 1) {
      cout << false << endl;
      continue;
    }
    int64_t s = comb.combination(d + x - 1, x);
    cout << (s <= t) << endl;
  }
}
