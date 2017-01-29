#include "template.hpp"

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (x >> i & 1) res += a[i];
  }
  cout << res << endl;
}
