#include "string/to_integer.hpp"

int main() {
  string s;
  cin >> s;
  int64_t res = 0;
  for (int i = 0; i < (1 << (s.size() - 1)); ++i) {
    int64_t t = 0;
    for (size_t j = 0; j < s.size(); ++j) {
      t = t * 10 + s[j] - '0';
      if (i & 1 << j) {
        res += t;
        t = 0;
      }
    }
    res += t;
  }
  cout << res << endl;
}
