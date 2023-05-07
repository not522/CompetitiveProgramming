#include "set.hpp"
#include "string.hpp"

int solve(Vector<String> &s, int i, int j) {
  int n = s.size();
  if (i == n) {
    for (int y = 0; y < n; ++y) {
      for (int x = y + 1; x < n; ++x) {
        s[y][x] = s[x][y] ^ 'o' ^ 'x';
      }
    }
    Set<int> w;
    for (const auto &i : s) {
      w.insert(i.count('x'));
    }
    return w.find(s[0].count('x')) + 1;
  }
  if (i == j) {
    return solve(s, i + 1, 0);
  }
  if (s[i][j] != '-') {
    return solve(s, i, j + 1);
  }
  s[i][j] = 'o';
  int res = solve(s, i, j + 1);
  s[i][j] = 'x';
  chmin(res, solve(s, i, j + 1));
  s[i][j] = '-';
  return res;
}

int main() {
  int n(in);
  Vector<String> s(n, in);
  cout << solve(s, 0, 0) << endl;
}
