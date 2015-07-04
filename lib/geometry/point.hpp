#pragma once
#include "geometry/real.hpp"

class Point : public Arithmetic<Point> {
public:
  Real x, y;
  
  Point() {}

  Point (Real x, Real y) : x(x), y(y) {}
  
  Point operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
  }

  Point operator-=(const Point& p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }

  Point operator*=(const Point& p) {
    Real xx = x * p.x - y * p.y;
    Real yy = x * p.y + y * p.x;
    return *this = Point(xx, yy);
  }

  Point operator/=(const Point& p) {
    Real nrm = p.norm();
    Real xx = (x * p.x + y * p.y) / nrm;
    Real yy = (x * p.y - y * p.x) / nrm;
    return *this = Point(xx, yy);
  }

  Real norm() const {
    return x * x + y * y;
  }

  Real abs() const {
    return sqrt(norm());
  }
};

inline Real norm(const Point& p) {
  return p.norm();
}

inline Real abs(const Point& p) {
  return p.abs();
}

ostream& operator<<(ostream& os, Point a) {
	os << "(" << a.x << "," << a.y << ")";
	return os;
}

istream& operator>>(istream& is, Point& a) {
  Real x, y;
	is >> x >> y;
	a = Point(x, y);
	return is;
}
