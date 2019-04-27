#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    c[i] = a + b;
    res += a;
  }
  rsort(c);
  for (int i = 1; i < n; i += 2) res -= c[i];
  cout << res << endl;
}
