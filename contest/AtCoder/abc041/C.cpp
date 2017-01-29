#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    a.emplace_back(h, i + 1);
  }
  rsort(a);
  for (auto i : a) {
    cout << i.second << endl;
  }
}
