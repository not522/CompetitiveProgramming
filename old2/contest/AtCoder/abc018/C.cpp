#include "cumulative_sum_2D.hpp"
#include "string.hpp"

int main() {
  int r(in), c(in), k(in);
  Vector<String> s(r, in);
  CumulativeSum2D<int> sum(r, c);
  Vector<String> t = s;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (s[i][j] != 'x') {
        continue;
      }
      for (int di = -k + 1; di <= k - 1; ++di) {
        if (i + di < 0 || r <= i + di) {
          continue;
        }
        sum.add(i + di, max(0, j - (k - abs(di) - 1)), i + di + 1,
                min(c, j + k - abs(di)), 1);
      }
    }
  }
  int res = 0;
  for (int i = k - 1; i < r - k + 1; ++i) {
    for (int j = k - 1; j < c - k + 1; ++j) {
      if (sum.value(i, j) == 0) {
        ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}
