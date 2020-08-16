#include "vector.hpp"

int main() {
  int n(in), res = 0;
  Vector<int> a(n, in);
  a.sort();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (a[i] == a[j] || a[i] == a[k] || a[j] == a[k] ||
            a[i] + a[j] <= a[k]) {
          continue;
        }
        ++res;
      }
    }
  }
  cout << res << endl;
}
