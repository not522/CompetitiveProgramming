#include "vector.hpp"

int main() {
  int n, T;
  cin >> n >> T;
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i].first >> c[i].second;
  sort(c);
  for (const auto& i : c) {
    if (i.second <= T) {
      cout << i.first << endl;
      return 0;
    }
  }
  cout << "TLE" << endl;
}
