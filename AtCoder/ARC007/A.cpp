#include "template.hpp"

int main() {
  char x;
  string s;
  cin >> x >> s;
  s.erase(remove(s.begin(), s.end(), x), s.end());
  cout << s << endl;
}
