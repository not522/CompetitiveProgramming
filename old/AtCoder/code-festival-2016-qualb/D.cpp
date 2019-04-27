#include "vector.hpp"

int main() {
  int n, k = 2;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int64_t res = a[0] - 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == k) ++k;
    else if (a[i] % k) res += a[i] / k;
    else res += a[i] / k - 1;
  }
  cout << res << endl;
}
