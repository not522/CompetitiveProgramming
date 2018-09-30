#include "container/power_set.hpp"

int main() {
  string s;
  cin >> s;
  for (auto i : PowerSet(3)) {
    int a = s[0] - '0';
    for (int j = 0; j < 3; ++j) {
      if (i.in(j)) a += s[j + 1] - '0';
      else a -= s[j + 1] - '0';
    }
    if (a == 7) {
      for (int j = 0; j < 3; ++j) cout << s[j] << (i.in(j) ? '+' : '-');
      cout << s[3] << "=7" << endl;
      return 0;
    }
  }
}
