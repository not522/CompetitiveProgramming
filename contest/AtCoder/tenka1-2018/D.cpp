#include "vector.hpp"
#include "string/join.hpp"

int main() {
  int n;
  cin >> n;
  for (int x = 2; ; ++x) {
    int y = x * (x - 1) / 2;
    if (y > n) {
      cout << "No" << endl;
      return 0;
    }
    if (y < n) continue;
    vector<vector<int>> v(x);
    int t = 1;
    for (int i = 0; i < x; ++i) {
      for (int j = i + 1; j < x; ++j) {
        v[i].emplace_back(t);
        v[j].emplace_back(t);
        ++t;
      }
    }
    cout << "Yes" << endl << x << endl;
    for (int i = 0; i < x; ++i) {
      cout << x - 1 << " " << join(v[i]) << endl;
    }
    return 0;
  }
}
