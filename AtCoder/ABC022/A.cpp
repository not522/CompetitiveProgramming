#include "template.hpp"

int main() {
  int n, s, t, w = 0, res = 0;
  cin >> n >> s >> t;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    w += a;
    if (s <= w && w <= t) ++res;
  }
  cout << res << endl;
}
