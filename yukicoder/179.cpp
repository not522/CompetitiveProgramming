#include "template.hpp"

bool solve(vector<string> s, int y, int x) {
  for (int i = 0; i < (int)s.size(); ++i) {
    for (int j = 0; j < (int)s[0].size(); ++j) {
      if (s[i][j] == '#') {
        s[i][j] = '.';
        if (i + y >= (int)s.size()) return false;
        if (j + x >= (int)s[0].size()) return false;
        if (s[i + y][j + x] == '.') return false;
        s[i + y][j + x] = '.';
      }
    }
  }
  return true;
}

bool solve(vector<string>& s) {
  for (int i = 0; i < (int)s.size(); ++i) {
    for (int j = 0; j < (int)s[0].size(); ++j) {
      if (solve(s, i, j)) return true;
    }
  }
  return false;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& i : s) cin >> i;
  int c = 0;
  for (auto& i : s) c+= count(i.begin(), i.end(), '#');
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
    reverse(s.begin(), s.end());
  }
  cout << "NO" << endl;
}
