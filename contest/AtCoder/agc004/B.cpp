#include "minmax.hpp"
#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int64_t n, x, r = numeric_limits<int64_t>::max();
  cin >> n >> x;
  vector<int64_t> a(n), b;
  cin >> a;
  b = a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) chmin(b[j], a[mod<int64_t>(j - i, n)]);
    chmin(r, accumulate(b) + i * x);
  }
  cout << r << endl;
}
