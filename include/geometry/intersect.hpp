#pragma once
#include "geometry/ccw.hpp"

template <bool strict = false>
bool intersect(const Line &line1, const Line &line2) {
  if (strict) {
    return (line1.vec() / line2.vec()).y != 0;
  }
  return ((line1.vec() / line2.vec()).y != 0) || (line1 == line2);
}

template <bool strict = false>
bool intersect(const Line &line, const Segment &segment) {
  Point p1 = (segment.a - line.a) / line.vec();
  Point p2 = (segment.b - line.a) / line.vec();
  if (strict) {
    return p1.y * p2.y < 0;
  }
  return p1.y * p2.y <= 0;
}

template <bool strict = false>
bool intersect(const Segment &segment, const Line &line) {
  return intersect(line, segment);
}

template <bool strict = false>
bool intersect(const Segment &segment1, const Segment &segment2) {
  int ccw1 = ccw(segment1, segment2.a) | ccw(segment1, segment2.b);
  int ccw2 = ccw(segment2, segment1.a) | ccw(segment2, segment1.b);
  if (strict) {
    return (ccw1 & ccw2) == (LEFT | RIGHT);
  }
  return ((ccw1 & ccw2) == (LEFT | RIGHT)) || ((ccw1 | ccw2) & ON);
}
