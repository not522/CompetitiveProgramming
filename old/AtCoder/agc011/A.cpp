#include "vector.hpp"

int main() {
  int n, c, k, res = 0, j = 0;
  cin >> n >> c >> k;
  vector<int> t(n);
  cin >> t;
  sort(t);
  for (int i = 0; i < n; ++i) {
    if (t[j] + k < t[i]) {
      ++res;
      j = i;
    } else if (i - j + 1 == c) {
      ++res;
      j = i + 1;
    }
  }
  if (j != n) ++res;
  cout << res << endl;
}
