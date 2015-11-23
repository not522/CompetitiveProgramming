#include "template.hpp"

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n - 1);
  for (int& i : a) cin >> i;
  vector<bool> visited(n);
  visited[0] = true;
  for (int i = 0; i < n - 1; ++i) {
    if (!visited[i]) continue;
    visited[i + a[i]] = true;
  }
  cout << (visited[t - 1] ? "YES" : "NO") << endl;
}
