#pragma once
#include "geometry/circle.hpp"
#include "geometry/intersect.hpp"

Real distance(const Segment& segment, const Point& point) {
  Point p = (point - segment.a) / segment.vec();
  if (p.x < 0) return (p * segment.vec()).abs();
  if (p.x > 1) return ((p - Point(1, 0)) * segment.vec()).abs();
  return (p.y * segment.vec()).abs();
}

Real distance(const Segment& segment1, const Segment& segment2) {
  if (intersect(segment1, segment2)) return 0;
  return min(min(distance(segment1, segment2.a), distance(segment1, segment2.b)), min(distance(segment2, segment1.a), distance(segment2, segment1.b)));
}

Real distance(const Circle& circle1, const Circle& circle2) {
  return max((circle1.c - circle2.c).abs() - circle1.r - circle2.r, Real(0));
}
