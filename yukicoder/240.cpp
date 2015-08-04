#include "template.hpp"

int main() {
  set<tuple<int, int>> s;
  s.insert(make_tuple(0, 0));
  const int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
  const int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
  for (int i = 0; i < 3; ++i) {
    auto ss = s;
    for (auto p : s) {
      for (int k = 0; k < 8; ++k) {
        ss.insert(make_tuple(get<0>(p) + dy[k], get<1>(p) + dx[k]));
      }
    }
    s = ss;
  }
  int x, y;
  cin >> x >> y;
  cout << (s.count(make_tuple(x, y)) ? "YES" : "NO") << endl;
}

