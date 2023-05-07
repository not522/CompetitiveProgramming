#include "geometry/point.hpp"

int main() {
  Real a(in), b(in), h(in), m(in);
  auto p = polar(a, deg2rad(30 * h + m / 2));
  auto q = polar(b, deg2rad(m * 6));
  cout << (p - q).abs() << endl;
}
