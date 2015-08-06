#include "geometry/cross_point.hpp"

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Line line1, line2;
    cin >> line1 >> line2;
    cout << crossPoint(line1, line2) << endl;
  }
}
