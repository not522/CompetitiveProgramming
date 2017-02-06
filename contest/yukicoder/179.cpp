#include "vector.hpp"

bool solve(vector<string> s, int y, int x) {
  for (uint i = 0; i < s.size(); ++i) {
    for (uint j = 0; j < s[0].size(); ++j) {
      if (s[i][j] == '#') {
        s[i][j] = '.';
        if (i + y >= s.size()) return false;
        if (j + x >= s[0].size()) return false;
        if (s[i + y][j + x] == '.') return false;
        s[i + y][j + x] = '.';
      }
    }
  }
  return true;
}

bool solve(vector<string>& s) {
  for (uint i = 0; i < s.size(); ++i) for (uint j = 0; j < s[0].size(); ++j) if (solve(s, i, j)) return true;
  return false;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  int c = 0;
  for (auto& i : s) c += count(i.begin(), i.end(), '#');
  if (c == 0 || c % 2) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (solve(s)) {
        cout << "YES" << endl;
        return 0;
      }
      for (auto& k : s) reverse(k.begin(), k.end());
    }
    reverse(s);
  }
  cout << "NO" << endl;
}
