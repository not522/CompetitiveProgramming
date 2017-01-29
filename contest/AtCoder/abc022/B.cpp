#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    if (s.count(a[i])) ++res;
    s.insert(a[i]);
  }
  cout << res << endl;
}
