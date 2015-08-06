#pragma once
#include "geometry/line.hpp"

inline Point crossPoint(const Line& line1, const Line& line2) {
  return line1.a + line1.vec() * ((line2.a - line1.a) / line2.vec()).y / (line1.vec() / line2.vec()).y;
}
