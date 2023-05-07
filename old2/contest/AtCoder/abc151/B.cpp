#include "vector.hpp"

int main() {
  int n(in), k(in), m(in);
  Vector<int> a(n - 1, in);
  int r = n * m - a.accumulate();
  if (r <= k) {
    cout << max(r, 0) << endl;
  } else {
    cout << -1 << endl;
  }
}
