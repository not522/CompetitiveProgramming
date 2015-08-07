#include "geometry/convex_polygon.hpp"

int main() {
  int n;
  cin >> n;
  ConvexPolygon<> convexPolygon(n);
  for (auto& p : convexPolygon) cin >> p;
  cout << convexPolygon.diameter() << endl;
}
