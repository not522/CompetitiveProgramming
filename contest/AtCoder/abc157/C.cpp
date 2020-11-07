#include "string.hpp"

int main() {
  int n(in), m(in);
  Vector<Tuple<String, bool>> v;
  for (int i = 0; String(i).size() <= n; ++i) {
    if (String(i).size() == n) {
      v.emplace_back(i, true);
    }
  }
  for (int i = 0; i < m; ++i) {
    int s(in), c(in);
    for (auto &[a, b] : v) {
      if (a[s - 1] != c + '0') {
        b = false;
      }
    }
  }
  for (auto &[a, b] : v) {
    if (b) {
      cout << a << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
