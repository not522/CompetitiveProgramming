#include "vector.hpp"

int main() {
  int64_t n, k;
  cin >> n >> k;
  vector<pair<int64_t, int64_t>> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
  sort(p);
  for (auto i : p) {
    k -= i.second;
    if (k <= 0) {
      cout << i.first << endl;
      return 0;
    }
  }
}
