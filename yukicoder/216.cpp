#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i : a) cin >> i;
  for (int& i : b) cin >> i;
  array<int, 101> c{0};
  for (int i = 0; i < n; ++i) c[b[i]] += a[i];
  cout << (*max_element(c.begin(), c.end()) == c[0] ? "YES" : "NO") << endl;
}
