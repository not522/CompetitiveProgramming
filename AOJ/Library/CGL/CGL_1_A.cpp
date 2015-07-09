#include "geometry/projection.hpp"

int main() {
  Point p1, p2;
  cin >> p1 >> p2;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Point p, r;
    cin >> p;
    r = perpendicular(Line(p1, p2), p);
    cout << r << endl;
  }
}
