#include "geometry/point.hpp"

inline Real det(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}
