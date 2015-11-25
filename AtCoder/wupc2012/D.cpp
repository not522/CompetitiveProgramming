#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      int k;
      cin >> k;
      a[i].emplace_back(k);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) a[i][j] += a[i - 1][j];
      else if (j == i) a[i][j] += a[i - 1][j - 1];
      else a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
    }
  }
  cout << *max_element(a.back().begin(), a.back().end()) << endl;
}
