#include "container/power_set.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (int& i : t) cin >> i;
  int res = numeric_limits<int>::max();
  for (auto i : PowerSet(n)) {
    int a = 0, b = 0;
    for (int j = 0; j < 4; ++j) {
      if (i.in(j)) a += t[j];
      else b += t[j];
    }
    res = min(res, max(a, b));
  }
  cout << res << endl;
}
