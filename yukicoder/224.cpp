#include "template.hpp"

int main() {
  int n, res = 0;
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) ++res;
  }
  cout << res << endl;
}
