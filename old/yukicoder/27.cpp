#include "dp/unbounded_knapsack.hpp"

int main() {
  vector<int> v(4);
  for (int& i : v) cin >> i;
  sort(v.begin(), v.end());
  if (v.back() <= 3) {
    cout << 4 << endl;
    return 0;
  }
  vector<int> a(3), b(3, -1);
  int res = numeric_limits<int>::max();
  for (a[0] = 1; a[0] <= v.back(); ++a[0]) {
    for (a[1] = a[0] + 1; a[1] <= v.back(); ++a[1]) {
      for (a[2] = a[1] + 1; a[2] <= v.back(); ++a[2]) {
        res = min(res, -unboundedKnapsack<int, int, true>(v, a, b));
      }
    }
  }
  cout << res << endl;
}
