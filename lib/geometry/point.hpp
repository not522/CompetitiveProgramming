#pragma once
#include "geometry/real.hpp"

class Point : public Arithmetic<Point> {
public:
  Real x, y;

  Point() {}

  Point(const Real& x, const Real& y) : x(x), y(y) {}

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

inline Real norm(const Point& point) {
  return point.norm();
}

ostream& operator<<(ostream& os, const Point& point) {
	os << fixed << setprecision(15) << point.x << " " << fixed << setprecision(15) << point.y;
	return os;
}

istream& operator>>(istream& is, Point& point) {
  Real x, y;
	is >> x >> y;
	point = Point(x, y);
	return is;
}
