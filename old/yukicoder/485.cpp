#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  if (b % a) cout << "NO" << endl;
  else cout << b / a << endl;
}
