#include "geometry/intersect.hpp"

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Line line1, line2;
    cin >> line1 >> line2;
    if (!intersect<true>(line1, line2)) cout << 2 << endl;
    else if ((line2.vec() / line1.vec()).x == 0) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
