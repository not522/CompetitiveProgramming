#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  map<pair<int, int>, vector<pair<int, int>>> c;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    int a = floor(x, 20), b = floor(y, 20);
    bool ok = true;
    for (int i = a - 1; i <= a + 1; ++i) {
      for (int j = b - 1; j <= b + 1; ++j) {
        for (auto k : c[make_pair(i, j)]) {
          if (pow(x - k.first, 2) + pow(y - k.second, 2) < 400) ok = false;
        }
      }
    }
    if (ok) {
      c[make_pair(a, b)].emplace_back(x, y);
      ++res;
    }
  }
  cout << res << endl;
}
