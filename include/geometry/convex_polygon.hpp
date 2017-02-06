#pragma once
#include "geometry/polygon.hpp"
#include "geometry/intersect.hpp"
#include "geometry/cross_point.hpp"

template<bool strict = true> class ConvexPolygon : public Polygon {
public:
  ConvexPolygon() {}

  ConvexPolygon(int n) : Polygon(n) {}

  ConvexPolygon(vector<Point> points) {
    int flag = ~(strict ? LEFT : LEFT | FRONT);
    sort(points.begin(), points.end());
    for (uint i = 0; i < points.size(); emplace_back(points[i++])) {
      while (size() > 1u && ccw(*(end() - 2), back(), points[i]) & flag) pop_back();
    }
    for (int i = points.size() - 2, r = size(); i >= 0; emplace_back(points[i--])) {
      while (int(size()) > r && ccw(*(end() - 2), back(), points[i]) & flag) pop_back();
    }
    pop_back();
  }

  Real diameter() {
    auto sides = getSides();
    int i = min_element(sides.begin(), sides.end()) - sides.begin();
    int j = max_element(sides.begin(), sides.end()) - sides.begin();
    sides.insert(sides.end(), sides.begin(), sides.end());
    Real res = 0;
    for (uint k = 0; k < 2 * size(); ++k) {
      if ((sides[i].vec() / sides[j].vec()).y >= 0) ++i;
      else ++j;
      res = max(res, (sides[i].a - sides[j].a).abs());
    }
    return res;
  }

  ConvexPolygon cut(const Line& line) {
    ConvexPolygon res;
    auto sides = getSides();
    for (const auto& side : sides) {
      if (ccw(line, side.a) != RIGHT) res.push_back(side.a);
      if (intersect<true>(line, side)) res.push_back(crossPoint(line, side));
    }
    return res;
  }
};
