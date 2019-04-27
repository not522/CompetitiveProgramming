#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int p, q;
    cin >> p >> q;
    if (n == p) n = q;
    else if (n == q) n = p;
  }
  cout << n << endl;
}
