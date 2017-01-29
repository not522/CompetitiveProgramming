#include "vector.hpp"
#include "dp/knapsack.hpp"

int main() {
  int64_t n, a, res = 0;
  cin >> n >> a;
  vector<int> x(n);
  cin >> x;
  vector<int> y, z;
  for (int i : x) {
    if (i >= a) y.emplace_back(i - a);
    else z.emplace_back(a - i);
  }
  auto yy = knapsackCount(2500, y);
  auto zz = knapsackCount(2500, z);
  for (int i = 0; i <= 2500; ++i) res += yy[i] * zz[i];
  cout << res - 1 << endl;
}
