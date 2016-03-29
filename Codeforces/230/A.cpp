#include "vector.hpp"

int main() {
  int s, n;
  cin >> s >> n;
  vector<pair<int, int>> d(n);
  for (auto& i : d) cin >> i.first >> i.second;
  sort(d);
  for (auto& i : d) {
    if (s <= i.first) {
      cout << "NO" << endl;
      return 0;
    }
    s += i.second;
  }
  cout << "YES" << endl;
}
