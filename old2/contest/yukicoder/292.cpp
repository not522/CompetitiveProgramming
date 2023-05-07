#include "string.hpp"

int main() {
  String s(in);
  int t(in), u(in);
  for (int i = 0; i < s.size(); ++i) {
    if (i == t || i == u) {
      continue;
    }
    cout << s[i];
  }
  cout << endl;
}
