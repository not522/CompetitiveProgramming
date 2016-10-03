#include "template.hpp"

int main() {
  int64_t n, a, c = 0, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    res += (a + c) / 2;
    c = a ? (a + c) % 2 : 0;
  }
  cout << res << endl;
}
