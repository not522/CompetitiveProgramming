#include "geometry/area.hpp"

int main() {
  Point a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(15) << abs(area(Segment(b - a, c - a))) << endl;
}
