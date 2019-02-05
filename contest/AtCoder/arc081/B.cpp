#include "math/mint.hpp"

bool check(char a, char b, int x, int y) {
  if (a == b) return x == y;
  return x != y;
}

int main() {
  int n;
  string s[2];
  cin >> n >> s[0] >> s[1];
  vector<vector<vector<Mint>>> dp(n, vector<vector<Mint>>(3, vector<Mint>(3)));
  if (s[0][0] == s[1][0]) {
    for (int i = 0; i < 3; ++i) dp[0][i][i] = 1;
  } else {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i != j) dp[0][i][j] = 1;
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int a = 0; a < 3; ++a) {
      for (int b = 0; b < 3; ++b) {
        if (!check(s[0][i - 1], s[1][i - 1], a, b)) continue;
        for (int x = 0; x < 3; ++x) {
          if (!check(s[0][i - 1], s[0][i], a, x)) continue;
          for (int y = 0; y < 3; ++y) {
            if (!check(s[1][i - 1], s[1][i], b, y)) continue;
            if (!check(s[0][i], s[1][i], x, y)) continue;
            dp[i][x][y] += dp[i - 1][a][b];
          }
        }
      }
    }
  }
  Mint res = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) res += dp.back()[i][j];
  }
  cout << res << endl;
}
