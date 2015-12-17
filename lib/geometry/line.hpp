#pragma once
#include "geometry/point.hpp"

class Line {
public:
  Point a, b;

  Line() {}

  Line (const Point& a, const Point& b) : a(a), b(b) {}

  bool operator==(const Line& line) const {
    return ((line.vec() / vec()).y == 0) && (((line.a - a) / vec()).y == 0);
  }

  Point vec() const {
    return b - a;
  }
};

inline ostream& operator<<(ostream& os, const Line& line) {
  os << line.a << " " << line.b;
  return os;
}

inline istream& operator>>(istream& is, Line& line) {
  Point a, b;
  is >> a >> b;
  line = Line(a, b);
  return is;
}
