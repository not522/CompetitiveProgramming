#include "string.hpp"

int main() {
  String s(in);
  s += ".";
  cerr << s << endl;
  int p = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[p] != s[i]) {
      cout << s[p] << i - p;
      p = i;
    }
  }
  cout << endl;
}
