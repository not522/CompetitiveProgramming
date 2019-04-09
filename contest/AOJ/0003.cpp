#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in);
  for (int i = 0; i < n; ++i) {
    Vector<int> a(3, in);
    a.sort();
    cout << (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) << endl;
  }
}
