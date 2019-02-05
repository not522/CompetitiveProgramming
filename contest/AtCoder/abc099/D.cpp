#include "template.hpp"

int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c)), k(n, vector<int>(n)), p(3, vector<int>(c));
  cin >> d >> k;
  for (int i = 0; i < c; ++i) {
    for (int y = 0; y < n; ++y){
      for (int x = 0; x < n; ++x) {
        p[(y + x) % 3][i] += d[k[y][x] - 1][i];
      }
    }
  }
  int res = numeric_limits<int>::max();
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i == j) continue;
      for (int k = 0; k < c; ++k) {
        if (i == k || j == k) continue;
        chmin(res, p[0][i] + p[1][j] + p[2][k]);
      }
    }
  }
  cout << res << endl;
}
