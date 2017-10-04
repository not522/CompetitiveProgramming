#include "minmax.hpp"

int tax(int x, int p) {
  return x * (100 + p) / 100;
}

int main() {
  while (true) {
    int x, y, s;
    cin >> x >> y >> s;
    if (x == 0 && y == 0 && s == 0) break;
    int res = -1;
    for (int i = 1; i < s; ++i) {
      for (int j = i; j < s; ++j) {
        if (tax(i, x) + tax(j, x) != s) continue;
        chmax(res, tax(i, y) + tax(j, y));
      }
    }
    cout << res << endl;
  }
}
