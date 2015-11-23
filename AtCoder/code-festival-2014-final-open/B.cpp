#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int res = 0, t = 1;
  for (char c : s) {
    res += (c - '0') * t;
    t *= -1;
  }
  cout << res << endl;
}
