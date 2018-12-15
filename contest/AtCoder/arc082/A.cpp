#include "minmax.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  unordered_map<int, int> m;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++m[a];
  }
  for (auto i : m) {
    int k = i.first;
    for (int j = -2; j <= 0; ++j) chmax(res, m[k + j] + m[k + j + 1] + m[k + j + 2]);
  }
  cout << res << endl;
}
