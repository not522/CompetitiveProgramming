#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int l = 0, t = 0;
  for (char c : s) {
    if (t == 0 && c == 'I') {
      ++l;
      t = 1;
    } else if (t == 1 && c == 'O') {
      ++l;
      t = 0;
    }
  }
  if (l % 2 == 0 && l > 0) --l;
  cout << l << endl;
}
