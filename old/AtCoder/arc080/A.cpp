#include "template.hpp"

int main() {
  int n, x = 0, y = 0, z = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 4 == 0) ++x;
    else if (a[i] % 2 == 0) ++y;
    else ++z;
  }
  if (y) ++z;
  cout << (x + 1 >= z) << endl;
}
