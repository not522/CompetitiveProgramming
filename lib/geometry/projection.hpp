#pragma once
#include "geometry/line.hpp"

Point projection(const Point& a, const Point &b) {
  return a * (b / a).x;
}

Point projection(const Line& line, const Point& point) {
  return line.a + projection(line.vec(), point - line.a);
}

Point reflection(const Point& a, const Point &b) {
  return a * (b / a).conj();
}

Point reflection(const Line& line, const Point& point) {
  return line.a + reflection(line.vec(), point - line.a);
}
