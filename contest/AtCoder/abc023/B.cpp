#include "template.hpp"

int main() {
  map<string, int> m;
  string k = "b";
  for (int i = 1; i < 100; ++i) {
    int n = m.size();
    m[k] = n;
    if (i % 3 == 1) k = "a" + k + "c";
    if (i % 3 == 2) k = "c" + k + "a";
    if (i % 3 == 0) k = "b" + k + "b";
  }
  int n;
  string s;
  cin >> n >> s;
  if (m.count(s)) cout << m[s] << endl;
  else cout << -1 << endl;
}
