#include "geometry/point.hpp"

int main() {
  Point a, b;
  Real t, v;
  int n;
  cin >> a.x >> a.y >> b.x >> b.y >> t >> v >> n;
  for (int i = 0; i < n; ++i) {
    Point p;
    cin >> p.x >> p.y;
    if ((p - a).abs() + (p - b).abs() <= t * v) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
