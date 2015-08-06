#pragma once
#include "geometry/real.hpp"

class Point : public Arithmetic<Point> {
public:
  Real x, y;

  Point() {}

  Point(const Real& x) : x(x), y(0) {}

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
    y = x * p.y + y * p.x;
    x = xx;
    return *this;
  }

  Point operator*=(const Real& r) {
    x *= r;
    y *= r;
    return *this;
  }

  Point operator/=(const Point& p) {
    Real nrm = p.norm();
    Real xx = (x * p.x + y * p.y) / nrm;
    y = (y * p.x - x * p.y) / nrm;
    x = xx;
    return *this;
  }

  Point operator/=(const Real& r) {
    x /= r;
    y /= r;
    return *this;
  }

  Real norm() const {
    return x * x + y * y;
  }

  Real abs() const {
    return sqrt(norm());
  }

  Point conj() const {
    return Point(x, -y);
  }
};

inline ostream& operator<<(ostream& os, const Point& point) {
	os << point.x << " " << point.y;
	return os;
}

inline istream& operator>>(istream& is, Point& point) {
  Real x, y;
	is >> x >> y;
	point = Point(x, y);
	return is;
}
