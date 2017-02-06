#include "container/fix_size_set.hpp"

int main() {
  vector<int> a(5), res;
  for (int& i : a) cin >> i;
  for (auto i : FixSizeSet(5, 3)) {
    int sum = 0;
    for (auto j : i) sum += a[int(j)];
    res.emplace_back(sum);
  }
  sort(res.rbegin(), res.rend());
  cout << res[2] << endl;
}
