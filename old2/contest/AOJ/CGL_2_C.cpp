#include "geometry/cross_point.hpp"

int main() {
  int q(in);
  for (int i = 0; i < q; ++i) {
    Line line1(in), line2(in);
    cout << crossPoint(line1, line2) << endl;
  }
}
