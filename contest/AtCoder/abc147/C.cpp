#include "container/power_set.hpp"

int main() {
  int n(in), res = 0;
  Vector<Vector<int>> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    int a(in);
    for (int j = 0; j < a; ++j) {
      x[i].emplace_back(int(in) - 1);
      y[i].emplace_back(in);
    }
  }
  for (auto s : powerSet(n)) {
    bool ok = true;
    int cnt = 0;
    for (auto i : s) {
      ++cnt;
      for (int j = 0; j < x[i].size(); ++j) {
        if (y[i][j]) {
          if (!s.contains(x[i][j])) {
            ok = false;
          }
        } else {
          if (s.contains(x[i][j])) {
            ok = false;
          }
        }
      }
    }
    if (ok) {
      chmax(res, cnt);
    }
  }
  cout << res << endl;
}
