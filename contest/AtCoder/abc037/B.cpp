#include "vector.hpp"

int main() {
  int n(in), q(in);
  Vector<int> a(n);
  for (int i = 0; i < q; ++i) {
    int l(in), r(in), t(in);
    for (int j = l - 1; j < r; ++j) {
      a[j] = t;
    }
  }
  a.output();
}
