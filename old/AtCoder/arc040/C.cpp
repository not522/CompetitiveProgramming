#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  for (int i = 0; i < n; ++i) {
    int j;
    for (j = n - 1; j >= 0; --j) {
      if (s[i][j] == '.') break;
    }
    if (j < 0) continue;
    for (int k = 0; k <= j; ++k) s[i][k] = 'o';
    if (i < n - 1) {
      for (int k = j; k < n; ++k) s[i + 1][k] = 'o';
    }
    ++res;
  }
  cout << res << endl;
}
