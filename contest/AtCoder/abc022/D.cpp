#include "geometry/centroid.hpp"

Real solve(const Vector<Point> &p) {
  Point c = centroid(p);
  auto f = [&](const Real &r, const Point &point) {
    return r + (c - point).abs();
  };
  return accumulate(p.begin(), p.end(), Real(0), f);
}

int main() {
  int n(in);
  Vector<Point> a(n, in), b(n, in);
  cout << solve(b) / solve(a) << endl;
}
