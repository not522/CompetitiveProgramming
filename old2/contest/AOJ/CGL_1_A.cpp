#include "geometry/projection.hpp"

int main() {
  Line line(in);
  int q(in);
  for (int i = 0; i < q; ++i) {
    cout << projection(line, Point(in)) << endl;
  }
}
