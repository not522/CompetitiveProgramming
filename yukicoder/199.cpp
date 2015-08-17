#include "geometry/convex_polygon.hpp"

int main() {
  vector<Point> p(5);
  for (auto& i : p) cin >> i;
  cout << (ConvexPolygon<>(p).size() == 5 ? "YES" : "NO") << endl;
}
