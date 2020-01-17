#include "set.hpp"

int main() {
  setBoolName("YES", "NO");
  Set<Tuple<int, int>> s;
  s.emplace(0, 0);
  const int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
  const int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
  for (int i = 0; i < 3; ++i) {
    auto ss = s;
    for (auto p : s) {
      for (int k = 0; k < 8; ++k) {
        ss.emplace(p.get<0>() + dy[k], p.get<1>() + dx[k]);
      }
    }
    s = ss;
  }
  int x(in), y(in);
  cout << bool(s.count(makeTuple(x, y))) << endl;
}
