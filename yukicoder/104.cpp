#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int p = 1;
  for (char c : s) {
    if (c == 'L') p *= 2;
    else p = 2 * p + 1;
  }
  cout << p << endl;
}
