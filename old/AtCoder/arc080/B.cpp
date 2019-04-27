#include "vector.hpp"
#include "string/join.hpp"

int main() {
  int h, w, n, t = 0;
  cin >> h >> w >> n;
  vector<int> a(n);
  cin >> a;
  vector<vector<int>> c(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      c[i][j] = t + 1;
      --a[t];
      if (a[t] == 0) ++t;
    }
    if (i % 2) reverse(c[i]);
  }
  for (int i = 0; i < h; ++i) cout << join(c[i]) << endl;
}
