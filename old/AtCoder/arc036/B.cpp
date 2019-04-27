#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int& i : h) cin >> i;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    if (i == 0 || h[i - 1] > h[i]) a[i] = i;
    else a[i] = a[i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1 || h[i + 1] > h[i]) b[i] = i;
    else b[i] = b[i + 1];
  }
  int res = 0;
  for (int i = 0; i < n; ++i) res = max(res, b[i] - a[i] + 1);
  cout << res << endl;
}
