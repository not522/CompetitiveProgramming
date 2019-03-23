#include "geometry/intersect.hpp"

int main() {
  set_bool_name("1", "0");
  int q(in);
  for (int i = 0; i < q; ++i) {
    cout << intersect(Segment(in), Segment(in)) << endl;
  }
}
