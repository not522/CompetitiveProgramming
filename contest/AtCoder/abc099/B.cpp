#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  int k = b - a;
  cout << k * (k - 1) / 2 - a << endl;
}
