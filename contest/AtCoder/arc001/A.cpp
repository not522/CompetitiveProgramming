#include "template.hpp"

int main() {
  int n;
  string s;
  cin >> n >> s;
  array<int, 4> a = {0, 0, 0, 0};
  for (char c : s) ++a[c - '1'];
  auto m = minmax_element(a.begin(), a.end());
  cout << *m.second << " " << *m.first << endl;
}
