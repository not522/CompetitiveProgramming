#include "template.hpp"

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  set<int> s;
  for (int i = a; i < a + k && i <= b; ++i) s.emplace(i);
  for (int i = b; i > b - k && a <= i; --i) s.emplace(i);
  for (int i : s) cout << i << endl;
}
