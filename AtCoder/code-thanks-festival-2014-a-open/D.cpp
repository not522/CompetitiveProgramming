#include "section.hpp"

void solve() {
  Section a, b, c;
  cin >> a >> b;
  c = a & b;
  cout << 100 * (b.size() - c.size()) << endl;
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) solve();
}
