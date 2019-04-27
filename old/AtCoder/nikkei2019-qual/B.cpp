#include "template.hpp"

int main() {
  int n, res = 0;
  string a, b, c;
  cin >> n >> a >> b >> c;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i] && b[i] == c[i]) {
      continue;
    } else if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) {
      ++res;
    } else {
      res += 2;
    }
  }
  cout << res << endl;
}
