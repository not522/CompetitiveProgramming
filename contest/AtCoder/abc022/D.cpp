#include "geometry/centroid.hpp"

Real solve(const vector<Point>& p) {
  Point c = centroid(p);
  auto f = [&](const Real& r, const Point& point){return r + (c - point).abs();};
  return accumulate(p.begin(), p.end(), Real(0), f);
}

int main() {
  int n;
  cin >> n;
  vector<Point> a(n), b(n);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  cout << solve(b) / solve(a) << endl;
}
