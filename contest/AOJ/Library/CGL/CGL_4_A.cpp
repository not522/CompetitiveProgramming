#include "geometry/convex_polygon.hpp"

int main() {
  int n;
  cin >> n;
  vector<Point> points(n);
  for (auto& p : points) cin >> p;
  ConvexPolygon<false> convexPolygon(points);
  auto f = [](Point a, Point b){return a.y == b.y ? a.x < b.x : a.y < b.y;};
  auto itr = min_element(convexPolygon.begin(), convexPolygon.end(), f);
  rotate(convexPolygon.begin(), itr, convexPolygon.end());
  cout << convexPolygon.size() << endl;
  for (const auto& point : convexPolygon) {
    cout << int(point.x) << " " << int(point.y) << endl;
  }
}
