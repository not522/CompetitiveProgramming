#pragma once
#include "geometry/point.hpp"

inline Real dot(const Point& a, const Point& b) {
  return a.x * b.x + a.y * b.y;
}

inline Real det(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}
