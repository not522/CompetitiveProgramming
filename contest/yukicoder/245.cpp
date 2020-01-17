#include "geometry/intersect.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<Segment> s(n, in);
  Vector<Point> p(2 * n);
  for (int i = 0; i < n; ++i) {
    p[i] = s[i].a;
    p[i + n] = s[i].b;
  }
  int res = 0;
  for (const auto &a : p) {
    for (const auto &b : p) {
      if (a == b) {
        continue;
      }
      Line line(a, b);
      int cnt = 0;
      for (const auto &k : s) {
        if (intersect(line, k)) {
          ++cnt;
        }
      }
      chmax(res, cnt);
    }
  }
  cout << res << endl;
}
