#include "string.hpp"

int main() {
  String s(in);
  int a = 0, z = s.size() - 1;
  while (s[a] != 'A') {
    ++a;
  }
  while (s[z] != 'Z') {
    --z;
  }
  cout << z - a + 1 << endl;
}
