#include "container/power_set.hpp"

int main() {
  int a;
  cin >> a;
  int f[] = {3, 5, 17, 257, 65537};
  int res = -2;
  for (auto i : PowerSet(5)) {
    int64_t k = 1;
    for (auto j : i) k *= f[j];
    res += most_bit(a / k) + 1;
  }
  cout << res << endl;
}
