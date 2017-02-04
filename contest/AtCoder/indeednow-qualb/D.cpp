#include "vector.hpp"

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n), p(c, -1);
  cin >> a;
  for (int& i : a) --i;
  vector<int64_t> res(c, (int64_t)n * (n + 1) / 2);
  for (int i = 0; i < n; ++i) {
    int64_t d = i - p[a[i]];
    res[a[i]] -= d * (d - 1) / 2;
    p[a[i]] = i;
  }
  for (int i = 0; i < c; ++i) {
    int64_t d = n - p[i];
    res[i] -= d * (d - 1) / 2;
  }
  cout << res;
}
