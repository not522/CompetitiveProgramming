#include "geometry/area.hpp"
#include "geometry/convex_polygon.hpp"

int main() {
  int n;
  cin >> n;
  ConvexPolygon<> convexPolygon(n);
  for (auto& p : convexPolygon) cin >> p;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Line line;
    cin >> line;
    cout << area(convexPolygon.cut(line)) << endl;
  }
}
