#include "vector.hpp"

int solve(int w, const vector<vector<int>>& v) {
  if (v[w].empty()) return 0;
  vector<int> u;
  for (int i : v[w]) u.emplace_back(solve(i, v));
  sort(u);
  for (unsigned i = 0; i < u.size(); ++i) u[i] += u.size() - i;
  return max(u);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n - 1);
  cin >> a;
  vector<vector<int>> b(n);
  for (int i = 0; i < n - 1; ++i) b[a[i] - 1].emplace_back(i + 1);
  cout << solve(0, b) << endl;
}
