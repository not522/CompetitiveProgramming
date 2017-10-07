#include "container/fix_size_set.hpp"

int main() {
  while (true) {
    int n, k, s, res = 0;
    cin >> n >> k >> s;
    if (n == 0 && k == 0 && s == 0) break;
    for (auto iter : FixSizeSet(n, k)) {
      int sum = 0;
      for (auto i : iter) sum += i + 1;
      if (sum == s) ++res;
    }
    cout << res << endl;
  }
}
