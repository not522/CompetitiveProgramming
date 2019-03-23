#include "geometry/distance.hpp"

int main() {
  int q(in);
  for (int i = 0; i < q; ++i) {
    Segment segment1(in), segment2(in);
    cout << distance(segment1, segment2) << endl;
  }
}
