#pragma once
#include "geometry/basic.hpp"

enum CCW{LEFT = 1, RIGHT = 2, BACK = 4, FRONT = 8, ON = 16};

int ccw(Point a, Point b, Point c) {
  Point p = (c - a) / (b - a);
  if (p.y > 0) return LEFT;
  if (p.y < 0) return RIGHT;
  if (p.x < 0) return BACK;
  if (p.x > 1) return FRONT;
  return ON;
}
