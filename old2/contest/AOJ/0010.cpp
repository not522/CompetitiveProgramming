#include "geometry/triangle.hpp"

int main() {
  int t(in);
  for (int i = 0; i < t; ++i) {
    Triangle t(in);
    Point p = t.circumcenter();
    cout << std::setprecision(3) << p << " " << (t.a - p).abs() << endl;
  }
}
