#include "vector.hpp"

int main() {
  int n(in), q(in);
  Vector<int> a(n + 1);
  for (int i = 0; i < q; ++i) {
    int l(in), r(in);
    a[l - 1] ^= 1;
    a[r] ^= 1;
  }
  a.resize(n);
  int r = 0;
  for (int i : a) {
    if (i) {
      r ^= 1;
    }
    cout << r;
  }
  cout << endl;
}
