#include "geometry/cross_point.hpp"

void solve() {
  Point a, b, c;
  cin >> a >> b >> c;
  Line s((a + b) / 2, (a + b) / 2 + (a - b) * Point(0, 1));
  Line t((a + c) / 2, (a + c) / 2 + (a - c) * Point(0, 1));
  Point p = crossPoint(s, t);
  Real::precision = 3;
  cout << fixed << setprecision(3) << p << " " << (a - p).abs() << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
