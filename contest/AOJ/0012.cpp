#include "geometry/polygon.hpp"

int main() {
  set_bool_name("YES", "NO");
  Polygon pol(3);
  Point p;
  while (pol = Polygon(3, cin), cin >> p) {
    cout << pol.cover(p) << endl;
  }
}
