#include "geometry/ccw.hpp"
#include "geometry/polygon.hpp"

int main() {
  int n;
  cin >> n;
  Polygon polygon(n);
  for (auto& p : polygon) cin >> p;
  for (auto& corner : polygon.getCorners()) {
    if (ccw(Segment(corner[0], corner[1]), corner[2]) == RIGHT) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}
