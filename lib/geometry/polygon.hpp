#pragma once
#include "geometry/segment.hpp"

class Polygon : public vector<Point> {
public:
  Polygon() {}

  Polygon(int n) : vector<Point>(n) {}
  
  vector<Segment> getSides() const {
    vector<Segment> res;
    Point pre = back();
    for (const auto& point : *this) {
      res.emplace_back(pre, point);
      pre = point;
    }
    return res;
  }
};
