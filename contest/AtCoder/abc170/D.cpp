#include "vector.hpp"

int main() {
  int n(in), res = 0;
  Vector<int> a(n, in), c(1000001);
  for (int i = 0; i < n; ++i) {
    ++c[a[i]];
  }
  for (int i = 1000000; i >= 1; --i) {
    for (int j = 2 * i; j <= 1000000; j += i) {
      c[j] += c[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (c[a[i]] == 1) {
      ++res;
    }
  }
  cout << res << endl;
}
