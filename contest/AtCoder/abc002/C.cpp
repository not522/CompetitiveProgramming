#include "geometry/area.hpp"

int main() {
  Point a, b, c;
  cin >> a >> b >> c;
  cout << area(Segment(b - a, c - a)).abs() << endl;
}
