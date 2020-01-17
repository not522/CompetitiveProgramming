#include "string.hpp"
#include "vector.hpp"

bool solve(Vector<String> s, int y, int x) {
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s[0].size(); ++j) {
      if (s[i][j] == '#') {
        s[i][j] = '.';
        if (i + y >= s.size()) {
          return false;
        }
        if (j + x >= s[0].size()) {
          return false;
        }
        if (s[i + y][j + x] == '.') {
          return false;
        }
        s[i + y][j + x] = '.';
      }
    }
  }
  return true;
}

bool solve(Vector<String> &s) {
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s[0].size(); ++j) {
      if (solve(s, i, j)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  setBoolName("YES", "NO");
  int h(in), w(in);
  (void)w;
  Vector<String> s(h, in);
  int c = 0;
  for (auto &i : s) {
    c += i.count('#');
  }
  if (c == 0 || c % 2) {
    cout << false << endl;
    return 0;
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (solve(s)) {
        cout << true << endl;
        return 0;
      }
      for (auto &k : s) {
        k.reverse();
      }
    }
    s.reverse();
  }
  cout << false << endl;
}
