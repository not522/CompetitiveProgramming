#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int n, k, res = numeric_limits<int>::max();
  cin >> n >> k;
  vector<int> h(n);
  cin >> h;
  sort(h);
  for (int i = 0; i + k - 1 < n; ++i) chmin(res, h[i + k - 1] - h[i]);
  cout << res << endl;
}
