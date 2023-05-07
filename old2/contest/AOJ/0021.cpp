#include "geometry/intersect.hpp"

int main() {
  setBoolName("NO", "YES");
  int t(in);
  for (int i = 0; i < t; ++i) {
    Line p(in), q(in);
    cout << intersect<true>(p, q) << endl;
  }
}
