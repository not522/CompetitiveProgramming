#pragma once
#include "geometry/cross_point.hpp"

class Triangle {
public:
  Point a, b, c;

  Triangle() {}

  Triangle(const Point &a, const Point &b, const Point &c) : a(a), b(b), c(c) {}

  Triangle(Input &in) : a(in), b(in), c(in) {}

  Point circumcenter() const {
    Line s((a + b) / 2, (a + b) / 2 + (a - b) * Point(0, 1));
    Line t((a + c) / 2, (a + c) / 2 + (a - c) * Point(0, 1));
    return crossPoint(s, t);
  }
};

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
  os << triangle.a << " " << triangle.b << " " << triangle.c;
  return os;
}
