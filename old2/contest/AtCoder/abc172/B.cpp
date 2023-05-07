#include "string.hpp"

int main() {
  String s(in), t(in);
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != t[i]) {
      ++res;
    }
  }
  cout << res << endl;
}
