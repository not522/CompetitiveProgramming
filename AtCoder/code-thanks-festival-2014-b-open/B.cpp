#include "template.hpp"

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << max({a + b + c, (a + b) * c, a * b + c, a * b * c}) << endl;
}
