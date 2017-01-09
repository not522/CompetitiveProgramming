#pragma once
#include "geometry/area.hpp"

Point centroid(const vector<Point>& points) {
  return accumulate(points.begin(), points.end(), Point(0)) / points.size();
}

Point centroid(const Polygon& polygon) {
  auto side = polygon.getSides();
  auto f = [](const Point& point, const Segment& segment){return point + (segment.a + segment.b) / 3 * area(segment);};
  return accumulate(side.begin(), side.end(), Point(0), f) / area(polygon);
}
