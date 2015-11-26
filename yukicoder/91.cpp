#include "vector.hpp"

int main() {
  vector<int> a(3);
  cin >> a;
  int res = 0;
  while (a[2] >= 0) {
    sort(a);
    int r = a[0];
    for (int& i : a) i -= r;
    res += r;
    a[0] += 1;
    a[2] -= 2;
  }
  cout << res << endl;
}
