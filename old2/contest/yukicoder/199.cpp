#include "geometry/convex_polygon.hpp"

int main() {
  setBoolName("YES", "NO");
  Vector<Point> p(5, in);
  cout << (ConvexPolygon<>(p).size() == 5) << endl;
}
