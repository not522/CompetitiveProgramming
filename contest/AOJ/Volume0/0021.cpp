#include "geometry/intersect.hpp"

void solve() {
  Line p, q;
  cin >> p >> q;
  cout << (intersect<true>(p, q) ? "NO" : "YES") << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
