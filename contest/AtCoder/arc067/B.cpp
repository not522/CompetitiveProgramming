#include "vector.hpp"

int main() {
  int64_t n, a, b, res = 0;
  cin >> n >> a >> b;
  vector<int> x(n);
  cin >> x;
  for (int i = 0; i < n - 1; ++i) res += min(a * (x[i + 1] - x[i]), b);
  cout << res << endl;
}
