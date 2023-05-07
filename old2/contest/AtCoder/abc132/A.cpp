#include "string.hpp"

int main() {
  String s(in);
  s.sort();
  cout << (s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) << endl;
}
