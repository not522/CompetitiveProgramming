#include "template.hpp"

int main() {
  string s;
  int64_t k;
  cin >> s >> k;
  for (int i = 0; ; ++i) {
    if (s[i] != '1') {
      cout << s[i] << endl;
      return 0;
    }
    --k;
    if (k == 0) {
      cout << 1 << endl;
      return 0;
    }
  }
}
