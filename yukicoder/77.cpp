#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  a.resize(2 * n);
  int res = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    for (int j = 0; j < i; ++j) {
      if (a[j] < j + 1) x += j + 1 - a[j];
      else y += a[j] - j - 1;
    }
    if (a[i] < i + 1) x += i + 1 - a[i];
    else y += a[i] - i - 1;
    for (int j = 0; j < i; ++j) {
      if (a[i * 2 - j] < j + 1) x += j + 1 - a[i * 2 - j];
      else y += a[i * 2 - j] - j - 1;
    }
    for (int j = 2 * i + 1; j < 2 * n; ++j) y += a[j];
    if (x > y) break;
    res = min(res, y);
  }
  cout << res << endl;
}
