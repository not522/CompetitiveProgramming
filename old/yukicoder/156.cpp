#include "template.hpp"

int main() {
  int n, m, res = 0;
  cin >> n >> m;
  vector<int> c(n);
  for (int& i : c) cin >> i;
  sort(c.begin(), c.end());
  for (int& i : c) {
    if (i <= m) ++res;
    m -= i;
  }
  cout << res << endl;
}
