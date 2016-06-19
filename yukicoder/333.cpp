#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a < b ? b - 2 : 1999999999 - b) << endl;
}
