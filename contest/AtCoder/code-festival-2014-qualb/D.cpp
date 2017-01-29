#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> h(n), a(n), b(n);
  for (int& i : h) cin >> i;
  for (int i = 0; i < n; ++i) {
    int p = i - 1;
    while (p != -1 && h[p] <= h[i]) p = a[p];
    a[i] = p;
  }
  for (int i = n - 1; i >= 0; --i) {
    int p = i + 1;
    while (p != n && h[p] <= h[i]) p = b[p];
    b[i] = p;
  }
  for (int i = 0; i < n; ++i) cout << b[i] - a[i] - 2 << endl;
}
