#include "geometry/convex_polygon.hpp"

int main() {
  int n(in);
  Vector<Point> points(n, in);
  ConvexPolygon<> convexPolygon(points);
  int q(in);
  for (int i = 0; i < q; ++i) {
    Line line(in);
    cout << convexPolygon.cut(line).area() << endl;
  }
}
