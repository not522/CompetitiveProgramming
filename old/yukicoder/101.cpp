#include "math.hpp"

int main() {
  int n(in), k(in);
  auto a = iota<int>(n);
  for (int i = 0; i < k; ++i) {
    int x(in), y(in);
    swap(a[x - 1], a[y - 1]);
  }
  Vector<bool> used(n);
  int64_t res = 1;
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    int64_t c = 0;
    for (int j = i; !used[j]; j = a[j]) {
      used[j] = true;
      ++c;
    }
    res = lcm(res, c);
  }
  cout << res << endl;
}
