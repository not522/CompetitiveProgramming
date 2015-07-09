#include "template.hpp"

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b == c && a - b == c) cout << "?" << endl;
  if (a + b == c && a - b != c) cout << "+" << endl;
  if (a + b != c && a - b == c) cout << "-" << endl;
  if (a + b != c && a - b != c) cout << "!" << endl;
}
