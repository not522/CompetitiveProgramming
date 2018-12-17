#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(3 * n);
  cin >> a;
  sort(a);
  int64_t res = 0;
  for (int i = 0; i < n; ++i) res += a[2 * i + n];
  cout << res << endl;
}
