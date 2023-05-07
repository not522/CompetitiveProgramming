#include "string.hpp"

int main() {
  String s(in), t(in);
  int r = 0;
  for (int i = 0; i < 3; ++i) {
    if (s[i] == t[i]) {
      ++r;
    }
  }
  cout << r << endl;
}
