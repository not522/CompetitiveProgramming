#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int p, q;
    cin >> p >> q;
    if (p <= q - 2) ++res;
  }
  cout << res << endl;
}
