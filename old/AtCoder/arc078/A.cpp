#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  cin >> a;
  auto b = partial_sum(a);
  int64_t res = numeric_limits<int64_t>::max();
  for (int i = 0; i < n - 1; ++i) chmin(res, abs(b.back() - 2 * b[i]));
  cout << res << endl;
}
