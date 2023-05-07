#include "math.hpp"

int main() {
  int n(in), d(in), t(in);
  Map<int, Vector<int>> x;
  for (int i = 0; i < n; ++i) {
    int y(in);
    x[mod(y, d)].emplace_back(floor(y, d));
  }
  int64_t res = 0;
  for (auto &i : x) {
    i.second.sort();
    int p = -inf<int>();
    for (int &j : i.second) {
      res += j + t - max(p, j - t) + 1;
      p = j + t + 1;
    }
  }
  cout << res << endl;
}
