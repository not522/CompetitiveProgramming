#include "template.hpp"

int main() {
  array<int, 3> a;
  for (int& i : a) cin >> i;
  int res = 0;
  while (a[2] >= 0) {
    sort(a.begin(), a.end());
    int r = a[0];
    for (int& i : a) i -= r;
    res += r;
    a[0] += 1;
    a[2] -= 2;
  }
  cout << res << endl;
}
