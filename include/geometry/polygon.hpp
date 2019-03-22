#pragma once
#include "vector.hpp"
#include "geometry/ccw.hpp"

class Polygon : public Vector<Point> {
public:
  Polygon() {}

  Polygon(int n) : Vector<Point>(n) {}

  Polygon(int n, Input& in) : Vector<Point>(n, in) {}

  Polygon(const std::initializer_list<Point>& p) : Vector<Point>(p) {}

  Polygon(const Vector<Point>& p) : Vector<Point>(p) {}

  vector<Segment> getSides() const {
    if (size() <= 1u) return {};
    vector<Segment> res;
    Point pre = back();
    for (const auto& point : *this) {
      res.emplace_back(pre, point);
      pre = point;
    }
    return res;
  }

  Vector<Vector<Point>> getCorners() const {
    if (size() <= 2u) return {};
    Vector<Vector<Point>> res;
    Point pre1 = *(end() - 2), pre2 = back();
    for (const auto& point : *this) {
      res.emplace_back(Vector<Point>({pre1, pre2, point}));
      pre1 = pre2;
      pre2 = point;
    }
    return res;
  }

  Point& operator[](int i) {
    return vector::operator[](mod(i, int(size())));
  }

  const Point& operator[](int i) const {
    return vector::operator[](mod(i, int(size())));
  }

  template<bool strict = false> bool cover(const Point& point) const {
    bool res = false;
    for (auto& side : getSides()) {
      if (ccw(side, point) == ON) return strict ? false : true;
      if (side.a.y > side.b.y) std::swap(side.a, side.b);
      if (side.a.y <= point.y && point.y < side.b.y && ((side.b - point) / (side.a - point)).y > 0) res = !res;
    }
    return res;
  }

  Real area() const {
    auto side = this->getSides();
    auto f = [](const Real& r, const Segment& segment){return r + segment.area();};
    return accumulate(side.begin(), side.end(), Real(0), f);
  }
};
