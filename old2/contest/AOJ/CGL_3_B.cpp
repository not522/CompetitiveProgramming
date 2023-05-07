#include "geometry/polygon.hpp"

int main() {
  int n(in);
  for (auto &corner : Polygon(n, in).getCorners()) {
    if (ccw(Segment(corner[0], corner[1]), corner[2]) == RIGHT) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}
