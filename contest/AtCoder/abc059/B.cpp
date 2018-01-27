#include "template.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  while (a.size() < b.size()) a = '0' + a;
  while (a.size() > b.size()) b = '0' + b;
  cout << (a > b ? "GREATER" : a < b ? "LESS" : "EQUAL") << endl;
}
