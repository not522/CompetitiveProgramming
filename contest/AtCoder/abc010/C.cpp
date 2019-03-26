#include "geometry/point.hpp"

int main() {
  set_bool_name("YES", "NO");
  Point a(in), b(in);
  Real t(in), v(in);
  int n(in);
  for (int i = 0; i < n; ++i) {
    Point p(in);
    if ((p - a).abs() + (p - b).abs() <= t * v) {
      cout << true << endl;
      return 0;
    }
  }
  cout << false << endl;
}
