#include "template.hpp"

int main() {
  int n, res = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) ++res;
  }
  cout << res << endl;
}
