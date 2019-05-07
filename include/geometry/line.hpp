#pragma once
#include "geometry/point.hpp"

class Line {
public:
  Point a, b;

  Line() {}

  Line(const Point &a, const Point &b) : a(a), b(b) {}

  Line(Input &in) : a(in), b(in) {}

  bool operator==(const Line &line) const {
    return ((line.vec() / vec()).y == 0) && (((line.a - a) / vec()).y == 0);
  }

  Point vec() const { return b - a; }
};

std::ostream &operator<<(std::ostream &os, const Line &line) {
  os << line.a << " " << line.b;
  return os;
}
