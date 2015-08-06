#pragma once
#include "geometry/intersect.hpp"

inline Real distance(const Segment& segment, const Point& point) {
  Point p = (point - segment.a) / segment.vec();
  if (p.x < 0) return (p * segment.vec()).abs();
  if (p.x > 1) return ((p - Point(1, 0)) * segment.vec()).abs();
  return (p.y * segment.vec()).abs();
}

inline Real distance(const Segment& segment1, const Segment& segment2) {
  if (intersect(segment1, segment2)) return 0;
  return min(min(distance(segment1, segment2.a), distance(segment1, segment2.b)), min(distance(segment2, segment1.a), distance(segment2, segment1.b)));
}
