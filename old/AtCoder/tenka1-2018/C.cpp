#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  cin >> a;
  sort(a);
  b[0] = a[n / 2];
  int64_t res = 0;
  for (int k = 0; k < 2; ++k) {
    for (int i = 1; i < n; i += 2) b[i] = a[i / 2];
    for (int i = 2; i < n; i += 2) b[i] = a[n - i / 2];
    int64_t r = 0;
    for (int i = 0; i < n - 1; ++i) r += abs(b[i] - b[i + 1]);
    chmax(res, r);
    reverse(a);
  }
  cout << res << endl;
}
