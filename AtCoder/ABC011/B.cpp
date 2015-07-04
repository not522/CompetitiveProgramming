#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (char& c : s) c = tolower(c);
  s[0] = toupper(s[0]);
  cout << s << endl;
}
