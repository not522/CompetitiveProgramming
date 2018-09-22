#include "template.hpp"

int main() {
  int n, m, r = 0;
  cin >> n;
  vector<string> s(n);
  cin >> s >> m;
  vector<string> t(m);
  cin >> t;
  for (const auto& z : s) {
    int a = 0;
    for (const auto& x : s) {
      if (x == z) ++a;
    }
    for (const auto& y : t) {
      if (y == z) --a;
    }
    r = max(r, a);
  }
  cout << r << endl;
}
