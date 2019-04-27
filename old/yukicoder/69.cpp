#include "template.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << (a == b ? "YES" : "NO") << endl;
}
