#include "string/parser.hpp"

int main() {
  string a, op, b;
  cin >> a >> op >> b;
  cout << parse(a + op + b) << endl;
}
