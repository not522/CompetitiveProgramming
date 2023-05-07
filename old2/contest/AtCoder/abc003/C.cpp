#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> r(n, in);
  r.partial_sort(k, true);
  double res = 0;
  for (int i = k - 1; i >= 0; --i) {
    res = (res + r[i]) / 2;
  }
  cout << res << endl;
}
