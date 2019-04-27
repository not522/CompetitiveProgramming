#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  if (a < 0) ++a;
  if (b < 0) ++b;
  cout << b - a << endl;
}
