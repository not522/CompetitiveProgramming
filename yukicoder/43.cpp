#include "vector.hpp"

int solve(vector<string>& s, int i, int j) {
  int n = s.size();
  if (i == n) {
    for (int y = 0; y < n; ++y) for (int x = y + 1; x < n; ++x) s[y][x] = s[x][y] ^ 'o' ^ 'x';
    set<int> w;
    for (const auto& i : s) w.insert(count(i.begin(), i.end(), 'x'));
    return distance(w.begin(), w.find(count(s[0].begin(), s[0].end(), 'x'))) + 1;
  }
  if (i == j) return solve(s, i + 1, 0);
  if (s[i][j] != '-') return solve(s, i, j + 1);
  s[i][j] = 'o';
  int res = solve(s, i, j + 1);
  s[i][j] = 'x';
  res = min(res, solve(s, i, j + 1));
  s[i][j] = '-';
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  cout << solve(s, 0, 0) << endl;
}
