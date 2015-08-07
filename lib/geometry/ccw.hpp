#pragma once
#include "geometry/segment.hpp"

enum CCW{LEFT = 1, RIGHT = 2, BACK = 4, FRONT = 8, ON = 16};

int ccw(const Point& a, const Point& b, const Point& c) {
  Point p = (c - a) / (b - a);
  if (p.y > 0) return LEFT;
  if (p.y < 0) return RIGHT;
  if (p.x < 0) return BACK;
  if (p.x > 1) return FRONT;
  return ON;
}

int ccw(const Segment& segment, const Point& point) {
  return ccw(segment.a, segment.b, point);
}

int ccw(const Line& line, const Point& point) {
  int res = ccw(line.a, line.b, point);
  if (res == BACK || res == FRONT) res = ON;
  return res;
}
