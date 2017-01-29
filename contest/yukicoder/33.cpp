#include "math/basic.hpp"

int main() {
  int n, d, t;
  cin >> n >> d >> t;
  map<int, vector<int>> x;
  for (int i = 0; i < n; ++i) {
    int y;
    cin >> y;
    x[mod(y, d)].emplace_back(floor(y, d));
  }
  long long res = 0;
  for (auto& i : x) {
    sort(i.second.begin(), i.second.end());
    int p = numeric_limits<int>::min();
    for (int& j : i.second) {
      res += j + t - max(p, j - t) + 1;
      p = j + t + 1;
    }
  }
  cout << res << endl;
}
