#pragma once
#include "geometry/line.hpp"

inline Point projection(const Point& a, const Point &b) {
  return a * (b / a).x;
}

inline Point perpendicular(const Line& line, const Point& point) {
  return line.a + projection(line.vec(), point - line.a);
}
