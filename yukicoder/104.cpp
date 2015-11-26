#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int p = 1;
  for (char c : s) p = 2 * p + (c == 'L' ? 0 : 1);
  cout << p << endl;
}
