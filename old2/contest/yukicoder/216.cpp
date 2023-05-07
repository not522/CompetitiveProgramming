#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in);
  Vector<int> a(n, in), b(n, in), c(101);
  for (int i = 0; i < n; ++i) {
    c[b[i]] += a[i];
  }
  cout << (c.max() == c[0]) << endl;
}
