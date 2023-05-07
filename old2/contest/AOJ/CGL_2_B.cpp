#include "geometry/intersect.hpp"

int main() {
  setBoolName("1", "0");
  int q(in);
  for (int i = 0; i < q; ++i) {
    cout << intersect(Segment(in), Segment(in)) << endl;
  }
}
