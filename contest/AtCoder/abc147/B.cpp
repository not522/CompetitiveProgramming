#include "string.hpp"

int main() {
  String s(in);
  int res = 0;
  for (int i = 0; i < s.size() / 2; ++i) {
    if (s[i] != s[s.size() - i - 1]) {
      ++res;
    }
  }
  cout << res << endl;
}
