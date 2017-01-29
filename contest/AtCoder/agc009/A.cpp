#include "vector.hpp"

int main() {
  int64_t n, r = 0;
  cin >> n;
  vector<int64_t> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  reverse(a);
  reverse(b);
  for (int i = 0; i < n; ++i) r += (a[i] + r) % b[i] ? b[i] - (a[i] + r) % b[i] : 0;
  cout << r << endl;
}
