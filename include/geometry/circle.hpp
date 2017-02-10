#pragma once
#include "geometry/point.hpp"

class Circle {
public:
  Point c;
  Real r;

  Circle() {}

  Circle(Point c, Real r) : c(c), r(r) {}

  Circle(Real x, Real y, Real r) : c(x, y), r(r) {}
};

ostream& operator<<(ostream& os, const Circle& circle) {
  os << circle.c.x << " " << circle.c.y << " " << circle.r;
  return os;
}

istream& operator>>(istream& is, Circle& circle) {
  Real x, y, r;
  is >> x >> y >> r;
  circle = Circle(x, y, r);
  return is;
}
