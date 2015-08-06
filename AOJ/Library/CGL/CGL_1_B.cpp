#include "geometry/projection.hpp"

int main() {
  Line line;
  cin >> line;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Point p, r;
    cin >> p;
    r = reflection(line, p);
    cout << r << endl;
  }
}
