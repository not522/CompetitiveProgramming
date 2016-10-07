#include "geometry/triangle.hpp"

void solve() {
  Triangle t;
  cin >> t;
  Point p = t.circumcenter();
  cout << setprecision(3) << p << " " << (t.a - p).abs() << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
