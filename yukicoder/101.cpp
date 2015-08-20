#include "math/basic.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    swap(a[x - 1], a[y - 1]);
  }
  vector<bool> used(n);
  long long res = 1;
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    long long c = 0;
    for (int j = i; !used[j]; j = a[j]) {
      used[j] = true;
      ++c;
    }
    res = lcm(res, c);
  }
  cout << res << endl;
}
