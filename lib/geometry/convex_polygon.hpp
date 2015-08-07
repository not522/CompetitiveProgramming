#pragma once
#include "geometry/polygon.hpp"

template<bool strict = true> class ConvexPolygon : public Polygon {
public:
  ConvexPolygon() {}

  ConvexPolygon(vector<Point> points) {
    int flag = ~(strict ? LEFT : LEFT | FRONT);
    sort(points.begin(), points.end());
    for (int i = 0; i < (int)points.size(); emplace_back(points[i++])) {
      while (size() > 1u && ccw(*(end() - 2), back(), points[i]) & flag) pop_back();
    }
    for (int i = points.size() - 2, r = size(); i >= 0; emplace_back(points[i--])) {
      while ((int)size() > r && ccw(*(end() - 2), back(), points[i]) & flag) pop_back();
    }
    pop_back();
  }
};
