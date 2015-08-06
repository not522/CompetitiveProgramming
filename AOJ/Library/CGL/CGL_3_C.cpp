#include "geometry/polygon.hpp"

int main() {
  int n;
  cin >> n;
  Polygon polygon(n);
  for (auto& p : polygon) cin >> p;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Point point;
    cin >> point;
    if (polygon.cover<true>(point)) cout << 2 << endl;
    else if (polygon.cover(point)) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
