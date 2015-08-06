#pragma once
#include "geometry/segment.hpp"

class Polygon : public vector<Point> {
public:
  Polygon() {}

  Polygon(int n) : vector<Point>(n) {}

  Polygon(initializer_list<Point> p) : vector<Point>(p) {}

  vector<Segment> getSides() const {
    vector<Segment> res;
    Point pre = back();
    for (const auto& point : *this) {
      res.emplace_back(pre, point);
      pre = point;
    }
    return res;
  }

  vector<array<Point, 3>> getCorners() const {
    vector<array<Point, 3>> res;
    Point pre1 = *(end() - 2), pre2 = back();
    for (const auto& point : *this) {
      res.emplace_back(array<Point,3>({{pre1, pre2, point}}));
      pre1 = pre2;
      pre2 = point;
    }
    return res;
  }

  Point& operator[](int i) {
    return vector::operator[](mod(i, (int)size()));
  }

  const Point& operator[](int i) const {
    return vector::operator[](mod(i, (int)size()));
  }
};
