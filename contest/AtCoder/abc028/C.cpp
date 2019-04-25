#include "container/fix_size_set.hpp"

int main() {
  Vector<int> a(5, in), res;
  for (auto i : fixSizeSet(5, 3)) {
    int sum = 0;
    for (auto j : i) {
      sum += a[j];
    }
    res.emplace_back(sum);
  }
  res.rsort();
  cout << res[2] << endl;
}
