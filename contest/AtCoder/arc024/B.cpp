#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  cin >> c;
  if (!in(c, 0) || !in(c, 1)) {
    cout << -1 << endl;
    return 0;
  }
  c.insert(c.end(), c.begin(), c.end());
  int cnt = 0, res = 0;
  for (int i = 1; i < 2 * n; ++i) {
    if (c[i] != c[i - 1]) cnt = 0;
    else ++cnt;
    chmax(res, cnt / 2 + 1);
  }
  cout << res << endl;
}
