#include "vector.hpp"

int main() {
  int64_t n;
  cin >> n;
  int64_t m = n * (n + 1) / 2;
  vector<int64_t> a(n);
  cin >> a;
  auto s = accumulate(a);
  if (s % m) {
    cout << "NO" << endl;
    return 0;
  }
  s /= m;
  for (int i = 0; i < n; ++i) {
    int d = a[(i + 1) % n] - a[i];
    if (d > s || (s - d) % n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
