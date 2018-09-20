#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a - (a > b ? 1 : 0)) << endl;
}
