#include "string/to_integer.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  int x = (a.size() > 1 ? 10 : toInteger<int>(a));
  int y = (b.size() > 1 ? 10 : toInteger<int>(b));
  if (x + y > x * y) cout << "S" << endl;
  if (x + y < x * y) cout << "P" << endl;
  if (x + y == x * y) cout << "E" << endl;
}
