#pragma once
#include "geometry/ccw.hpp"
#include "geometry/line.hpp"

class Segment : public Line {
public:
  Segment() {}

  Segment (const Point& a, const Point& b) : Line(a, b) {}
};

template<bool strict = false> inline bool intersect(const Line& l, const Segment& s) {
  int ccw1 = ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b);
  int ccw2 = ccw(s.a, s.b, l.a) * ccw(s.a, s.b, l.b);
  return strict ? ccw1 < 0 && ccw2 < 0 : ccw1 <= 0 && ccw2 <= 0;
}

template<bool strict = false> inline bool intersect(const Segment& s1, const Segment& s2) {
  int ccw1 = ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b);
  int ccw2 = ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b);
  return strict ? ccw1 < 0 && ccw2 < 0 : ccw1 <= 0 && ccw2 <= 0;
}
