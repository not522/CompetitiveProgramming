#include "template.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for (int& i : t) cin >> i;
  for (int i = 3; i <= n; ++i) {
    if (accumulate(t.begin() + i - 3, t.begin() + i, 0) < k) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
