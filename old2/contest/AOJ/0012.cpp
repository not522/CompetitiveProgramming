#include "geometry/polygon.hpp"

int main() {
  setBoolName("YES", "NO");
  Polygon pol(3);
  Point p;
  while (pol = Polygon(3, in), p = in, !in.eof) {
    cout << pol.cover(p) << endl;
  }
}
