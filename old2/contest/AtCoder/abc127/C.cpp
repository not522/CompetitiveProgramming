#include "vector.hpp"

int main() {
  int n(in), m(in);
  (void)n;
  Vector<int> l(m), r(m);
  read(l, r);
  cout << max(r.min() - l.max() + 1, 0) << endl;
}
