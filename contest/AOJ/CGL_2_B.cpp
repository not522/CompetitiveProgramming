#include "geometry/intersect.hpp"

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Segment segment1, segment2;
    cin >> segment1 >> segment2;
    if (intersect(segment1, segment2)) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
