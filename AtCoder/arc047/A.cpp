#include "template.hpp"

int main() {
  int n, l;
  string s;
  cin >> n >> l >> s;
  int t = 1, res = 0;
  for (char c : s) {
    if (c == '+') {
      ++t;
      if (t > l) {
        ++res;
        t = 1;
      }
    } else {
      --t;
    }
  }
  cout << res << endl;
}
