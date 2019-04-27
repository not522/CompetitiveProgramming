#include "vector.hpp"

int main() {
  int n, r = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  rsort(a);
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) r += a[i];
    else r -= a[i];
  }
  cout << r << endl;
}
