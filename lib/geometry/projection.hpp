#pragma once
#include "geometry/line.hpp"

inline Point projection(const Point& a, const Point &b) {
  return a * (b / a).x;
}

inline Point projection(const Line& line, const Point& point) {
  return line.a + projection(line.vec(), point - line.a);
}

inline Point reflection(const Point& a, const Point &b) {
  return a * (b / a).conj();
}

inline Point reflection(const Line& line, const Point& point) {
  return line.a + reflection(line.vec(), point - line.a);
}
