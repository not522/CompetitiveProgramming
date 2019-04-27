#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n, 1);
  vector<bool> f(n);
  f[0] = true;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    --c[x];
    ++c[y];
    f[y] = f[x] || f[y];
    if (c[x] == 0) f[x] = false;
  }
  cout << count(f, true) << endl;
}
