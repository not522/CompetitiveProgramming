#include "geometry/area.hpp"
#include "string/split.hpp"

int main() {
  string line;
  while (cin >> line) {
    auto v = split(line, ',');
    Polygon polygon(4);
    for (int i = 0; i < 4; ++i) polygon[i] = Point(stold(v[2 * i]), stold(v[2 * i + 1]));
    if (area(polygon) < 0) reverse(polygon.begin(), polygon.end());
    auto corners = polygon.getCorners();
    cout << (all_of(corners.begin(), corners.end(), [](array<Point, 3> corner){return ccw(Segment(corner[0], corner[1]), corner[2]) != RIGHT;}) ? "YES" : "NO") << endl;
  }
}
