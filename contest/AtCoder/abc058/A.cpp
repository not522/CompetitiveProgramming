#include "template.hpp"

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (b - a == c - b ? "YES" : "NO") << endl;
}
