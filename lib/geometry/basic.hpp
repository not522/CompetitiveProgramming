#pragma once
#include "geometry/point.hpp"

inline Real dot(const Point& a, const Point& b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

inline Real det(const Point& a, const Point& b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
