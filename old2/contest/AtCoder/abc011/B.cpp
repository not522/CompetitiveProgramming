#include "string.hpp"

int main() {
  String s(in);
  s.tolower();
  s[0] = toupper(s[0]);
  cout << s << endl;
}
