#include "template.hpp"

int main() {
  int c;
  cin >> c;
  vector<array<int, 3>> b(c);
  array<int, 3> a{0};
  for (auto& i : b) {
    for (auto& j : i) cin >> j;
    sort(i.begin(), i.end());
    for (int j = 0; j < 3; ++j) a[j] = max(a[j], i[j]);
  }
  cout << accumulate(a.begin(), a.end(), 1, multiplies<int>()) << endl;
}
