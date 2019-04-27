#include "template.hpp"

int main() {
  string s;
  cin >> s;
  char m = 'z';
  int res = 0;
  for (char c : s) {
    if (c <= m) {
      ++res;
      m = c;
    }
  }
  cout << res << endl;
}
