#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (a[a[i] - 1] - 1 == i) ++res;
  }
  cout << res / 2 << endl;
}
