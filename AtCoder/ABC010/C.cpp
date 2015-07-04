#include "geometry/point.hpp"

int main() {
  Point a, b;
  Real t, v;
  int n;
  cin >> a.x >> a.y >> b.x >> b.y >> t >> v >> n;
  for (int i = 0; i < n; ++i) {
    Point p;
    cin >> p.x >> p.y;
    if (abs(p - a) + abs(p - b) <= t * v) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
