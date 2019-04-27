#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << max({a + b, a - b, a * b}) << endl;
}
