#pragma once
#include "geometry/polygon.hpp"

inline Real area(const Segment& segment) {
  return (segment.a.x * segment.b.y - segment.a.y * segment.b.x) / 2;
}

inline Real area(const Polygon& polygon) {
  auto side = polygon.getSides();
  auto f = [](const Real& r, const Segment& segment){return r + area(segment);};
  return accumulate(side.begin(), side.end(), Real(0), f);
}
