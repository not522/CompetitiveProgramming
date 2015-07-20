#include "template.hpp"

int main() {
  int n, k, res = 0, r = 0;
  string s;
  cin >> n >> k >> s;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) v[i] = s[i] - '0';
  for (int i = 0, j = 0; i < k; ++i, ++j) {
    if (r) --r;
    else ++res;
    if (j == n) j = 0;
    r += v[j];
  }
  cout << res << endl;
}
