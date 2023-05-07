#include "vector.hpp"

int main() {
  int64_t b(in), n(in);
  Vector<int64_t> c(n, in);
  c.sort();
  int64_t sum = c.accumulate(), r = c[n / 2];
  if (c[n / 2] * n > sum + b) {
    r = (sum + b) / n;
  }
  int64_t res = 0;
  for (auto i : c) {
    res += abs(r - i);
  }
  cout << res << endl;
}
