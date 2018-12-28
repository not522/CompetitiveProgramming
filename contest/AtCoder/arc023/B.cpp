#include "vector.hpp"

int main() {
  int r, c, d, res = 0;
  cin >> r >> c >> d;
  vector<vector<int>> a(r, vector<int>(c));
  cin >> a;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i + j <= d && (i + j) % 2 == d % 2) chmax(res, a[i][j]);
    }
  }
  cout << res << endl;
}
