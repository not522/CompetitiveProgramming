#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  a.sort();
  for (int i = 0; i <= n; ++i) {
    Vector<int> v(n - i, 2 * i + 4 * (n - i) - 4);
    v.resize(n, 2 * i + 4 * (n - i) - 2);
    if (a == v) {
      cout << i << " " << n - i << endl;
    }
  }
}
