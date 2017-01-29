#include "vector.hpp"

bool solve(const vector<vector<int>>& t, int i, int x) {
  if (i == 0) return x == 0;
  return any_of(t[i - 1], [&](int j){return solve(t, i - 1, x ^ j);});
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> t(n, vector<int>(k));
  cin >> t;
  cout << (solve(t, n, 0) ? "Found" : "Nothing") << endl;
}
