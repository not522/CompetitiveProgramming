#include "vector.hpp"

void solve() {
  int n(in);
  Map<int, int> m;
  for (int i = 0; i < n; ++i) {
    ++m[int(in)];
  }
  Vector<int> v = {0, 0, 0};
  for (auto i : m) {
    v.emplace_back(i.second);
  }
  v.rsort();
  int res = 0;
  while (v[2] > 0) {
    for (int i = 0; i < 3; ++i) {
      --v[i];
    }
    v.rsort();
    ++res;
  }
  cout << res << endl;
}

int main() {
  int t(in);
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
