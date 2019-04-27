#include "template.hpp"

int main() {
  string n;
  cin >> n;
  int c = count(n.begin(), n.end(), '4') + count(n.begin(), n.end(), '7');
  cout << (c == 4 || c == 7 ? "YES" : "NO") << endl;
}
