#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  set<int> s;
  for (int i = 0, j = 0; i < n; ++i) {
    while (s.count(a[i])) s.erase(a[j++]);
    s.emplace(a[i]);
    chmax(res, i - j + 1);
  }
  cout << res << endl;
}
