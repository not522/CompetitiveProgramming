#include "vector.hpp"

int main() {
  int n(in), m(in), res = inf<int>();
  Vector<int> d(m, in);
  d.emplace_back(0);
  d.sort();
  for (int i = 0; i + n <= m; ++i) {
    chmin(res, 2 * abs(d[i]) + abs(d[i + n]));
    chmin(res, abs(d[i]) + 2 * abs(d[i + n]));
  }
  cout << res << endl;
}
