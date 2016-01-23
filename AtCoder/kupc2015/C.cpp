#include "vector.hpp"

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  cin >> a;
  for (auto& i : a) for (int& j : i) if (j == -1) j = numeric_limits<int>::max() / 2;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) {
    if (a[i][j] + a[j][k] < a[i][k]) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) {
    bool ok = false;
    for (int k = 0; k < n; ++k) if (a[i][j] + a[j][k] == a[i][k]) ok = true;
    if (!ok) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int i = 0; i < n; ++i) if (a[i][i] != 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
