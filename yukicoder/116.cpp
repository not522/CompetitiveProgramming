#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n - 2; ++i) {
    auto itr = a.begin() + i;
    if (set<int>(itr, itr + 3).size() != 3u) continue;
    auto m = minmax_element(itr, itr + 3);
    if (m.first != itr && m.second != itr) ++res;
    else if (m.first != itr + 2 && m.second != itr + 2) ++res;
  }
  cout << res << endl;
}
