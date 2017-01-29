#include "geometry/distance.hpp"

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Segment segment1, segment2;
    cin >> segment1 >> segment2;
    cout << distance(segment1, segment2) << endl;
  }
}
