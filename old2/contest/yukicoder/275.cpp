#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  a.sort();
  cout << (a[(n - 1) / 2] + a[n / 2]) / 2.0 << endl;
}
