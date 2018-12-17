#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int64_t res = 0, k = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[i] == 'W') {
      res += i - k;
      ++k;
    }
  }
  cout << res << endl;
}
