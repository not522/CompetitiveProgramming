#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  cout << a - b + max({-a / 100 * 100 + 900, -a / 10 % 10 * 10 + 90, -a % 10 + 9, b / 100 * 100 - 100, b / 10 % 10 * 10, b % 10}) << endl;
}
