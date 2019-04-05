#include "geometry/polygon.hpp"
#include "string.hpp"

int main() {
  set_bool_name("YES", "NO");
  for (String line; line = in, !in.eof;) {
    auto v = line.split(',').transform(cast<String, long double>());
    Polygon polygon(4);
    for (int i = 0; i < 4; ++i) {
      polygon[i] = Point(v[2 * i], v[2 * i + 1]);
    }
    if (polygon.area() < 0) {
      polygon.reverse();
    }
    auto is_convex = [](const Vector<Point> &corner) {
      return ccw(Segment(corner[0], corner[1]), corner[2]) != RIGHT;
    };
    cout << polygon.getCorners().all_of(is_convex) << endl;
  }
}
