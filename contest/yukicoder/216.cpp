#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  cin >> a >> b;
  array<int, 101> c{{0}};
  for (int i = 0; i < n; ++i) c[b[i]] += a[i];
  cout << (*max_element(c.begin(), c.end()) == c[0] ? "YES" : "NO") << endl;
}
