#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  for (int i = 0; i < m; ++i) cin >> c[i] >> d[i];
  for (int i = 0; i < n; ++i) {
    int r = 0;
    for (int j = 1; j < m; ++j) {
      if (abs(a[i] - c[j]) + abs(b[i] - d[j]) < abs(a[i] - c[r]) + abs(b[i] - d[r])) r = j;
    }
    cout << r + 1 << endl;
  }
}
