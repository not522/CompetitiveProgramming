#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  int res = a;
  for (; a >= b; a = a / b + a % b) res += a / b;
  cout << res << endl;
}
