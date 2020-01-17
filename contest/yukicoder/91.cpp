#include "vector.hpp"

int main() {
  Vector<int> a(3, in);
  int res = 0;
  while (a[2] >= 0) {
    a.sort();
    int r = a[0];
    for (int &i : a) {
      i -= r;
    }
    res += r;
    a[0] += 1;
    a[2] -= 2;
  }
  cout << res << endl;
}
