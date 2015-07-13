#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  sort(a.rbegin(), a.rend());
  int res = 0;
  for (int i = 0; i < n; i += 2) res += a[i];
  cout << res << endl;
}
