#pragma once
#include "geometry/polygon.hpp"

Point centroid(const Vector<Point> &points) {
  return points.accumulate() / points.size();
}

Point centroid(const Polygon &polygon) {
  auto side = polygon.getSides();
  auto f = [](const Point &point, const Segment &segment) {
    return point + (segment.a + segment.b) / 3 * segment.area();
  };
  return side.accumulate(Point(0), f) / polygon.area();
}
