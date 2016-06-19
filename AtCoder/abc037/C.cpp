#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  cin >> a;
  int64_t s = accumulate(a.begin(), a.begin() + k, 0ll), res = s;
  for (int i = 0; k + i < n; ++i) {
    res += s += a[k + i] - a[i];
  }
  cout << res << endl;
}
