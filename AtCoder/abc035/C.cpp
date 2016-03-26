#include "template.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    a[l - 1] ^= 1;
    a[r] ^= 1;
  }
  a.resize(n);
  int r = 0;
  for (int i : a) {
    if (i) r ^= 1;
    cout << r;
  }
  cout << endl;
}
