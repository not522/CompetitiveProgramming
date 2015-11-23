#include "template.hpp"

int main() {
  array<int, 10> b;
  for (int i = 0; i < 10; ++i) {
    int k;
    cin >> k;
    b[k] = i;
  }
  int n;
  cin >> n;
  vector<pair<int, string>> a(n);
  for (auto& i : a) cin >> i.second;
  for (int i = 0; i < n; ++i) {
    for (char j : a[i].second) a[i].first = a[i].first * 10 + b[j - '0'];
  }
  sort(a.begin(), a.end());
  for (const auto& i : a) cout << i.second << endl;
}
