#include "geometry/basic.hpp"

int main() {
  Point a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(15) << abs(det(b - a, c - a)) / 2 << endl;
}
