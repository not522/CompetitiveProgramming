#pragma once
#include "geometry/basic.hpp"

enum CCW{LEFT = 1, RIGHT = -1, BACK = 2, FRONT = -2, ON = 0};

int ccw(Point a, Point b, Point c) {
  b -= a; c -= a;
  if (det(b, c) > 0) return LEFT;
  if (det(b, c) < 0) return RIGHT;
  if (dot(b, c) < 0) return BACK;
  if (b.norm() > c.norm()) return FRONT;
  return ON;
}
