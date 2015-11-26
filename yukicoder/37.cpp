#include "vector.hpp"
#include "dp/knapsack.hpp"

int main() {
  int t, n;
  cin >> t >> n;
  vector<int> c(n), v(n);
  cin >> c >> v;
  for (int i = 0; i < n; ++i) {
    for (int vv = v[i] / 2; vv; vv /= 2) {
      c.emplace_back(c[i]);
      v.emplace_back(vv);
    }
  }
  cout << knapsack(t, c, v) << endl;
}
