#include "geometry/intersect.hpp"

int main() {
  set_bool_name("NO", "YES");
  int t(in);
  for (int i = 0; i < t; ++i) {
    Line p(in), q(in);
    cout << intersect<true>(p, q) << endl;
  }
}
