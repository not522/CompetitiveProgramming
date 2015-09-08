#include "template.hpp"

int main() {
  string s;
  cin >> s;
  const int n = s.size();
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + j <= n && j < n; ++j) {
      string ss = s.substr(i, j), r = ss;
      reverse(r.begin(), r.end());
      if (ss == r) res = max(res, j);
    }
  }
  cout << res << endl;
}
