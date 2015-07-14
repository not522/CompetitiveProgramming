#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (i != 0 && a[i - 1] == a[i]) continue;
    if (i != n - 1 && a[i + 1] == a[i]) continue;
    ++res;
  }
  cout << res << endl;
}
