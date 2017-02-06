#include "geometry/point.hpp"
#include "math/basic.hpp"

int main() {
  Point p;
  cin >> p;
  cout << int(floor(p.abs() * 2 + 1).toLongDouble()) << endl;
}
