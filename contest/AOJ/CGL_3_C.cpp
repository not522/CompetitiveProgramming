#include "geometry/polygon.hpp"

int main() {
  int n(in);
  Polygon polygon(n, in);
  int q(in);
  for (int i = 0; i < q; ++i) {
    Point point(in);
    if (polygon.cover<true>(point)) {
      cout << 2 << endl;
    } else if (polygon.cover(point)) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
