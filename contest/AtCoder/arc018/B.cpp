#include "geometry/area.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<Point> p(n);
  for (auto& i : p) cin >> i;
  for (const auto& a : p) {
    for (const auto& b : p) {
      for (const auto& c : p) {
        Real r = area(Polygon({a, b, c}));
        if (r != 0 && floor(r) == r) ++res;
      }
    }
  }
  cout << res / 6 << endl;
}
