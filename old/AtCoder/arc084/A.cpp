#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  cin >> a >> b >> c;
  sort(a);
  sort(b);
  sort(c);
  int64_t res = 0;
  for (int i = 0; i < n; ++i) res += int64_t(lower_bound(a, b[i])) * (n - upper_bound(c, b[i]));
  cout << res << endl;
}
