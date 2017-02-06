#include "template.hpp"

int main() {
  int n, p, q;
  cin >> n >> p;
  vector<int> a(p);
  for (int& i : a) cin >> i;
  cin >> q;
  vector<int> b(q);
  for (int& i : b) cin >> i;
  set<int> s(a.begin(), a.end());
  s.insert(b.begin(), b.end());
  cout << (n == int(s.size()) ? "I become the guy." : "Oh, my keyboard!") << endl;
}
