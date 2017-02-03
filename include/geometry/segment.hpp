#pragma once
#include "geometry/line.hpp"

class Segment : public Line, public Ordered<Segment> {
public:
  Segment() {}

  Segment (const Point& a, const Point& b) : Line(a, b) {}

  bool operator<(const Segment& segment) const {
    return a == segment.a ? b < segment.b : a < segment.a;
  }
};
