#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    array<int, 3> a;
    for (int& i : a) cin >> i;
    if (accumulate(a.begin(), a.end(), 0) >= 2) ++res;
  }
  cout << res << endl;
}
