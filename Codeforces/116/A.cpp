#include "template.hpp"

int main() {
  int n, res = 0, r = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    r += b - a;
    res = max(res, r);
  }
  cout << res << endl;
}
