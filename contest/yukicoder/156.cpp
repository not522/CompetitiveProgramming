#include "vector.hpp"

int main() {
  int n(in), m(in), res = 0;
  Vector<int> c(n, in);
  c.sort();
  for (int i : c) {
    if (i <= m) {
      ++res;
    }
    m -= i;
  }
  cout << res << endl;
}
