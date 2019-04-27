#include "vector.hpp"

int main() {
  vector<pair<int, string>> v(3);
  for (int i = 0; i < 3; ++i) cin >> v[i].first;
  v[0].second = "A";
  v[1].second = "B";
  v[2].second = "C";
  rsort(v);
  for (int i = 0; i < 3; ++i) cout << v[i].second << endl;
}
