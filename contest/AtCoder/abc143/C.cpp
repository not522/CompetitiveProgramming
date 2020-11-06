#include "string.hpp"

int main() {
  int n(in), res = 1;
  String s(in);
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] != s[i]) {
      ++res;
    }
  }
  cout << res << endl;
}
