#include "geometry/intersect.hpp"

int main() {
  set_bool_name("NO", "YES");
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    Line p, q;
    cin >> p >> q;
    cout << intersect<true>(p, q) << endl;
  }
}
