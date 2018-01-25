#include "template.hpp"

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  cout << (a.back() == b[0] && b.back() == c[0] ? "YES" : "NO") << endl;
}
