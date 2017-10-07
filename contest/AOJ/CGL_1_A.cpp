#include "geometry/projection.hpp"

int main() {
  Line line;
  cin >> line;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    Point p, r;
    cin >> p;
    r = projection(line, p);
    cout << r << endl;
  }
}
