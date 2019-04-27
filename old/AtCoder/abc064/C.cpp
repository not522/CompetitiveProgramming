#include "vector.hpp"

int main() {
  int n, r = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  vector<bool> c(8);
  for (int i : a) {
    if (i < 3200) c[i / 400] = true;
    else ++r;
  }
  cout << max(1, count(c, true)) << " " << r + count(c, true) << endl;
}
