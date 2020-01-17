#include "dp/knapsack.hpp"
#include "vector.hpp"

int main() {
  int t(in), n(in);
  Vector<int> c(n, in), v(n, in);
  for (int i = 0; i < n; ++i) {
    for (int vv = v[i] / 2; vv; vv /= 2) {
      c.emplace_back(c[i]);
      v.emplace_back(vv);
    }
  }
  cout << knapsack(t, c, v) << endl;
}
