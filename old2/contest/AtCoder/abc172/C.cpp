#include "vector.hpp"

int main() {
  int n(in), m(in), k(in);
  Vector<int64_t> a(n, in), b(m, in);
  int64_t a_sum = 0, b_sum = b.accumulate();
  int j = m, res = 0;
  for (int i = 0; i <= n; ++i) {
    while (j > 0 && a_sum + b_sum > k) {
      --j;
      b_sum -= b[j];
    }
    if (a_sum + b_sum > k) {
      cout << res << endl;
      return 0;
    }
    chmax(res, i + j);
    if (i < n) {
      a_sum += a[i];
    }
  }
  cout << res << endl;
}
