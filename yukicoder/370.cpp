#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int n, m, res = numeric_limits<int>::max();
  cin >> n >> m;
  vector<int> d(m);
  cin >> d;
  d.emplace_back(0);
  sort(d);
  for (int i = 0; i + n <= m; ++i) {
    chmin(res, 2 * abs(d[i]) + abs(d[i + n]));
    chmin(res, abs(d[i]) + 2 * abs(d[i + n]));
  }
  cout << res << endl;
}
