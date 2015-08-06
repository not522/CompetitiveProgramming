#pragma once
#include "geometry/ccw.hpp"

template<bool strict = false> inline bool intersect(const Line& l, const Segment& s) {
  Point p1 = s.a / l.vec(), p2 = s.b / l.vec();
  if (strict) return p1.y * p2.y < 0;
  return p1.y * p2.y <= 0;
}

template<bool strict = false> inline bool intersect(const Segment& s, const Line& l) {
  return intersect(l, s);
}

template<bool strict = false> inline bool intersect(const Segment& s1, const Segment& s2) {
  int ccw1 = ccw(s1, s2.a) | ccw(s1, s2.b);
  int ccw2 = ccw(s2, s1.a) | ccw(s2, s1.b);
  if (strict) return (ccw1 & ccw2) == (LEFT | RIGHT);
  return ((ccw1 & ccw2) == (LEFT | RIGHT)) || ((ccw1 | ccw2) & ON);
}
