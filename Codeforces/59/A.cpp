#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int u = 0, l = 0;
  for (char c : s) {
    if (isupper(c)) ++u;
    else ++l;
  }
  for (char c : s) cout << (char)(u > l ? toupper(c) : tolower(c));
  cout << endl;
}
