#include "string.hpp"
#include "vector.hpp"

void solve() {
  String s(in), t = "atcoder ";
  int res = inf<int>();
  for (int i = 0; i <= 7; ++i) {
    int k = 0;
    Vector<int> v;
    for (int j = 0; j < s.size(); ++j) {
      if (k < i) {
        if (s[j] == t[k]) {
          v.emplace_back(j);
          ++k;
        }
      } else {
        if (s[j] > t[k]) {
          v.emplace_back(j);
          break;
        }
      }
    }
    if (v.size() <= i) {
      continue;
    }
    int r = 0;
    for (int j = 0; j <= i; ++j) {
      r += v[j] - j;
    }
    chmin(res, r);
  }
  if (res == inf<int>()) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}

int main() {
  int t(in);
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
