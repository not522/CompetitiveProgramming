#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (char c : s) {
    if (c == 'a') continue;
    if (c == 'i') continue;
    if (c == 'u') continue;
    if (c == 'e') continue;
    if (c == 'o') continue;
    cout << c;
  }
  cout << endl;
}
