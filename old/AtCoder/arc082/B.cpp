#include "template.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> p(n);
  cin >> p;
  for (int i = 0; i < n - 1; ++i) {
    if (p[i] != i + 1) continue;
    ++res;
    if (p[i + 1] == i + 2) p[i + 1] = -1;
  }
  if (p[n - 1] == n) ++res;
  cout << res << endl;
}
