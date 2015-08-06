#pragma once
#include "geometry/segment.hpp"

enum CCW{LEFT = 1, RIGHT = 2, BACK = 4, FRONT = 8, ON = 16};

int ccw(const Segment& segment, const Point& point) {
  Point p = (point - segment.a) / segment.vec();
  if (p.y > 0) return LEFT;
  if (p.y < 0) return RIGHT;
  if (p.x < 0) return BACK;
  if (p.x > 1) return FRONT;
  return ON;
}
