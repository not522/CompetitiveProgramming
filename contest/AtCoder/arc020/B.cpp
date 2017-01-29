#include "vector.hpp"

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  cin >> a;
  int res = n;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 1; j <= 10; ++j) {
      if (i == j) continue;
      int r = 0;
      for (int k = 0; k < n; ++k) {
        if (k % 2) {
          if (a[k] != i) ++r;
        } else {
          if (a[k] != j) ++r;
        }
      }
      res = min(res, r);
    }
  }
  cout << res * c << endl;
}
