#include "geometry/intersect.hpp"
#include "geometry/polygon.hpp"

int main() {
  Segment segment;
  cin >> segment;
  int n;
  cin >> n;
  Polygon polygon(n);
  for (auto& point : polygon) cin >> point;
  int c = 0;
  for (const auto& side : polygon.getSides()) {
    if (intersect(segment, side)) ++c;
  }
  cout << c / 2 + 1 << endl;
}
