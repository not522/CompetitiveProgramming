#include "template.hpp"

int main() {
  int n, s = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    s += r - l + 1;
  }
  cout << s << endl;
}
