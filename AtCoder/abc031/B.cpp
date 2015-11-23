#include "template.hpp"

int main() {
  int l, h, n;
  cin >> l >> h >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cout << (a < l ? l - a : a <= h ? 0 : -1) << endl;
  }
}
