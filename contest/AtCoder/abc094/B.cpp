#include "template.hpp"

int main() {
  int n, m, x, s = 0, t = 0;
  cin >> n >> m >> x;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    if (a < x) ++s;
    else ++t;
  }
  cout << min(s, t) << endl;
}
