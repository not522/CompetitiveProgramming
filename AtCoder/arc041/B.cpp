#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n, string(m, '0')), b(n);
  for (auto& s : b) cin >> s;
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      if (b[i - 1][j] != '0') {
        a[i][j] = b[i - 1][j];
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) b[i + dy[k]][j + dx[k]] -= a[i][j] - '0';
      }
    }
  }
  for (const auto& s : a) cout << s << endl;
}
