#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (char c : s) cout << char(c ^ 'a' ^ 'A');
  cout << endl;
}
