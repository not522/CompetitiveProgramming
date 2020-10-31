#include "container/power_set.hpp"

int main() {
  int n(in), m(in);
  Vector<Vector<int>> s(m);
  for (int i = 0; i < m; ++i) {
    int k(in);
    s[i] = Vector<int>(k, in) - 1;
  }
  Vector<int> p(m, in);
  int res = 0;
  for (const auto bit : powerSet(n)) {
    bool ok = true;
    for (int i = 0; i < m; ++i) {
      int c = 0;
      for (int t : s[i]) {
        if (bit.contains(t)) {
          ++c;
        }
      }
      if (c % 2 != p[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++res;
    }
  }
  cout << res << endl;
}
