#include "geometry/convex_polygon.hpp"

int main() {
  int n(in);
  Vector<Point> points(n, in);
  cout << ConvexPolygon<>(points).diameter() << endl;
}
