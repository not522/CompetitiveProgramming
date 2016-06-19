#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int res = 0;
  for (char c : s) {
    if (isdigit(c)) res += c - '0';
  }
  cout << res << endl;
}
