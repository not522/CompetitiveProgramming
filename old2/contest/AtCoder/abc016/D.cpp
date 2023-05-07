#include "geometry/intersect.hpp"
#include "geometry/polygon.hpp"

int main() {
  Segment segment(in);
  int n(in);
  Polygon polygon(n, in);
  auto intersect_side = [&](const auto &side) {
    return intersect(segment, side);
  };
  cout << polygon.getSides().count_if(intersect_side) / 2 + 1 << endl;
}
