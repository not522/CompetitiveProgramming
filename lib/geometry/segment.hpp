#pragma once
#include "geometry/line.hpp"

class Segment : public Line {
public:
  Segment() {}

  Segment (const Point& a, const Point& b) : Line(a, b) {}
};
