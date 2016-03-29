#include "template.hpp"

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  a += b;
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  cout << (a == c ? "YES" : "NO") << endl;
}
