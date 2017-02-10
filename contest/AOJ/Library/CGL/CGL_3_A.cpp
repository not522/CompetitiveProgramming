#include "geometry/area.hpp"

int main() {
  int n;
  cin >> n;
  Polygon polygon(n);
  for (auto& p : polygon) cin >> p;
  cout << setprecision(1) << area(polygon) << endl;
}
