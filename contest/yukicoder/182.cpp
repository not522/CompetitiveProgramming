#include "vector.hpp"

int main() {
  int n(in), res = 0;
  Vector<int> a(n, in);
  a.sort();
  for (int i = 0; i < n; ++i) {
    if (i != 0 && a[i - 1] == a[i]) {
      continue;
    }
    if (i != n - 1 && a[i + 1] == a[i]) {
      continue;
    }
    ++res;
  }
  cout << res << endl;
}
