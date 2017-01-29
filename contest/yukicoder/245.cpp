#include "minmax.hpp"
#include "vector.hpp"
#include "geometry/intersect.hpp"

int main() {
  int n;
  cin >> n;
  vector<Segment> s(n);
  cin >> s;
  vector<Point> p(2 * n);
  for (int i = 0; i < n; ++i) {
    p[i] = s[i].a;
    p[i + n] = s[i].b;
  }
  int res = 0;
  for (const auto& a : p) {
    for (const auto& b : p) {
      if (a == b) continue;
      Line line(a, b);
      int cnt = 0;
      for (const auto& k : s) if (intersect(line, k)) ++cnt;
      chmax(res, cnt);
    }
  }
  cout << res << endl;
}
