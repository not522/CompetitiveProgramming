#include "vector.hpp"

int main() {
  int n(in), r = 0;
  Vector<int> a(n, in);
  Vector<bool> c(8);
  for (int i : a) {
    if (i < 3200) {
      c[i / 400] = true;
    } else {
      ++r;
    }
  }
  cout << max(1, c.count(true)) << " " << r + c.count(true) << endl;
}
