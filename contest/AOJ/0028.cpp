#include "map.hpp"

int main() {
  int mx = 0;
  Map<int, int> m;
  for (int n; cin >> n;) {
    ++m[n];
    chmax(mx, m[n]);
  }
  for (auto i : m) {
    if (i.second == mx) {
      cout << i.first << endl;
    }
  }
}
