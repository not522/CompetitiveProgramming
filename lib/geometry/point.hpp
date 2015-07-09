#pragma once
#include "geometry/real.hpp"

class Point : public complex<Real> {
public:
  Point() {}

  Point(const Real& x, const Real& y) : complex<Real>(x, y) {}

  Point(const complex<Real> z) : complex<Real>(z) {}

  Real norm() const {
    return real() * real() + imag() * imag();
  }

  Real abs() const {
    return std::abs(*this);
  }
};

inline Real norm(const Point& point) {
  return point.norm();
}

ostream& operator<<(ostream& os, const Point& point) {
	os << "(" << point.real() << "," << point.imag() << ")";
	return os;
}

istream& operator>>(istream& is, Point& point) {
  Real x, y;
	is >> x >> y;
	point = Point(x, y);
	return is;
}
